#define __SFR_OFFSET 0x20
  
#include "avr/io.h"

.global start
.global forever

start:
  LDI R16, 0b00100000     ;PORTB output
  STS DDRB, R16
  LDI R17, 0x00
  STS PORTB, R17    ;0 en PORTB
  LDI R16, 0x00
  STS TCCR1A, R16   ;todos los bits TCCR1A en 0
  RET

forever: 
  LDI R16, 0xC2
  STS TCNT1H, R16   ;0xC2 en TCNT1H 
  LDI R16, 0xF7
  STS TCNT1L, R16   ;0xF7 en TCNT1H
  LDI R16, 0x05
  STS TCCR1B, R16   ; 0x05 en TCCR1B
  L:LDS R0, TIFR1     ;TIFR1 en R0
  SBRS R0, 0        ; overflow?
  RJMP L            ; Loop hasta el overflow
  LDI R16, 0x00
  STS TCCR1B, R16   ; 
  LDI R16, 0x01
  STS TIFR1, R16    ; 
  COM R17           ; 
  STS PORTB, R17    ; Cambiar el estado del LED
  RET

    
