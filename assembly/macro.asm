;**Kalvin 31894666**

;**main - macros **


  LIST P=16F628A, R=DEC    ; Use the PIC16F628 and decimal system 

        #include <P16F628A.INC>  ; Include header file 

        __config  _INTRC_OSC_NOCLKOUT & _LVP_OFF & _WDT_OFF & _PWRTE_ON & _BODEN_ON 
        
;*** vari�veis ***
    
    Cblock 0x0C         
    TempC               
    LO
    endc
    
;*** mem�ria de programa ***

    ORG  0x00           
    goto Main
    
    ORG  0x04           
    goto ISR            
                        
                        
    #include "bank.inc" 
    #include "7-seg.inc"
    
Main                    
    LED_Init
    
    LED_Disp2 0x72      
                        
loop  GOTO  loop        

    END                