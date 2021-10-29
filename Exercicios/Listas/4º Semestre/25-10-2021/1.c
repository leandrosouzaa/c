#define SIZE 20

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

void insert_sort(int arr[], int *qtd) { 
   int i, j, key;
   *qtd = 0;
   
   for (i = 1; i < SIZE; i++) {
      key = arr[i];
      j = i - 1;
 
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
         *qtd+=1;
      }
      arr[j + 1] = key;
   }
}

void peneira(int *vet, int raiz, int fundo, int *qtd) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		} else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		} else {
			filhoMax = raiz * 2 + 1;
		}

      if (vet[raiz] < vet[filhoMax]) {
         tmp = vet[raiz];
         vet[raiz] = vet[filhoMax];
         vet[filhoMax] = tmp;
         raiz = filhoMax;
      } else {
         pronto = 1;
      }
      *qtd+=1;
   }
}

void heap_sort(int *vet, int n,int *qtd) {
	int i, tmp;
	*qtd = 0;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1, qtd);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1, qtd);
	}
}

void shellsort(int arr[], int *qtd) {
    int i, j, k, tmp;
    for (i = SIZE / 2; i > 0; i = i / 2)
    {
        for (j = i; j < SIZE; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}

void shell_sort(int arr[], int *qtd) {
   int i, j, k, tmp;
   for (i = SIZE / 2; i > 0; i = i / 2) {
      for (j = i; j < SIZE; j++) {
         for(k = j - i; k >= 0; k = k - i) {
            if (arr[k+i] >= arr[k]) {
               *qtd+=1;
               break;
            } else {
               *qtd+=1;
               tmp = arr[k];
               arr[k] = arr[k+i];
               arr[k+i] = tmp;
            }
         }
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

int main () {
   int vetorA[SIZE], vetorB[SIZE];
   int qtd, temp, opcao;
   
   do {
      printf("\n\nBusca e Ordenacao - Leandro Souza\n");
      printf("1 - Ler Vetor.\n");
      printf("2 - Preencher Vetor.\n");
      printf("3 - Ordenacao Bubble Sort.\n");
      printf("4 - Ordenacao Selection Sort.\n");
      printf("5 - Ordenacao Insert Sort.\n");
      printf("6 - Ordenacao Heap Sort.\n");
      printf("7 - Ordenacao Shell Sort.\n");
      printf("8 - Ordenacao Quick Sort.\n");
      printf("9 - Busca Sequencial.\n");
      printf("10 - Busca Binaria.\n");
      printf("11 - Carregar Vetor Secundario para a Memoria.\n");
      printf("12 - Imprimir Vetor Primario.\n");
      printf("13 - Imprimir Vetor Secundario.\n");
      
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
            printf("Iniciando Operacao (Insert Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            insert_sort(vetorB, &qtd);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 6:
            printf("Iniciando Operacao (Heap Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            heap_sort(vetorB, SIZE, &qtd);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 7:
            printf("Iniciando Operacao (Shell Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            shell_sort(vetorB, &qtd);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 8:
            printf("Iniciando Operacao (Quick Sort)...\n");
            printf("Clonando para vetor secundario...\n");
            clonar_vetor(vetorA, vetorB);
            printf("Iniciando Ordenacao...\n");
            quick_sort(vetorB, 0, SIZE - 1);
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 9:
            printf("Busca Sequencial (Vetor Precisa estar Ordenado.\n");
            printf("Informe um valor para buscar: ");
            scanf("%d", &temp);
            printf("Valor encontrado na posicao %d.\n", buscaSequencial(temp, vetorA, &qtd));
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 10:
            printf("Busca Binaria (Vetor Precisa estar Ordenado.\n");
            printf("Informe um valor para buscar: ");
            scanf("%d", &temp);
            printf("Valor encontrado na posicao %d.\n", buscaBinaria(vetorA, temp, &qtd));
            printf("Operacao concluida com %d iteracoes.\n", qtd);
            break;
            
         case 11:
            clonar_vetor(vetorB, vetorA);
            break;
            
         case 12:
            imprimir_vetor(vetorA);
            break;
         
         case 13:
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
