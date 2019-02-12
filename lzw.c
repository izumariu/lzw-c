#include <stdio.h>
#include <stdlib.h>

char* buf; 
unsigned int buf_s;

char** pats;
unsigned int pats_s;

long* outarr;
unsigned long outarr_s;

void allocInit();
void freeAll();

int main(void) {

	return 0;

}

void allocInit() {

	buf = malloc(2);
	pats = malloc(sizeof(char*)*256);

	for(int i = 0; i < 256; i++)
		pats[i] = malloc(1);

}

void freeAll() {

	for(int i = 0; i < 256; i++) 
		free(pats[i]);

	free(buf);
	free(pats);

}
