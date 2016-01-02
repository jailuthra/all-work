#include<stdio.h>
#include<string.h>
#include<assert.h>

/* COMMENT STRIP */

int main (int argc, char * argv[])
{
	assert(argc > 1);
	FILE * fin;
	fin = fopen(argv[1], "r");
	if (!fin) {
		fprintf(stderr, "Could not open %s\n", argv[1]);
	}
	char ch = fgetc(fin);
	int mode = 0;
	/* 0: Default
	   1: Maybe comment's coming
	   2: Multi-line comment
	   3: Single-line comment
	**/
	/**/
	//test*/
	while (ch != EOF) {
		if (mode == 0) {
			if (ch == '/') {
				mode = 1;
			}
		}

		else if (mode == 1) {
			if (ch == '*') {
				mode = 2;
			}
			else if (ch == '/') {
				mode = 3;
			}
			else {
				mode = 0;
			}
		}

		else if (mode == 2) {
			if (ch == '*') {
				ch = fgetc(fin);
				if (ch == '/') {
					mode = 0;
					printf("\n");
				} else if (ch == '*') { 
					continue;
				} else {
					printf("*%c", ch);
				}
			} else {
				printf("%c", ch);		
			}
		}

		else if (mode == 3) {
			if (ch == '\n') {
				printf("%c");
				mode = 0;
			} else {
				printf("%c", ch);
			}
		}

		ch = fgetc(fin);
	}
	return 0;
}
