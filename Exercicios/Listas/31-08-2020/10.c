#include <stdio.h>

int main() {
   printf("Cinema - Leandro Ribeiro de Souza \n\n");

   int i, qtdAssentos, idade, qtdMeias = 0, qtdCriancas = 0;
   float total;

   printf("Informe a quantidade de assentos a serem ocupados: ");
   scanf("%i", &qtdAssentos);

   if (qtdAssentos <= 0) {
      printf("Quantidade de assentos inválidas, finalizando o programa...");
   }

   for (i=qtdAssentos; i > 0; i--) {
      printf("\n\nInforme a idade do Cliente:");
      scanf("%i", &idade);
      if (idade < 12 || idade > 59) {
         printf("Tipo de Ingresso: Meio");
         qtdMeias++;
         total = total + 9;
      } else {
         printf("Tipo de Ingresso: Inteiro");
         total = total + 18;
      }

      if (idade < 12) {
         qtdCriancas++;
      }
   }

   printf("\n\nRELATÓRIO DE VENDAS\n\n");
   printf("Total de Ingressos vendidos: %i.\n", qtdAssentos);
   printf("Ingressos Integrais: %i.\n", qtdAssentos - qtdMeias);
   printf("Ingressos Meio: %i.\n", qtdMeias);
   printf("Idosos na sessão: %i.\n", qtdMeias - qtdCriancas);
   printf("Crianças na sessão: %i.\n", qtdCriancas);
   printf("\nTOTAL ARRECADADO: R$%0.2f.", total);   

   return 0;
}
