// -- andrewg, original author was zen-parse :)
#include <stdlib.h>


int main(int argc, char **argv)
{
	printf("argc: %d\n", argc);
	if(argc) exit(0);
	printf("here\n");
	printf(argv[3]);
	exit(EXIT_FAILURE);
}
