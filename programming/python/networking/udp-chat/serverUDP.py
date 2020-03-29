import socket

UDP_IP = "192.168.15.14" 
UDP_PORT = 5005
ENCODING = 'UTF-8'
BUFFER_SIZE = 1024

# Criação de socket UDP
# Argumentos, AF_INET que declara a família do protocolo; se fosse um envio via Bluetooth usariamos AF_BLUETOOTH
# SOCK_DGRAM, indica que será UDP.
server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) 

# IP e porta que o servidor deve aguardar a conexão
server.bind((UDP_IP, UDP_PORT)) 
print("Server listening on port %d" % (UDP_PORT)) 
 
while True:
    data, addr = server.recvfrom(BUFFER_SIZE)
    messageFromClient = data.decode(ENCODING)
    
    if messageFromClient == "quit":
        print("Quitting...")
        server.close()
        break
    
    print("New message from client: ", addr)
    print (messageFromClient)

    messageToClient = input("Enter your message for the client: ")    
    server.sendto(messageToClient.encode(ENCODING), (addr[0], addr[1]))

    if messageToClient == "quit":
        print("Quitting...")
        server.close()
        break