#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * rot13(const char *str){
	int size = 20;
	int pos = 0;
	char *rotated = malloc(size * sizeof(char));

	while(str[pos] != '\0'){
		if(str[pos] >= 'A' && str[pos] <= 'M')
			rotated[pos] = str[pos] + 13;
		else if(str[pos] >= 'a' && str[pos] <= 'm')
			rotated[pos] = str[pos] + 13;
		else if(str[pos] >= 'N' && str[pos] <= 'Z')
			rotated[pos] = str[pos] - 13;
		else if(str[pos] >= 'n' && str[pos] <= 'z')
			rotated[pos] = str[pos] - 13;
		else
			rotated[pos] = str[pos];
		pos++;
		if(pos >= size){
			size += 20;
			rotated = realloc(rotated, size);
		}
	}

	// don't forget that \0
	rotated[pos] = '\0';

	return rotated;	
}

int main(int argc, char **argv){
	int ignoreNewline = 0;
	int size = 50;
	char *input = malloc(size * sizeof(char));
	int pos = 0;

	printf("Enter the string you wish to ROT13, ending with a newline\n");

	while((input[pos] = getchar()) != EOF){
		if(input[pos] == '\n' && ignoreNewline == 0)
			break;
		
		pos++;	
		if(pos >= size){
			size += 50;
			input = realloc(input, size);
		}
	}
	// Adding null terminator
	if(ignoreNewline && pos <= size)
		input[pos + 1] = '\0';
	else
		input[pos] = '\0';
	
	char *encoded = rot13(input);

	printf("%s\n", encoded);
	free(input);
	free(encoded);
	return 0;
}

