import cv2
img = cv2.VideoCapture(0)
while True:
    ret,frame = img.read()
    grayscaled = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(255-grayscaled,(5,5),sigmaX=0,sigmaY=0)
    cv2.imshow("Online",frame)
    cv2.imshow("Sketch",255-cv2.divide(255-cv2.divide(grayscaled,255-blurred,scale=256),255-blurred,scale=256))
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
img.release()
cv2.destroyAllWindows()
