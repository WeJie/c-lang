#include <stdio.h>

#define MAXLINE 20
#define TABLEN 2

void detab(char str[]); 
int mygetline(char str[]);
void copy(char to[], char from[]);

int main() {
	int len;
	char line[MAXLINE];

	while((len = mygetline(line)) > 0) {
		detab(line);
		printf("%s\n", line);
	}

	return 0;
}

int mygetline(char s[]) {
	int c, i;

	for (i = 0; (c=getchar()) != EOF && c!='\n'; i++)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

void detab(char str[]) {
	int i, k;
	char temp[MAXLINE];

	i = k = 0;
	while(str[i] != '\0') {
		if (str[i] == '\t') {
			for (int j = 0; j < TABLEN; j++) {
				temp[k+j] = ' ';
			}
			k = k + TABLEN;
			i++;
			continue;
		}
		temp[k] = str[i];
		i++;
		k++;
	}

	copy(str, temp); 
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
