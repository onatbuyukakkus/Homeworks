  list P=18F8722

#include <p18f8722.inc>
config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

state   udata 0x21
state

counter   udata 0x22
counter

counter2   udata 0x29
counter2

w_temp  udata 0x23
w_temp

status_temp udata 0x24
status_temp

pclath_temp udata 0x25
pclath_temp

portb_var   udata 0x26
portb_var

row1    udata 0x27
row1

column1 udata 0x28
column1

row2    udata 0x2C
row2

column2 udata 0x2D
column2

row3    udata 0x2E
row3

column3 udata 0x2F
column3

randNumber udata 0x2A
randNumber

counter3 udata 0x2B
counter3

level udata 0x30
level

temp udata 0x31
temp

segmentTen udata 0x32
segmentTen

segmentOne udata 0x33
segmentOne

L1 udata 0x34
L1

ninetySecFlag udata 0x35
ninetySecFlag

selectRow udata 0x36
selectRow

selectCol udata 0x37
selectCol

ra4Flag udata 0x38
ra4Flag

x udata 0x39
x

y udata 0x3A
y

pair1Selected udata 0x3B
pair1Selected

pair2Selected udata 0x3C
pair2Selected

pair3Selected udata 0x3D
pair3Selected

org     0x00
goto    init


org     0x08
goto    isr             ;go to interrupt service routine

org     0x18
goto isr_b


init:
    ;Disable interrupts
    clrf    INTCON
    clrf    INTCON2
    call    clearAll
    clrf    segmentOne
    clrf    segmentTen
    clrf    pair1Selected
    clrf    pair2Selected
    clrf    pair3Selected
    clrf    selectRow
    clrf    selectCol
    clrf    randNumber
    clrf    x
    clrf    y
    clrf    row1
    clrf    column1
    clrf    row2
    clrf    column2
    clrf    row3
    clrf    column3
    ;Configure Output Ports
    clrf    LATF
    clrf    TRISF
    clrf    TRISE
    clrf    TRISG
    clrf    TRISC
    clrf    TRISD
    clrf    TRISH
    clrf    TRISJ
    clrf    LATG
    movlw   b'11111111'
    movwf   TRISA
    clrf    selectRow
    clrf    selectCol
    clrf    ra4Flag
    movlw 0x0f
    movwf ADCON1

    bsf	    RCON,7
    bsf	    IPR1,0
    bcf	    INTCON2,0

    ;Configure Input/Interrupt Ports
    movlw   b'11110000'
    movwf   TRISB
    bcf     INTCON2, 7  ;Pull-ups are enabled
   clrf    PORTB

    ;Initialize Timer1
    movlw   b'10110000' ;Disable Timer1 by setting TMR0ON to 0 (for now)
                        ;Configure Timer1 as an 8-bit timer/counter by setting T08BIT to 1
                        ;Timer1 increment from internal clock with a prescaler of 1:8.
    movwf   T1CON
    clrf    PORTB
    ;Enable interrupts
    movlw   b'11001000' ;Enable Global, peripheral, Timer0 and RB interrupts by setting GIE, PEIE, TMR0IE and RBIE bits to 1
    movwf   INTCON



    listenRA4
    btfsc PORTA,4    ;Listen button whether it is pressed or not. if yes then skip.
    goto listenRA4
    ReleaseRA4
    btfss PORTA,4    ;Listen button whether it is released or not, if yes then skip.
    goto ReleaseRA4




    bsf     T1CON, 0    ;Enable Timer1 by setting TMR0ON to 1
    bsf     PIE1,0
    movlw d'1'
    movwf level
    goto main

Table1 ;7 segment display için table
    ADDWF PCL
    RETLW b'00111111' ;0
    RETLW b'00000110' ;1
    RETLW b'01011011' ;2
    RETLW b'01001111' ;3
    RETLW b'01100110' ;4
    RETLW b'01101101' ;5
    RETLW b'01111101' ;6
    RETLW b'00000111' ;7
    RETLW b'01111111' ;8
    RETLW b'01100111' ;9

main:
    goto encoding

    ;btfsc	state,0         ; Is state 0?
	;bsf     PORTF,0         ; No, then turn on LED0
	;btfss   state,0         ; Is state 1?
	;bcf     PORTF,0         ; No, then turn off LED0
    ;btfss   state,0         ; Is state 1?
    ;goto    main
    goto main

