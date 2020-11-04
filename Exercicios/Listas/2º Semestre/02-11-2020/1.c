#include <stdio.h>

int main() {
   printf("Matriz 5x5 - Leandro Ribeiro de Souza \n\n");

   int i, j, posicaoMaior[2] = {0, 0}, posicaoMenor[2] = {0,0}, colMaiorSoma = 0;
   float numeros[5][5], total = 0, soma[5], somaDiags[2];

   for(i=0; i < 5; i++) {
      for(j=0; j < 5; j++) {
         printf("Matriz [%d][%d]: ", i, j);
         scanf("%f", &numeros[i][j]);
      }
   }

   for(i=0; i < 5; i++) {
      soma[i] = 0;
      for(j=0; j < 5; j++) {
         total+= numeros[i][j];
         soma[i]+= numeros[i][j];

         if (numeros[i][j] > numeros[posicaoMaior[0]][posicaoMaior[1]]) {
            posicaoMaior[0] = i;
            posicaoMaior[1] = j;
         }

         if (numeros[i][j] < numeros[posicaoMenor[0]][posicaoMenor[1]]) {
            posicaoMenor[0] = i;
            posicaoMenor[1] = j;
         } 
      }
      if (soma[i] < soma[colMaiorSoma]) {
         colMaiorSoma = i;
      }
      somaDiags[0]+= numeros[i][i];
      somaDiags[1]+= numeros[i][4-i];
   }
 
   printf("\nRELATÓRIO FINAL\n");
   printf("Posição do Maior Elemento: Matriz[%d][%d].\n", posicaoMaior[0], posicaoMaior[1]);
   printf("Posição do Menor Elemento: Matriz[%d][%d].\n", posicaoMenor[0], posicaoMenor[1]);
   printf("Coluna com maior Soma: %d.\n", colMaiorSoma);
   printf("Soma da primeira diagonal: %0.2f.\n", somaDiags[0]);
   printf("Soma da segunda diagonal: %0.2f.\n", somaDiags[1]);
   printf("Soma total da Matriz: %0.2f.", total);

   return 0;
}
