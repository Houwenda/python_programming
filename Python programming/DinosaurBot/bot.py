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
    pyautogui.keyDown('down')

def pressSpace():
    pyautogui.keyUp('down')
    pyautogui.keyDown('space')
    time.sleep(0.18)
    #print("Jump")
    pyautogui.keyUp('space')
    pyautogui.keyDown('down')


def imageGrab():
    box = (320, 525, 380, 530)
    image = ImageGrab.grab(bbox=box)
#    image.show('image')
    gray_image = ImageOps.grayscale(image)
    a = array(gray_image.getcolors())
    #print(a.sum())
    return a.sum()

def test():
    while True:
        imageGrab()

def main():
    restartGame()
    while True:
        if(imageGrab() != 547):
            pressSpace()
            print('Jump')
            #time.sleep(0.1)

main()

test()
