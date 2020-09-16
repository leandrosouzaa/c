#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Adivinhador - Leandro Ribeiro de Souza \n\n");

   int n1, n2, sorteado, qtdTentavas = 1;

   srand(time(NULL));

   printf("Informe um número entre 1 e 75: ");
   scanf("%i", &n1);

   printf("Informe outro número entre 1 e 75: ");
   scanf("%i", &n2);

   if (n1 > 75 || n2 > 75 || n1 < 1 || n2 < 1) {
      printf("\nDados inválidos.\n");
      printf("Encerrando o programa...\n");

      return 0;
   }

   do {
      sorteado = rand()%75 + 1;
      printf("\nTentativa número: %i.\n", qtdTentavas);
      printf("Número Gerado: %i.\n", sorteado);
      qtdTentavas++;
   } while (sorteado != n1 && sorteado != n2);

   printf("\nTotal de Tentavias: %i.\n", qtdTentavas);
   if (sorteado == n1) {
      printf("Número adivinhado: %i.\n", n1);
   } else {
      printf("Número adivinhado: %i.\n", n1);
   }

   return 0;
}
