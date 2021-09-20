#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

int check_winnner(char board[3][3]);

/* A tic tac toe game made in C. */
int main(int argc, char* argv[]) {
    char board[3][3];
    char player_char;
    int user_input;
    int turn = 0;
    int winner = -1;

    // Initialize the tic-tac-toe board with empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    while (winner == -1) {
        clear();
        winner = check_winnner(board);

        printf("┌───┬───┬───┐\n");
        printf("│ %c │ %c │ %c │\n", board[0][0], board[0][1], board[0][2]);
        printf("├───┼───┼───┤\n");
        printf("│ %c │ %c │ %c │\n", board[1][0], board[1][1], board[1][2]);
        printf("├───┼───┼───┤\n");
        printf("│ %c │ %c │ %c │\n", board[2][0], board[2][1], board[2][2]);
        printf("└───┴───┴───┘\n");

        if (winner != -1) {
            break;
        }

        // turn 0 is player 1, turn 1 is player 2
        if (turn == 0) {
            player_char = 'x';
            turn = 1;
        }
        else {
            player_char = 'o';
            turn = 0;
        }

        printf("(%c turn) Place your piece from 1-9!\n", player_char);

        while (1) {

            // Get the position of the new piece
            do {
                printf("$ ");
                scanf("%i", &user_input);
            }
            while (user_input < 1 || user_input > 9);

            // Check if the position is occupied
            if (board[user_input / 3][user_input % 3 - 1] == ' ') {
                // Place the board from 1-9, left-to-right then top-to-bottom
                board[user_input / 3][user_input % 3 - 1] = player_char;
                break;
            }

            else {
                printf("Position already occupied.\n");
                continue;
            }
        }
    }

    if (winner == 0) {
        printf("Player 1 won!\n");
    }
    else if (winner == 1) {
        printf("Player 2 won!\n");
    }

    return 0;
}

/* Check the winner of the game
   -1 means no winner
    0 means player 1 won
    1 means player 2 won
   -2 means draw
  */
int check_winnner(char board[3][3]) {
    char *pieces = malloc(sizeof(char) * 2);
    pieces[0] = 'x';
    pieces[1] = 'o';

    // i is the index of the player
    for (int i = 0; i < 2; i++) {

        // Horizontal pieces
        for (int j = 0; j < 3; j++) {
            if (board[j][0] == pieces[i]
                && board[j][0] == board[j][1]
                && board[j][1] == board[j][2]) {
                free(pieces);
                return i;
            }
        }

        // Vertical pieces
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == pieces[i]
                && board[0][j] == board[1][j]
                && board[1][j] == board[2][j]) {
                free(pieces);
                return i;
            }
        }
    }

    free(pieces);
    return -1;
}
