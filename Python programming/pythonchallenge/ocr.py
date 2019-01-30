# -*- coding: utf-8 -*-
from functools import reduce

with open('ocr.txt', 'r') as f:
    #print(f.read())
    characters = {}
    for ch in f.read():
        if ch in characters:
            characters[ch] += 1
        else:
            characters[ch] = 1
    print(sorted(characters.items(), key=lambda i:i[1]))
# 
with open('ocr.txt', 'r') as f:
    #print(f.read())
    characters = []
    for ch in f.read():
        if ch in characters:
            continue
        else:
            characters.append(ch)
    #print(characters)
    print(reduce(lambda x,y:x+y, characters))