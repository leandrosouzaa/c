#include <stdio.h>

int main() {
   printf("Página de um Livro - Leandro Ribeiro de Souza \n\n");

   char temp,pagina[3][10] = {' '};
   int  tl, i, j,full, qtdVogais = 0, qtdConsoantes = 0, qtdPalavras = 0, tempCounter = 0;
   printf("\nDIGITE SEU TEXTO:\n\n");
   for (i=0; i < 3; i++) {
      tl=0;
      printf("%s%d |", i < 9 ? "0" : "",i + 1);
      do {
         scanf("%c", &pagina[i][tl]);
      } while(tl < 10 && pagina[i][tl++] != 10);
      if (tl < 10) 
         tl--;
   }

   printf("\nTEXTO DIGITADO: \n\n");
   for(i=0; i < 3; i++) {
      tempCounter = 0;
      if (i > 0 && pagina[i-1][9] != NULL) {
         printf("\n");
      }
      printf("%s%d |", i < 9 ? "0" : "",i + 1);
      for(j=0; j < 10; j++) {

         temp = pagina[i][j];
         if (temp==65||temp==69||temp==79||temp==73||temp==85||temp==97||temp==101||temp==105||temp==111) {
            qtdVogais++;
            tempCounter++;
         } else {
            if ((temp > 64 && temp < 91) || (temp > 96 && temp < 123)) {
               qtdConsoantes++;
               tempCounter++;
            }
         }
         if ((pagina[i][j] != ' ' && (pagina[i][j + 1] == ' '|| pagina[i][j] == 10 || tempCounter == 10))) {
            qtdPalavras++;

         }

         printf("%c", temp);
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Vogais: %i.\n", qtdVogais);
   printf("Quantidade de Consoantes: %i.\n", qtdConsoantes);
   printf("Quantidade de Palavras: %i.\n", qtdPalavras);
   return 0;
}
