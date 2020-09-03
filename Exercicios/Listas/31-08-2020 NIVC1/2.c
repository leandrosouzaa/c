#include <stdio.h>

int main() {
   printf("Vinhos - Leandro Ribeiro de Souza \n\n");

   char tipoVinho, tipoVinhoMaisCaro;
   float valor, vinhoMaisCaro = 0;

   printf("Informe um Tipo de Vinho: ");
   scanf(" %c", &tipoVinho);

   if (tipoVinho == 'f') {
      printf("\nFinalizando Programa...");
      return 0;
   }

   printf("Informe o valor do Vinho: ");
   scanf("%f", &valor);

   if (valor < 0) {
      printf("\nValor inválido\n");
      printf("Finalizando Programa...");
      return 0;
   }

   while (tipoVinho != 'f') {
      printf("\nInforme um Tipo de Vinho: ");
      scanf(" %c", &tipoVinho);

      printf("Informe o valor do Vinho: ");
      scanf("%f", &valor);

      if (valor > vinhoMaisCaro && tipoVinho != 'f') {
         vinhoMaisCaro = valor;
         tipoVinhoMaisCaro = tipoVinho;
      }
   }

   printf("\nVINHO MAIS CARO\n");
   switch (tipoVinhoMaisCaro)
   {
   case 't':
      printf("Tipo: Tinto.");
      break;
   case 'b':
      printf("Tipo: Branco.");
      break;
   case 'r':
      printf("Tipo: Rosê.");
      break;
   default:
      printf("Tipo: Desconhecido.");
      break;
   }

   printf("\nValor: %f", vinhoMaisCaro);

   return 0;
}
