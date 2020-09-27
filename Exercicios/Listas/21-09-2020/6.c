#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Auxílio Permanência - Leandro Ribeiro de Souza \n\n");

   int i = 0, vagas, n, busca, buscaIndex = -1;
   char status;

   printf("Informe a quantidade de Alunos: ");
   scanf("%d", &n);

   int prontuarios[n];

   for (i=0; i < n; i++) {
      printf("\nProntuário do colocado em %iº na lista de prioridade: PE", i + 1);
      scanf("%i", &prontuarios[i]);
   }

   printf("\nInforme um Prontuário para busca: PE");
   scanf("%i", &busca);

   i=0;
   while (i < n && prontuarios[buscaIndex] != busca) {
      if (prontuarios[i] == busca) {
         buscaIndex = i;
      }
      i++;
   }

   if (buscaIndex == -1) {
      printf("Prontuário não encontrado.\n");
   } else {
      printf("Colocação do Prontuário PE%i na lista: %iª.\n", busca , buscaIndex + 1);
   }

   printf("\nQuantidade de Selecionados: ");
   scanf("%i", &vagas);

   printf("\nLISTA DE SELECIONADOS\n");

   i = 0;
   while (i < n && i < vagas) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
      i++;
   }
   

   printf("\nCLASSIFICAÇÃO GERAL\n");
   for (i=0; i < n; i++) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
   }

   return 0;
}
