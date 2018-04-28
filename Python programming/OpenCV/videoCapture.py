# -*- coding: utf-8 -*-
#读取摄像头
import numpy as np
import cv2

cap = cv2.VideoCapture(0)  #0或-1接收第一个摄像头的画面，1接收第二个摄像头画面，以此类推

while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Our operations on the frame come here
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()

#如果cap没有初始化，会报错，使用cap.isOpened()查看，若返回true则已经初始化，若false则使用cap.open()


#读取视频
import numpy as np
import cv2

cap = cv2.VideoCapture('vtest.avi')

while(cap.isOpened()):
    ret, frame = cap.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()


#保存视频图像
#将摄像头的画面翻转并保存
import numpy as np
import cv2

cap = cv2.VideoCapture(0)

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'DIVX')  #FORURCC用4个字节表示视频的codec，Windows用DIVX
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))  #20.0表示fps,（640,480）表示大小

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
        frame = cv2.flip(frame,0)  #画面翻转

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()
