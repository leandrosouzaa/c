#include <stdio.h>

int main() {
   printf("Lanchonete Gostosura - Leandro Ribeiro de Souza \n\n");

   int qtdSanduiche = 0;
   float qQueijo, qPresunto, qHamburguer = 0;

   printf("Informe a quantidade de sanduíches que deseja fazer: ");
   scanf("%i", &qtdSanduiche);

   qQueijo = qtdSanduiche * 0.05 * 2;
   qPresunto = qtdSanduiche * 0.05;
   qHamburguer = qtdSanduiche * 0.1;

   printf("\nQuantidade de ingredientes necessários para o recheio de %i sanduíches:\n", qtdSanduiche);
   printf("Queijo: %0.2fkg\n",qQueijo );
   printf("Presunto: %0.2fkg\n",qPresunto );
   printf("Hamburguer: %0.2fkg\n",qHamburguer );

   return 0;
}
