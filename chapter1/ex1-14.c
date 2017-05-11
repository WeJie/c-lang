# include <stdio.h>

#define TOTAL 128 

int main() {
	int c, i, j;
	int wordlen[TOTAL];

	for (i = 0; i < TOTAL; i++)
		wordlen[i] = 0;

	while((c = getchar()) != EOF) {
		++wordlen[c];
	}

	for (i = 0; i < TOTAL; i++) {
		printf("%c:", i);
		for (j = 0; j < wordlen[i]; j++)
			printf("|");
		printf("\n");
	}
}
