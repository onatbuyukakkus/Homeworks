//Onat Büyükakkuş 2035772
//Enver Evci 1942085

#include <p18cxxx.h>
#include <p18f8722.h>
#pragma config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF
#define _XTAL_FREQ   40000000
#include "Includes.h"
#include "LCD.h"
#define timer1Int PIR1
#pragma interrupt myisr // Pragma for interrupt service routine
unsigned int statusSave;
unsigned int pclathSave;
unsigned int adcReady = 0;
unsigned int timer1counter=0;
unsigned int timer0counter=0;
unsigned int counter2=0;
unsigned char sevenSegInitialNumOne;
unsigned char sevenSegInitialNumTen;
unsigned int sevenSegNumbers[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};
bit busy;
int firstChoice=1;
bit cursorBlink;
unsigned char firstSelected;
unsigned int row;
unsigned int col;
unsigned int row2;
unsigned int col2;
unsigned char curRow[2][5]={{0xFF,0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF,0xFF}};
unsigned int adcValue;
int adcFlag=0;
unsigned int temp;
bit start=0;
unsigned int correctNumber=0;
unsigned int RB6Flag=0;
unsigned int RB7Flag=0;
unsigned char stringRow;
unsigned char stringCol;
unsigned char axis='X';
unsigned char ansRow[2][5]={{'!','?','!','#','='},{'#','=',';','?',';'}};
void initADC();
void initTimers();
void updateLCD();
void entryDisplay();
void saveRegisters();
void restoreRegisters();
void interruptExit();
void timer0isr();
void timer1isr();
void timer1InterruptExit();
void displaySevenSegment();
void beginningDisplay();
void displayGame();
void cursorAt();
void changeCol();
void changeRow();
void fixPrevCursor();
void showADCVal();
void axisRowColDisplay();
void changeAxis();
void changedCol();
void changedRow();
void initB_int();
void selectElement();
void freeze();


