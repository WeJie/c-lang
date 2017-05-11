# include <stdio.h>

int main() {
  int c;
	int space;

	space = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') { 
			if ((++space) > 1)
				continue;
			putchar(c);
		} else {
			space = 0;
			putchar(c);
		}
	}

}
