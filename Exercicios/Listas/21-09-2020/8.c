#include <stdio.h>

int main() {
   printf("Nome Completo - Leandro Ribeiro de Souza \n\n");

   char nome[30];
   int tl = 0, qtdPalavras = 0, qtdEspacos = 0, i;

   printf("Informe um nome: ");
   do {
      scanf("%c", &nome[tl]);
   } while(tl< 30 && nome[tl++] != 10);
   if (tl < 30 ) {
      tl--;
   }

   for (i = 0; i < tl; i++) {
      if ((nome[i] == ' ' && nome[i + i] != ' ') && nome[i - 1] != ' ') {
         qtdEspacos++;
      }

      if ((nome[i] != ' ' && nome[i + 1] == ' ')) {
         qtdPalavras++;
      }
   }
   
   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Palavras: %i.\n", qtdPalavras + 1);
   printf("Quantidade de Espaços: %i.\n", qtdEspacos);
   printf("Nome completo: ");
   for (i=0; i < tl; i++) {
      printf("%c", nome[i]);
   }

   printf("\nPrimeiro Nome: ");
   i = 0;
   while (i < tl && nome[i] != ' ') {
      printf("%c", nome[i]);
      i++;
   }

   return 0;
}
