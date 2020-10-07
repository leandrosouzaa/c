#include <stdio.h>

int main() {
   printf("Avaliação de um Filme - Leandro Ribeiro de Souza \n\n");

   int idade = 0, i, nota, qtdOtimo = 0, qtdRegular = 0, qtdBom = 0;
   float totalIdadeOtimo = 0, mediaIdadeOtimo = 0, porcentagem;

   for(i=0; i < 10; i++) {
      do {
         printf("\nInforme a idade do espectador %d: ", i + 1);
         scanf("%d", &idade);
      } while(idade <= 0);

      do {
         printf("Avaliação do espectador %d: ", i + 1);
         scanf("%i", &nota);
      } while (!(nota == 1 || nota == 2 || nota == 3));

      switch (nota) {
         case 1:
            qtdRegular++;
            break;

         case 2:
            qtdBom++;
            break;

         case 3: 
            qtdOtimo++;
            totalIdadeOtimo+=idade;
            break;

         default:
            printf("Entra inválida, espectador %d desconsiderado.\n", i + 1);
            break;
      }
   }

   porcentagem = (qtdBom / 10.0) * 100;
   mediaIdadeOtimo = totalIdadeOtimo / qtdOtimo;

   printf("\nRELATÓRIO FINAL\n");
   printf("Avaliações Regulares: %d.\n", qtdRegular);
   printf("Avaliações Boas: %d.\n", qtdBom);
   printf("Avaliações Ótimas: %d.\n", qtdOtimo);
   printf("Media da idade das pessoas que responderam Ótimo: %0.2f anos.\n", mediaIdadeOtimo);
   printf("Porcentagem de pessoas que consideram o filme bom: %0.2f%%", porcentagem);

   return 0;
}
