from __future__ import print_function
import os

import tensorflow.keras as keras
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Activation, Flatten, BatchNormalization
from tensorflow.keras.layers import Conv2D, MaxPooling2D

from tensorflow.keras.optimizers import RMSprop, SGD, Adam
from tensorflow.keras.callbacks import ModelCheckpoint, EarlyStopping, ReduceLROnPlateau

# Configuración

# Directorio de imágenes
train_data_dir = 'img/'
validation_data_dir = 'img/'

# Función de lotes con modificaciones aleatorias
train_datagen = ImageDataGenerator(
    rotation_range = 30,
    width_shift_range = 0.4,
    height_shift_range = 0.4,
    shear_range = 0.3,
    zoom_range = 0.3,
    horizontal_flip = True,
    rescale = 1./255)
validation_datagen = ImageDataGenerator(rescale = 1./255) # Cambiar la escala de los valores en la matriz

# Generación de lotes normalizados
batch_size = 32
img_rows, img_cols = 48, 48
train_generator = train_datagen.flow_from_directory(
    train_data_dir,
    target_size = (img_rows, img_cols), # Cada imagen se redimensionará a este tamaño
    color_mode = 'grayscale',
    batch_size = batch_size,
    class_mode = 'categorical',
    shuffle = True) # Mezclar el orden

validation_generator = validation_datagen.flow_from_directory(
    validation_data_dir,
    target_size = (img_rows, img_cols),
    color_mode = 'grayscale',
    batch_size = batch_size,
    class_mode = 'categorical',
    shuffle = True)

# Modelado de la CNN

num_classes = 3 # Feliz, enojado
model = Sequential()

# Block 1 (esta capa crea un núcleo de convolución que se convoluciona con la entrada de la capa para producir un tensor de salida)
model.add(Conv2D(32, 3, padding = 'same', kernel_initializer = 'he_normal', input_shape = (img_rows, img_cols, 1)))
model.add(Activation('elu'))
model.add(BatchNormalization()) # Entradas cambian, lo que provoca la variedad de no estacionariedad

model.add(Conv2D(32, 3, padding = 'same', kernel_initializer = 'he_normal', input_shape = (img_rows, img_cols, 1)))
model.add(Activation('elu'))
model.add(BatchNormalization()) # Entradas cambian, lo que provoca la variedad de no estacionariedad

model.add(MaxPooling2D(pool_size = (2, 2))) # Reduce la dimensionalidad de la imagen, tomando grupos de 2x2 y nos quedamos con el máximo de pool
model.add(Dropout(0.2)) # La capa de abandono establece aleatoriamente las unidades de entrada en 0 para evitar sobreajuste

# Block 2
model.add(Conv2D(64, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(Conv2D(64, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(MaxPooling2D(pool_size = (2, 2)))
model.add(Dropout(0.2))

# Block 3
model.add(Conv2D(128, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(Conv2D(128, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(MaxPooling2D(pool_size = (2, 2)))
model.add(Dropout(0.2))

# Block 4
model.add(Conv2D(256, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(Conv2D(256, 3, padding = 'same', kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())

model.add(MaxPooling2D(pool_size = (2, 2)))
model.add(Dropout(0.2))

# Block 5
model.add(Flatten())
model.add(Dense(64, kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())
model.add(Dropout(0.5))

# Block 6
model.add(Dense(64, kernel_initializer = 'he_normal'))
model.add(Activation('elu'))
model.add(BatchNormalization())
model.add(Dropout(0.5))

# Block 7
model.add(Dense(num_classes, kernel_initializer = 'he_normal'))
model.add(Activation('softmax'))

print(model.summary()) # Resumen de cada capa

model.compile(optimizer = Adam(lr = 0.001), # Optimizer that implements the Adam algorithm
              loss = 'categorical_crossentropy', # Calcula la pérdida de entropía cruzada entre las etiquetas y predicciones
              metrics = ['accuracy']) # Calcula la frecuencia con la que las predicciones son iguales a las etiquetas

# Entrenamiento de la CNN

# Se detiene el entrenamiento cuando una métrica monitoreada haya dejado de mejorar
earlystop = EarlyStopping(monitor = 'val_loss',
                          min_delta = 0, # min change
                          patience = 5, # no change
                          verbose = 1,
                          restore_best_weights = True)

# Configuración para guardar un modelo
checkpoint = ModelCheckpoint(filepath = 'Modelo_3.h5', # Nombre
                             monitor = 'val_loss',
                             verbose = 1,
                             save_best_only = True,
                             mode = 'min')
                             #patience = 5,
                             #verbose = 1,
                             #min_delta = 0.0001)

reduce_lr = ReduceLROnPlateau(monitor='val_loss',
                              factor=0.2,
                              patience=5,
                              verbose=1,
                              min_lr=0.00001)

callbacks = [earlystop, checkpoint, reduce_lr]
epochs = 25
history = model.fit(
    train_generator, # 1,600 imágenes
    steps_per_epoch = None, # Hasta que se acaben las imágenes de train según los lotes es la época
    epochs = epochs,
    callbacks = callbacks,
    validation_data = validation_generator, # 400 imágenes
    validation_steps = None) # Hasta que se acaben las imágenes de validation según los lotes es la época