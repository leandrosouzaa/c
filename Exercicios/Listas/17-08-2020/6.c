#include <stdio.h>

int main() {
   printf("Salário do Vendedor - Leandro Ribeiro de Souza \n\n");

   float totalVendas, salarioMinimo, salarioTotal = 0;

   printf("Informe o Salário Mínimo do vendedor: R$");
   scanf("%f", &salarioMinimo);

   printf("Total de vendas do vendedor: R$");
   scanf("%f", &totalVendas);

   salarioTotal = salarioMinimo + (totalVendas * 0.04);

   printf("\nSalário Mínimo: R$%f.\n", salarioMinimo);
   printf("Total de Vendas: R$%f.\n", totalVendas);
   printf("Bônus de vendas: R$%f.\n", salarioMinimo * 0.04);
   printf("Salário Total: R$%f.", salarioTotal);

   return 0;
}
