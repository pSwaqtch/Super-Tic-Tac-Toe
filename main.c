#include "header.h"

struct Player player[2];

int main() {
    clearScreen();
    printf("Made with <3 by KRUPAL \n                  ~pSwaqtch\n\n");
    
    for (int i = 0; i < 2; ++i) {
        initializePlayer(&player[i]);
    }

    getGameData();

    clearScreen();
    toss();

    char gameBoard[3][3][3][3], superBoard[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            superBoard[i][j]=' ';
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    gameBoard[i][j][k][l] = ' ';
                }
            }
        }
    }

    int superIndex=0, localIndex=0;
    bool isWin = false;

    while(!isWin){
        int i = (player[0].isTurn) ? 0 : 1;

        printf("\nTurn for %s (%c) =>\n",player[i].name,player[i].token );
        superIndex = superInput(superBoard, localIndex);

        printLocalBoard(gameBoard,superIndex);
        localIndex = localInput(gameBoard, superIndex);

        markBoard(gameBoard,superIndex,localIndex);
        
        isLocalWin(gameBoard,superBoard,superIndex,&isWin);
        
        clearScreen();
        printGameBoard(gameBoard);

        switchPlayer();
    }

    switchPlayer();
    gameResult();
    endGame();

    clearScreen();
    return 0;
}