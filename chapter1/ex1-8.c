# include <stdio.h>

int main() {
	int c, nl, space, tab;
	
	nl = 0;
	space = 0;
	tab = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == ' ')
			++space;
		if (c == '\t')
			++tab;
	}

	printf("newline-num: %d, space-num: %d, tab-num: %d", nl, space, tab);
}


