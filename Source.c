#include <stdio.h> 
#include <stdlib.h>
char string(int, char);
int main() {
	int is_it_equal_words = 0, counter_letters = 0, words_count = 0, word_length, str_length;
	char *str, *word;
	printf("Enter a string:\n");
	string(&str_length, &str);
	printf("\nEnter a world:\n");
	string(&word_length, &word);
	for (int i = 0; str[i] != '\n'; i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			counter_letters++;
			if (!((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z'))) {
				if (counter_letters == word_length) {
					for (int j = i - (counter_letters-1), k = word_length-1;  j <= i; j++, k--) {
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
	str[3];
	while (str != NULL)
		free(str);
	for (int i = 0; i < word_length; i++)
		free(word[i]);
	free(word);
	getchar();
	return 0;
}
char string(int* len, char** array) {
	*len = 0;
	int maxlen = 1;
	char *s = (char*)malloc(sizeof(char));//empty string

	char letter = getchar();
	while (letter != '\n') {
		s[(*len)++] = letter;
		if (*len >= maxlen) {
			maxlen *= 2;
			s = (char*)realloc(s, maxlen * sizeof(char));
			if (*s == NULL) {
				printf("ERROR. Can't reallocate memory");
				getchar();
				return-1;
			}
		}
		letter = getchar();
	}
	s[*len] = '\n';
	s[(*len)+1] = '\0';
	*array = s;
	return 0;
}