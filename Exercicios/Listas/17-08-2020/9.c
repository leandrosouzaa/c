#include <stdio.h>

int main() {
   printf("Sono Tranquilo - Leandro Ribeiro de Souza \n\n");

   int qtdDiarias = 0;
   float valorDiaria, valorTotal, desconto, valorDesconto, gastosDiversos, valorFinal = 0;

   printf("Informe o Valor da diárias: R$");
   scanf("%f", &valorDiaria);

   printf("Informe o Total de diárias: ");
   scanf("%i", &qtdDiarias);

   printf("Informe a Porcentagem de desconto: ");
   scanf("%f", &desconto);

   printf("Informe o total dos Gastos Diversos: R$");
   scanf("%f", &gastosDiversos);

   valorTotal = qtdDiarias * valorDiaria + gastosDiversos;
   valorDesconto = valorTotal * (desconto/100);
   valorFinal = valorTotal - valorDesconto;

   printf("\nQuantidade de Diárias: %i.\n",qtdDiarias);
   printf("Valor da diária: R$%0.2f.\n", valorDiaria);
   printf("Porcentagem de desconto: %0.2f%%.\n", desconto);
   printf("Gastos diversos: R$%0.2f.\n", gastosDiversos);
   printf("Valor Total: R$%0.2f.\n", valorTotal);
   printf("Valor de Desconto: R$%0.2f.\n", valorDesconto);
   printf("Valor Final a ser pago: R$%0.2f.\n", valorFinal);

   return 0;
}
