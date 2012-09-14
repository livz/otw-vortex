/*
 * 0xbadc0ded.org Challenge #02 (2003-07-08)
 *
 * Joel Eriksson <je@0xbadc0ded.org>
 */


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long val = 31337;
unsigned long *lp = &val;

int main(int argc, char **argv)
{
        unsigned long **lpp = &lp, *tmp;
        char buf[128];

        if (argc != 2)
                exit(1);
        printf("lpp before: %8p\n", lpp);
        strcpy(buf, argv[1]);
        printf("lpp after: %8p\n", lpp);


        if (((unsigned long) lpp & 0xffff0000) != 0x08040000) {
                exit(2);
        }

        tmp = *lpp;
        **lpp = (unsigned long) &buf;
        *lpp = tmp;
        printf("here2\n");
        exit(0);

}
