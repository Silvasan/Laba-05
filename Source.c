
#include <stdio.h> 
#include <stdlib.h>

char string(int, char);
int main() {
	int i=0,j=0,k=0, is_it_equal_words = 0, counter_letters = 0, words_count = 0, word_length, str_length;
	printf("Enter a string:\n");
	char* str;
	if(string(&str_length, &str) ==(char)-1)
		return -1;
	char* word;
	printf("\nEnter a world:\n");
	if (string(&word_length, &word) == (char)-1)
		return -1;
	for (; str[i] != '\0'; i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			counter_letters++;
			if (!((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z'))) {
				if (counter_letters == word_length) {
					for (j = i - (counter_letters-1), k = word_length-1;  j <= i; j++, k--) {
						if (str[j] == word[k]) {
							is_it_equal_words++;
							if (is_it_equal_words == counter_letters) {
								words_count++;
								is_it_equal_words = 0;
								counter_letters = 0;
								break;
							}
						}
						else break;
					}
				}
				else counter_letters = 0;
			}
		}
	}
	printf("\nResult: %d", words_count);
	free(str);
	str = NULL;
	free(word);
 	word = NULL;
	getchar();
	return 0;
}

char string(int* len, char** array) {
	*len = 0;
	int maxlen = 1;
	char *s = (char*)malloc(sizeof(char));//empty string
	if (s == NULL) {
		printf("ERROR. Can't allocate memory");
		getchar();
		return-1;
	}
	char letter = getchar();
	while (letter != '\n') {
		s[(*len)++] = letter;
		if (*len >= maxlen) {
			maxlen *= 2;
			char *tmp = (char*)realloc(s, maxlen * sizeof(char));
			if (tmp == NULL) {
				printf("ERROR. Can't reallocate memory");
				getchar();
				return-1;
			}
		}
		letter = getchar();
	}
	s[*len] = '\0';
	*array = s;
	return *array;
}