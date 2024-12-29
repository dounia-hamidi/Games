#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_guessing_game() {
    int number_to_guess, guess, attempts = 0;

    srand(time(0));
    number_to_guess = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number_to_guess);
}

int main() {
    number_guessing_game();
    return 0;
}
