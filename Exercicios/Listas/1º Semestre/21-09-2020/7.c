#include <stdio.h>

int main() {
   printf("Vários Vetores - Leandro Ribeiro de Souza \n");

   int item, i, a[5], b[5], c[10], somaA = 0, somaB = 0, x, temp;

   do {
      printf("\nSELECIONE UMA OPÇÃO:\n");
      printf("1 - Ler dois Vetores.\n");
      printf("2 - Juntar Vetores.\n");
      printf("3 - Somas dos Elementos.\n");
      printf("4 - Multiplicar Elementos de um Vetor por X.\n");
      printf("5 - Troca entre Vetores.\n");
      printf("6 - Mostrar Vetores.\n");
      printf("7 - Sair do Programa.\n");
      printf("Opção: ");
      scanf("%i", &item);
      
      switch (item) {
         case 1:
            printf("\nLEITURA DOS VETORES A E B\n");
            for (i=0; i < 5; i++) {
               printf("Informe um número para a posição %i do Vetor A: ", i);
               scanf("%i", &a[i]);
            }
            printf("\n");
            for (i=0; i < 5; i++) {
               printf("Informe um número para a posição %i do Vetor B: ", i);
               scanf("%i", &b[i]);
            }
            break;

         case 2:
            printf("\nJuntando Vetores...\n");
            for (i=0; i < 5; i++) {
               c[i] = a[i];
               c[5+i] = b[i];
            }
            printf("Junção concluída!\n");
            break;

         case 3:
            printf("\nSOMA DE ELEMENTOS\n");

            for (i=0; i < 5; i++) {
               somaA+= a[i];
               somaB+= b[i];
            }

            printf("Soma do Vetor A: %i.\n", somaA);
            printf("Soma do Vetor B: %i.\n", somaB);

            if (somaA > somaB) {
               printf("O Vetor A possui a soma maior.\n");
            } else {
               if (somaB > somaA) {
                  printf("O Vetor B possui a soma maior.\n");
               } else {
                  printf("O Vetores possuem a soma igual.\n");
               }
            }
            break;

         case 4: 
            printf("\nMULTIPLICAÇÃO DE UM VETOR POR X\n");
            printf("Informe um número para multiplicar o Vetor C: ");
            scanf("%i", &x);

            printf("\nRESULTADO\n");
            for (i=0; i < 10; i++) {
               c[i]*=x;
               printf("Posição %i multiplicada por %i = %i.\n", i, x, c[i]);
            }
            break;

         case 5:
            printf("\nTrocando Vetores...\n");
            for (i = 0; i < 5; i ++) {
               temp  = a[i];
               a[i] = b[i];
               b[i] = temp;
            }
            printf("Vetores Trocados.\n");
            break;

         case 6:
            printf("\nMOSTRANDO VETORES A E B\n");
            printf("VETOR A:\n");
            for (i=0; i < 5; i++) {
               printf("Posição %i: %i.\n", i, a[i]);
            }
            printf("\nVETOR B:\n");
            for (i=0; i < 5; i++) {
               printf("Posição %i: %i.\n", i, b[i]);
            }
            break;
         
         case 7:
            printf("\nFinalizando Programa...\n");
            break;

         default:
            printf("\nEntrada inválida...\n");
            printf("Voltando para o Menu...\n");
            break;
      }
   } while (item != 7);

   return 0;
}
