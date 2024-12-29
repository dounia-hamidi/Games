#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define WORD_COUNT 5

// Predefined word list and lexical field
const char *wordList[WORD_COUNT] = {"Computer", "Software", "AI", "Technology", "Hack"};
const char *lexicalField = "Technology";

int main() {
    char guessedWord[50];
    int attempts = 0;

    // Seed the random number generator and select a random word
    srand(time(NULL));
    const char *selectedWord = wordList[rand() % WORD_COUNT];

    printf("Welcome to the Word Guessing Game!\n");
    printf("All words are related to the field of %s.\n\n", lexicalField);

    printf("You have %d attempts to guess the word.\n\n", MAX_ATTEMPTS);

    // Game loop
    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d/%d: Enter your guess: ", attempts + 1, MAX_ATTEMPTS);
        scanf("%49s", guessedWord);

        // Convert guessed word to lowercase for case-insensitive comparison
        for (int i = 0; guessedWord[i]; i++) {
            guessedWord[i] = tolower(guessedWord[i]);
        }

        // Convert selected word to lowercase for comparison
        char lowerSelectedWord[50];
        strcpy(lowerSelectedWord, selectedWord);
        for (int i = 0; lowerSelectedWord[i]; i++) {
            lowerSelectedWord[i] = tolower(lowerSelectedWord[i]);
        }

        if (strcmp(guessedWord, lowerSelectedWord) == 0) {
            printf("Congratulations! You guessed the word correctly: %s\n", selectedWord);
            return 0;
        } else {
            printf("Incorrect guess. Try again.\n");
        }

        attempts++;
    }

    printf("Sorry, you've used all your attempts. The correct word was: %s\n", selectedWord);
    return 0;
}
