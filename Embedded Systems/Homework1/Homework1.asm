;----------------------------------------;
    ;Grup No: 51
	;Student ID 2035772
	;Name and Surname Onat Buyukakkus
	;Student ID 1942085
	;Name and Surname Enver Evci
    ;----------------------------------------;

list P=18F8722

#include <p18f8722.inc>
config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

;------------Variables-------------------
W_TEMP		equ	020h
STATUS_TEMP	equ	021h
PCLATH_TEMP	equ	022h
randNumber udata 0x23
randNumber


	;----------------------------------------;
    ;   Other variable declerations          ;
    ;----------------------------------------;

segmentLoopChoice equ 0x26

L1        EQU 0X25
L3        EQU 0X30
L4        EQU 0X31
L5        EQU 0X32
counter equ 0x33
counter2 equ 0x34
number    udata 0x27
number
health udata 0x24
health
digitOne udata 0x28
digitOne

digitTen udata 0x29
digitTen


randomDigitOne udata 0x35
randomDigitOne

randomDigitTen udata 0x36
randomDigitTen

;randomdigitone random sayinin birler basamagini, randomdigitten onlar basmasigini tutar.
;Basitce bu kod rf5 tu?una bas?lmas?n? bekledikten sonra oyunu baslatir, daha sonra healhti ve 7 segmenti display eder ve rf0-4 butonlarini
;dinler. butonlara gore basamaklari arttirir ve her rf0a basildiginda random sayiyla karsilatirir, karsilastirdiktan sonra dogruluga, azliga
;ya da cokluga gore cani azaltir(top most) ve yonlendirici oklari yakar. health kontrolune gore oyunun bitisini tayin eder.

    org	0x00
	goto    init

	org	0x08
	goto    timer0_isr    ; Goto Interrupt service routine


init:

    call    initTimer0

    ;----------------------------------------;
    ;   Other required init configurations   ;
    ;----------------------------------------;

    CLRF   PORTA
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    CLRF   PORTE
    CLRF   PORTF
    CLRF   PORTG
    CLRF   PORTH
    CLRF   PORTJ
    CLRF   health


    MOVLW 0X00
    MOVWF TRISD
    MOVWF TRISG
    MOVWF TRISC
    MOVWF TRISB
    MOVWF TRISE
    MOVWF TRISH
    MOVWF TRISJ
    MOVWF TRISA



    CLRF   PORTA
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    CLRF   PORTE
    CLRF   PORTF
    CLRF   PORTG
    CLRF   PORTH
    CLRF   PORTJ
    CLRF   digitOne
    CLRF   digitTen
    CLRF   health
    CLRF   number
    MOVLW  0x0F
    MOVWF  ADCON1

    MOVLW 0x7F
    MOVWF TRISF
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
    call startButton ;RF5i bekleyen loop

input:

    MOVFF health,PORTE ;PORTEye healthi bas
    call healthDisplay ;healthin top most azalmasi icin fonksiyon
    call display ;7 segment display loop
    goto takeInput ;RF5 haric diger inputlari bekleyen loop
inputReady:

    goto input
death: ; Kaybedildiginde ekrani temizler, lp3 e devam eder dogru cevabi gosterir ve oyunu bitirir

    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    CLRF   PORTE
    MOVLW 0x00
    MOVWF counter
lp3:


    CPFSLT randNumber
    goto RDT


    MOVFF counter, randomDigitTen

    call displayLoser

    goto init
RDT:

    INCF counter
    MOVLW 0x0A
    SUBWF randNumber,1
    MOVFF randNumber,randomDigitOne
    MOVLW 0x0A
    goto lp3



