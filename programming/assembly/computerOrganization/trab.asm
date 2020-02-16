PROCESSOR 16f84
#include "p16f84.inc"

_CONFIG_CP_OF &_WDT_OFF &_PWRTE_ON &_XT_OSC

Cblock 0x0C
TempC
LO
endc

LEDtrisA equ TRISA
LEDportA equ PORTA

LEDtrisB equ TRISB
LEDportB equ PORTB

ORG0X00
goto Main

ORG 0X04
goto ISR

#include "bank.inc"
#include"7-seg.inc"

Main

LED_Init
LED_Disp2 0x21

loop goto loop

End



__________________


Arquivo inc:

LED_Init macro
    call InitPorts
    call InitTimers
    endm
    
LED_Disp2 macro num
    movlw num
    movwf LO
    call UpdateDisplau
    endm

InitPorts
    BANK1
    clrf LEDtrisA
    clrf LEDtrisB
    BANK0
    clrf LEDportA
    clrf LEDportB
    bsf LEDportA,3
    
    RETURN
    
InitTimers
    BANK1
    movlw B'10000100'
    movwf OPTION_REG
    BANK0
    movlw B'00100000'
    movwf INTCON
    movlw .96
    movwf TMR0
    
    RETFIE
    
ISR
    bcf INTCON,GIE
    btfsc INTCON,GIE
    goto ISR
    
    movlw .96
    movlw TMR0
    bcf INTCON,TOIF
    call UpdateDisplay
    
    RETFIE
    
UpdateDisplay
    movf LEDportA,W
    clrf LEDportA
    andlw 0x0f
        movwf TempC
    bsf TempC,4
    rrf TempC,F
    btfss STATUS,C
    bcf TempC,3
    btfsc TempC,0
    goto UpdateMsd
UpdateLsd
    call ChkMsdZero
    btfss STATUS,Z
    movf LO,W
    andlw 0x0f
    goto DisplayOut
UpdateMsd
    swapf LO,W
    andlw 0x0f
    btfsc STATUS,Z
    movlw 0x0a
    
DisplayOut
    callLedTable
    movwf LEDportB
    movf TempC,W
    movwf LEDportA
    
    RETURN
    
LedTable
    addwf PCL,F
    retlw B'00111111'
    retlw B'00000110'
    retlw B'01011011'
    retlw B'01001111'
    retlw B'01100110'
    retlw B'01101101'
    retlw B'01111101'
    retlw B'00000111'
    retlw B'01111111'
    retlw B'01101111'
    retlw B'00000000'

ChkMsdZero
    movf LO,W
    btfss STATUS,Z
    RETURN
    retlw .10
   