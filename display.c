#include "header.h"

void printGameBoard(char gameBoard[3][3][3][3]) {
    printf("╔═════════════════════════════════════════════════════════════════════════════════╗\n");
//  printf("║    Name                   ╭─────────────────────────╮                   Name    ║\n");
    printf("║%*s%s%*s╭─────────────────────────╮%*s%s%*s║\n", 4, "", player[0].name, 23 - strlen(player[0].name), "", 23 - strlen(player[1].name), "", player[1].name, 4, "");
    printf("║    Time : 00:00           │    Super Tic-Tac-Toe    │           Time : 00:00    ║\n");
    printf("║    Supers Won : %d         ╰─────────────────────────╯         Supers Won : %d    ║\n",player[0].localWin,player[1].localWin);
    printf("╠═════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                           ┃                         ┃                           ║\n");
    printf("║     ╭─────┬─────┬─────╮   ┃   ╭─────┬─────┬─────╮   ┃   ╭─────┬─────┬─────╮     ║\n");


    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            printf("║     ");
            for (int j = 0; j < 3; j++) {
                printf("│");
                for (int l = 0; l < 3; l++) {
                    printf("%3c  │", gameBoard[i][j][k][l]);
                }
                if(j<2)printf("   ┃   ");
            } printf("     ║\n");
            if(k<2)printf("║     ├─────┼─────┼─────┤   ┃   ├─────┼─────┼─────┤   ┃   ├─────┼─────┼─────┤     ║\n");
        }

                printf("║     ╰─────┴─────┴─────╯   ┃   ╰─────┴─────┴─────╯   ┃   ╰─────┴─────┴─────╯     ║\n");
        if(i<2){printf("║                           ┃                         ┃                           ║\n");
                printf("║  ━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━  ║\n");
                printf("║                           ┃                         ┃                           ║\n");
                printf("║     ╭─────┬─────┬─────╮   ┃   ╭─────┬─────┬─────╮   ┃   ╭─────┬─────┬─────╮     ║\n");
        }
    }   

    printf("║                           ┃                         ┃                           ║\n");
    printf("╠═══════════════════════════╦═════════════════════════╦═══════════════════════════╣\n");
    printf("║    Total Time : 00:00     ║ Made with ^ by pSwaqtch ║           ~ Krupal Virani ║\n");
    printf("╚═══════════════════════════╩═════════════════════════╩═══════════════════════════╝\n");
}

void printSuperBoard(char superBoard[3][3]) {
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃         SUPER BOARD       ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃                           ┃\n");
    printf("┃    ╔═════╦═════╦═════╗    ┃\n");
    for (int i = 0; i < 3; i++) {
        printf("┃    ║  ");
        for (int j = 0; j < 3; j++) {
            printf("%c", superBoard[i][j]);
            if (j<2) {
                printf("  ║  ");
            }
        }
        printf("  ║    ┃\n");
        if (i<2) {
            printf("┃    ╠═════╬═════╬═════╣    ┃\n");
        }
    }
    printf("┃    ╚═════╩═════╩═════╝    ┃\n");
    printf("┃                           ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void printLocalBoard(char gameBoard[3][3][3][3], int superIndex){
    int col_s = (superIndex - 1) / 3;
    int row_s = (superIndex - 1) % 3;

    printf("╔═══════════════════════╗\n");
    printf("║     LOCAL BOARD %d     ║\n",superIndex);
    printf("╠═══════════════════════╣\n");
    printf("║  ╭─────┬─────┬─────╮  ║\n");
    for (int i = 0; i < 3; i++) {
        printf("║  │  ");
        for (int j = 0; j < 3; j++) {
            printf("%c", gameBoard[col_s][row_s][i][j]);
            if (j<2) {
                printf("  │  ");
            }
        }
        printf("  │  ║\n");
        if (i<2) {
            printf("║  ├─────┼─────┼─────┤  ║\n");
        }
    }
    printf("║  ╰─────┴─────┴─────╯  ║\n");
    printf("╚═══════════════════════╝\n");
}

void clearScreen() {
    printf("\033[H\033[J");
}