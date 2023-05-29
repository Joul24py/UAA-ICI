import cv2
import os

web_cam = cv2.VideoCapture(0) # Webcam
faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml') # Carga Haarcascades
count = 0

while(web_cam.isOpened()):
    ret, frame = web_cam.read() # Lee la webcam
    
    # Preprocesamiento
    grises = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    rostro = faceCascade.detectMultiScale(grises, 1.5, 5)
    cv2.imshow("Creando Dataset", frame) # Muestra lectura de la webcam
    
    for(x,y,w,h) in rostro:
        cv2.rectangle(frame, (x,y), (x + w, y + h), (255, 0, 0), 4) # Enmarca rostro
        count += 1 # Rostros detectados
        cv2.imwrite("img/" + str(count) + '.jpg', grises[y:y + h, x:x + w]) # Guarda el rostro
        #
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    elif count >= 400:
        break

# Liberamos la captura
web_cam.release()
cv2.destroyAllWindows()