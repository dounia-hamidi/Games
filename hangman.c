#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define WORD_LIST_SIZE 5

void choose_random_word(char *word) {
    const char *word_list[WORD_LIST_SIZE] = {"Computer", "Software", "Artificial", "Intelligence", "Technology", "Hack"};
    srand(time(0));
    strcpy(word, word_list[rand() % WORD_LIST_SIZE]);
}

void display_word(char *word, int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char word[20];
    int guessed[20] = {0};
    int attempts = 0;
    char guess;
    int correct_guess;

    printf("Welcome to Hangman!\n");
    printf("The words are related to the field of technology.\n");

    choose_random_word(word);

    while (attempts < MAX_ATTEMPTS) {
        display_word(word, guessed);
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        correct_guess = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            attempts++;
            printf("Incorrect guess. You have %d attempts left.\n", MAX_ATTEMPTS - attempts);
        }

        int all_guessed = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (!guessed[i]) {
                all_guessed = 0;
                break;
            }
        }

        if (all_guessed) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            return 0;
        }
    }

    printf("Sorry, you've run out of attempts. The word was: %s\n", word);
    return 0;
}