;;;;;;;;;;;;;;;;;;;;;;;;
clearAll
    clrf    PORTB
    clrf    PORTE
    clrf    PORTG
    clrf    PORTF
    clrf    PORTC
    clrf    PORTD
    CLRF    PORTH
    CLRF    PORTJ
    clrf    PORTA
    return
isr_b:
    call save_registers
	btfss   INTCON, 0           ;Is this PORTB on change interrupt
	goto timer0_isr             ;No, then exit from interrupt service routine
	movf	PORTB, w            ;Read PORTB to working register
	movwf	portb_var           ;Save it to shadow register
	btfsc	portb_var, 4        ;Test its 4th bit whether it is cleared
	;goto	rb_interrupt_exit2  ; RB4 is 1
	goto isr_b_5
    goto decCol            ; RB4 is 0, Button is pressed, so turn on LED7
isr_b_5:
    btfsc	portb_var, 5        ;Test its 4th bit whether it is cleared
	;goto	rb_interrupt_exit2  ; RB4 is 1
	goto isr_b_6
    goto incCol
isr_b_6:
    btfsc	portb_var, 6        ;Test its 4th bit whether it is cleared
	;goto	rb_interrupt_exit2  ; RB4 is 1
	goto isr_b_7
    goto decRow
isr_b_7:
    btfsc	portb_var, 7        ;Test its 4th bit whether it is cleared
	;goto	rb_interrupt_exit2  ; RB4 is 1
	goto rb_interrupt_exit0
    goto incRow

decCol:
    movlw d'3'
    tstfsz selectCol
    goto decC
    movwf selectCol
    goto rb_interrupt_exit1
decC:
    decf selectCol
    goto rb_interrupt_exit1
incCol:
    movlw d'3'
    cpfseq selectCol
    goto colA
    clrf selectCol
    goto rb_interrupt_exit1
colA:
    incf selectCol
    goto rb_interrupt_exit1
decRow:
    movlw d'5'
    tstfsz selectRow
    goto decR
    movwf selectRow
    goto rb_interrupt_exit1
decR:
    decf selectRow
    goto rb_interrupt_exit1
incRow:
    movlw d'5'
    cpfseq selectRow
    goto rowA
    clrf selectRow
    goto rb_interrupt_exit1
rowA:
    incf selectRow
    goto rb_interrupt_exit1

rb_interrupt_exit1:
	movf	portb_var, w        ;Put shadow register to W
	movwf	PORTB               ;Write content of W to actual PORTB, so that we will be able to clear RBIF
	bcf     INTCON, 0           ;Clear PORTB on change FLAG
	call	restore_registers   ;Restore STATUS and PCLATH registers to their state before interrupt occurs
	retfie

rb_interrupt_exit0:
    bcf     INTCON, 0
    call    restore_registers   ;Restore STATUS and PCLATH registers to their state before interrupt occurs
    retfie

;;;;;;;;;;;;;;;;;;;;;;;;
isr:
    call    save_registers  ;Save current content of STATUS and PCLATH registers to be able to restore them later

    btfss   PIR1, 0       ;Is this a timer interrupt?
    goto timer_interrupt_exit
    goto    timer_interrupt ;Yes. Goto timer interrupt handler part

;;;;;;;;;;;;;;;;;;;;;;;; Timer interrupt handler part ;;;;;;;;;;;;;;;;;;;;;;;;;;
timer_interrupt:
    incf	counter, f              ;Timer interrupt handler part begins here by incrementing count variable

    movf	counter, w              ;Move count to Working register
    sublw	d'20'                    ;Decrement 5 from Working register
    btfss	STATUS, Z               ;Is the result Zero?
    goto	timer_interrupt_exit    ;No, then exit from interrupt service routine

    tstfsz counter2
    decf    counter2, f


    tstfsz  segmentOne
    goto contSegment
    call fixSegment
    clrf	counter                 ;Yes, then clear count variable
    comf	state, f
    goto timer_interrupt_exit
 contSegment:
    decf segmentOne


    clrf	counter                 ;Yes, then clear count variable
    comf	state, f                ;Complement our state variable which controls on/off state of LED0





