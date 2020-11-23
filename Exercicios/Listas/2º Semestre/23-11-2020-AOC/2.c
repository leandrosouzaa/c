#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
   printf(" - Leandro Ribeiro de Souza \n\n");
   double maiorPositivo, menorPositivo, maiorNegativo, menorNegativo, overflow, underflow;

   maiorPositivo = 4503599627370495 * pow(2,972);
   menorPositivo = 1 * pow(2,-1074);
   printf("Maior valor positivo: %f\n\n",maiorPositivo);
   printf("Menor valor positivo: %0.1075f\n\n",menorPositivo);
   getchar();
   system("cls");

   maiorNegativo = 1 * pow(2,-1074) * -1;
   menorNegativo = 4503599627370495 * pow(2,972) * -1;
   printf("Maior valor negativo: %0.1075f\n\n",maiorNegativo);
   printf("Menor valor negativo: %f\n\n",menorNegativo);
   getchar();
   system("cls");

   overflow = 4503599627370495 * pow(2,973);
   underflow = 1 * pow(2,-1075);
   printf("Exemplo de Overflow: %f\n\n",overflow);
   printf("Exemplo de Underflow: %0.1075f\n\n",underflow);
   getchar();

   return 0;
}
