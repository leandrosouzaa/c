#include <stdio.h>

int main() {
   printf("Sequência de Fibonacci - Leandro Ribeiro de Souza \n\n");

   int i, ntermos, n1 = 0, n2 = 1, termo;

   printf("Informe o número de termos que você deseja visualizar: ");
   scanf("%i", &ntermos);

   if (ntermos < 4) {
      printf("\nÉ necessário informar um número maior que 4. Finalizando programa...");

      return 0;
   }

   for (i = 0; i < ntermos; i++) {
      termo = n1 + n2;
      n2 = n1;
      n1 = termo;

      printf("%i\n",termo);
   }

   return 0;
}
