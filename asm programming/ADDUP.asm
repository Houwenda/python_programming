DATAS SEGMENT
	STRING1 DB 'INPUT A NUM:',0DH,0AH,'$'
	STRING2 DB 'ERR1:OVERFLOW',0DH,0AH,'$'
	STRING3 DB 'ERR2:ILLEGAL INPUT',0DH,0AH,'$'
	STRING4 DB 'SUM=',0DH,0AH,'$'
	STRING5 DB 'ERR3:OVERFLOW',0DH,0AH,'$'
	STRING6 DB 'ERR4:OVERFLOW',0DH,0AH,'$'
	STRING7 DB 'ERR5:OVERFLOW',0DH,0AH,'$'
    NUM DB 00H
    SUM DW 0000H;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    LEA DX,STRING1
    MOV AH,9
    INT 21H
IN1:    
    MOV AH,01H
    INT 21H
    CMP AL,13
    JZ OUT1
    
    MOV CL,AL
    MOV BL,NUM
    MOV AL,10
    MUL BL
    
    ;CMP AH,0;OVERFLOW
    JO ERR1
    
    CMP CL,'0';CHECK INPUT
    JB ERR2
    CMP CL,'9'
    JA ERR2
    SUB CL,30H
    ADC AL,CL  ;OVERFLOW
    JO ERR3
    MOV NUM,AL
    JMP IN1               
    
OUT1:
	MOV CH,0
	MOV CL,NUM
	MOV AX,0
ADDUP:
	
	ADC AX,CX;OVERFLOW
	JO ERR4
	
	LOOP ADDUP

	MOV SUM,AX
	
	LEA DX,STRING4
	MOV AH,9
	INT 21H

	MOV DX,0
	MOV AX,SUM
	MOV BX,10
	MOV CX,0
STACK1:	
	INC CX
	DIV BX
	PUSH DX
	CMP AX,0
	JNZ STACK1
OUTPUT:
	POP AX
	MOV DL,AL
	ADD DL,30H ;OVERFLOW
	JO ERR5
	
	MOV AH,2
	INT 21H
	
	LOOP OUTPUT	
	MOV AH,4CH
    INT 21H

ERR1:	
	LEA DX,STRING2
	MOV AH,9
	INT 21H
	
	MOV AH,4CH
    INT 21H
ERR2:
	LEA DX,STRING3
	MOV AH,9
	INT 21H
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
    
ERR3:	
	LEA DX,STRING5
	MOV AH,9
	INT 21H
	
	MOV AH,4CH
    INT 21H
ERR4:	
	LEA DX,STRING6
	MOV AH,9
	INT 21H
	
	MOV AH,4CH
    INT 21H
ERR5:
	LEA DX,STRING7
	MOV AH,9
	INT 21H
	
	MOV AH,4CH
    INT 21H
CODES ENDS
    END START




