chars = "~`!@#$%&*()-=+_[]{};:<>,.?/|"#可以引入中文字典
#ban = "abcdefghijklmnopqrstuvwxyz"
#ban = ban + ban.upper()
result = 'eval'
r1=''
r2=''
for i in result:
    flag = 0
    for t in chars:
        for m in chars:
           # if i == chr(ord(t) | ord(m)):
           #     print(i + '=' + t +'|' + m)
            if i == chr(ord(t) ^ ord(m)):
                r1 = r1 + t
                r2 = r2 + m
                flag = 1
                break
        if flag == 1: break
    if flag == 1 : continue
           #     print(i + '=' + t +'^' + m)
           # if i == chr(ord(t) & ord(m)):
           #     print(i + '=' + t +'&' + m)
print ("\'"+r1+"\'" +'  ^  ' + "\'"+ r2 + "\'")

