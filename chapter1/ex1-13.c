# include <stdio.h>

#define TOTAL 20

int main() {
	int c, i, j, wl;
	int wordlen[TOTAL];
	
	wl = 0;
	for (i = 0; i < TOTAL; i++)
		wordlen[i] = 0;
	
	while((c = getchar()) != EOF) {
		++wl;
		if (c == ' ' || c == '\n' || c == '\t') {
			++wordlen[wl-1];
			wl = 0;
		}
	}

	for (i = 0; i < TOTAL; i++) {
		printf("%d:", i);
		for (j = 0; j < wordlen[i]; j++)
			printf("|");
		printf("\n");
	}
}
