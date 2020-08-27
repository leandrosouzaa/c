#include <stdio.h>

int main() {
   printf("Login - Leandro Ribeiro de Souza \n\n");

   int senha = 0;

   printf("Informe a senha (Somente números): ");
   scanf("%i", &senha);

   if (senha == 4876) {
      printf("\n[ACESSO AUTORIZADO]\n");
   } else {
      printf("\n[ACESSO NEGADO]\n");
   };

   return 0;
}
