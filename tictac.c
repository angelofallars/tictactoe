#include <stdio.h>

#define clear() printf("\033[H\033[J")

int check_winnner(char board[3][3]);

/* A tic tac toe game made in C. */
int main(int argc, char* argv[]) {
    char board[3][3];
    char player_char;
    int user_input;
    int turn = 0;

    // Initialize the tic-tac-toe board with empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    while (1) {
        clear();

        printf("┌───┬───┬───┐\n");
        printf("│ %c │ %c │ %c │\n", board[0][0], board[0][1], board[0][2]);
        printf("├───┼───┼───┤\n");
        printf("│ %c │ %c │ %c │\n", board[1][0], board[1][1], board[1][2]);
        printf("├───┼───┼───┤\n");
        printf("│ %c │ %c │ %c │\n", board[2][0], board[2][1], board[2][2]);
        printf("└───┴───┴───┘\n");

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

    return 0;
}

// Check the winner of the game
int check_winnner(char board[3][3]) {
    return 0;
}
