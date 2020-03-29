import socket

TCP_IP = '192.168.15.14'   
TCP_PORT = 24000   
BUFFER_SIZE = 1024
ENCODING = 'UTF-8'

# Criação de socket TCP do cliente
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor em IP e porta especifica 
client.connect((TCP_IP, TCP_PORT))

while True:
    messageToServer  = input("Enter your message for the server: ")
    client.send(messageToServer.encode(ENCODING))
    
    if(messageToServer == "quit"):
        print("Quitting...")
        client.close()
        break

    data, addr = client.recvfrom(1024)
    messageFromServer = data.decode(ENCODING)
    
    if messageFromServer == "quit":
        client.close()
        print("Quitting...")
        break

    print ("Received message from server: \n", messageFromServer)


