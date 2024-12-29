#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void generate_random_numbers(int *numbers, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 100 + 1;
    }
}

void print_numbers(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void sort_numbers(int *numbers, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main() {
    int numbers[SIZE];
    int user_sorted[SIZE];
    int correct_sorted[SIZE];
    int correct_count = 0;

    generate_random_numbers(numbers, SIZE);

    printf("Welcome to the Number Sorting Game!\n");
    printf("Here are the random numbers:\n");
    print_numbers(numbers, SIZE);

    printf("Enter the numbers in ascending order:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &user_sorted[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        correct_sorted[i] = numbers[i];
    }
    sort_numbers(correct_sorted, SIZE);

    for (int i = 0; i < SIZE; i++) {
        if (user_sorted[i] == correct_sorted[i]) {
            correct_count++;
        }
    }

    printf("You got %d numbers in the correct position.\n", correct_count);
    printf("The correct sorted list is:\n");
    print_numbers(correct_sorted, SIZE);

    return 0;
}
