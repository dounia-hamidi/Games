#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
bool makeMove(char board[SIZE][SIZE], int row, int col, char player);
bool checkWinner(char board[SIZE][SIZE], char player);
bool isDraw(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char player1 = 'X', player2 = 'O';
    int row, col;
    bool game_over = false;

    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 is '%c', Player 2 is '%c'.\n\n", player1, player2);

    displayBoard(board);

    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        char currentPlayer = (turn % 2 == 0) ? player1 : player2;
        printf("Player %d (%c), enter your move (row and column): ", (turn % 2) + 1, currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > SIZE || col < 1 || col > SIZE || !makeMove(board, row - 1, col - 1, currentPlayer)) {
            printf("Invalid move. Try again.\n");
            turn--;
            continue;
        }

        displayBoard(board);

        if (checkWinner(board, currentPlayer)) {
            printf("Player %d (%c) wins!\n", (turn % 2) + 1, currentPlayer);
            game_over = true;
            break;
        }

        if (isDraw(board)) {
            printf("It's a draw!\n");
            game_over = true;
            break;
        }
    }

    if (!game_over) {
        printf("Game over!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("---");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

bool makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