timer_interrupt_exit:
    bcf     PIR1, 0           ;Clear TMROIF
	;movlw	d'61'               ;256-61=195; 195*256*5 = 249600 instruction cycle;
	;movwf	TMR0
	call	restore_registers   ;Restore STATUS and PCLATH registers to their state before interrupt occurs
	retfie


;;;;;;;;;;;; Register handling for proper operation of main program ;;;;;;;;;;;;
fixSegment
    tstfsz  segmentTen
    goto    fixTen
    clrf    ninetySecFlag
    return

fixTen:
    movlw d'9'
    movwf segmentOne
    decf  segmentTen
    return
save_registers:
    movwf 	w_temp          ;Copy W to TEMP register
    swapf 	STATUS, w       ;Swap status to be saved into W
    clrf 	STATUS          ;bank 0, regardless of current bank, Clears IRP,RP1,RP0
    movwf 	status_temp     ;Save status to bank zero STATUS_TEMP register
    movf 	PCLATH, w       ;Only required if using pages 1, 2 and/or 3
    movwf 	pclath_temp     ;Save PCLATH into W
    clrf 	PCLATH          ;Page zero, regardless of current page
	return

restore_registers:
    movf 	pclath_temp, w  ;Restore PCLATH
    movwf 	PCLATH          ;Move W into PCLATH
    swapf 	status_temp, w  ;Swap STATUS_TEMP register into W
    movwf 	STATUS          ;Move W into STATUS register
    swapf 	w_temp, f       ;Swap W_TEMP
    swapf 	w_temp, w       ;Swap W_TEMP into W
    return

;------------------------ The suedo random generator functions by using TIMER0-------------------------------------------------------------------;
initTimer0

    movlw	B'01001111'	; Timer0 increment from internal clock with a prescaler of 1:256.
    movwf	T0CON

    bsf 	INTCON, TMR0IE 	; Enable TMR0 interrupt
    bsf 	INTCON, GIEH 	; Enable all interrupts
    bsf 	INTCON, GIE 	; Enable all interrupts
    bsf     T0CON, TMR0ON
    return

encoding:
    movlw d'1'
    cpfseq level
    goto encodCheck2
    goto encod1
encodCheck2:
    movlw d'2'
    cpfseq level
    goto encodCheck3
    goto encod2
encodCheck3:
    movlw d'3'
    cpfseq level
    goto encod3
    goto encod3


encod1:
  call randomNum1
  movlw d'3'
  movwf counter2
lpppp:
  tstfsz counter2
  goto displ1
  goto playstate1
displ1:
   call displayRowCol1
   call display321
   goto lpppp

encod2:
  ;movff row1,PORTC
  ;movff column1,PORTD
  ;movff row2,PORTE
  ;movff column2,PORTF
  movlw d'3'
  movwf counter2
  lpppp2:
    tstfsz counter2
    goto displ2
    goto playstate2
  displ2:
    call displayRowCol1
   
    call displayRowCol2
   
    call display321
    goto lpppp2

encod3:
    movlw d'3'
    movwf counter2
    lpppp3:
        tstfsz counter2
        goto   displ3
        goto   playState3
    displ3:
        call displayRowCol1
        
        call displayRowCol2
        
        call displayRowCol3
       
        call display321
        goto lpppp3

randomNum1
    call initTimer0
    call assignRandomNumber
    call terminateTimerInterrupt
    return
randomNum2
    call initTimer0
    call assignRandomNumber2
    call terminateTimerInterrupt
    return
randomNum3
    call initTimer0
    call assignRandomNumber3
    call terminateTimerInterrupt
    return






display321
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF counter2,0
    ADDWF counter2,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    CALL delay
    return


displayRowCol1
    movlw d'0'
    cpfseq column1
    goto RowCol1_1
    goto col0row_1
RowCol1_1:
    movlw d'1'
    cpfseq column1
    goto RowCol2_1
    goto col1row_1
RowCol2_1:
    movlw d'2'
    cpfseq column1
    goto col3row_1
    goto col2row_1

col0row_1:
    
    movlw  b'00000001'
    movwf temp
    movf row1,0
    addlw d'1'
loop_1_0:
   decfsz WREG
   goto _1_0
   movf temp,0
   iorwf PORTC,1
   return
_1_0:
    rlncf temp
    goto loop_1_0

col1row_1:
    
    movlw  b'00000001'
    movwf temp

    movf row1,0
    addlw d'1'
