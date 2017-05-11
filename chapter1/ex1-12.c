# include <stdio.h>

/* 以每行一个单词的形式打印其输入*/
int main() {
	int c;

	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			printf("\n");
			continue;
		}
		putchar(c);
	}

}
