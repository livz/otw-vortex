#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    char* arg[] = {"ARG0", "ARG1", "ARG2", "ARG3", "ARG4", "ARG5", NULL};
    char* env[] = {"ENV0", "ENV1", "ENV2", "ENV3", NULL};

    execve("./layout",arg,env);
}