loop_1_1:
   decfsz WREG
   goto _1_1
   movf temp,0
   iorwf PORTD,1
   return
_1_1:
    rlncf temp
    goto loop_1_1
col2row_1:
   
    movlw  b'00000001'
    movwf temp
    movf row1,0
    addlw d'1'
loop_1_2:
   decfsz WREG
   goto _1_2
   movf temp,0
   iorwf PORTE,1
   return
_1_2:
    rlncf temp
    goto loop_1_2
col3row_1:
    
    movlw  b'00000001'
    movwf temp
    movf row1,0
    addlw d'1'
loop_1_3:
   decfsz WREG
   goto _1_3
   movf temp,0
   iorwf PORTF,1
   return
_1_3:
    rlncf temp
    goto loop_1_3


displayRowCol2
    movlw d'0'
    cpfseq column2
    goto RowCol1_2
    goto col0row_2
RowCol1_2:
    movlw d'1'
    cpfseq column2
    goto RowCol2_2
    goto col1row_2
RowCol2_2:
    movlw d'2'
    cpfseq column2
    goto col3row_2
    goto col2row_2

col0row_2:
    
    movlw  b'00000001'
    movwf temp
    movf row2,0
    addlw d'1'
loop_2_0:
   decfsz WREG
   goto _2_0
   movf temp,0
   iorwf PORTC,1
   return
_2_0:
    rlncf temp
    goto loop_2_0

col1row_2:
    
    movlw  b'00000001'
    movwf temp

    movf row2,0
    addlw d'1'
loop_2_1:
   decfsz WREG
   goto _2_1
   movf temp,0
   iorwf PORTD,1
   return
_2_1:
    rlncf temp
    goto loop_2_1
col2row_2:
    
    movlw  b'00000001'
    movwf temp
    movf row2,0
    addlw d'1'
loop_2_2:
   decfsz WREG
   goto _2_2
   movf temp,0
   iorwf PORTE,1
   return
_2_2:
    rlncf temp
    goto loop_2_2
col3row_2:
    
    movlw  b'00000001'
    movwf temp
    movf row2,0
    addlw d'1'
loop_2_3:
   decfsz WREG
   goto _2_3
   movf temp,0
   iorwf PORTF,1
   return
_2_3:
    rlncf temp
    goto loop_2_3


displayRowCol3
movlw d'0'
    cpfseq column3
    goto RowCol1_3
    goto col0row_3
RowCol1_3:
    movlw d'1'
    cpfseq column3
    goto RowCol2_3
    goto col1row_3
RowCol2_3:
    movlw d'2'
    cpfseq column3
    goto col3row_3
    goto col2row_3

col0row_3:
    
    movlw  b'00000001'
    movwf temp
    movf row3,0
    addlw d'1'
loop_3_0:
   decfsz WREG
   goto _3_0
   movf temp,0
   iorwf PORTC,1
   return
_3_0:
    rlncf temp
    goto loop_3_0

col1row_3:
    
    movlw  b'00000001'
    movwf temp

    movf row3,0
    addlw d'1'
loop_3_1:
   decfsz WREG
   goto _3_1
   movf temp,0
   iorwf PORTD,1
   return
_3_1:
    rlncf temp
    goto loop_3_1
col2row_3:
    
    movlw  b'00000001'
    movwf temp
    movf row3,0
    addlw d'1'
loop_3_2:
   decfsz WREG
   goto _3_2
   movf temp,0
   iorwf PORTE,1
   return
_3_2:
    rlncf temp
    goto loop_3_2
col3row_3:
   
    movlw  b'00000001'
    movwf temp
    movf row3,0
    addlw d'1'
loop_3_3:
   decfsz WREG
   goto _3_3
   movf temp,0
   iorwf PORTF,1
   return
_3_3:
    rlncf temp
    goto loop_3_3



displayRowColSelect
movlw d'0'
    cpfseq selectCol
    goto RowCol1_3_S
    goto col0row_3_S
RowCol1_3_S:
    movlw d'1'
    cpfseq selectCol
    goto RowCol2_3_S
    goto col1row_3_S
RowCol2_3_S:
    movlw d'2'
    cpfseq selectCol
    goto col3row_3_S
    goto col2row_3_S

