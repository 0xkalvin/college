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
    # Envia mensagem para servidor 
    client.send(messageToServer.encode(ENCODING))
    # Encerra chat
    if(messageToServer == "quit"):
        print("Quitting...")
        client.close()
        break

    # Recebe dados do servidor 
    data, addr = client.recvfrom(1024)
    messageFromServer = data.decode(ENCODING)
    # Caso servidor envie mensagem de quit, cliente se encerra
    if messageFromServer == "quit":
        client.close()
        print("Quitting...")
        break

    print ("Received message from server: \n", messageFromServer)


