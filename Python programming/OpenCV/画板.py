#!usr/bin/env_python3
# -*- coding: utf-8 -*-
import numpy as np
import cv2

def nothing(x):
    pass

drawing = False

def draw_dot(event,x,y,flags,param):
    global drawing
    r = cv2.getTrackbarPos('R','Draw')
    g = cv2.getTrackbarPos('G','Draw')
    b = cv2.getTrackbarPos('B','Draw')
    radius = cv2.getTrackbarPos('Width','Draw')
    wipe = cv2.getTrackbarPos('Wipe','Draw')

    if wipe == 0:  #画图模式
        if  event == cv2.EVENT_LBUTTONDOWN:
            drawing = True

        elif event == cv2.EVENT_MOUSEMOVE:
            if drawing == True:
                cv2.circle(img,(x,y),radius,(b,g,r),-1)

        elif event == cv2.EVENT_LBUTTONUP:
            drawing = False
            cv2.circle(img,(x,y),radius,(b,g,r),-1)

    elif wipe == 1:  #擦除模式
        if  event == cv2.EVENT_LBUTTONDOWN:
            drawing = True

        elif event == cv2.EVENT_MOUSEMOVE:
            if drawing == True:
                cv2.circle(img,(x,y),radius,(0,0,0),-1)

        elif event == cv2.EVENT_LBUTTONUP:
            drawing = False
            cv2.circle(img,(x,y),radius,(0,0,0),-1)

#创建画板和图框
img = np.zeros((512,1900,3), np.uint8)
cv2.namedWindow('Draw')
cv2.setMouseCallback('Draw',draw_dot)


cv2.createTrackbar('R','Draw',0,255,nothing)
cv2.createTrackbar('G','Draw',0,255,nothing)
cv2.createTrackbar('B','Draw',0,255,nothing)
cv2.createTrackbar('Width','Draw',1,20,nothing)  #线宽
cv2.createTrackbar('Wipe','Draw',0,1,nothing)  #擦除


while(1):
    cv2.imshow('Draw',img)
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
