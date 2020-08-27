#include <stdio.h>
#include <math.h>

int main() {
   printf("Cálculo de Média - Leandro Ribeiro de Souza \n\n");

   float n1,n2,n3,media = 0;

   printf("Informe um número: ");
   scanf("%f", &n1);

   printf("Informe outro número: ");
   scanf("%f", &n2);

   printf("Informe outro número: ");
   scanf("%f", &n3);

   media = (n1 + n2 + n3) / 3;

   printf("\nMédia entre os números: %0.2f.\n", media);  

   return 0;
}
