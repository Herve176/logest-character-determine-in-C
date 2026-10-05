#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void find_longest_word(char *longest_word);

int main() {
    char longest_word[MAXLINE];

    // Correction ici : On initialise le premier élément à \0
    longest_word[0] = '\0';

    find_longest_word(longest_word);

    if (strlen(longest_word) > 0) {
        printf("Le mot le plus long : %s\n", longest_word);
        printf("Longueur : %lu\n", strlen(longest_word));
    } else {
        printf("Aucun mot saisi.\n");
    }

    return 0;
}

void find_longest_word(char *longest_word) {
    int chartext;
    char current_word[MAXLINE];
    int current_length = 0;
    int longest_length = 0;

    while ((chartext = getchar()) != EOF) {
        if (chartext != ' ' && chartext != '\n' && chartext != '\t') {
            if (current_length < MAXLINE - 1) {
                current_word[current_length] = (char)chartext;
                current_length++;
            }
        } else {
            if (current_length > 0) {
                current_word[current_length] = '\0';

                if (current_length > longest_length) {
                    longest_length = current_length;
                    strcpy(longest_word, current_word);
                }
                current_length = 0;
            }
        }
    }

    if (current_length > longest_length) {
        current_word[current_length] = '\0';
        strcpy(longest_word, current_word);
    }
}
