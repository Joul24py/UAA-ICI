from keras.models import load_model
from time import sleep
from tensorflow.keras.utils import img_to_array
from keras.preprocessing import image
import cv2
import numpy as np

#
face_classifier = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml') # Carga Haarcascades
classifier = load_model('Modelo_3.h5') # Carga modelo
#class_labels = ['Feliz', 'Enojado', 'Sorpresa', 'Neutral', 'Triste']
class_labels = ['Feliz', 'Enojado', 'Sorpresa']

# Para cargarle imágenes
'''
'''

# Detección en tiempo real con webcam
cap = cv2.VideoCapture(0) # Webcam
while True:
    ret, frame = cap.read() # Lee webcam
    # Preprocesa la imagen
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # escala de grises
    faces = face_classifier.detectMultiScale(gray, 1.3, 5) # Detección de caras (ubicación de la cara)
    
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2) # Obtiene sólo el área de la cara (recorta la cara)
        
        roi_gray = gray[y:y + h, x:x + w] # Vuelve a generar la escala de grises
        roi_gray = cv2.resize(roi_gray, (48, 48), interpolation = cv2.INTER_AREA) # Interpolación -> para minimizar la imagen
        
        # Si detecta rostro genera un recuadro
        if np.sum([roi_gray]) != 0:
            roi = roi_gray.astype('float')/255.0 # escala y convierte a grises
            roi = img_to_array(roi) # Convierte a números
            roi = np.expand_dims(roi, axis = 0)
            
            preds = classifier.predict(roi)[0] # Predicción (el cero implica el canal que hace referencia a la webcam)
            label = class_labels[preds.argmax()]
            label_position = (x, y) # Posición x, y para escribir la etiqueta (feliz o enojado) encima del recuadro
            cv2.putText(frame, label, label_position, cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 255, 0), 3) # Escribe la etiqueta (feliz o enojado)
        
        else:
            cv2.putText(frame, 'No Face Found', (20, 60), cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 255, 0), 3) # No abre cámara hasta detectar rostro

    cv2.imshow('Detector de emociones', frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()