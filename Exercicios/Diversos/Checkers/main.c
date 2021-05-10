#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "board.h"

int main() {
   printf("Checkers - Leandro Ribeiro de Souza \n\n");
   Board board;
   init(&board);
   // for(int i =0; i < 8; i++) {
      // for(int j = 0; j < 8; j++) {
         // printf("%d ", board.board[i][j]);
      // }
      // printf("\n");
   // }
   printBoard(&board);
   return 0;
}