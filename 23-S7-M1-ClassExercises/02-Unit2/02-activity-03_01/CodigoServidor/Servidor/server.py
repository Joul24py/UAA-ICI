#%% Conexión
import socket

s = socket.socket()
host = socket.gethostname()
port = 8080
s.bind((host,port))
s.listen(1)
print(host)
print("Esperando conexiones...")
conn, addr = s.accept()
print(addr + " se ha conectado")

#%% Transfiriendo archivos
filename = "Control.txt"
file = open(filename, 'rb')
file_data = file.read(1024)
conn.send(file_data)
print("Archivo enviado")