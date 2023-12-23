#include "header.h"

void getGameData(){
    // User given values
    printf("Enter the name of: \nPlayer 1: ");
    readName(player[0].name, sizeof(player[0].name));

    printf("Player 2: ");
    readName(player[1].name, sizeof(player[1].name));

    printf("\nSelect the token for %s: ", player[0].name);
    scanf(" %c",&player[0].token);

    printf("\nSelect the token for %s: ", player[1].name);
    scanf(" %c",&player[1].token);
}

void readName(char *buffer, size_t bufferSize) {
    fgets(buffer, bufferSize, stdin);

    // Remove the newline character, if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void initializePlayer(struct Player *player) {
    // Default values
    player->token = 'X';
    player->indexCount = 0;
    player->localWin = 0;
    player->SuperWin = 0;
    player->isTurn = false;
}

int superInput(char superBoard[3][3], int localIndex){

    int col_s = (localIndex - 1) / 3;
    int row_s = (localIndex - 1) % 3;

    if( superBoard[col_s][row_s] == ' ' ){
        return localIndex;
    } else {
        printSuperBoard(superBoard);
        printf("Choose the Super box: ");
        int index = 0;
        while (1) {
            if (scanf("%d", &index) != 1) {
                printf("Enter a valid integer between 1 and 9 :");
                clearInputBuffer();
            } else if (index >= 1 && index <= 9) {

                col_s = (index - 1) / 3;
                row_s = (index - 1) % 3;

                if (superBoard[col_s][row_s] == ' '){
                //markIndex();
                    return index;
                }
                else{
                    printf("Choose a valid Super Index : ");
                }
            } else {
                printf("Enter a valid integer between 1 & 9 :");
            }

        }
    }
}

int localInput(char gameBoard[3][3][3][3], int superIndex ){

    printf("Choose the Local index: ");
    int index=0;

    while (1) {
        if (scanf("%d", &index) != 1) {
            printf("Enter a valid integer between 1 and 9 !\n");
            clearInputBuffer();
        } else if (index >= 1 && index <= 9) {
            
            int col_s = (superIndex - 1) / 3;
            int row_s = (superIndex - 1) % 3;

            int col_i = (index - 1) / 3;
            int row_i = (index - 1) % 3;
            
            if (gameBoard[col_s][row_s][col_i][row_i] == ' '){
                return index;
            }
            else{
            printf("Choose a valid Index : ");
            }

        } else {
            printf("Enter a valid integer between 1 and 9!\n");
        }
    
    }

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}