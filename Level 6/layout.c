#include <stdio.h>

int main() {
    register int ebp asm("ebp");    
    
    char **env = *(char***)(ebp + 16);
    char **argv = *(char ***)(ebp + 12);
    int argc = *(int*)(ebp + 8);
    
    printf("[EBP + 16] - First element of env[] array: %s\n", env[0]);
    printf("[EBP + 12] - First element of argv[] array: %s\n", argv[0]); 
    printf("[EBP +  8] - Number of arguments (argc): %d\n", argc);
}