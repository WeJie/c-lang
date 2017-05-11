#include <stdio.h>

#define MAXLINE 20
#define TABLEN 2

void entab(char str[]);
int mygetline(char str[]);
void copy(char to[], char from[]);

int main() {
	int len;
	char line[MAXLINE];

	while((len = mygetline(line)) > 0) {
		entab(line);
		printf("%s\n", line);
	}

	return 0;
}

int mygetline(char s[]) {
	int c, i;

	for (i = 0; (c=getchar()) != EOF && c!='\n'; i++) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/*
 * four machine-config on dealing the sequence
 * M1 normal char
 * M2 first space after the normal char
 * M3 space after space
 * M4 normal char after space 
 * */
void entab(char str[]) {
	int i, k, count;
	char temp[MAXLINE];

	i = k = count = 0;
	while(str[i] != '\0') {
		if (str[i] == ' ') {
			count++;
			if (! (i > 1 && str[i - 1] != ' ') && (count  == TABLEN)) {
				// M3
				temp[k] = '\t';
				printf("tab\n");
				count = 0;
				k++;
			} 
		} else {
			if (i > 1 && str[i - 1] == ' ') {
				// M4
				while(count > 0) {
					temp[k] = ' ';
					k++;
					count--;
				}
			}

			// M1
			temp[k] = str[i];
			k++;
		}
		// M2
		i++;
	}
	temp[k] = '\0';
	k++;

	copy(str, temp); 
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
