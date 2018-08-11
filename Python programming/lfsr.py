# -*- coding: utf-8 -*-
string1 = raw_input('input ciphertext:\n')
print(string1)
squ = ''
i = 0
while i<6:
    
    for j in string1[i:i+6]:
        if j == '1':
            squ += '1'
        else:
            squ += '0'

    i += 1

print(squ) #squ为异或方程组的系数矩阵
output = string1[-6:-1] #异或方程组的结果矩阵

'''
高斯消元法求异或方程组的解

'''
p0 = 1
p1 = 0
p2 = 0
p3 = 0
p4 = 0
p5 = 1

'''
string3 = [0,0,0,0,0,0]
string2 = string1[0:6]
j = 0
for i in string2:
    string3[j] = i
    j += 1
'''

string2 = [1,0,1,0,1,1]
i = 0
while i<12:

    x = int(string2[5])
    print(string2[0])

    if p0 == 1:
        x = x^int(string2[0])
    if p1 == 1:
        x = x^int(string2[1])
    if p2 == 1:
        x = x^int(string2[2])
    if p3 == 1:
        x = x^int(string2[3])
    if p4 == 1:
        x = x^int(string2[4])
    if p5 == 1:
        x = x^int(string2[5])

    string2[0] = string2[1]
    string2[1] = string2[2]
    string2[2] = string2[3]
    string2[3] = string2[4]
    string2[4] = string2[5]
    string2[5] = x

    i += 1
