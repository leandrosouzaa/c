#include <stdio.h>

int main() {
   printf("Manos e Manas - Leandro Ribeiro de Souza \n\n");

   int idade = 0;

   printf("Informe a idade do cliente: ");
   scanf("%i", &idade);

   if (idade > 17) {
      printf("\n[VENDA AUTORIZADA]\n");
   } else {
      printf("\n[VENDA NÃO AUTORIZADA]\n");
   };
   
   return 0;
}
