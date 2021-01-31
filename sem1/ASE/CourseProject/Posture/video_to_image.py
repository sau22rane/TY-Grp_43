import cv2
import numpy as np

cap = cv2.VideoCapture("yoga1.mp4")
print(cap.get(cv2.CAP_PROP_FPS))
count = 1
path = "Yoga1/yoga1_{}.jpg"
while True:
    ret, frame = cap.read()
    if(ret == False):
        break
    cv2.imwrite(path.format(count),frame)
    count+=1