void interrupt myisr() { // interrupt service routine
    saveRegisters();
    if(INTCONbits.RBIF==1){
        if(RB6 == 0)
        {
            RB6Flag=1;
        }
        else if(RB7 == 0)
        {
            RB7Flag=1;
        }
        INTCONbits.RBIF = 0;
    }
    if((PIR1bits.ADIF)==1){
        PIR1bits.ADIF=0;
        adcValue=ADRES;
        GO_DONE=0;
    }
    if(timer1Int){
        timer1isr();
    }
    else if(INTCONbits.TMR0IF==1){
        timer0isr();
    }
}
void timer0isr(){
    INTCONbits.TMR0IF=0;
    timer0counter++;
    if(timer0counter==16){
        GO_DONE=1;
        adcFlag=1;
        timer0counter=0;
    }
}
void timer1isr(){
    if(timer1counter==19){
        if(start)
            displaySevenSegment();
        cursorBlink=cursorBlink^0x01;
        if(counter2>0){
            counter2--;
        }
        else {
            busy=0;
        }
        timer1counter=0;
        //7-segment count down handling
        if(sevenSegInitialNumOne==0){
            sevenSegInitialNumTen--; sevenSegInitialNumOne=9;
        }
        else
            sevenSegInitialNumOne=(sevenSegInitialNumOne-1)%10;
        //
        }
    else {
        switch(timer1counter){
            case 4:
                if(start)
                    displaySevenSegment();
                cursorBlink=cursorBlink^0x01;
                break;
            case 9:
                if(start)
                    displaySevenSegment();
                cursorBlink=cursorBlink^0x01;
                break;
            case 14:
                if(start)
                    displaySevenSegment();
                cursorBlink=cursorBlink^0x01;
                break;
        }
        timer1counter++;
    }
    timer1InterruptExit();
}
void timer1InterruptExit(){
    timer1Int=timer1Int^0x01; //tmr1if is cleared
    restoreRegisters();
}
// Main Function
void main(void)
{
    __delay_ms(15);
    __delay_ms(15);
    __delay_ms(15);
    __delay_ms(15); // These delays are required for correct operation of the LCD
    InitLCD();			// Initialize LCD in 4bit mode
    initADC();
    initB_int();
    initTimers();
    entryDisplay();
    while(busy);
    beginningDisplay();
    while(busy);
    sevenSegInitialNumOne=9;
    sevenSegInitialNumTen=9;
    displayGame();
    start=1;
    axisRowColDisplay();
    while(!(sevenSegInitialNumOne==0 && sevenSegInitialNumTen==0)){
        displaySevenSegment();
        cursorAt();
        displaySevenSegment();

        if(RB6Flag==1) {
            RB6Flag=0;
            changeAxis();
        }
        if(RB7Flag==1) {
            RB7Flag=0;
            if(curRow[row][col]==0xff || curRow[row][col]==' ')
                selectElement();
        }
        if(adcFlag){
            if(axis=='X')
                changeCol();
            if(axis=='Y')
                changeRow();
            ADCON0bits.ADON=1;
            PIE1bits.ADIE=1;
            PIR1bits.ADIF=1;
            adcFlag=0;
        }
    }
    freeze();
}
void freeze(){
    INTCON=0;
    if(row==0)
        WriteCommandToLCD(0x81+col);
    else WriteCommandToLCD(0xc1+col);
    WriteDataToLCD(curRow[row][col]);
   
    while(1){
        displaySevenSegment();
    }
}
void initADC(){
    TRISH4=1;
    ADCON0=0x32;
    ADCON1=0x00;
    ADCON2=0x8A;
}
void fixPrevCursor(){
    if(row==0) WriteCommandToLCD(0x81+col);
    else  WriteCommandToLCD(0xC1+col);
    WriteDataToLCD(curRow[row][col]);
}
void changeAxis(){
    if(axis=='X'){
        axis='Y';
    }
    else {
        axis='X';
    }
    WriteCommandToLCD(0x8D);
    WriteDataToLCD(axis);
}
void selectElement(){
    if(firstChoice==1){
        curRow[row][col]=ansRow[row][col];
        firstChoice=0;
        firstSelected=ansRow[row][col];
        row2=row;
        col2=col;
    }
    else{
        curRow[row][col]=ansRow[row][col];
        if(firstSelected==ansRow[row][col]){
            correctNumber++;
            if(correctNumber==5){
                freeze();
            }
        }
        else{
            busy=1;
            counter2=1;
            while(busy){
                displaySevenSegment();
                cursorAt();
            };
            curRow[row2][col2]=0xFF;
            curRow[row][col]=0xFF;
            if(row==0)
                WriteCommandToLCD(0x81+col);
            else WriteCommandToLCD(0xc1+col);
            WriteDataToLCD(0xFF);
            __delay_ms(2);
            if(row2==0)
                WriteCommandToLCD(0x81+col2);
            else WriteCommandToLCD(0xc1+col2);
            WriteDataToLCD(0xFF);
        }
        firstChoice=1;
    }
}
/*void showADCVal(){
    temp=adcValue;
    PORTH=0x01;
    PORTJ=sevenSegNumbers[adcValue/1000];
    adcValue=adcValue-(adcValue/1000)*1000;
    __delay_ms(2);
    PORTH=0x02;
    PORTJ=sevenSegNumbers[adcValue/100];
    adcValue=adcValue-(adcValue/100)*100;
    __delay_ms(2);
    PORTH=0x04;
    PORTJ=sevenSegNumbers[adcValue/10];
    adcValue=adcValue-(adcValue/1000)*10;
    __delay_ms(2);
    PORTH=0x08;
    PORTJ=sevenSegNumbers[adcValue];
    __delay_ms(2);
    adcValue=temp;
}*/
void changeCol(){
    changedCol();
    fixPrevCursor();
    if(adcValue>=0 && adcValue<205){
        col=0;
    }
    if(adcValue>=205 && adcValue<410){
        col=1;
    }
    if(adcValue>=410 && adcValue<615){
        col=2;
    }
    if(adcValue>=615 && adcValue<820){
        col=3;
    }
    if(adcValue>=820 && adcValue<1024){
        col=4;
    }

}
void changeRow(){
    changedRow();
    fixPrevCursor();
    if(adcValue>=0 && adcValue<512){
        row=0;
    }
    else{
        row=1;
    }
}
void initB_int(){
    TRISB = 0 ;
    TRISB6 = 1;
    TRISB7 = 1;
    PORTB = 1;
    INTCON=0;
    INTCON2=0;
}
void initTimers(void)
{
    //INTCON2=0;
    //Timer1
    T1CON=0b10110000;
    T1CON=T1CON|0x01;
    PIE1=0x01;
    //
    //Timer0
    T0CON = 0;
    T0CONbits.T08BIT = 1;
    T0CONbits.PSA = 0;
    T0CONbits.TMR0ON = 1;
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 1;
    //
    INTCON=0b11101000;
    INTCON2bits.RBPU = 0;
}
void cursorAt(){
    if(row==0) WriteCommandToLCD(0x81+col);
    else  WriteCommandToLCD(0xC1+col);
    if(curRow[row][col]==0xFF){
        if(cursorBlink){
            WriteDataToLCD(" ");
        }
        else{
            WriteDataToLCD(0xFF);
        }
    }
    else{
        WriteDataToLCD(curRow[row][col]);
    }
}
void axisRowColDisplay(){
    stringRow = (char)(((int)'0') + row);
    stringCol = (char)(((int)'0') + col);
    if(axis=='X') {
       WriteCommandToLCD(0x88);
       WriteStringToLCD("Axis:X  ");
       WriteCommandToLCD(0xc8);
       WriteStringToLCD("R:");
       WriteCommandToLCD(0xca);
       WriteDataToLCD(stringRow);
       WriteCommandToLCD(0xcc);
       WriteStringToLCD("C:");
       WriteCommandToLCD(0xce);
       WriteDataToLCD(stringCol);
    }
    if(axis=='Y') {
       WriteCommandToLCD(0x88);
       WriteStringToLCD("Axis:Y  ");
       WriteCommandToLCD(0xc8);
       WriteStringToLCD("R:");
       WriteCommandToLCD(0xca);
       WriteDataToLCD(stringRow);
       WriteCommandToLCD(0xcc);
       WriteStringToLCD("C:");
       WriteCommandToLCD(0xce);
       WriteDataToLCD(stringCol);
    }
}
void changedCol(){
    stringCol = (char)(((int)'0') + col);
    WriteCommandToLCD(0xce);
    WriteDataToLCD(stringCol);
}
void changedRow(){
    stringRow = (char)(((int)'0') + row);
    WriteCommandToLCD(0x8d);
    WriteDataToLCD(axis);
    WriteCommandToLCD(0xca);
    WriteDataToLCD(stringRow);
}
void saveRegisters(){
    statusSave=STATUS;
    pclathSave=PCLATH;
}
void restoreRegisters(){
    STATUS=statusSave;
    PCLATH=pclathSave;
}
//#################################//
//#===========DISPLAYS============#//
//#################################//
void displaySevenSegment(){
    PORTH=0x01;
    PORTJ=sevenSegNumbers[sevenSegInitialNumTen];
    __delay_ms(2);
    PORTH=0x02;
    PORTJ=sevenSegNumbers[sevenSegInitialNumOne];
    __delay_ms(2);
    PORTH=0x04;
    PORTJ=sevenSegNumbers[0];
    __delay_ms(2);
    PORTH=0x8;
    PORTJ=sevenSegNumbers[correctNumber];
    __delay_ms(2);
}
void entryDisplay()
{
    busy=1;
    ClearLCDScreen();           // Clear LCD screen
    WriteCommandToLCD(0x80);
    WriteStringToLCD(" Find the Pair! ");
    WriteCommandToLCD(0xc0);
    WriteStringToLCD(" ************** ");
    counter2=2;
}
void beginningDisplay(){
    busy=1;
    ClearLCDScreen();           // Clear LCD screen
    WriteCommandToLCD(0x80);
    WriteStringToLCD(" !?!#=  Axis:X  ");
    WriteCommandToLCD(0xc0);
    WriteStringToLCD(" #=;?;  R:0 C:0 ");
    counter2=2;
}
void displayGame(){
    int tmp=1;
    ClearLCDScreen();           // Clear LCD screen
    WriteCommandToLCD(0x80);
    WriteDataToLCD(" ");
    while(tmp<6){
        WriteCommandToLCD(0x80+(tmp++));
        WriteDataToLCD(curRow[0][tmp-2]);
    }
    WriteCommandToLCD(0x80+(tmp++));
    WriteDataToLCD(" ");
    tmp=1;
    while(tmp<6){
        WriteCommandToLCD(0xc0+(tmp++));
        WriteDataToLCD(curRow[0][tmp-2]);
    }
}
