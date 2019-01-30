# -*- coding:utf-8 -*-
import requests,re,time,sys
number = 55205
number = sys.argv[1]
for count in range(400):
    r = requests.get('http://www.pythonchallenge.com/pc/def/linkedlist.php', params = {'nothing': number})
    #print(r.url)
    #print(r.text)
    resultStr = (re.compile('and the next nothing is [0-9]+')).findall(r.text)[0]
    if resultStr == r.text:
        print(resultStr)
    else:
        print('pattern changed')
        break
    number = resultStr[24:]
    time.sleep(2)