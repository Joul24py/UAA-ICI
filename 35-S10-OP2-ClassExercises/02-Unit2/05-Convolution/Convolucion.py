import cv2
import numpy as np
import matplotlib.pyplot as plt

#%% Primera convolución
# cargar imagen
img = cv2.imread("imagen.jpg")

# crear kernel de desenfoque
kernel = np.ones((5,5),np.float32)/25

# aplicar filtro de desenfoque
blurred = cv2.filter2D(img,-1,kernel)

# mostrar imagenes
fig, axs = plt.subplots(1, 2, figsize=(10, 10))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Imagen original")
axs[1].imshow(blurred, cmap="gray")
axs[1].set_title("Imagen después de aplicar filtro Sobel en dirección x")
plt.show()

#%% Segunda convolución
# cargar imagen
img = cv2.imread("imagen.jpg")

# crear kernel de realce de bordes
kernel = np.array([[-1,-1,-1], [-1,9,-1], [-1,-1,-1]])

# aplicar filtro de realce de bordes
edges = cv2.filter2D(img,-1,kernel)

# mostrar imagenes
fig, axs = plt.subplots(1, 2, figsize=(10, 10))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Imagen original")
axs[1].imshow(edges, cmap="gray")
axs[1].set_title("Imagen después de aplicar filtro Sobel en dirección x")
plt.show()

#%% Tercera convolución
# cargar imagen
img = cv2.imread("imagen.jpg")

# crear kernel de detección de bordes
kernel = np.array([[-1,-1,-1], [-1,8,-1], [-1,-1,-1]])

# aplicar filtro de detección de bordes
edges = cv2.filter2D(img,-1,kernel)

# mostrar imagenes
fig, axs = plt.subplots(1, 2, figsize=(10, 10))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Imagen original")
axs[1].imshow(edges, cmap="gray")
axs[1].set_title("Imagen después de aplicar filtro Sobel en dirección x")
plt.show()

#%% Cuarta convolución
# cargar imagen
img = cv2.imread("imagen.jpg")

# aplicar filtro de sobel
sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=5)

# mostrar imagenes
fig, axs = plt.subplots(1, 2, figsize=(10, 10))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Imagen original")
axs[1].imshow(sobelx, cmap="gray")
axs[1].set_title("Imagen después de aplicar filtro Sobel en dirección x")
plt.show()

#%% Quinta convolución
# cargar imagen
img = cv2.imread("imagen.jpg")

# crear kernel laplaciano
kernel = np.array([[0,1,0], [1,-4,1], [0,1,0]])

# aplicar filtro laplaciano
edges = cv2.filter2D(img,-1,kernel)

# mostrar imagenes
fig, axs = plt.subplots(1, 2, figsize=(10, 10))
axs[0].imshow(img, cmap="gray")
axs[0].set_title("Imagen original")
axs[1].imshow(edges, cmap="gray")
axs[1].set_title("Imagen después de aplicar filtro Sobel en dirección x")
plt.show()