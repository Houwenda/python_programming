DATAS SEGMENT
	STRING1 DB 'ERROR',0dh,0ah,'$'
	STRING2 DB 'NUM=$'
	STRING3 DB 'SUM=$'
	STRING4 DB 'OVERFLOW$'
    NUM DW 0
    SUM DW 0;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    LEA DX,STRING2
	MOV AH,9
	INT 21H
    
INPUT:  
 
    MOV AH,01H;输入
    INT 21H
   
    CMP AL,13;判断回车
    JZ STEP2
    
    CMP AL,'0';判断合法输入
    JB ERR1
    CMP AL,'9'
    JA ERR1
    SUB AL,'0';字符转换为数字
    MOV AH,0;
    PUSH AX;暂时空出AX
    
    MOV AX,NUM
    
    MOV BX,10;乘数放入bx
    MUL BX;把num乘BX(10)存入AX
    POP DX;把输入的数字放入DX
    ADD DX,AX;实现输入多位数
    MOV NUM,DX;把得到的多位数放入data段
    
    JMP INPUT
    
STEP2:
	
	MOV AX,SUM;0
	MOV DX,NUM

ADDUP:
	
	ADD AX,DX;累加
	JO ERR2
	DEC DX;NUM减1
	CMP DX,0
	JNZ ADDUP;从输入值一直加到0
    
	MOV SUM,AX;将累加得到的数放回data段
	MOV CX,0;用cx计数按位输出的次数，所以此处将cx清零
	MOV BX,10;为div设定除数
	
STEP3:	

	MOV DX,0;div将dx ax连接成的双字数据除以bx,所以此处将dx清零
	DIV BX;商送入ax 余数送入dx	        
    PUSH DX;余数送入stack段
    INC CX;输出所用的次数加一
    CMP AX,0;
    JNZ STEP3;商不为0时继续短除   
    
	LEA DX,STRING3
	MOV AH,9
	INT 21H

OUTPUT:
    
    POP DX;将后放入stack段的一个数拿出 放入dx
    ADD DX,'0';将数值转化为字符放入dx
    
    MOV AH,2
    INT 21H;输出dl中ASCII对应的字符
    
    LOOP OUTPUT;CX递减到0时停止
    
    MOV AH,4CH
    INT 21H  
    
ERR1:
	LEA DX,STRING1
	MOV AH,9
	INT 21H
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
    
ERR2:
	LEA DX,STRING4
	MOV AH,9
	INT 21H
    MOV AH,4CH
    INT 21H
        
CODES ENDS
    END START



