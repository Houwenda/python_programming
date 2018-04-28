#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import cv2

image1 = cv2.imread('test.png',0)  # 0:grayscale 1:color image(default) -1:unchanged(alpha channel)
cv2.imshow('窗口名',image1)  #创建窗口并显示图像
cv2.waitKey(0)  #暂停，直到按任意键
cv2.destoryAllWindows()  #关闭所有窗口
cv2.destoryWindow('窗口名')  #关闭指定窗口


cv2.namedWindow('窗口名',cv2.WINDOW_NORMAL)  #创建一个窗口 cv2.WINDOW_NORMAL:可以缩放  CV2.WINDOW_AUTOSIZE(DEFAULT):不可缩放
cv2.imshow('窗口名',image1)  #显示图像


cv2.imwrite('文件名.png',iamge1)  #在工作目录保存图片  png格式


##实例
import numpy as np
import cv2
img=cv2.imread('1.png',0)  #打开为灰度图
cv2.imshow('image',img)
k = cv2.waitKey(0)   #64位系统使用  k = cv2.waitKey(0) & 0xFF
if k == 27:  #读入ESC后退出
    cv2.destoryAllWindows()
elif k == ord('s'):  #读入s后保存并退出
    cv2.imwrite('2.png',img)
    cv2.destoryAllWindows()


#matplotlib
import numpy as np
import cv2
from matplotlib import pyplot as plt
img =cv2.imread('1.png',0)
plt.imshow(img, cmap= 'gray', interpolation= 'bicubic')
plt.xticks([]),plt.yticks([])  #to hide tick values on X and Y axis
plt.show
#OpenCV打开彩色图时使用BGR模式，matplotlib使用RGB模式，打开会出错
#解决方法
import cv2
import numpy as np
import matplotlib.pyplot as plt

img1 = cv2.imread('messi4.jpg')
b,g,r = cv2.split(img1)
img2 = cv2.merge([r,g,b])
plt.subplot(121);plt.imshow(img1) # expects distorted color
plt.subplot(122);plt.imshow(img2) # expect true color
plt.show()

cv2.imshow('bgr image',img1) # expects true color
cv2.imshow('rgb image',img2) # expects distorted color
cv2.waitKey(0)
cv2.destroyAllWindows()
