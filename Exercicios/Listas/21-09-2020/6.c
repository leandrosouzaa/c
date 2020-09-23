#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Auxílio Permanência - Leandro Ribeiro de Souza \n\n");

   int i = 0, tl = 0, vagas, prontuarios[256], busca, buscaIndex = -1;
   char status;

   do {
      printf("\nProntuário do colocado em %iº na lista de prioridade: PE", tl + 1);
      scanf("%i", &prontuarios[tl]);
      
      tl++;

      printf("Existem mais alunos? ");
      scanf(" %c", &status);
   } while (status == 's' && tl < 100);

   printf("\nInforme um Prontuário para busca: PE");
   scanf("%i", &busca);

   // while (i <= tl && prontuarios[buscaIndex] != buscaIndex) {
      // printf("%i", prontuarios[i]);
      // if (prontuarios[i] == busca) {
         // buscaIndex = i;
         // printf("caiu e saiu");
      // }
      // i++;
   // }

   for (i = 0; (i <= tl && prontuarios[buscaIndex] != busca); i++) {
      if (prontuarios[i] == busca) {  
         buscaIndex = i;
      };
   }

   if (buscaIndex == -1) {
      printf("Prontuário não encontrado.\n");
   } else {
      printf("Colocação do Prontuário PE%i na lista: %iª.\n", busca , buscaIndex + 1);
   }

   printf("\nQuantidade de Selecionados: ");
   scanf("%i", &vagas);

   printf("\nLISTA DE SELECIONADOS\n");
   for (i=0; (i < tl && i < vagas); i++) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
   }

   printf("\nCLASSIFICAÇÃO GERAL\n");
   for (i=0; i < tl; i++) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
   }

   return 0;
}