col0row_3_S:
    
    movlw  b'00000001'
    movwf temp
    movf selectRow,0
    addlw d'1'
loop_3_0_S:
   decfsz WREG
   goto _3_0_S
   movf temp,0
   iorwf PORTC,1
   return
_3_0_S:
    rlncf temp
    goto loop_3_0_S

col1row_3_S:
      
    movlw  b'00000001'
    movwf temp

    movf selectRow,0
    addlw d'1'
loop_3_1_S:
   decfsz WREG
   goto _3_1_S
   movf temp,0
   iorwf PORTD,1
   return
_3_1_S:
    rlncf temp
    goto loop_3_1_S
col2row_3_S:
    
    movlw  b'00000001'
    movwf temp
    movf selectRow,0
    addlw d'1'
loop_3_2_S:
   decfsz WREG
   goto _3_2_S
   movf temp,0
   iorwf PORTE,1
   return
_3_2_S:
    rlncf temp
    goto loop_3_2_S
col3row_3_S:
    
    movlw  b'00000001'
    movwf temp
    movf selectRow,0
    addlw d'1'
loop_3_3_S:
   decfsz WREG
   goto _3_3_S
   movf temp,0
   iorwf PORTF,1
   return
_3_3_S:
    rlncf temp
    goto loop_3_3_S



assignRandomNumber

    movf   TMR0,0
    movwf  randNumber
    ;movff randNumber,PORTB
    movlw  b'00000011'
    andwf randNumber,0
    movwf column1

    movlw  b'00001111'
    andwf randNumber,0
    ;movwf y

    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    movlw  b'00001111'
    andwf randNumber,1
    ;movff randNumber,x

    movff randNumber,row1
    movlw 0x06
   loop:
    cpfslt randNumber
    goto mod
    goto ret
   mod:
    MOVLW 0x06
    subwf randNumber,1
    movff randNumber,row1
    movlw 0x06
    goto loop
   ret:

    return

assignRandomNumber2


    movf   TMR0,0
    movwf  randNumber
    ;movff randNumber,PORTB
    movlw  b'00000011'
    andwf randNumber,0
    movwf column2

    movlw  b'00001111'
    andwf randNumber,0
    movwf y


    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    movlw  b'00001111'
    andwf randNumber
    movff randNumber,x

    movff randNumber,row2
    movlw 0x06
   loop2:
    cpfslt randNumber
    goto mod2
    goto ret2
   mod2:
    MOVLW 0x06
    subwf randNumber,1
    movff randNumber,row2
    movlw 0x06
    goto loop2
   ret2:
   movf row1,0
   cpfseq row2
   return
   movf column1,0
   cpfseq column2
   return
   goto startRandom2
   return

startRandom2:
   movff column1,column2
   ;movf row1,0
   ;sublw d'5'
   ;movwf row2
   comf x
    movff x,row2
    movlw 0x06
   loop2_1:
    cpfslt x
    goto mod2_1
    goto ret2_1
   mod2_1:
    MOVLW 0x06
    subwf x,1
    movff x,row2
    movlw 0x06
    goto loop2_1
   ret2_1:
    return

  assignRandomNumber3


    movf   TMR0,0
    movwf  randNumber
    ;movff randNumber,PORTB
    movlw  b'00000011'
    andwf randNumber,0
    movwf column3

    movlw  b'00001111'
    andwf randNumber,0
    movwf  y

    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    rrncf randNumber
    movlw  b'00001111'
    andwf randNumber
    movff  randNumber, x

    movff randNumber,row3
    movlw 0x06
   loop3:
    cpfslt randNumber
    goto mod3
    goto check_1_3
   mod3:
    MOVLW 0x06
    subwf randNumber,1
    movff randNumber,row3
    movlw 0x06
    goto loop3

   check_1_3:
   movf row1,0
   cpfseq row3
   goto check_2_3
   movf column1,0
   cpfseq column3
   goto check_2_3


   comf x,1
   movff x,row3
   movlw 0x06
   loopa3:
    cpfslt x
    goto moda3
    goto check_2_3
   moda3:
    MOVLW 0x06
    subwf x,1
    movff x,row3
    movlw 0x06
    goto loopa3

   check_2_3:
   movff row2,WREG
   cpfseq row3
   return
   movf column2,0
   cpfseq column3
   return
   movff row2,row3
   comf y,1
   movlw  b'00000011'
   andwf y,0
   movwf column3

   return


