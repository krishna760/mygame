// C program for creating & simulating a Snake & Ladder Game
// Coded by: Krishna Bhandari. /\('-')/\ 

// Constraints and Rules
/*
1. The game will begin with any dice value.
2. If a 6(six) appears, then a chance is awarded to that player.
3. Only the location of the current player is shown on the board,
   the location of the other player is mentioned below the board.
4. Snakes: 99 to 1, 65 to 40, 25 to 9.
5. Ladders: 70 to 93, 60 to 83, 13 to 42.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to generate random dice values from 1 to 6
int random() {
    int rem;
A:
    rem = rand() % 7;  // Generate number between 0 and 6
    if (rem == 0)      // If 0, reroll (dice values start from 1)
        goto A;
    else
        return rem;
}

// Function to display the current board state with the player's position
void displaychart(int curp, char player[4]) {
    int i, j, t, c, sft = 0, diceres;

    // If player reaches position 100, they win
    if (curp == 100) {
        printf("*****Congratulations*****\n\n\nPlayer %s wins\n", player);
        scanf("%*s");  // Wait for user input before exit
        exit(0);
    }

    // Print board from 100 to 1 in a zigzag pattern
    for (i = 10; i > 0; i--) {
        t = i - 1;
        if ((sft % 2) == 0) {  // Even row: right to left
            c = 0;
            for (j = 10; j >= 1; j--) {
                diceres = (i * j) + (t * c++);
                if (curp == diceres)
                    printf("%s\t", player);  // Show player position
                else
                    printf("%d\t", diceres);  // Show cell number
            }
            sft++;
        } else {  // Odd row: left to right
            c = 9;
            for (j = 1; j <= 10; j++) {
                diceres = (i * j) + (t * c--);
                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

// Main function - game loop
void main() {
    int dice, cur_pos1 = 0, cur_pos2 = 0;
    char ch;

    while (1) {
        // Game title and rules
        printf("\t\t** SNAKE AND LADDER GAME **\n\t\tCoded By Krishna Bhandari\n");
        printf("Snakes:- 25 to 9,\t65 to 40,\t99 to 1.\n");
        printf("Ladders:- 13 to 42,\t60 to 83,\t70 to 93.\n");

        // Player turn options
        printf("Choose your option\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Exit\n");

        scanf("%s", &ch);

        switch (ch) {
            case '1':
                dice = random();  // Roll dice for Player 1
                system("cls");    // Clear screen (for Windows)
                printf("\t\t\t\tDice = %d\n\n", dice);

                if (dice == 6)
                    printf("Dice=6: You have earned a chance to play one more time.\n");

                cur_pos1 += dice;

                // Check if new position is valid (≤ 100)
                if (cur_pos1 < 101) {
                    // Handle snake and ladder cases for Player 1
                    if (cur_pos1 == 99) displaychart(1, "$P1$");
                    else if (cur_pos1 == 65) displaychart(40, "$P1$");
                    else if (cur_pos1 == 25) displaychart(9, "$P1$");
                    else if (cur_pos1 == 70) displaychart(93, "$P1$");
                    else if (cur_pos1 == 60) displaychart(83, "$P1$");
                    else if (cur_pos1 == 13) displaychart(42, "$P1$");
                    else displaychart(cur_pos1, "$P1$");  // Normal move
                } else {
                    cur_pos1 -= dice;  // Revert move if exceeds 100
                    printf("Range exceeded of Player 1.\n");
                    displaychart(cur_pos1, "$P1$");
                }

                // Show other player’s position
                printf("Player 2 position is %d\n", cur_pos2);
                break;

            case '2':
                dice = random();  // Roll dice for Player 2
                system("cls");
                printf("\t\t\t\tDice = %d\n\n", dice);

                cur_pos2 += dice;

                if (cur_pos2 < 101) {
                    if (cur_pos2 == 99) displaychart(1, "$P2$");
                    else if (cur_pos2 == 65) displaychart(40, "$P2$");
                    else if (cur_pos2 == 25) displaychart(9, "$P2$");
                    else if (cur_pos2 == 70) displaychart(93, "$P2$");
                    else if (cur_pos2 == 60) displaychart(83, "$P2$");
                    else if (cur_pos2 == 13) displaychart(42, "$P2$");
                    else displaychart(cur_pos2, "$P2$");
                } else {
                    cur_pos2 -= dice;
                    printf("Range exceeded of Player 2.\n");
                    displaychart(cur_pos2, "$P2$");
                }

                printf("Player 1 position is %d\n", cur_pos1);
                break;

            case '3':  // Exit game
                exit(0);

            default:
                printf("Incorrect choice. Try Again\n");
        }
    }
}
