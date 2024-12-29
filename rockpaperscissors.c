#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game() {
    char *choices[] = {"rock", "paper", "scissors"};
    char user_choice[10];
    int computer_choice;
    char play_again;

    srand(time(0));

    do {
        printf("Enter rock, paper, or scissors: ");
        scanf("%s", user_choice);

        computer_choice = rand() % 3;

        printf("Computer chose: %s\n", choices[computer_choice]);

        if ((strcmp(user_choice, "rock") == 0 && computer_choice == 2) ||
            (strcmp(user_choice, "paper") == 0 && computer_choice == 0) ||
            (strcmp(user_choice, "scissors") == 0 && computer_choice == 1)) {
            printf("You win!\n");
        } else if ((strcmp(user_choice, "rock") == 0 && computer_choice == 1) ||
                   (strcmp(user_choice, "paper") == 0 && computer_choice == 2) ||
                   (strcmp(user_choice, "scissors") == 0 && computer_choice == 0)) {
            printf("You lose!\n");
        } else if ((strcmp(user_choice, "rock") == 0 && computer_choice == 0) ||
                   (strcmp(user_choice, "paper") == 0 && computer_choice == 1) ||
                   (strcmp(user_choice, "scissors") == 0 && computer_choice == 2)) {
            printf("It's a tie!\n");
        } else {
            printf("Invalid input. Please enter rock, paper, or scissors.\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');
}

int main() {
    play_game();
    return 0;
}
