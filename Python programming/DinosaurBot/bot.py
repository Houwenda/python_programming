# _*_ coding: utf-8 _*_

from PIL import ImageGrab, ImageOps
import pyautogui
import time
from numpy import *

class Cordinates():
    replayBtn = (480, 480)
    dinosaur = (176, 490)
    # x1 = 225 x2 = 241 y1 = 515  y2 = 537


def restartGame(): 
    pyautogui.click(Cordinates.replayBtn)

def pressSpace():
    pyautogui.keyDown('space')
    time.sleep(0.05)
    #print("Jump")
    pyautogui.keyUp('space')

def imageGrab():
    box = {225, 515, 241, 537 }
    image = ImageGrab.grab(box)
    print(image )
    gray_image = ImageOps.grayscale(image)
    a = array(gray_image.getcolors())
    print(a.sum())
    return a.sum()

def main():
    restartGame()
    while True:
        if(imageGrab() != 2247):
            pressSpace()
            time.sleep(0.1)

main()