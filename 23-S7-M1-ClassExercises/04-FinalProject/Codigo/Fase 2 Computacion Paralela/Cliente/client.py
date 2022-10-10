#%% Conexión
import socket

s = socket.socket()
print("Ingresa la dirección del host")
host = input()
port = 8080
s.connect((host,port))
print("Conectado")

#%% Transfiriendo archivos
filename = "Control.txt"
file = open(filename, 'wb')
file_data = s.recv(1024)
file.write(file_data)
file.close()
print("Recibido")