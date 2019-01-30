# -*- coding:utf-8 -*-

# 未完成
from PIL import Image
img = Image.open('oxygen.jpg')
width, height = img.size
#print(width)
#print(height)
pixel = img.load()
i = 4
while i < 608:
    print(chr(pixel[i,0]), end = '')
    #print(img.getpixel((i,0)))
    i += 7
