# -*- coding: utf-8 -*-
import requests

r = requests.get('http://www.pythonchallenge.com/pc/def/'+ str(pow(2,38)) + '.html')
print(r.text)
r = requests.get('http://www.pythonchallenge.com/pc/def/map.html')
print(r.text)