#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int mygetline(char s[]);
int copy(char to[], int start, char from[]);
void myrstrip(char str[], int length);

int main() {
	int len, length, slen;
	char line[MAXLINE], allstr[MAXLINE];

	length = 0;
	while ((len = mygetline(line)) > 0) {
		myrstrip(line, len);
		slen = copy(allstr, length, line);
		length = length + slen;
	}

	printf("%s", allstr);
	return 0;
}

void myrstrip(char str[], int length) {
	int i;
	i = length - 1;
	while(str[i] == ' ' || str[i] == '\32' || str[i] == '\t' || str[i] == '\n') {
			str[i] = '\0';
			i--;
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

int copy(char to[], int start, char from[]) {
	int i;
	i = 0;
	while ((to[start] = from[i]) != '\0') {
		++i;
		++start;
	}
	return i;

}
