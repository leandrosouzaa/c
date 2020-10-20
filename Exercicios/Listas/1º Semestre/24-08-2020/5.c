#include <stdio.h>

int main() {
   printf("Reajuste Salárial - Leandro Ribeiro de Souza \n\n");

   float salario, reajuste, salarioReajustado, taxaReajuste;

   printf("Informe o Salário do Funcionário: R$");
   scanf("%f", &salario);

   if (salario > 1500) {
      taxaReajuste = 0.10;
   } else {
      taxaReajuste = 0.15;
   };

   reajuste = salario * taxaReajuste;
   salarioReajustado = salario + reajuste;

   printf("\nSalário do funcionário: R$%0.2f.\n", salario);
   printf("Taxa de Reajuste: %0.2f%%.\n", taxaReajuste);
   printf("Valor do Reajuste: R$%0.2f.\n", reajuste);
   printf("Salário do funcionário: R$%0.2f\n", salario);
   printf("Salário após Reajuste: R$%0.2f", salarioReajustado);

   return 0;
}
