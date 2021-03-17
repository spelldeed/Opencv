import numpy as np
import cv2
img3 = cv2.imread('image.jpg')
def event_check(event,x,y,flags,param):
    if(event==cv2.EVENT_LBUTTONDOWN):
        print(x,",",y)
       
        points.append((x,y))
        if(len(points)>=3):
            #---------------------------y1-------:-------y2---,-----x1-----:-----x2-----
            part_to_be_copied = img3[points[0][1]:points[1][1],points[0][0]:points[1][0]]
            #----------y3----:---y3+(y2-y1)---------------------------,-----x3-----:------x3+(x2-x1)------
            img3[points[2][1]:points[2][1]+(points[1][1]-points[0][1]),points[2][0]:points[2][0]+(points[1][0]-points[0][0])]=part_to_be_copied
            cv2.imshow("copy_paste",img3)
            cv2.imshow("ROI", part_to_be_copied )
        

  
    
points=[] 
print("we choose ROI by selecting the ROI using a rectangle,hence\nFirst to select the part of image , think of containing it into a rectangle\nNow select the upper leftmost corner of this rectangle\nnow select the down rightmost corner of this rectangle\nNOw to insert it into the same image select a point such that the left and upper part of the point in the image has enough space to accomodate the ROI\n")
cv2.imshow("copy_paste",img3)
cv2.setMouseCallback("copy_paste",event_check)
if(cv2.waitKey(0)==27):
    cv2.destroyAllWindows()
