#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* FILE SHREDDER */

int main (int argc, char * argv[])
{
	assert(argc > 1);
	FILE * fin;
	fin = fopen(argv[1], "r");
	if (!fin) {
		fprintf(stderr, "Could not open %s\n", argv[1]);
	}
	int i = 1;
	char outname[20];
	sprintf(outname, "shread_%d", i);
	FILE * fout = fopen(outname, "w");
	char ch = fgetc(fin);
	while (ch != EOF) {
		if (ch != '\n') {
			fputc(ch, fout);
		} else {
			fclose(fout);
			i++;	
			sprintf(outname, "shread_%d", i);
			fout = fopen(outname, "w");
		}
		ch = fgetc(fin);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}