playstate1:  ;1. lvl play state
    clrf    PORTF
    clrf    PORTC
    clrf    PORTD
    clrf    PORTE
    movlw d'9'
    movwf segmentTen
    movlw d'0'
    movwf segmentOne
    movlw d'1'
    movwf ninetySecFlag
    ninetyLoop:
        tstfsz ninetySecFlag
        goto displayNinetySegment
        goto endState

displayNinetySegment:
    tstfsz ra4Flag
    goto contNinety1
    btfsc PORTA,4
    goto contNinety1
    bsf ra4Flag,0
contNinety1:
    movlw d'1'
    cpfseq ra4Flag
    goto contNinety2
    btfss PORTA,4
    goto contNinety2
    bcf ra4Flag,0
    call compare1

contNinety2:
    CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVF segmentTen,0
    ADDWF segmentTen,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF segmentOne,0
    ADDWF segmentOne,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    CALL delay

    MOVLW 0x01
    MOVWF PORTH
    MOVF selectRow,0
    ADDWF selectRow,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay

    MOVLW 0x02
    MOVWF PORTH
    MOVF selectCol,0
    ADDWF selectCol,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    goto ninetyLoop


endStateDisplay
    CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVLW b'01011110'
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    movf level,0
    decf WREG
    ADDWF WREG,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    CALL delay

    MOVLW 0x01
    MOVWF PORTH
    MOVLW b'01111001'
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay

    MOVLW 0x02
    MOVWF PORTH
    MOVLW b'01010100'
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    return

playstate2:
    call clearAll
    clrf selectRow
    clrf selectCol
    movlw d'9'
    movwf segmentTen
    movlw d'0'
    movwf segmentOne
    movlw d'1'
    movwf ninetySecFlag
    ninetyLoop2:
        tstfsz ninetySecFlag
        goto displayNinetySegment2
        goto endState

displayNinetySegment2:
    tstfsz ra4Flag
    goto contNinety1_2
    btfsc PORTA,4
    goto contNinety1_2
    bsf ra4Flag,0
contNinety1_2:
    movlw d'1'
    cpfseq ra4Flag
    goto contNinety2_2
    btfss PORTA,4
    goto contNinety2_2
    bcf ra4Flag,0
    call compare2

contNinety2_2:
    CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVF segmentTen,0
    ADDWF segmentTen,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF segmentOne,0
    ADDWF segmentOne,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    CALL delay

    MOVLW 0x01
    MOVWF PORTH
    MOVF selectRow,0
    ADDWF selectRow,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay

    MOVLW 0x02
    MOVWF PORTH
    MOVF selectCol,0
    ADDWF selectCol,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    goto ninetyLoop2


playState3:
    call clearAll
    clrf selectRow
    clrf selectCol
    movlw d'9'
    movwf segmentTen
    movlw d'0'
    movwf segmentOne
    movlw d'1'
    movwf ninetySecFlag
    ninetyLoop3:
        tstfsz ninetySecFlag
        goto displayNinetySegment3
        goto endState

displayNinetySegment3:
    tstfsz ra4Flag
    goto contNinety1_3
    btfsc PORTA,4
    goto contNinety1_3
    bsf ra4Flag,0
contNinety1_3:
    movlw d'1'
    cpfseq ra4Flag
    goto contNinety2_3
    btfss PORTA,4
    goto contNinety2_3
    bcf ra4Flag,0
    call compare3

contNinety2_3:
    CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVF segmentTen,0
    ADDWF segmentTen,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF segmentOne,0
    ADDWF segmentOne,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    CALL delay

    MOVLW 0x01
    MOVWF PORTH
    MOVF selectRow,0
    ADDWF selectRow,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay

    MOVLW 0x02
    MOVWF PORTH
    MOVF selectCol,0
    ADDWF selectCol,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    CALL delay
    goto ninetyLoop3


;;;;;;;;; END STATE ;;;;;;;;;;;;
endState:
    listenEndRA4
    call endStateDisplay
    btfsc PORTA,4    ;Listen button whether it is pressed or not. if yes then skip.
    goto listenEndRA4
    ReleaseEndRA4
    call endStateDisplay
    btfss PORTA,4    ;Listen button whether it is released or not, if yes then skip.
    goto ReleaseEndRA4
    goto init
