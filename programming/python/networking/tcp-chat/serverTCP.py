import socket 

TCP_IP = '192.168.15.14'
TCP_PORT = 24000 
BUFFER_SIZE = 1024
ENCODING = 'UTF-8'

# Criação de socket TCP
# SOCK_STREAM, indica que será TCP.
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# IP e porta que o servidor deve aguardar a conexão
server.bind((TCP_IP, TCP_PORT))

#Define o limite de conexões. 
server.listen(1)

print("Server listening on port %d" % (TCP_PORT)) 

# Aceita conexão 
conn, addr = server.accept()
print ('Address connected:', addr)

while True:

    # Dados retidados da mensagem recebida de algum cliente
    data = conn.recv(BUFFER_SIZE)
    if data: 
        messageFromClient = data.decode(ENCODING)

        # Caso cliente envie uma mensagem de quit do chat, o servidor se encerra
        if messageFromClient == "quit":
            print("Quitting...")
            conn.close()
            break
        
        print ("Received message from client \n", messageFromClient)
        
        messageToClient  = input("Enter your message for the client: ")
        conn.send(messageToClient.encode())  
        
        # Encerra chat
        if messageToClient  == "quit":
            print("Quitting...")
            conn.close()
            break


    

