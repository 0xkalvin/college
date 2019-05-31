;**Kalvin 31894666**

;**led pisca**

LED_Init macro
    call InitPorts
    call InitTimers
    endm
    
LED_Disp2 macro num
    movlw num
    movwf LO
    call UpdateDisplay
    endm
    
;**Subprogramas**

InitPorts
    BANK1
    clrf TRISA       
    clrf TRISB       
    BANK0
    clrf PORTA       
    clrf PORTB       
    bsf  PORTA, 3    
    
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
    
;**ISR - Rotina de Servi�o de Interrup��o**

ISR
    bcf   INTCON, GIE   
    btfsc INTCON, GIE   
    goto  ISR
    
    movlw .96          
    movwf TMR0
    bcf   INTCON, T0IF  
    call  UpdateDisplay 
    
    RETFIE
    
UpdateDisplay
    movf  PORTA, W
    clrf  PORTA
    andlw 0x0f
    movwf  TempC   
    bsf   TempC, 4
    rrf   TempC, F 
    btfss STATUS, C
    bcf   TempC, 3
    btfsc TempC, 0
    goto  UpdateMsd
    
UpdateLsd
    call  ChkMsdZero
    btfss STATUS, Z
    movf  LO, W
    andlw 0x0f
    goto  DisplayOut2
    
UpdateMsd
    swapf LO, W
    andlw 0x0f
    btfsc STATUS, Z
    movlw 0x0a
    
DisplayOut
    call  LedTable
    movwf PORTB
    movf  TempC, W
    movwf PORTA
    RETURN
    
DisplayOut2
    call  LedTable2
    movwf PORTB
    movf  TempC, W
    movwf PORTA
    RETURN
    
    
LedTable
    addwf PCL, F
    retlw B'11101110'  
    retlw B'00101000'   
    retlw B'11001101'   
    retlw B'01101101'  
    retlw B'00101011'   
    retlw B'01100111'   
    retlw B'11100111'   
    retlw B'00101100'   
    retlw B'11101111'   
    retlw B'00101111'   
    
LedTable2
    addwf PCL, F
    retlw B'11111110'   
    retlw B'00111000'   
    retlw B'11011101'   
    retlw B'01111101'   
    retlw B'00111011'   
    retlw B'01110111'   
    retlw B'11110111'   
    retlw B'00111100'  
    retlw B'11111111'   
    retlw B'00111111'   
    
ChkMsdZero
    movf  LO, W
    btfss STATUS, Z
    RETURN
    retlw .10
    goto  DisplayOut

