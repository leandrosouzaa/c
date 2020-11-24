#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
   printf("Testes da IEEE 754 - Leandro Ribeiro de Souza \n\n");
   double maiorPositivo, menorNegativo, overflow,  underflow;


   maiorPositivo = 9007199254740991 * pow(2,971);
   printf("Maior valor positivo: %f\n\n",maiorPositivo);


   menorNegativo = 9007199254740991 * pow(2,971) * -1;
   printf("Menor valor negativo: %f\n\n",menorNegativo);
   getchar();
   system("cls");


   overflow = 9007199254740991* pow(2,973);
   underflow = 9007199254740991 * pow(2,973) * -1;
   printf("Exemplo de Overflow: %f\n\n",overflow);
   printf("Exemplo de Underflow: %0.1075f\n\n",underflow);
   getchar();

   return 0;
}