;;;;;;;;;;;;;;;;;;;;;;;;;;
finalState:
    incf level
    goto endState
;;;;;;;;; WAIT STATE ;;;;;;;;;;;;
waitState1:
    clrf PORTH
    clrf PORTJ
    call clearAll
    listenWait1RA4
    btfsc PORTA,4    ;Listen button whether it is pressed or not. if yes then skip.
    goto listenWait1RA4
    ReleaseWait1RA4
    btfss PORTA,4    ;Listen button whether it is released or not, if yes then skip.
    goto ReleaseWait1RA4
    incf level
    call randomNum2
    ;movff level, PORTG
    goto encoding


waitState2:
    clrf PORTH
    clrf PORTJ
    call clearAll
    clrf pair1Selected
    clrf pair2Selected
    listenWait2RA4
    btfsc PORTA,4    ;Listen button whether it is pressed or not. if yes then skip.
    goto listenWait2RA4
    ReleaseWait2RA4
    btfss PORTA,4    ;Listen button whether it is released or not, if yes then skip.
    goto ReleaseWait2RA4
    incf level
    call randomNum3
    ;movff level, PORTG
    goto encoding
;;;;;;;;;;;;;;;;;;;;;;;;;;
timer0_isr

	call	save_registers ; save current content of STATUS and PCLATH registers to be abel to restore later

    movlw	d'157'		;256-157=99
    movwf	TMR0

    bcf	INTCON,TMR0IF

	call	restore_registers ; restore STATUS and PCLATH registers to their state before interrupt occurs

    retfie

terminateTimerInterrupt
   bcf   T0CON, TMR0ON
   bcf 	INTCON, TMR0IE 	; Disable TMR0 interrupt
return


delay
    movlw 50
    movwf L1
    loop4
    decfsz L1,1
        goto loop4
    return

bit:
    goto bit


compare1
    call displayRowColSelect
    movf selectRow,0
    cpfseq  row1
    goto endState
    movf selectCol,0
    cpfseq column1
    goto endState
    call randomNum1

    goto waitState1

compare2
    call displayRowColSelect
    movf selectRow,0
    cpfseq  row1
    goto compare2_1
    movf selectCol,0
    cpfseq column1
    goto compare2_1
    call randomNum1
    tstfsz pair1Selected
    goto endState
    incf pair1Selected
    tstfsz pair2Selected
    goto waitState2
    clrf selectRow
    clrf selectCol
    goto ninetyLoop2

compare2_1:
    movf selectRow,0
    cpfseq row2
    goto endState
    movf selectCol,0
    cpfseq column2
    goto endState
    call randomNum2
    tstfsz pair2Selected
    goto endState
    incf pair2Selected
    tstfsz pair1Selected
    goto waitState2
    clrf selectRow
    clrf selectCol
    goto ninetyLoop2

compare3
    call displayRowColSelect
    movf selectRow,0
    cpfseq  row1
    goto compare3_1
    movf selectCol,0
    cpfseq column1
    goto compare3_1
    tstfsz pair1Selected
    goto endState
    incf pair1Selected
    tstfsz pair2Selected
    goto is3Selected
    clrf selectRow
    clrf selectCol
    goto ninetyLoop3

is3Selected:
    tstfsz pair3Selected
    goto finalState
    clrf selectRow
    clrf selectCol
    goto ninetyLoop3

compare3_1:
    movf selectRow,0
    cpfseq row2
    goto compare3_2
    movf selectCol,0
    cpfseq column2
    goto compare3_2
    tstfsz pair2Selected
    goto endState
    incf pair2Selected
    tstfsz pair1Selected
    goto is3Selected
    clrf selectRow
    clrf selectCol
    goto ninetyLoop3

compare3_2:
    movf selectRow,0
    cpfseq row3
    goto endState
    movf selectCol,0
    cpfseq column3
    goto endState
    tstfsz pair3Selected
    goto endState
    incf pair3Selected
    tstfsz pair1Selected
    goto is2Selected
    clrf selectRow
    clrf selectCol
    goto ninetyLoop3

is2Selected:
    tstfsz pair2Selected
    goto finalState;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    clrf selectRow
    clrf selectCol
    goto ninetyLoop3
end
