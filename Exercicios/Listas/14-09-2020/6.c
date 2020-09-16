#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
   printf("Dados - Leandro Ribeiro de Souza \n\n");
   srand(time(NULL));

   int dado1, dado2, jogador1 = 0, jogador2 =0, qtdRodadas = 1;

   while (jogador1 < 11 && jogador2 < 11) {
      printf("\nRodada Número: %i.\n", qtdRodadas);
      dado1 = rand()%6 + 1;
      printf("Número tirado pelo Jogador 1: %i.\n", dado1);

      dado2 = rand()%6 + 1;
      printf("Número tirado pelo Jogador 2: %i.\n", dado2);

      if (dado1 > dado2) {
         jogador1++;
      } else {
         if (dado2 > dado1) {
            jogador2++;
         } 
      }

      qtdRodadas++;
   }

   printf("\nRESULTADO FINAL\n");
   printf("Total de Rodadas: %i.\n", qtdRodadas);
   printf("Pontos do Jogador 1: %i.\n", jogador1);
   printf("Pontos do Jogador 2: %i.", jogador2);

   return 0;
}