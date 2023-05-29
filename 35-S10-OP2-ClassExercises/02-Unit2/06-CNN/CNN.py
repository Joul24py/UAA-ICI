import os
import numpy as np
from PIL import Image
import tensorflow as tf
from tensorflow.keras import layers, models

data_dir = 'numbers'
labels = os.listdir(data_dir)

images = []
for label in labels:
    for filename in os.listdir(os.path.join(data_dir, label)):
        img = Image.open(os.path.join(data_dir, label, filename))
        img = img.resize((28, 28), resample=Image.BILINEAR)
        img = np.array(img)
        images.append((img, int(label)))

np.random.shuffle(images)

split = int(0.8 * len(images))
train_data = images[:split]
test_data = images[split:]

x_train = np.array([train_data[i][0] for i in range(len(train_data))])
y_train = np.array([train_data[i][1] for i in range(len(train_data))])
x_test = np.array([test_data[i][0] for i in range(len(test_data))])
y_test = np.array([test_data[i][1] for i in range(len(test_data))])

# Hasta aquí, x_train y y_train ambos tienen 17244

x_train = x_train.reshape((-1, 28, 28, 3))
x_train = x_train.astype('float32') / 255.0
x_test = x_test.reshape((-1, 28, 28, 3))
x_test = x_test.astype('float32') / 255.0
y_train = y_train.reshape((-1, 1))
y_train = y_train.astype('float32') / 255.0

model = models.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 3)),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),
    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5, batch_size=32, validation_data=(x_test, y_test))

test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)
print('Accuracy:', test_acc)
