#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_vetor(int vetor[], int n) {
   srand(time(NULL));
   printf("\nPreenchendo o Vetor: \n");
   for(int i = 0; i < n; i++) {
      vetor[i] = rand() % 5;
      printf("Valor para a Posicao %d: %d.\n", i, vetor[i]);
   }
}

void imprimir_vetor(int vetor[], int n) {
   for(int i = 0; i < n; i++) {
      printf(" %d", vetor[i]);
   }
}

int busca_sequencial(int vet[], int n, int chave, int posicoes[]) {
   int i;
   int quantidade = 0;
   
   for(i=0;i<n && chave >= vet[i];i++) {
      if(vet[i]==chave) {
         posicoes[quantidade++] = i;
      };
   };
   
   return quantidade;
}

int busca_binaria(int vet[], int n, int chave, int posicoes[]) {
   int inicio = 0;
   int fim = n-1;
   int meio;
   
   int quantidade = 0;
   
   while (inicio <= fim) {
      meio = (inicio + fim)/2;
      if (chave == vet[meio]) {
         posicoes[quantidade++] = meio;
         // Toda vez que um vetor eh "jogado fora", eu volto percorro ele procurando ocorrencias.
         for(int j=inicio; j<meio; j++) {
            if(vet[j] == chave) {
               posicoes[quantidade++] = j;
            }
         }
      }
         
      if (chave < vet[meio])
         fim = meio-1;
      else
         inicio = meio+1;
   }
   
   return quantidade;
}

void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

int partition(int array[], int low, int high) {
   int pivot = array[high];

   int i = (low - 1);

   for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
         i++;
         swap(&array[i], &array[j]);
      }
   }
   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

void quick_sort(int array[], int low, int high) {
   if (low < high) {
      int pi = partition(array, low, high);
      quick_sort(array, low, pi - 1);
      quick_sort(array, pi + 1, high);
   }
}

int main() {
   int vetor[20], posicoes[20];
   
   printf("Preenchendo vetor aleatoriamente");
   preencher_vetor(vetor, 20);
   
   quick_sort(vetor, 0, 20-1);
   
   printf("\n\nVetor Gerado e Ordenado: ");
   imprimir_vetor(vetor, 20);
   
   int quantidade = busca_sequencial(vetor, 20, 4, posicoes);
   printf("\n\nValores encontrados nas posicoes (%d encontrados, SEQUENCIAL):", quantidade);
   imprimir_vetor(posicoes, quantidade);
   
   quantidade = busca_binaria(vetor, 20, 4, posicoes);
   printf("\n\nValores encontrados nas posicoes (%d encontrados, BINARIA):", quantidade);
   imprimir_vetor(posicoes, quantidade);

   return 0;
} 