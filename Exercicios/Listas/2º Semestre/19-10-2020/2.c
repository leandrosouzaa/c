#include <stdio.h>

int main() {
   printf("Placa Mercosul - Leandro Ribeiro de Souza \n\n");

   int tl = 0, i, qtdNumeros = 0, qtdLetras = 0, indexPrimeiro = -1, indexUltimo;
   char placa[7];

   printf("Informe uma placa do Mercosul: ");
   do {
      scanf("%c", &placa[tl]);
      tl++;
   } while(tl < 7);
   if (tl < 7 ) 
      tl--;

   for(i=0; i < tl; i++) {
      if (placa[i] >='0' && placa[i] <= '9') {
         qtdNumeros++;
         if (indexPrimeiro == -1) {
            indexPrimeiro = i;
         }
         indexUltimo = i;
      } else if ((placa[i] > 64 && placa[i] < 91 )||(placa[i] > 96 && placa[i] < 123)) {
         qtdLetras++;
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Letras: %d.\n", qtdLetras);
   printf("Quantidade de Números: %d.\n", qtdNumeros);
   printf("Posição do primeiro número: %d.\n", indexPrimeiro + 1);
   printf("Números da placa: ");
   for(i=0; i < tl; i++) {
      if (placa[i] >='0' && placa[i] <= '9') 
         printf("%c", placa[i]);
   }
   printf("\nLetras da placa: ");
   for(i=0; i < tl; i++) {
      if ((placa[i] > 64 && placa[i] < 91 )||(placa[i] > 96 && placa[i] < 123)) 
         printf("%c ", placa[i]);
   }


   return 0;
}
