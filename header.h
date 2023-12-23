#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct Player {
    char name[80];
    char token;
    int indexCount;
    int localWin;
    int SuperWin;
    bool isTurn;
    //int time;
};

extern struct Player player[2];

int main();

//input.c
void getGameData();
void readName(char *buffer, size_t bufferSize);
void initializePlayer(struct Player *player);
int superInput(char superBoard[3][3], int localIndex);
int localInput(char gameBoard[3][3][3][3], int superIndex );
void clearInputBuffer();

//gamePlay.c
void toss();
void markBoard(char gameBoard[3][3][3][3], int superIndex, int localIndex);
void isLocalWin(char gameBoard[3][3][3][3],char superBoard[3][3],int superIndex, bool *isWin);
void isSuperWin(char superBoard[3][3], bool *isWin);
void switchPlayer();
void gameResult();
void endGame();

void clearScreen();
void printSuperBoard(char superBoard[3][3]);
void printLocalBoard(char gameBoard[3][3][3][3], int superIndex);
void printGameBoard(char gameBoard[3][3][3][3]);

#endif /* HEADER_H */