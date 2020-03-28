import socket 

TCP_IP = '192.168.15.14'    # Endereço IP do servidor 
TCP_PORTA = 24000           # Porta disponibilizada pelo servidor
TAMANHO_BUFFER = 1024       # Definição do tamanho do buffer
 
# Criação de socket TCP
# SOCK_STREAM, indica que será TCP.
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# IP e porta que o servidor deve aguardar a conexão
server.bind((TCP_IP, TCP_PORTA))

#Define o limite de conexões. 
server.listen(1)

print("Server listening on port %d" % (TCP_PORTA)) 

# Aceita conexão 
conn, addr = server.accept()
print ('Address connected:', addr)

while 1:

    # Dados retidados da mensagem recebida de algum cliente
    data = conn.recv(TAMANHO_BUFFER)
    
    if data: 
        # Caso cliente envie uma mensagem de quit do chat, o servidor se encerra
        if data.decode('UTF-8') == "quit":
            print("Quitting...")
            conn.close()
            break
        
        print ("Received message: ", data)
        
        message  = input("Enter your message for the client: ")
        conn.send(message.encode())  
        
        # Encerra chat
        if message  == "quit":
            print("Quitting...")
            conn.close()
            break


    

