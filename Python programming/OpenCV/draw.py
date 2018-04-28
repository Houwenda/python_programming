#!/usrr/bin/env_python3
# -*- coding: utf-8 -*-

#画线
#创建一个黑图，从左上到右下画蓝线
import numpy as np
import cv2

# Create a black image
img = np.zeros((512,512,3), np.uint8)

# Draw a diagonal blue line with thickness of 5 px
cv2.line(img,(0,0),(511,511),(255,0,0),5)
#画线图像，起始点，结束点，BGR颜色，线宽


#画矩形
#在图像右上角画一个绿框
cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)
#画线图像，矩形左上角坐标，右下角坐标，BGR颜色，线宽


#画圆
#在先前的矩形内部画红色的圆
cv2.circle(img,(447,63), 63, (0,0,255), -1)
#画线图像，圆心，半径，BGR颜色，线宽(-1时使用默认值1)


#画椭圆
#在图像中心画半个椭圆
cv2.ellipse(img,(256,256),(100,50),0,0,180,255,-1)
#画线图像，椭圆中心坐标，(长轴长，短轴长)，逆时针方向的旋转角，顺时针方向的画弧始末角度（0,360表示整个椭圆），线宽


#画多边形
#画一个四顶点的黄色图形
pts = np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)
pts = pts.reshape((-1,1,2))
cv2.polylines(img,[pts],True,(0,255,255))
#画线图像，处理后的顶点数据，True表示闭合图形（False表示绘制连接所有点的折线），BGR颜色


#添加文字
#在图像中写一个白色的OpenCV
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'OpenCV',(10,500), font, 4,(255,255,255),2,cv2.CV_AA)
#写字位置，要写的字，字左下角坐标，font类型，大小，BGR颜色，线宽，线型（推荐cv2.LINE_AA，仅限OpenCV3）
'''
cv2.imshow('draw',img)
cv2.waitKey(0)
cv2.destoryAllWindows()
'''
