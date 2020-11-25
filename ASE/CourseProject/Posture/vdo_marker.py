import cv2
import numpy as np

cap = cv2.VideoCapture("yoga_women7.mp4")

out = cv2.VideoWriter("./Videos/yoga_women7.avi",cv2.VideoWriter_fourcc('M','J','P','G'), 23, (680,384))

while True:
    ret, frame = cap.read()

    if not ret:
        break

    cv2.imshow("Window", frame)

    k = cv2.waitKey(30)
    if k == ord('m'):
        frame[0:10,0:10,:] = 255
        print("marked")
    elif (k == 27 or k == 32):
        break
    else:
        frame[0:10,0:10,:] = 0
    
    print(frame[0,0,0])
    out.write(frame)


out.release()