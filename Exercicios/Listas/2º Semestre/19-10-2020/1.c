#include <stdio.h>

int main() {
   printf("Vetor de Elementos - Leandro Ribeiro de Souza \n");

   float num[30], menorElemento, maiorElemento, media, soma; 
   int tl = 0, i = 0, opcao;
   char continua;

   do {
      printf("\nInforme um número para a posição %d: ", i);
      scanf("%f", &num[i]);
      i++;
      tl++;

      if (tl!=30){
         printf("Informar mais elementos? ");
         scanf(" %c", &continua);
      }
   } while (i < 30 && continua == 'S');

   menorElemento = num[0];
   maiorElemento = num[0];
   soma = num[0];

   for (i=1; i < tl; i++) {
      if (num[i] > maiorElemento)
         maiorElemento = num[i];
      if (num[i] < menorElemento) 
         menorElemento = num[i];
      soma+= num[i];      
   }

   media = (soma / tl) * 1.0;

   do {
      printf("\n\nOpções disponveis:\n");
      printf("1 - Maior e Menor Elemento\n");
      printf("2 - Soma e Média do vetor\n");
      printf("3 - Vetor Completo\n");
      printf("4 - Finalizar Programa\n");

      printf("Escolha um item: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         printf("Maior Elemento: %0.2f.\n", maiorElemento);
         printf("Menor Elemento: %0.2f.\n", menorElemento);

         break;
      
      case 2:
         printf("Soma dos Elementos: %0.2f.\n", soma);
         printf("Média dos Elementos: %0.2f.\n", media);

         break;

      case 3:
         printf("Vetor Completo: \n");
         for (i=0; i < tl; i++) {
            printf("Vetor[%d] = %0.2f.\n", i, num[i]);
         }
         break;
      
      case 4: 
         printf("Finalizando programa...");
         
         break;      
      
      default:
         printf("Item inválido, tente novamente.");
         break;
      }
   } while(opcao != 3);

   return 0;
}
