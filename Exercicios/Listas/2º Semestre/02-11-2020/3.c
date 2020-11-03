#include <stdio.h>

int main() {
   printf("Página de um Livro - Leandro Ribeiro de Souza \n\n");

   char temp,pagina[40][80] = {' '};
   int  tl, i, j,full, qtdVogais = 0, qtdConsoantes = 0, qtdPalavras;
   printf("\nDIGITE A PÁGINA ABAIXO\n\n");
   for (i=0; i < 40; i++) {
      tl=0;
      printf("%i |", i + 1);
      do {
         scanf(" %c", &pagina[i][tl]);
      } while(tl < 80 && pagina[i][tl++] != 10);
      if (tl < 80) 
         tl--;
   }

   for(i=0; i < 40; i++) {
      for(j=0; j < 80; j++) {
         temp = pagina[i][j];
         printf("\n");
         if (temp==65||temp==69||temp==79||temp==73||temp==85||temp==97||temp==101||temp==105||temp==111) {
            qtdVogais++;
         } else {
            if ((temp > 64 && temp < 91) || (temp > 96 && temp < 123)) {
               qtdConsoantes++;
            }
         }
         if ((pagina[i][j] != ' ' && pagina[i][j + 1] == ' ')) {
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
