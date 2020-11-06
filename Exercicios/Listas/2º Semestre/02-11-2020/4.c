#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));

   printf("Escaninho - Leandro Ribeiro de Souza \n");
   int escaninho[10][5] = {0}, i, j, temp[2], pacote;

   for(i=0; i < 20; i++) {
      do {
         temp[0] = rand() % 10; 
         temp[1] = rand() % 5;
      } while(escaninho[temp[0]][temp[1]]);
      escaninho[temp[0]][temp[1]] = i + 1;
      printf("\nPacote %i:\n", i +1);
      printf("Posicao: \n");
      printf("   Linha: %i.\n", temp[0]);
      printf("   Coluna: %i.\n", temp[1]);   
   }   

   printf("\nRELATORIO POR LINHA\n");
   for(i=0; i < 10; i++) {
      printf("Pacotes na linha %i:", i + 1);

      for(j=0; j < 5; j++) {
         if(escaninho[i][j]) {
            printf(" %d", escaninho[i][j]);
         }
      }
      printf(".\n");
   }

   printf("\nRELATORIO POR COLUNA\n");
      for(i=0; i < 5; i++) {
         printf("Pacotes na COLUNA %i:", i + 1);

         for(j=0; j < 10; j++) {
            if(escaninho[j][i]) {
               printf(" %d", escaninho[j][i]);
            }
         }
      printf(".\n");
   }

   printf("\nInforme um Pacote para procurar (1 a 20): ");
   scanf("%i", &pacote);
   temp[0] = -1;
   for(i=0; i < 10; i++) {
      for(j=0; j < 5; j++) {
         if(escaninho[i][j] == pacote) {
            temp[0] = i;
            temp[1] = j;
            j=5;
            i=10;
         }
      }
   }

   if (temp[0] == -1) {
      printf("Pacote não encontrado.\n");
   } else {
      printf("Pacote encontrado!\n");
      printf("Posição: \n");
      printf("   Linha: %i.\n", temp[0] + 1);
      printf("   Coluna: %i.\n", temp[1] + 1);   
   }
   
   printf("\nPOSCIONAMENTO DOS PACOTES\n\n");
   printf("    | 01 | 02 | 03 | 04 | 05 |\n");
   printf("————+————+————+————+————+————+\n");
   for(i=0; i < 10; i++) {
      printf(" %s%d |",i < 9 ? "0" : "", i + 1);
      for(j=0; j <  5; j++) {
         if (escaninho[i][j]) {
            printf(" %s%d |", escaninho[i][j] < 10 ? "0" : "",escaninho[i][j]);
         } else {
            printf("    |");
         }
      }
      printf("\n");
      printf("————+————+————+————+————+————+\n");
   }

   return 0;
}