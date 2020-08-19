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
   printf("Valor da diária: R$%g.\n", valorDiaria);
   printf("Porcentagem de desconto: %g%%.\n", desconto);
   printf("Gastos diversos: R$%g\n.", gastosDiversos);
   printf("Valor Total: R$%g.\n", valorTotal);
   printf("Valor de Desconto: R$%g.\n", valorDesconto);
   printf("Valor Final a ser pago: R$%g.\n", valorFinal);

   return 0;
}
