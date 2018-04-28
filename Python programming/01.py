#!/usr/bin/env python3     //加上此注释可以直接在mac和Linux中运行,./01.py
# -*- coding: utf-8 -*-
print('hello','world!')  #逗号输出为空格，输出hello World
name = input('please enter your name:')  #输出please enter your name,并传入用户输入,输入值为字符串
int(input())  #如果输入为数字，可用int()函数将字符串型转化为数字型

a=100
if a>=0:  #冒号结尾语句后的缩进视为代码块，and or not控制逻辑
    print(a)
else:
    print(-a)

print(r'\\\\\')  #内部字符串默认不转义
print('''line1
line2
line3
''')  #'''括起来用于表示多行字符串，相当于line1\nline2\nline3\n,也可用r表示不转义

print(9/3)  #3.0 除号/结果都是浮点数
print(10/3)  #3.3333333333 整数除法都是精确的
print(10//3)  #3 地板除// 两个整数相除得到整数
print(10%3)  #1 得到整数
ord('A')  #返回字符串的整数表示
chr(65)  #将编码转换为字符
#'abc'和b'abc'前者是Unicode后者是bytes,每个字符占一个字节
'ABC'.encode('ascii')
'中文'.encode('utf-8')  #用encode()可以编码为指定的bytes
b'ABC'.decode('ascii')
b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8')  #用decode()可以将网络或磁盘的字节流转换为str
b'\xe4\xb8\xad\xff'.decode('utf-8', errors='ignore')  #如果只有小部分错误编码，忽略错误字节
len('abc')  #计算字符串长度，若是bytes则计算字节数
'Hi, %s, you have $%d.' % ('Michael', 1000000)  #占位符 %s字符串，%d整数，%f浮点数，%x十六进制整数
#字符串中含有%时用%%转义
'Hello, {0}, 成绩提升了 {1:.1f}%'.format('小明', 17.125)  #format() 另一种格式化字符串的方法

#list数据类型
classmates = ['Micheal','Bob','Tracy']
classmates[-1]  #可以从末尾向前索引 例如-1，-2
classmates.append('Adam')  #append向末尾添加元素
classmates.insert(1,'Adam')  #将元素插入指定索引
classmates.pop(1)  #删除指定索引的元素，并返回
#tuple数据类型
classmates = ('Michael', 'Bob', 'Tracy')  #只可以读取，不能改变内容
t=(1,)  #只有一个元素的tuple需要添加逗号防止歧义
#tuple指向的元素不能改变，但是元素本身可能改变，如 t=(1,2,['x','y']) t[2][0]=a

#条件语句
if 条件1 :
    print()
elif 条件2 :
    print()
else 条件3 :
    print()
