# -*- coding: utf-8 -*-
import re, zipfile
nothing = 90052

while True:
    f0 = zipfile.ZipFile('channel.zip', 'r')
    print((f0.getinfo(str(nothing) + '.txt').comment).decode(), end = '')
    with open('./channel/' + str(nothing) + '.txt') as f:
        #print(f.read())
        nothing = (re.compile('Next nothing is [0-9]+')).findall(f.read())[0][16:]
        #print(nothing)