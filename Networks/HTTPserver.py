from socket import *
import threading

msgSize = 10000
rootpath = raw_input("please enter root path of the server: ") + "\\"

def serveclient(client_s, client_addr):
    print str(client_addr) + " connected..."
    
    #GET request
    msg = client_s.recv(msgSize)

    #check if GET rquest
    if msg.split(' ')[0] == "GET":
        ans = ""
        print str(client_addr) + " asked for '" + msg.split(' ')[1] + "'"
        
        #openning the file
        try:
            f = open(rootpath + msg.split(' ')[1], 'r')
            data = f.read()
            ans = "HTTP/1.0 Document Follows\nContent-length " + str(len(data)) + "\n" + data
        except IOError:
            ans = "HTTP/1.0 404 Not Found"

        #returning the data
        client_s.sendall(ans)
    
    client_s.close()
    print str(client_addr) + " disconnected..."
    
def main(): 
    #server socket
    server_s = socket(AF_INET, SOCK_STREAM)

    server_s.bind(("0.0.0.0", 80))
    server_s.listen(5)

    connections = []

    while (1):
        #waiting to client 
        client_s, client_addr = server_s.accept()
        connection = threading.Thread(target=serveclient, args=(client_s, client_addr))
        connections.append(connection)
        connection.start()
    
    server_s.close()


if __name__ == "__main__":
    main()
