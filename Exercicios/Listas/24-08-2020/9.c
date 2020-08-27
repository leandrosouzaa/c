#include <stdio.h>

int main() {
   printf("Categoria - Leandro Ribeiro de Souza \n\n");

   int idade = 0;

   printf("Informe a idade do Competidor: ");
   scanf("%i", &idade);

   if (idade >= 5 && idade <= 7) {
      printf("Categoria: Infantil A.");
   } else {
      if (idade > 7 && idade <= 10) {
         printf("Categoria: Infantil B.");
      } else {
         if (idade > 10 && idade <= 13) {
            printf("Categoria: Juvenil A.");
         } else {
            if (idade > 13 && idade <= 17) {
               printf("Categoria: Juvenil B.");
            } else {
               if (idade > 17) {
                  printf("Categoria: Adulto.");
               } else {
                  printf("Idade inválida para competir.");
               }
            }
         }
      }
   }

   return 0;
}
