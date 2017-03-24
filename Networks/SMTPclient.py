from socket import *

msgSize = 10000
failed = True

#create the socket
s = socket(AF_INET, SOCK_STREAM)

#connect to the SMTP server 
s.connect(("mail.barak.net.il", 25))

#check if succeeded
lastmsg = s.recv(msgSize)
if lastmsg.split(' ')[0] == "220":
    #send HELO
    s.sendall("HELO " + gethostname() + "\r\n")

    #check return
    lastmsg = s.recv(msgSize)
    if lastmsg.split(' ')[0] == "250":
        #From
        src = raw_input("please enter source mail address:\n")
        s.sendall("MAIL From:<" + src + ">\r\n")

        #check return
        lastmsg = s.recv(msgSize)
        if lastmsg.split(' ')[0] == "250":
            #To
            dst = raw_input("please enter destination mail address:\n")
            s.sendall("RCPT To:<" + dst + ">\r\n")
            
            #check return
            lastmsg = s.recv(msgSize)
            if lastmsg.split(' ')[0] == "250":
                #data
                s.sendall("DATA\r\n")

                #check return
                lastmsg = s.recv(msgSize)
                if lastmsg.split(' ')[0] == "354":
                    #sending the mail
                    msg = ""
                    s.sendall("From: " + src + "\r\n" +
                              "To: " + dst + "\r\n" +
                              "Subject: " + raw_input("please enter subject of mail:\n") + "\r\n")

                    print "please enter the mail:\n"
                    
                    while msg != ".":
                        msg = raw_input("")
                        s.sendall(msg + "\r\n") 

                    #check return
                    lastmsg = s.recv(msgSize)
                    if lastmsg.split(' ')[0] == "250":
                        print "mail sent!\n"
                        failed = False
                              
    #send QUIT
    s.sendall("quit\r\n")
    s.recv(msgSize)

if failed:
    print "Failed to connect to server!\nDo something!!!\nLast msg:\n" + lastmsg

#close the socket
s.close()

print "bye bye!"
