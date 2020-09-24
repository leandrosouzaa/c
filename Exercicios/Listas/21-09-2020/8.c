#include <stdio.h>

int main() {
   printf("Nome Completo - Leandro Ribeiro de Souza \n\n");

   char nome[30];
   int tl = 0, qtdPalavras = 0, qtdEspacos = 0, i;

   do {
      scanf("%c", &nome[tl]);
   } while(tl< 20 && nome[tl++] != 10);
   if (tl < 20 ) {
      tl--;
   }

   for (i = 0; i < tl; i++) {
      if ((nome[i] == ' ' && nome[i + i] != ' ') && nome[i - 1] != ' ') {
         qtdEspacos++;
      }
   }
   for (i = 0; i < tl; i++) {
      if ((nome[i] != ' ' && nome[i + 1] == ' ')) {
         qtdPalavras++;
      }
   }
   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Palavras: %i.\n", qtdPalavras + 1);
   printf("Quantidade de Espaços: %i.\n", qtdEspacos);
   printf("Primeiro Nome: ");
   for(i=0;(i < tl && nome[i] != ' ');i++) {
      printf("%c", nome[i]);
   }

   return 0;
}
