#include "header.h"

void toss() {
    srand(time(NULL));
    int i = rand() % 2; 
    player[i].isTurn=true;
}

void markBoard(char gameBoard[3][3][3][3], int superIndex, int localIndex){
    int col_s = (superIndex - 1) / 3;
    int row_s = (superIndex - 1) % 3;

    int col_l = (localIndex - 1) / 3;
    int row_l = (localIndex - 1) % 3;

    int i = (player[0].isTurn) ? 0 : 1;
    gameBoard[col_s][row_s][col_l][row_l] = player[i].token;
}

void isLocalWin(char gameBoard[3][3][3][3], char superBoard[3][3], int superIndex, bool *isWin) {
    int col_s = (superIndex - 1) / 3;
    int row_s = (superIndex - 1) % 3;

    int q = (player[0].isTurn) ? 0 : 1;
    char token = player[q].token;

    if (superBoard[col_s][row_s] == ' ') {
        for (int k = 0; k < 3; k++) {
            if ((gameBoard[col_s][row_s][k][0] + gameBoard[col_s][row_s][k][1] + gameBoard[col_s][row_s][k][2] == 3 * token) ||
                (gameBoard[col_s][row_s][0][k] + gameBoard[col_s][row_s][1][k] + gameBoard[col_s][row_s][2][k] == 3 * token) ||
                (gameBoard[col_s][row_s][0][0] + gameBoard[col_s][row_s][1][1] + gameBoard[col_s][row_s][2][2] == 3 * token) ||
                (gameBoard[col_s][row_s][2][0] + gameBoard[col_s][row_s][1][1] + gameBoard[col_s][row_s][0][2] == 3 * token)) {

                player[q].localWin++;
                superBoard[col_s][row_s] = player[q].token;

                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        gameBoard[col_s][row_s][x][y] = player[q].token;
                    }
                }
            
                isSuperWin(superBoard,isWin);
                k=3;
            }
        }
    }
}

void isSuperWin(char superBoard[3][3], bool *isWin){
    int q = (player[0].isTurn) ? 0 : 1;
    char token = player[q].token;

    for (int k = 0; k < 3; k++) {
        if ((superBoard[k][0] + superBoard[k][1] + superBoard[k][2] == 3 * token) ||
            (superBoard[0][k] + superBoard[1][k] + superBoard[2][k] == 3 * token) ||
            (superBoard[0][0] + superBoard[1][1] + superBoard[2][2] == 3 * token) ||
            (superBoard[2][0] + superBoard[1][1] + superBoard[0][2] == 3 * token)) {
            player[q].SuperWin++;
            *isWin = !(*isWin);
        }
    }
}

void switchPlayer(){
    player[0].isTurn = !player[0].isTurn;
    player[1].isTurn = !player[1].isTurn;
}

void gameResult(){
    int i = (player[0].isTurn) ? 0 : 1;
    printf("%s WON !!!\n", player[i].name);
}

void endGame(){
    printf("\nEnter q to exit, 'enter' to play again...");
    clearInputBuffer();
    char c=getchar();
    if (c=='\n'){
        main();
    }else if (c=='q') {
        clearInputBuffer();
    }
}