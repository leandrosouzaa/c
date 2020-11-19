#include <stdio.h>
#include <stdlib.h>

int readprontuarios(int prontuarios[256]) {
   int i = 0, logicalSize = 0;
   char status;

   do {
      printf("\nProntuário do colocado em %iº na lista de prioridade (max 256): PE", logicalSize + 1);
      scanf("%i", &prontuarios[i]);
      printf("Existem mais alunos [S/N]? ");
      scanf(" %c", &status);
      i++;
      logicalSize++;
   } while(logicalSize < 256 && (status == 's' || status == 'S'));
   
   return logicalSize;
}

int findByProntuario(int prontuarios[256], int logicalSize, int prontuario) {
   int i = 0;
   while (i < logicalSize) {
      if (prontuarios[i] == prontuario) {
         return i;
      }
      i++;
   }
   return -1;
}

void showSelecteds(int prontuarios[256], int logicalSize, int quantitySelected) {
   int i = 0;
   printf("\nLISTA DE SELECIONADOS\n");

   while (i < logicalSize && i < quantitySelected) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
      i++;
   }
}

void showAll(int prontuarios[256], int logicalSize) {
   int i;
   printf("\nCLASSIFICAÇÃO GERAL\n");
   for (i=0; i < logicalSize; i++) {
      printf("%iº: PE%i.\n", i+1, prontuarios[i]);
   }
}

int main() {
   printf("Auxílio Permanência - Leandro Ribeiro de Souza \n\n");

   int quantitySelected, n, prontToFind, prontuarios[256], tl = 0;
   
   int logicalSize = readprontuarios(prontuarios);

   printf("\nInforme um Prontuário para busca: PE");
   scanf("%i", &prontToFind);

   int prontFound = findByProntuario(prontuarios, logicalSize, prontToFind); 

   if (prontFound == -1) {
      printf("Prontuário não encontrado.\n");
   } else {
      printf("Colocação do Prontuário PE%i na lista: %iª.\n", prontToFind , prontFound + 1);
   }

   printf("\nQuantidade de Selecionados: ");
   scanf("%i", &quantitySelected);
   showSelecteds(prontuarios, logicalSize, quantitySelected);

   showAll(prontuarios, logicalSize);

   return 0;
}
