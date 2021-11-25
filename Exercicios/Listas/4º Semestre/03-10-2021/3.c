#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
   unsigned int prontuario;
   float nota;
} Aluno;

Aluno* getAlunos(int qtd) {
   return (Aluno *) malloc(qtd * sizeof(Aluno));
}

void ler_alunos(Aluno alunos[], int qtd) {
   for(int i = 0; i < qtd; i++) {
      printf("Prontuario: ");
      scanf("%u", &alunos[i].prontuario);
      printf("Nota: ");
      scanf("%f", &alunos[i].nota);
      printf("\n");
   }
};

void apresentar(Aluno alunos[], int n) {
   for(int i = 0; i < n; i++) {
      printf("Prontuario: %d.\n", alunos[i].prontuario);
      printf("Nota: %.2f.\n\n", alunos[i].nota);
   }
}

void swap(Aluno *a, Aluno *b) {
   Aluno t = *a;
   *a = *b;
   *b = t;
}


int partition_prontuario(Aluno array[], int low, int high) {

   int pivot = array[high].prontuario;

   int i = (low - 1);

   for (int j = low; j < high; j++) {
      if (array[j].prontuario <= pivot) {
         i++;
         swap(&array[i], &array[j]);
      }
   }
   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

int partition_nota(Aluno array[], int low, int high) {

   int pivot = array[high].nota;

   int i = (low - 1);

   for (int j = low; j < high; j++) {
      if (array[j].nota <= pivot) {
         i++;
         swap(&array[i], &array[j]);
      }
   }
   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

void quick_sort(Aluno array[], int low, int high, int tipo) {
   if (low < high) {
      int pi;
      if(tipo == 0) {
         pi = partition_prontuario(array, low, high);   
      } else {
         pi = partition_nota(array, low, high);
      }
      
      quick_sort(array, low, pi - 1, tipo);
      quick_sort(array, pi + 1, high, tipo);
   }
}

// Escolhi o método Quick Sort devido sua alta estabilidade independente da quantidade de registros.
// Tendo isso em vista, não terei problemas caso a quantidade de registros aumente ou diminua exponencialmente, sempre terei um resultado satisfatório.
// Alem do mais, eu consegui compreender ele melhor e me sinto mais confortavel usando ele.

int main() {
   int n;
   
   printf("Quantidade desejada: ");
   scanf("%d", &n);
   
   Aluno* alunos = getAlunos(n);
   
   ler_alunos(alunos, n);
   
   printf("\nLista Informada: ");
   apresentar(alunos, n);
   
   printf("\nLista Ordeanda por Prontuario: \n");
   quick_sort(alunos, 0, n - 1, 0);
   apresentar(alunos, n);
   
   printf("\nLista Ordeanda por Nota: \n");
   quick_sort(alunos, 0, n - 1, 1);
   apresentar(alunos, n);

   return 0;
}