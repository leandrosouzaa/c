#include <stdio.h>

float numeros[5][5];

void readMatriz() {
   int i, j;
   for(i=0; i < 5; i++) {
      for(j=0; j < 5; j++) {
         printf("Matriz [%d][%d]: ", i, j);
         scanf("%f", &numeros[i][j]);
      }
   }
}

int scrollMatrix() {
   int i, j, posicaoMaior[2] = {0}, posicaoMenor[2] = {0}, maiorLinha = 0, menorColuna = 0;
   float total = 0, somaLinhas[5] = {0}, somaDiags[2] = {0}, somaColunas[5] = {0};

   printf("\nMatriz informada:");
   for(i=0; i < 5; i++) {
      printf("\n");
      for(j=0; j < 5; j++) {
         printf("\t%0.2f", numeros[i][j]);
         total+= numeros[i][j];
         somaLinhas[i]+= numeros[i][j];
         somaColunas[i]+= numeros[j][i];

         if (numeros[i][j] > numeros[posicaoMaior[0]][posicaoMaior[1]]) {
            posicaoMaior[0] = i;
            posicaoMaior[1] = j;
         }

         if (numeros[i][j] < numeros[posicaoMenor[0]][posicaoMenor[1]]) {
            posicaoMenor[0] = i;
            posicaoMenor[1] = j;
         } 
      }
      if (somaLinhas[i] > somaLinhas[maiorLinha]) {
         maiorLinha = i;
      }
      if (somaColunas[i] < somaColunas[menorColuna]) {
         menorColuna = i;
      }

      somaDiags[0]+= numeros[i][i];
      somaDiags[1]+= numeros[i][4-i];
   }
 
   printf("\n\nRELATÓRIO FINAL\n\n");
   
   printf("Maior Elemento da Matriz: %0.2f.\n", numeros[posicaoMaior[0]][posicaoMaior[1]]);
   printf("Posição do Maior Elemento: Matriz[%d][%d].\n\n", posicaoMaior[0], posicaoMaior[1]);
   
   printf("Menor Elemento da Matriz: %0.2f.\n", numeros[posicaoMenor[0]][posicaoMenor[1]]);
   printf("Posição do Menor Elemento: Matriz[%d][%d].\n\n", posicaoMenor[0], posicaoMenor[1]);
   
   printf("Linha com maior Soma: %d com %0.2f.\n", maiorLinha + 1, somaLinhas[maiorLinha]);
   printf("Coluna com menor Soma: %d com %0.2f.\n\n", menorColuna + 1, somaColunas[menorColuna]);
   
   printf("Soma da primeira diagonal: %0.2f.\n", somaDiags[0]);
   printf("Soma da segunda diagonal: %0.2f.\n\n", somaDiags[1]);

   printf("Soma total da Matriz: %0.2f.", total);
}


int main() {
   printf("Matriz 5x5 - Leandro Ribeiro de Souza \n\n");

   readMatriz();
   scrollMatrix();

   return 0;
}
