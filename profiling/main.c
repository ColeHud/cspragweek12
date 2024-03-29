#include <stdio.h>
#include <string.h>

#define LONG_TIME (0xffffffff/8)

void child1(void) {
	printf("\n     Inside child1()\n");
	int i = 0;

	for( ; i < (LONG_TIME * 2); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void child2(void) {
	int i = 0;

	for( ; i < 16; i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void parent(void) {
	printf("\n   Inside parent \n");
	int i = 0;

	for (i=0 ; i < (LONG_TIME); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}
	child1();

	printf("\n     Starting child2() loop\n");
	for (i=0 ; i < (LONG_TIME/2); i++) {
		child2();
	}

	return;
}

static void no_children(void) {
	printf("\n   Inside no_children \n");
	int i = 0;

	for (i=0; i < (LONG_TIME * 5); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

int main(int argc, char **argv) {
	printf("\n Inside main()\n");
	int i = 0;

	parent();
	no_children();

	printf("\n Exiting \n");
	return 0;
}
