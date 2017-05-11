#include <stdio.h>

#define MAXLINE 100
#define WRAPLEN 5 

void wordwrapping(char str[]);
int mygetline(char str[]);
void copy(char to[], char from[]);


int main() {
	int len;
	char line[MAXLINE];

	while((len = mygetline(line)) > 0) {
		wordwrapping(line);
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

/**
 * three machine-config of four state on dealing the char sequence
 * M1: char and line length smaller than n
 * M2: line length equal to n and pre char is not space
 * M2: line length equal to n and pre char is space
 */
void wordwrapping(char str[]) {
	int i, k;
	char temp[MAXLINE];
	i = k = 0;

	while (str[i] != '\0') {
		if ((i+1) % WRAPLEN == 0) {
			if (str[i - 1] == ' ') {
				// M3
				while (temp[k - 1] == ' ' && k > 0) {
					k--;
				}
			} 	
			// M2
			temp[k] = str[i];
			k++;
			temp[k] = '\n';
		} else {
			// M1
			temp[k] = str[i];
		}
		k++;
		i++;
	}
	temp[k] = '\0';

	copy(str, temp);
}


void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
