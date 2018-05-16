DATAS SEGMENT
	STRING1 DB 0DH,0AH,"INPUT ERROR$"
	STRING2 DB 0DH,0AH,"OVERFLOW$"
	STRING3 DB "NUM= $"
	STRING4 DB "RESULT= $"
    NUM DW 0
    N DW 0
    RESULTH DW 0
    RESULTL DW 0
    COUNT DW 0
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    LEA DX,STRING3
	MOV AH,9
	INT 21H
	
INPUT:   

    MOV AH,01H;输入
    INT 21H
    
    CMP AL,13;ENTER则进入下一步
    JZ STEP2
    
    CMP AL,'0';判断合法性
    JB ERR1
    CMP AL,'9'
    JA ERR1
    
    SUB AL,'0'    
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
	
	MOV AX,1
	PUSH AX
	MOV AX,NUM;用ax传值 
	CALL MULDW;调用子程序
	
STEP3:  ;转化为十进制放入堆栈段
	
	MOV CX,10;存放除数
	MOV DX,RESULTH
	MOV AX,RESULTL
	PUSH AX;保存低16位
	MOV AX,DX;高16位放入ax
	MOV DX,0;DIV将dx ax连接的双字除以源操作数，所以此处dx清零	
	DIV CX;商放入ax 余数放入dx	
	MOV BX,AX;商放入bx
	POP AX;拿出低16位
	DIV CX;将dx ax连接的双字除以源操作数 商放入ax 余数放入dx
	MOV CX,DX;余数放入cx
	MOV DX,BX;高16位放入dx 低16位放入ax
	
	MOV RESULTH,DX
	MOV RESULTL,AX
	PUSH CX;将余数入栈
	
	MOV CX,COUNT;计数加一
	INC CX;
	MOV COUNT,CX;
	
	CMP DX,0;高16位不为0 则商肯定不为0 继续短除
	JNZ STEP3		 
	CMP AX,0;高16位为0 低16位不为0 继续短除
	JNZ STEP3
	
	MOV CX,COUNT;商为0 设定输出循环次数
	
	LEA DX,STRING4
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

	
MULDW PROC NEAR ;子程序 将累乘结果放入数据段

	CMP AX,0;NUM是否为0
	JNZ STEP4
	MOV RESULTL,1
	JMP RETURN

STEP4:
	
	PUSH AX
	DEC AX
	CALL MULDW
	
RETURN:
	
	POP CX;存放call时的地址
	POP AX
	MOV N,AX;NUM的值放入数据段供计算高位时使用
	MUL RESULTL;N*[(N-1)!低16位] 结果的低16位放入ax 高16位放入dx
	MOV BX,DX;BX暂时存放高16位
	MOV RESULTL,AX;低16位放入数据段
	MOV AX,N;拿出NUM
	MUL RESULTH;N*[(N-1)!高16位] 结果应当只存在低16位 放入ax
	CMP DX,0
	JNZ ERR2
	ADD AX,BX;实现双字乘法 其结果的高16位放入ax
	MOV RESULTH,AX;高16位放入数据段
	PUSH CX;将call时的地址入栈
	
	RET
MULDW ENDP

	    
ERR1:

	LEA DX,STRING1
	MOV AH,9
	INT 21H
	
    MOV AH,4CH
    INT 21H
    
ERR2:

	LEA DX,STRING2
	MOV AH,9
	INT 21H
	
    MOV AH,4CH
    INT 21H
    
CODES ENDS
    END START














