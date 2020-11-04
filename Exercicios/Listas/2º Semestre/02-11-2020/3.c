#include <stdio.h>

int main() {
   printf("Página de um Livro - Leandro Ribeiro de Souza \n\n");

   char temp,pagina[40][80] = {0};
   int  tl, i, j,full, qtdVogais = 0, qtdConsoantes = 0, qtdPalavras = 0, tempCounter = 0;
   printf("\nDIGITE SEU TEXTO:\n\n");
   for (i=0; i < 40; i++) {
      tl=0;
      printf("%s%d |", i < 9 ? "0" : "",i + 1);
      do {
         scanf("%c", &pagina[i][tl]);
      } while(tl < 80 && pagina[i][tl++] != 10);
      if (tl < 80) 
         tl--;
   }

   printf("\nTEXTO DIGITADO: \n\n");
   for(i=0; i < 40; i++) {
      tempCounter = 0;
      printf("%s%d |", i < 9 ? "0" : "",i + 1);
      for(j=0; j < 80; j++) {
         temp = pagina[i][j];
         // verifica se é letra
         if ((temp > 64 && temp < 91) || (temp > 96 && temp < 123)) {
            tempCounter++;
            // verifica se é vogal
            if (temp==65||temp==69||temp==79||temp==73||temp==85||temp==97||temp==101||temp==105||temp==111) {
               qtdVogais++;
            } else {
               qtdConsoantes++;
            }
         }
         if ((temp != ' ' && (pagina[i][j + 1] == ' ' || pagina[i][j+1] == 45|| temp == 10 || tempCounter == 80))) {
            qtdPalavras++;
         }
         printf("%c", temp);
      }

      if ((pagina[i][79] != 0 && pagina[i][79] != 10)) {
         printf("\n");
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Vogais: %i.\n", qtdVogais);
   printf("Quantidade de Consoantes: %i.\n", qtdConsoantes);
   printf("Quantidade de Palavras: %i.\n", qtdPalavras);
   return 0;
}
