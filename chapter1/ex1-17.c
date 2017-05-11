#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[]);
void copy(char to[], int start, char from[]);

int main() {
	int len, max, length;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 80;
	length = 0;
	while ((len = mygetline(line)) > 0)
		if (len > max) {
			copy(longest, length, line);
			length = length + len;
		}
	printf("%s", longest);
	return 0;
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

void copy(char to[], int start, char from[]) {
	int i;
	i = 0;
	while ((to[start] = from[i]) != '\0') {
		++i;
		++start;
	}

}