healthDisplay ;healthin top most azalmasi icin fonksiyon
    sixHealth:
        MOVLW b'00000110' ;6
        CPFSEQ health ;6 ile health karsilastirma
        goto fiveHealth ;6 degilse 5 ile karsilatirmaya git
        MOVLW b'00111111' ;6==health ise portenin hepsini yak
        MOVWF PORTE
        RETURN
    fiveHealth:
        MOVLW b'00000101' ;5
        CPFSEQ health ;5 ile health karsilastirma
        goto fourHealth ;5 degilse 4 ile karsilatirmaya git
        MOVLW b'00111110' ;5==health ise portenin top most hariç yak
        MOVWF PORTE
        RETURN
    fourHealth:
        MOVLW b'00000100' ;4
        CPFSEQ health ;4 ile health karsilastirma
        goto threeHealth ;4 degilse 3 ile karsilastirmaya git
        MOVLW b'00111100' ;4==health ise portenin top most 2 hariç yak
        MOVWF PORTE
        RETURN
    threeHealth:
        MOVLW b'00000011' ;3
        CPFSEQ health ;3 ile health karsilastirma
        goto twoHealth ;3 degilse 2 ile karsilastirmaya git
        MOVLW b'00111000' ;3==health ise portenin top most 3 hariç yak
        MOVWF PORTE
        RETURN
    twoHealth:
        MOVLW b'00000010' ;2
        CPFSEQ health ;2 ile health karsilastirma
        goto oneHealth ;2 degilse 1 ile karsilastirmaya git
        MOVLW b'00110000' ;2==health ise portenin top most 4 hariç yak
        MOVWF PORTE
        RETURN
    oneHealth:
        MOVLW b'00000001' ;1
        CPFSEQ health ;1 ile health karsilastirma
        goto noHealth ;1 degilse healh=0 olmak zorunda o yuzden olume git
        MOVLW b'00100000' ;1==health ise portenin top most 5 hariç yak
        MOVWF PORTE
        RETURN
    noHealth:
        MOVLW b'00000000' ;0
        MOVWF PORTE ;porteyi sondur
        goto death ;olme fonskiyonu
        RETURN


takeInput:

    pressInput0: ;RF0 basildi mi
        call display
        BTFSS PORTF,0
        goto pressInput1 ;basilmadiysa RF1i kontrol et
        goto releaseInput0 ;RF0 release edildi mi
    pressInput1: ;RF1 basildi mi
        call display
        BTFSS PORTF,1
        goto pressInput2 ;basilmadiysa RF2yi kontrol et
        goto releaseInput1 ;RF1 release edildi mi
    pressInput2: ;RF2 basildi mi
        call display
        BTFSS PORTF,2
        goto pressInput3 ;basilmadiysa RF3u kontrol et
        goto releaseInput2 ;RF2 release edildi mi
    pressInput3:;RF3 basildi mi
        call display
        BTFSS PORTF,3
        goto pressInput4 ;basilmadiysa RF4u kontrol et
        goto releaseInput3 ;RF3 release edildi mi
    pressInput4: ;RF4 basildi mi
        call display
        BTFSS PORTF,4
        goto pressInput0 ;basilmadiysa loopta RF0 kontrol et
        goto releaseInput4 ;RF4 release edildi mi



    releaseInput0:
        call display
        BTFSC PORTF,0
        goto releaseInput0
        goto check ;RF0 release edildiyse sayiyi kontrol et
    releaseInput1:
        call display
        BTFSC PORTF,1
        goto releaseInput1
        goto decrOne ;RF1 release edildiyse birler basamagini bir azalt
    releaseInput2:
        call display
        BTFSC PORTF,2
        goto releaseInput2
        goto incrOne ;RF2 release edildiyse birler basamagini bir arttir
    releaseInput3:
        call display
        BTFSC PORTF,3
        goto releaseInput3
        goto decrTen ;RF3 release edildiyse onlar basamagini bir azalt
    releaseInput4:
        call display
        BTFSC PORTF,4
        goto releaseInput4
        goto incrTen ;RF3 release edildiyse onlar basamagini bir arttir

finish ; Kazanildiginda gosterilecekleri ayarlar

    call displaysOne
    call delay
    call displaysTen
    call delay
     CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVF digitTen,0
    ADDWF digitTen,0
    call Table1
    MOVWF PORTJ
    call delay
    CALL delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF digitOne,0
    ADDWF digitOne,0
    call Table1
    MOVWF PORTJ
    RETURN
displayLoser	; Kaybedildiginde dogru cevabi gosterir.
displayLoser1:
    CALL delay
    MOVLW 0x04
    MOVWF PORTH
    MOVF randomDigitTen,0
    ADDWF randomDigitTen,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin onlar basamagi atilir.
    call delay
    MOVLW 0x08
    MOVWF PORTH
    MOVF randomDigitOne,0
    ADDWF randomDigitOne,0
    call Table1
    MOVWF PORTJ ; Portj ye dogru cevabin birler basamagi atilir.
    call delay

    MOVLW 0x03
    MOVWF PORTH
    MOVLW 0x40
    MOVWF PORTJ
    call delay

    goto displayLoser1
displayWinner ;3 kere yanip sonme islevini gerceklestirir.

    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    ;================
    call displayFinish ;Belli bir sure boyunca dogru sayiyi gosterir

    MOVLW 0x0F
    MOVWF PORTH
    MOVLW 0x00
    MOVWF PORTJ
    call delay3 ;Belli bir sure boyunca sondurur
    call finish
    ;================
    call displayFinish ;Belli bir sure boyunca dogru sayiyi gosterir
    MOVLW 0x0F
    MOVWF PORTH
    MOVLW 0x00
    MOVWF PORTJ
    call delay3 ;Belli bir sure boyunca sondurur
    call finish
    ;================
    call displayFinish ;Belli bir sure boyunca dogru sayiyi gosterir
    MOVLW 0x0F
    MOVWF PORTH
    MOVLW 0x00
    MOVWF PORTJ
    call delay3 ;Belli bir sure boyunca sondurur
    ;================
    goto init

