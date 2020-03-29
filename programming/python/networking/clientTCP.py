import socket

TCP_IP = '192.168.15.14'    # Endereço IP do servidor 
TCP_PORT = 24000           # Porta disponibilizada pelo servidor
BUFFER_SIZE = 1024

# Criação de socket TCP do cliente
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor em IP e porta especifica 
client.connect((TCP_IP, TCP_PORT))

while True:
    message  = input("Enter your message for the server: ")
    # Envia mensagem para servidor 
    client.send(message.encode('UTF-8'))
    # Encerra chat
    if(message == "quit"):
        print("Quitting...")
        client.close()
        break

    # Recebe dados do servidor 
    data, addr = client.recvfrom(1024)
    # Caso servidor envie mensagem de quit, cliente se encerra
    if data.decode('UTF-8') == "quit":
        client.close()
        print("Quitting...")
        break

    print ("received message: ", data)


