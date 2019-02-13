#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* buf;
unsigned int buf_s;

char** pats;
unsigned int pats_s;

long* outarr;
unsigned long outarr_s;

void memInit();
void freeAll();
unsigned short isInPatternList(char*);
unsigned int patternIndex(char*);
void pushPattern(char*);
void pushToPattern(char);
void clearPattern();

int main(void) {

	memInit();

	clearPattern(); // unneccesary?

	int scanf_r = 0;
	char scanf_buf = (char)0;

	while( scanf("%c", &scanf_buf) >= 0 ) {

		if(isInPatternList(buf)) {
			pushToPattern(scanf_buf);
		} else {
			
		}

	}

	freeAll();

	return 0;

}

void memInit() {

	buf_s = 2;

	buf = malloc(buf_s);
	memset(buf, (char)0, buf_s);

	pats_s = 256;

	pats = malloc( sizeof(char*) * pats_s );

	for(int i = 0; i < pats_s; i++) {
		pats[i] = malloc(1);
		pats[i][0] = (char)i;
	}

}

void freeAll() {

	for(int i = 0; i < pats_s; i++)
		free(pats[i]);

	free(buf);
	free(pats);

}

unsigned short isInPatternList(char *toFind) {

	for(int pat_i = 0; pat_i < pats_s; pat_i++) {
		if(pat_i < 256) {
			if(pats[pat_i][0] == toFind[0]) return 1;
		} else {
			if(strcmp(toFind, pats[pat_i]) == 0) return 1;
		}
	}

	return 0;

}

unsigned int patternIndex(char *toFind) {

	for(int pat_i = 0; pat_i < pats_s; pat_i++) {
		if(pat_i < 256) {
			if(pats[pat_i][0] == toFind[0]) return pat_i;
		} else {
			if(strcmp(toFind, pats[pat_i]) == 0) return pat_i;
		}
	}

	return pats_s;

}

void pushPattern(char* pat) {

	pats_s++;
	pats = realloc(pats, sizeof(char*) * pats_s);
	pats[pats_s-1] = malloc(strlen(pat) + 1);

	memset(pats[pats_s-1], (char)0, strlen(pat) + 1);
	strcpy(pats[pats_s-1], pat);

}

void pushToPattern(char toPush) {

	buf_s++;
	buf = realloc(buf, buf_s);
	buf[buf_s-1] = (char)0;
	buf[buf_s-2] = toPush;

}

void clearPattern() {

	buf = realloc(buf, 2);
	memset(buf, (char)0, 2);
	buf_s = 2;

}
