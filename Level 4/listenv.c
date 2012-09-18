/* 
 * Test program to find the location of envirnment variables on stack.
 *  - test with/without ASLR
 * 
 * To disable ASLR: 
 * echo 0 > /proc/sys/kernel/randomize_va_space
 * 
 * To enable ASLR:
 * echo 2 > /proc/sys/kernel/randomize_va_space
 * 
 */

#include <stdio.h>

extern char **environ;

/* Return the current stack pointer */
unsigned long find_esp(void){
	// Copy stack pointer into EAX
    __asm__("mov %esp, %eax");
    
    // Return value of the function is in EAX
}

int  main() {
	char **env = NULL;
	
    for (env = environ; *env; ++env)
        printf("%p:\t%s\n", env, *env);

    unsigned long p = find_esp(); 
    printf ("Current stack pointer: Ox%lx\n" , p) ;
        
    return 0;
}