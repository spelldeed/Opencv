import numpy as np
import cv2
import datetime
img = cv2.imread('image.jpg')
cap = cv2.VideoCapture(0)
while(cap.isOpened()):
    ret,frame=cap.read()
    if(ret==True):
        font= cv2.FONT_HERSHEY_SIMPLEX
        dt = str(datetime.datetime.now())
        frame = cv2.putText(frame,dt,(20,20),font,0.5,(220,150,100),2,cv2.LINE_AA)
        cv2.imshow("LIVE",frame)
        if(cv2.waitKey(0)==27):
            break
    else:
        break
cap.release()
cv2.destroyAllWindows()
