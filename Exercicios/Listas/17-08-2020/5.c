#include <stdio.h>

int main() {
   printf("Conta de Energia - Leandro Ribeiro de Souza \n\n");

   float qtdKw, valorKw ,valorTotal, valorFinal, salario = 0;

   printf("Informe a quantidade de KWs gastos: ");
   scanf("%f", &qtdKw);

   printf("Informe o salário mínimo: R$");
   scanf("%f", &salario);

   valorKw = salario/700;
   valorTotal = qtdKw * valorKw;
   valorFinal = valorTotal - (valorTotal / 10);

   printf("\nValor do KW: R$%f.\n", valorKw);
   printf("Valor Total da conta: R$%f.\n", valorTotal);
   printf("Valor com desconto (10%%): R$%f.", valorFinal);

   return 0;
}
