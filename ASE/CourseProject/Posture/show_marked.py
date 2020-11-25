import cv2
import numpy as np

cap = cv2.VideoCapture("./Videos/yoga_women7.avi")

semaPhore = False
while True:
    ret, frame = cap.read()
    if not ret:
        break
    print(frame[0,0,0])
    if(not ret):
        break
    if(frame[0,0,0] > 250):
        semaPhore = not semaPhore
    if(semaPhore):
        cv2.imshow("Window", frame)

    k = cv2.waitKey(30)
    if k == 27 or k == 32:
        break
