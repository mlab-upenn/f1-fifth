import cv2

cap = cv2.VideoCapture('/dev/video4')

while True:
    ret,frame = cap.read()
    cv2.imshow("Frame",frame)
    cv2.waitKey(1)