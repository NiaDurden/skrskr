#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


char check(char str[])
{
	int i, length;
	length = strlen(str);
	if(length == 1) return 0;

	for(i = 0; i < length; i++)
	if(str[i] != str[(length - 1) - i]) return 0;

	return 1;
}

int main(int argc, char *argv[])
{
	FILE *file = argv[1];

	setlocale(LC_ALL, "rus");
	char str[80];
	char *estr;
	char *skr;

	if((file = fopen("text.txt", "r")) == NULL){
	puts("File not found!");
	return 1;
	}

	char *mass;
	mass = calloc(sizeof(char), 1000);
	skr = calloc(sizeof(char), 1000);

	while(1){
		estr = fgets(str, sizeof(str), file);
		if(estr == NULL){
			if(feof(file) != 0)
			break;
		}

		strcat(skr, str);
	}

	int i, j;
	for(i = 0, j = 0; skr[i]; ++i){
		if((skr[i] >= ' ' && skr[i] <= '/') || (skr[i] >= ':' && skr[i] <= ';') || (skr[i] >= ',' && skr[i] <= '-') || skr[i] == '\n')
			continue;
		mass[j] = skr[i];
		j++;
	}


	if(check(mass) == 1)
		printf("Yes, the string %s is a palindrome.\n", mass);
	else
		printf("No, a line is not palindromes.\n");

	free(mass);
	fclose(file);
	return 0;
}

