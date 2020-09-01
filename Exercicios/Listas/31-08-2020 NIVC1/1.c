#include <stdio.h>

int main() {
   printf("Triângulos - Leandro Ribeiro de Souza \n\n");

   float ladoA, ladoB, ladoC;

   printf("Informe o valor do lado A do triângulo:");
   scanf("%f", &ladoA);

   printf("Informe o valor do lado B do triângulo:");
   scanf("%f", &ladoB);

   printf("Informe o valor do lado C do triângulo:");
   scanf("%f", &ladoC);

   printf("\n");

   if (ladoA >= ladoB + ladoC || ladoB >= ladoA + ladoC || ladoC >= ladoA + ladoB) {
      printf("Este triângulo não existe.");
      return 0;
   }

   if (ladoA == ladoB && ladoB == ladoC) {
      printf("Este Triângulo é equilátero.");
   } else {
      if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
         printf("Este Triângulo é isósceles.");
      } else {
         printf("O Triângulo é escaleno.");
      }
   }
   return 0;
}

