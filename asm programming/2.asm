DATAS SEGMENT
    XXX DW 2222
    YYY DW 1111
    ZZZ DW 3333;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    SBB AX,AX
    MOV BX,75
    MOV AX,XXX
    IMUL YYY
    ADD AX,ZZZ
    ADC DX,0
    SUB AX,1024
    SBB DX,0
    IDIV BX
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
