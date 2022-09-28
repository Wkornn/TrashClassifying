import cv2
import cvzone
from statistics import mode
from cvzone.SerialModule import SerialObject

arduino = SerialObject("COM3")
cap = cv2.VideoCapture(0)
maskClassifier = cvzone.Classifier('keras_model.h5', 'labels.txt')

Blank = []
Recycle = []
General = []
Compostable = []
A_index = []
ids = int

while True:
    _, img = cap.read()
    cv2.imshow("Image", img)
    index = []
    for x in range():
        predictions, i = maskClassifier.getPrediction(img)
        cv2.imshow("Image", img)
        index.append(i)
    index = mode(index)
    A_index.append(index)
    arduino.sendData(A_index)
    cv2.waitKey(1)
