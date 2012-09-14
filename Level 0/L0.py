import socket
import struct

def solve():
    host = "vortex.labs.overthewire.org"
    port = 5842
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    s.connect((host, port))
    
    sum = 0
    for i in range(0,4):
        data = s.recv(4)
        num,  = struct.unpack("<I", data)
        sum += num
    print "Sum: %u" % (sum)
    
    s.send(struct.pack("<I",(sum & 0xFFFFFFFF)))
    level1 =  s.recv(1024)
    print level1

    s.close()
        
if __name__=="__main__":        
    solve()