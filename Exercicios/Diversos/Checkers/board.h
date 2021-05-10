typedef struct sBoard {
   int board[8][8];
} Board;

typedef struct sCoordinate {
   int x, y;
} Coordinate;

void init(Board *board) {
   int cont = 0, i = 0;
   for(i=0; i < 2; i++) {
      for(int j=0; j < 8; j++) {
         if(cont % 2 == 0) {
            board->board[i][j] = 1;
         } else {
            board->board[i][j] = 0;
         }
         cont++;
      }
      cont++;
   }
   cont++;
   for(i; i < 6; i++) {
      for(int j=0; j < 8; j++) {
         board->board[i][j] = 0;
         cont++;
      }
   }
   for(i; i < 8; i++) {
      for(int j=0; j < 8; j++) {
         if(cont % 2) {
            board->board[i][j] = 2;
         } else {
            board->board[i][j] = 0;
         }
         cont++;
      }
      cont++;
   }
}

void printSquare(Coordinate coord, int status, int color) {
   if(color == 0) {
      int i = 0;
      if(status) {
         gotoxy(coord.x+2, coord.y + 2 + i);
         printf("@@@@@");
         
         for(i; i < 4; i++) {
            gotoxy(coord.x+2, coord.y + 2 + i);
            printf("@   @");
         }
         gotoxy(coord.x+2, coord.y + 2 + i);
         printf("@@@@@");
      } else {
         for(int i = 0; i < 5; i++) {
            gotoxy(coord.x+2, coord.y + 2 + i);
            printf("@@@@@");
         }
      }
   } else {
      int i = 0;
      if(status) {
         gotoxy(coord.x+2, coord.y + 2 + i);
         printf("     ");

         for(i; i < 4; i++) {
            gotoxy(coord.x+2, coord.y + 2 + i);
            printf(" @@@ ");
         }

         gotoxy(coord.x+2, coord.y + 2 + i);
         printf("     ");
      } else {
         for(int i = 0; i < 5; i++) {
            gotoxy(coord.x+2, coord.y + 2 + i);
            printf("     ");
         }
      }
   }
}

void printBoard(Board *board) {
   system("clear");
   
   bool color = true;
   Coordinate coord;
   int counter = 0;   
   for(int i=0; i < 42; i++) {
      gotoxy(1, i +1);
      printf("|");
      gotoxy(42, i +1);
      printf("|");
      gotoxy(i+1, 1);
      printf("-");
      gotoxy(i+1, 42);
      printf("-");
   };
   gotoxy(1, 1);
   printf("+");
   gotoxy(1, 42);
   printf("+");
   gotoxy(42, 1);
   printf("+");
   gotoxy(42, 42);
   printf("+");

   for(int i=0; i < 8; i++) {
      coord.y = (i * 5);
      counter++;
      for(int j=0; j < 8; j++) {
         coord.x = (j * 5);
         printSquare(coord, board->board[i][j], counter % 2);
         counter++;
      }
   }
   gotoxy(1, 45);
};