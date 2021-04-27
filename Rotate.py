#Warpaffine -> dst(x,y)=src(M11x+M12y+M13,M21x+M22y+M23)
#Let's Rotate around center keeping whole image in to the frame
#do read about matrix returned by getRotationMatrix2D

def rotate_in(image,angle):
    h=image.shape[0]
    w=image.shape[1]
    center = (h//2,w//2)
    imgrot=cv2.getRotationMatrix2D((center[1],center[0]),-angle,1.0)
    cos = np.abs(imgrot[0,0])
    sin =np.abs(imgrot[0,1])
    new_w = int((h*sin)+(w*cos))
    new_h = int((w*sin)+(h*cos))
    imgrot[0, 2] += (new_w / 2) - center[1]
    imgrot[1, 2] += (new_h / 2) - center[0]
    return(cv2.warpAffine(image,imgrot,(new_w,new_h)))

print("Enter an angle : ")
angle=int(input())
cv2.imshow("Rotated_in",rotate_in(img,angle))
cv2.waitKey(0)
