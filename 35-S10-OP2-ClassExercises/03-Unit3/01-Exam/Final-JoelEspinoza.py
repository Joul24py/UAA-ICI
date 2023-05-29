# Importa las bibliotecas necesarias, como TensorFlow y Keras

import pandas as pd
import numpy as np
from tensorflow import keras
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Embedding, LSTM, Dense

# Carga el archivo CSV que contiene las críticas y sus etiquetas utilizando pandas

data = pd.read_csv("movie_data.csv")

# Preprocesa los datos

reviews = data['review'].values
labels = data['sentiment'].values

# Tokeniza los textos utilizando la clase Tokenizer de Keras

tokenizer = Tokenizer()
tokenizer.fit_on_texts(reviews)
sequences = tokenizer.texts_to_sequences(reviews)

# Establece la longitud máxima de las secuencias

max_sequence_length = 100  # Longitud máxima de las secuencias
padded_sequences = pad_sequences(sequences, maxlen=max_sequence_length)

# Dividir los datos en conjuntos de entrenamiento y prueba

split_ratio = 0.8  # Proporción de entrenamiento-prueba
split_index = int(split_ratio * len(padded_sequences))

x_train = padded_sequences[:split_index]
y_train = labels[:split_index]
x_test = padded_sequences[split_index:]
y_test = labels[split_index:]

# Construye el modelo de la red neuronal LSTM

vocab_size = len(tokenizer.word_index) + 1  # Tamaño del vocabulario
embedding_dim = 100  # Dimensión de la capa de embedding

model = Sequential()
model.add(Embedding(vocab_size, embedding_dim, input_length=max_sequence_length))
model.add(LSTM(128))
model.add(Dense(1, activation='sigmoid'))

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Entrena el modelo con los datos de entrenamiento

model.fit(x_train, y_train, epochs=10, batch_size=16)

# Evalúa el modelo con los datos de prueba

loss, accuracy = model.evaluate(x_test, y_test)
print('Accuracy:', accuracy)