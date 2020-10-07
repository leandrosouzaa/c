#include <stdio.h>

int main() {
   printf("Taxa de INSS - Leandro Ribeiro de Souza \n\n");

   float salario, salarioLiquido, desconto;

   do {
      printf("Informe seu Salário: R$");
      scanf("%f", &salario);

      if (salario <= 0) {
         printf("Entrada inválida, tente novamente. \n\n");
      }

   } while(salario <= 0);

   printf("\nRELATÓRIO FINAL\n");
   if (salario <= 600) {
      desconto = 0;
      printf("Porcentagem de Desconto: 0%%.\n");

   } else if (salario >  600 && salario <= 1200) {
         desconto = (salario / 100) * 20;
         printf("Porcentagem de Desconto: 20%%.\n");
      } else if (salario > 1200 && salario <= 2000 ) {
            desconto = (salario/100) * 25;
            printf("Porcentagem de Desconto: 25%%.\n");
         } else if (salario > 2000) {
               desconto = (salario/100) * 30;
               printf("Porcentagem de Desconto: 30%%.\n");
            }
         

   salarioLiquido = salario - desconto;

   printf("Salário Total: R$%0.2f.\n", salario);
   printf("Valor descontado: R$%0.2f.\n", desconto);
   printf("Salário Liquido: R$%0.2f.\n", salarioLiquido);

   return 0;
}
