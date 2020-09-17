#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Adivinhador - Leandro Ribeiro de Souza \n\n");

   int n1, n2, sorteado1, sorteado2, qtdTentavas = 1;

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
      sorteado1 = rand()%75 + 1;
      sorteado2 = rand()%75 + 1;

      printf("\nTentativa número: %i.\n", qtdTentavas);
      printf("1° Número Gerado: %i.\n", sorteado1);
      printf("2 °Número Gerado: %i.\n", sorteado2);

      qtdTentavas++;
   } while (sorteado1 != n1 || sorteado2 != n2);

   printf("\nTotal de Tentavias: %i.\n", qtdTentavas);
   printf("1° Número adivinhado: %i.\n", sorteado1);
   printf("2° Número adivinhado: %i.\n", sorteado2);

   return 0;
}
