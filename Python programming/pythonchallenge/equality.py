# -*- coding: utf-8 -*-
import re 
# 正则
def judge_line2(line):
    result = (re.compile(r'[a-z]+[A-Z]{3}[a-z]{1}[A-Z]{3}[a-z]+?')).findall(line) #懒惰匹配
    if result != []:
        print(result[0][-5:-4], end = '')
# 遍历
def judge_line(line):
    i = 0
    while i < len(line)-9:
        cut = line[i:i+9]
        flag = False #
        if not ord(cut[0]) in range(ord('a'),ord('z')+1):
            flag = True #不符合
        if not ord(cut[4]) in range(ord('a'),ord('z')+1):
            flag = True 
        if not ord(cut[8]) in range(ord('a'),ord('z')+1):
            flag = True 
        for j in range(1,4):
            if not ord(cut[j]) in range(ord('A'),ord('Z')+1):
                flag = True 
                break
        for j in range(5,8):
            if not ord(cut[j]) in range(ord('A'),ord('Z')+1):
                flag = True 
                break
        if not flag: #符合
            #print(cut)
            print(cut[4], end = '')
        else:
            pass
            #print(cut[3] + '不符合')
        i += 1

if __name__ == '__main__':
    with open('equality.txt', 'r') as f:
        for lines in f.readlines():
            judge_line(lines)
        print('')
    with open('equality.txt', 'r') as f:
        for lines in f.readlines():
            judge_line2(lines)            

    