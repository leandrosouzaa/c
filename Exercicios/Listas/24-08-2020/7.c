#include <stdio.h>

int main() {
   printf("Peso Ideal - Leandro Ribeiro de Souza \n\n");

   float altura, peso = 0;
   char sexo;

   printf("Informe sua Altura (cm): ");
   scanf("%f", &altura);

   printf("Informe o seu Sexo (M para Masculino e F para Feminino): ");
   scanf(" %c", &sexo);

   if (sexo == 'M') {
      peso = (72.7 * (altura / 100)) - 58;
   } else {
      peso = (62.1 * (altura / 100)) - 44.7;
   };

   printf("\nSeu peso ideal é %0.2fkg.", peso);

   return 0;
}
