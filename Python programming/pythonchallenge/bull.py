# -*- coding:utf-8 -*-
def next(former):
    result = ''
    i = 1
    ch = former[0]
    count = 1
    while True:
        if i == len(former):
            break
        elif ch == former[i]:
            count += 1
            i += 1
        else:  
            result += str(count) + ch        
            count = 1
            ch = former[i]
            #print('next:' + ch)            
            i += 1
        #print('result:' + result)
    result += str(count) + ch
    #print(result)
    return result
                
if __name__ == '__main__':
    #next('111221')
    former = '1'
    for count in range(30):
        former = next(former)
        #print(former) 
    print(len(former))