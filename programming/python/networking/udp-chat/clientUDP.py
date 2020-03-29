import socket  
  
UDP_IP = "192.168.15.14"  
UDP_PORT = 5005          
ENCODING = 'UTF-8'
BUFFER_SIZE = 1024

# Criação de socket UDP
# SOCK_DGRAM, indica que será UDP.
client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
    messageToServer  = input("Enter your message for the server: ")
    client.sendto(messageToServer.encode(ENCODING), (UDP_IP, UDP_PORT))

    if messageToServer == "quit":
        print("Quitting...")
        client.close()
        break

    data, addr = client.recvfrom(BUFFER_SIZE)
    messageFromServer = data.decode(ENCODING)

    if messageFromServer == "quit":
        print("Quitting...")
        client.close()
        break
    
    print("New message from server: \n", messageFromServer)
    

