import numpy as np
import cv2
img = cv2.imread('image.jpg')
events = [i for i in dir(cv2) if "event".casefold() in i.casefold()]
print(events)
print(img.shape)
def event_check(event,x,y,flags,param):
    if(event==cv2.EVENT_LBUTTONDOWN):
        textbgr = str(img[y,x,0])+','+str(img[y,x,1])+','+str(img[y,x,2])
        font = cv2.FONT_HERSHEY_PLAIN
        cv2.putText(img,textbgr,(x,y),font,1,(255,45,100),2)
        cv2.imshow("image",img)
    elif(event==cv2.EVENT_RBUTTONDOWN):
        text = str(x)+' , '+str(y)
        font = cv2.FONT_HERSHEY_PLAIN
        cv2.putText(img,text,(x,y),font,1,(108,72,26),2)
        print(x,",",y)
        cv2.imshow("image",img)

cv2.imshow("image",img)
cv2.setMouseCallback("image",event_check)
if(cv2.waitKey(0)==27):
    cv2.destroyAllWindows()