displayFinish ;Dogru cevap verildiginde yanip sonem sirasinda, yanma suresini ayarlar.
    MOVLW 0x15
    MOVWF counter
   lp1:
    TSTFSZ counter
    goto decrCounter
    return
decrCounter:
    DECF counter
    MOVLW 0x99
    MOVWF counter2
lp2:
    TSTFSZ counter2
    goto decrCounter2
    goto lp1
decrCounter2:
    DECF counter2
    call finish
    goto lp2


check:
    MOVFF randNumber,WREG
    CPFSEQ number ;random number ile sayiyi kontrol et
    goto cont1 ;ayni degilse kucuk mu diye bak
    goto displayWinner ;ayniysa 7 segmentte yak son
cont1:
    MOVFF randNumber,WREG
    CPFSLT number ;random number sayidan kucukse
    goto cont2 ;degilse buyuk mu diye bak
    goto checkLt ;can dusurme, ok goruntuleme
cont2:
    MOVFF randNumber,WREG
    CPFSGT number ;random number sayidan buyukse
    goto input ;buraya girmeyecek
    goto checkGt ;can dusurme ok goruntuleme


checkLt:
    DECF health ;healthi azalt
    MOVWF PORTE
    call displayLT ;yukari dogru ok goster
    goto input ;Rf0-Rf4 beklemeye devam et
checkGt:
     DECF health ;healthi azalt
    MOVWF PORTE
    call displayGT ;asagi dogru ok goster
    goto input ;rf0-rf4 beklemeye devam et

decrOne: ; Bir azaltir
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    DECF number
    DECF digitOne
    MOVLW b'11111111' ;digitOne -1 e duserse duzeltme fonksiyonuna yollar
    CPFSEQ digitOne
    goto input
    call fixOneDec
    goto input
incrOne: ; Bir arttirir
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    INCF number
    INCF digitOne
    MOVLW b'00001010' ;digitOne 10 u gecerse fix etme fonksiyonuna yollar
    CPFSEQ digitOne
    goto input
    call fixOneInc
    goto input
decrTen: ; On azaltir
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    MOVLW b'00001010'
    SUBWF number,1
    DECF digitTen
    MOVLW b'11111111' ;digitTen -1 e duserse duzeltme fonksiyonuna yollar
    CPFSEQ digitTen
    goto input
    call fixTenDec
    goto input
incrTen: ; On arttirir
    CLRF   PORTB
    CLRF   PORTC
    CLRF   PORTD
    MOVLW b'00001010'
    ADDWF number,1
    INCF digitTen
    MOVLW b'00001010' ;digitTen 10 u gecerse fix etme fonksiyonuna yollar
    CPFSEQ digitTen
    goto input
    call fixTenInc
    goto input

display
    call displaysOne ;birler basamagi icin 7 segment display fonksiyonu
    call delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    call displaysTen ;onlar basamagi icin 7 segment display fonksiyonu
    call delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    call displaysOthers ;-- icin 7 segment display fonksiyonu
    call delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    RETURN

displaysOne
    CALL delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    MOVLW 0x02 ;porthda D3un yanmasi icin
    MOVWF PORTH
    MOVF digitOne,0 ;memorynin 2ser ilerlemesinden kaynakli
    ADDWF digitOne,0 ;digitone'in tabledan cekilmesi
    call Table1
    MOVWF PORTJ ;7segment displaye basilmasi
    RETURN

displaysTen
    CALL delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    MOVLW 0x01 ;porthda D2nin yanmasi icin
    MOVWF PORTH
    MOVF digitTen,0 ;memorynin 2ser ilerlemesinden kaynakli
    ADDWF digitTen,0 ;digitten'in tabledan cekilmesi
    call Table1
    MOVWF PORTJ ;7segment displaye basilmasi
    RETURN

displaysOthers
    CALL delay ;sayilarin yanip sonmeden ayn? anda gorulebilmesi icin
    MOVLW 0x0C ;porthda D1 ve D0in yanmasi icin
    MOVWF PORTH
    MOVLW 0x40 ;-- 7segment display kodu
    MOVWF PORTJ ;7segment displaye basilmasi
    RETURN
