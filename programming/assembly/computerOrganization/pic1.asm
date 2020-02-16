; kalvin 31894666
; roger 31849571

LIST P=16F628, R=DEC    ; Use the PIC16F628 and decimal system

        #include "P16F628.INC"  ; Include header file

        __config  _INTRC_OSC_NOCLKOUT & _LVP_OFF & _WDT_OFF & _PWRTE_ON & _BODEN_ON

        CBLOCK 0x20             ; Declare variable addresses starting at 0x20 
          Loop1,Loop2 
        ENDC 
; ----------- 
; INITIALIZE 
; ----------- 
; 
        ORG    0x000           ; Program starts at 0x000 
 
        CLRF   PORTA           ; Initialize port A 
        CLRF   PORTB           ; Initialize port B 
 
        BSF    STATUS,RP0      ; RAM bank 1 
 
        CLRF   TRISA           ; All pins port A output 
        CLRF   TRISB           ; All pins port B output 

        BCF    STATUS,RP0      ; RAM bank 0 
; 
; ------------------------ 
; FUNCTION OF PORT A PINS 
; ------------------------ 
; 
        MOVLW    7 
        MOVWF    CMCON         ; Comparators off, all pins digital I/O 
; 
; ---------- 
; MAIN LOOP 
; ---------- 
;    
Main    
        BSF     PORTA, 0      ; Turn on LED connected to RA2 
        CALL    delay 
        BSF     PORTA, 1      ; Turn on LED connected to RA2 
        BCF     PORTA, 0      ; Turn off LED connected to RA2 
        CALL    delay 
        BSF     PORTA, 2      ; Turn on LED connected to RA2 
        BCF     PORTA, 1      ; Turn off LED connected to RA2 
        CALL    delay 
        BSF     PORTA, 3      ; Turn on LED connected to RA2 
        BCF     PORTA, 2      ; Turn off LED connected to RA2 
        CALL    delay 
        BSF     PORTA, 4      ; Turn on LED connected to RA2 
        BCF     PORTA, 3      ; Turn off LED connected to RA2 
        CALL    delay 
        BSF     PORTB, 5      ; Turn on LED connected to RA2 
        BCF     PORTA, 4      ; Turn off LED connected to RA2 
        CALL    delay
        BSF     PORTB, 6      ; Turn on LED connected to RA2 
        BCF     PORTB, 5      ; Turn off LED connected to RA2 
        CALL    delay 
        BSF     PORTB, 7      ; Turn on LED connected to RA2 
        BCF     PORTB, 6      ; Turn off LED connected to RA2 
        CALL    delay 
        BCF     PORTB, 7      ; Turn off LED connected to RA2 
        GOTO    Main 
; 
; --------------- 
; DELAY 250 MSEC 
; --------------- 
; 
delay
        MOVLW   250 
        MOVWF   Loop1 
Outer
        MOVLW   200 
        MOVWF   Loop2 
Inner   
        NOP 
        NOP 
        DECFSZ  Loop2,F 
        GOTO    Inner          ; Inner loop = 5 usec. 
        DECFSZ  Loop1,F 
        GOTO    Outer 
        RETURN 
        END

;MNMONICOS PIC 16F628A

;NOP	RETURN	RETFIE	OPTION	SLEEP	CLRWDT	TRIS†.MOVW,CLR†, SUBWF, DECF, IORWF, ANDWF,XORWF,ADDWF,MOVF, COMF,INCF, DECFSZ, RRF, RLF,SWAPF,INCFSZ,
;BCF, BSF, BTFSC,BTFSS,CALL, GOTO,MOVLW, RETLW, IORLW, ANDLW, XORLW,†SUBLW,ADDLW






;MNMONICOS PIC 18F455O
;NOP
;SLEEP
;CLRWDT
;PUSH
;POP
;DAW
;TBLRD*
;TBLRD*+
;TBLRD*-
;TBLRD+*
;TBLWR
;RETFIE [, FAST]
;RETURN [, FAST]
;CALLW*
;RESET
;MOVLB

;SUBLW†k
;IORLW†k
;XORLW†k
;ANDLW†k
;RETLW†k
;MULLW†k
;MOVLW†k
;ADDLW†k


;MULWF†
;DECF†
;IORWF†
;ANDWF†
;XORWF†
;COMF†
;ADDWFC†
;ADDWF†
;INCF†
;DECFSZ†
;RRCF†
;RLCF†
;SWAPF†
;INCFSZ†
;RRNCF†
;RLNCF†
;INFSNZ†
;DCFSNZ†
;MOVF†
;SUBFWB†


;CPFSLT†
;CPFSEQ†
;CPFSGT†
;TSTFSZ†
;SETF†
;CLRF†
;NEGF†
;MOVWF†
;BTG†

;BSF†
;BCF†
;BTFSS†
;BTFSC†

;MOVFF†
;BRA†
;RCALL†

;BZ†
;BNZ†
;BC†
;BNC†
;BOV†
;BNOV†
;BN†
;BNN†

;ADDFSR†
;ADDULNK†
;SUBFSR†
;SUBULNK†
;PUSHL†
;MOVSF†

;MOVSS

;CALL†

;LFSR†

;GOTO†
;SUBWFB†
;SUBWF†



