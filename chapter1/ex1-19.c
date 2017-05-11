#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[]);
void reverse(char s[], int length);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = mygetline(line)) > 0) {
		reverse(line, len);
		printf("after reverse: %s \n", line);
	}

	return 0;
}

void reverse(char str[], int len) {
	char temp;
	int j;

	while(j < len) {
		--len;
		temp = str[len];
		str[len] = str[j];
		str[j] = temp;
		++j;
	}
}

int mygetline(char s[]) {
	int c, i;

	for (i=0;(c=getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

