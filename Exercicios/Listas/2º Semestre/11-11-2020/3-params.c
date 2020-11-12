#include <stdio.h>


int readLicensePlate(char vetor[7], int tl) {
   printf("Informe uma placa do Mercosul: ");
   do {
      scanf("%c", &vetor[tl]);
      tl++;
   } while(tl < 7);
   if (tl < 7 ) 
      tl--;

   return tl;
}

void generateReports(char vetor[7], int tl) {
   int i, qtdNumeros = 0, qtdLetras = 0, indexPrimeiro = -1, indexUltimo;

   for(i=0; i < tl; i++) {
      if (vetor[i] >='0' && vetor[i] <= '9') {
         qtdNumeros++;
         if (indexPrimeiro == -1) {
            indexPrimeiro = i;
         }
         indexUltimo = i;
      } else if ((vetor[i] > 64 && vetor[i] < 91 )||(vetor[i] > 96 && vetor[i] < 123)) {
         qtdLetras++;
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Letras: %d.\n", qtdLetras);
   printf("Quantidade de Números: %d.\n", qtdNumeros);
   printf("Posição do primeiro número: %d.\n", indexPrimeiro + 1);
}

void showNumbers(char vetor[7], int tl) {
   int i;
   for(i=0; i < tl; i++) {
      if (vetor[i] >='0' && vetor[i] <= '9') 
         printf("%c", vetor[i]);
   }

}

void showLetters(char vetor[7], int tl) {
   int i;
   for(i=0; i < tl; i++) {
      if ((vetor[i] > 64 && vetor[i] < 91 )||(vetor[i] > 96 && vetor[i] < 123)) 
         printf("%c ", vetor[i]);
   }

}

int main() {
   char placa[7];
   int tl = 0;

   printf("Placa Mercosul - Leandro Ribeiro de Souza \n\n");

   tl = readLicensePlate(placa, tl);
   generateReports(placa, tl);

   printf("Números da placa: ");
   showNumbers(placa, tl);
   printf("\nLetras da placa: ");
   showLetters(placa, tl);
   return 0;
}