displayLT ;yukari dogru ok goster
     MOVLW 0x02
     MOVWF PORTB
     MOVLW 0x0F
     MOVWF PORTC
     MOVLW 0x02
     MOVWF PORTD
     RETURN
displayGT ;asagi dogru ok goster
     MOVLW 0x40
     MOVWF PORTB
     MOVLW 0xF0
     MOVWF PORTC
     MOVLW 0x40
     MOVWF PORTD
     RETURN



fixTenInc ;On arttirma sirasinda 9 dan 19 a cikmamasini saglar
    MOVLW b'00001010'
    SUBWF number,1
    DECF digitTen
    call display
    RETURN
fixTenDec ;On azaltma sirasinda 0 dan -10 a dusmemesini saglar
    MOVLW b'00001010'
    ADDWF number,1
    INCF number
    INCF digitTen
    call display
    RETURN
fixOneInc ;Bir arttirma sirasinda 9 dan 10 a cikmamasini saglar
    DECF number
    DECF digitOne
    call display
    RETURN
fixOneDec ;Bir azaltma sirasinda 0 dan -1 e dusmemesini saglar
    INCF number
    INCF digitOne
    call display
    RETURN
startButton: ;RF5i dinleyen loop
    BTFSS PORTF,5
    GOTO startButton

Release: ;RF5e basildiginda release olmasini bekleyen loop
    BTFSC PORTF,5
    GOTO Release
    call assignRandomNumber
    call terminateTimerInterrupt
    MOVLW 0x06
    MOVWF health ;her oyunun baslangicinda once healthi 6 yapmak
    call display ;7 segment display loop
    ;MOVFF randNumber, PORTB
    goto input ;RF5 haric diger inputlari bekleyen, health yazan loop


;------------------------ The suedo random generator functions by using TIMER0-------------------------------------------------------------------;
initTimer0

    movlw	B'01001111'	; Timer0 increment from internal clock with a prescaler of 1:256.
    movwf	T0CON

    bsf 	INTCON, TMR0IE 	; Enable TMR0 interrupt
    bsf 	INTCON, GIEH 	; Enable all interrupts
    bsf 	INTCON, GIE 	; Enable all interrupts
    bsf     T0CON, TMR0ON
    return

assignRandomNumber

    movf   TMR0,0
    movwf  randNumber
    movlw  d'157'
    subwf  randNumber,1
    addwf  randNumber,0
    return

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
   bcf 	INTCON, GIEH 	; Disable all interrupts
   bcf 	INTCON, GIE 	; Disable all interrupts
return
;;;;;;;;;;;; Register handling for proper operation of main program ;;;;;;;;;;;;

save_registers:
	MOVWF 	W_TEMP		;Copy W to TEMP register
	SWAPF 	STATUS,W 	;Swap status to be saved into W
	CLRF 	STATUS 		;bank 0, regardless of current bank, Clears IRP,RP1,RP0
	MOVWF 	STATUS_TEMP 	;Save status to bank zero STATUS_TEMP register
	MOVF 	PCLATH, W 	;Only required if using pages 1, 2 and/or 3
	MOVWF 	PCLATH_TEMP 	;Save PCLATH into W
	CLRF 	PCLATH 		;Page zero, regardless of current page

	return

restore_registers:
	MOVF 	PCLATH_TEMP, W 	;Restore PCLATH
	MOVWF 	PCLATH 		;Move W into PCLATH
	SWAPF 	STATUS_TEMP,W 	;Swap STATUS_TEMP register into W
	;(sets bank to original state)
	MOVWF 	STATUS 		;Move W into STATUS register
	SWAPF 	W_TEMP,F 	;Swap W_TEMP
	SWAPF 	W_TEMP,W 	;Swap W_TEMP into W

	return
;--------------------------------------------------------------------------------------------------------------------------------------------------------------------;
delay3
    call delay2
    call delay2
    call delay2

return


delay2
;    MOVLW 6
;    MOVWF L6
; LOOP4
    MOVLW 250
    MOVWF L5
 LOOP3
     MOVLW 250                        ; Copy 50 to W
     MOVWF L4                    ; Copy W into L2
 LOOP2
     MOVLW 255                   ; Copy 255 into W
     MOVWF L3                    ; Copy W into L1
 LOOP1
     decfsz L3,F                    ; Decrement L1. If 0 Skip next instruction
         GOTO LOOP1                ; ELSE Keep counting down
     decfsz L4,F                    ; Decrement L2. If 0 Skip next instruction
         GOTO LOOP2
     decfsz L5,F
        GOTO LOOP3
;     decfsz L6,F
;        GOTO LOOP4

return

delay
    movlw 50
    movwf L1
    loop4
    decfsz L1,1
        goto loop4
    return

end