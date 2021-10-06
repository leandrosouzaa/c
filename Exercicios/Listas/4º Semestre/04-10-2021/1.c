#define SIZE 15

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ler_vetor(int vetor[]) {
   printf("\nPreencha o Vetor: \n");
   for(int i = 0; i < SIZE; i++) {
      printf("Valor para a Posicao %d: ", i+1);
      scanf("%d", &vetor[i]);
   }
}

void preencher_vetor(int vetor[]) {
   srand(time(NULL));
   printf("\nPreenchendo o Vetor: \n");
   for(int i = 0; i < SIZE; i++) {
      vetor[i] = rand() % 200;
      printf("Valor para a Posicao %d: %d.\n", i+1, vetor[i]);
   }
}

void imprimir_vetor(int vetor[]) {
   printf("\nVetor:");
   for(int i = 0; i < SIZE; i++) {
      printf(" %d", vetor[i]);
   }
}

void clonar_vetor(int vetorA[], int vetorB[]) {
   for(int i = 0; i < SIZE; i++) {
      vetorB[i] = vetorA[i];
   }
}


void bubble_sort (int vetor[], int *qtd) {
   int k, j, aux;
   *qtd = 0;
   
   printf("%d ", *qtd);

   for (k = 1; k < SIZE; k++) {
      for (j = 0; j < SIZE - 1; j++) {
         *qtd+=1;
         if (vetor[j] > vetor[j + 1]) {
            aux = vetor[j];
            vetor[j]     = vetor[j + 1];
            vetor[j + 1] = aux;
         }
      }
   }
   printf("%d", *qtd);
}

void selection_sort(int num[], int *qtd) { 
   int i, j, min, aux;
   *qtd = 0;
   for (i = 0; i < (SIZE-1); i++) {
      min = i;
      for (j = (i+1); j < SIZE; j++) {
         *qtd+=1;
         if(num[j] < num[min]) 
            min = j;
      }
      if (i != min) {
         aux = num[i];
         num[i] = num[min];
         num[min] = aux;
      }
   }
}

int buscaSequencial(int elem, int vetor[], int *qtd) {
     int i;
     *qtd = 0;
     for(i=0;i<SIZE && elem >= vetor[i];i++) {
         *qtd+=1;
         if(vetor[i]==elem) {
            return i;
         }
     }
     return -1;
}

int buscaBinaria ( int vet[], int chave, int *qtd) {
   int inicio = 0;
   int fim = SIZE-1;
   int meio;
   *qtd = 0;
   while (inicio <= fim) {
      *qtd+=1;
      meio = (inicio + fim)/2;
      if (chave == vet[meio])
         return meio;
      if (chave < vet[meio])
         fim = meio-1;
      else
         inicio = meio+1;
   }
   
   return -1;
}

int main () {
   int vetorA[SIZE], vetorB[SIZE];
   int qtd, temp, opcao;
   
   do {
      printf("\n\nBusca e Ordenacao - Leandro Souza\n");
      printf("1 - Ler Vetor.\n");
      printf("2 - Preencher Vetor.\n");
      printf("3 - Ordenacao Bubble Sort.\n");
      printf("4 - Ordenacao Selection Sort.\n");
      printf("5 - Busca Sequencial.\n");
      printf("6 - Busca Binaria.\n");
      printf("7 - Carregar Vetor Secundario para a Memoria.\n");
      printf("8 - Imprimir Vetor Primario.\n");
      printf("9 - Imprimir Vetor Secundario.\n");
      
      printf("\n0 - Encerrar Programa.\n");
      printf("\nEscolha uma opcao: ");
      scanf("%d", &opcao);
      
      switch (opcao) {
         case 1:
            ler_vetor(vetorA);
            break;
            
         case 2:
            preencher_vetor(vetorA);
            break;
            
         case 3:
            printf("Iniciando Operacao (Bubble Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            bubble_sort(vetorB, &qtd);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 4:
            printf("Iniciando Operacao (Selection Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            selection_sort(vetorB, &qtd);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 5:
            printf("Busca Sequencial (Vetor Precisa estar Ordenado.\n");
            printf("Informe um valor para buscar: ");
            scanf("%d", &temp);
            printf("Valor encontrado na posicao %d.\n", buscaSequencial(temp, vetorA, &qtd));
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 6:
            printf("Busca Binaria (Vetor Precisa estar Ordenado.\n");
            printf("Informe um valor para buscar: ");
            scanf("%d", &temp);
            printf("Valor encontrado na posicao %d.\n", buscaBinaria(vetorA, temp, &qtd));
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 7:
            clonar_vetor(vetorB, vetorA);
            break;
            
         case 8:
            imprimir_vetor(vetorA);
            break;
         
         case 9:
            imprimir_vetor(vetorB);
            break;
            
         case 0:
            printf("Encerrando o Sistema.\n");
            break;
            
         default:
            printf("Opcao invalida. Tente novamente.\n");
      }
      
   } while(opcao != 0);
}
