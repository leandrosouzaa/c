#define TAMMAX 10
#include <stdio.h>

typedef struct sFila {
   int itens[TAMMAX];
   int inicio, fim;
} Fila;

void inicializa(Fila *f) {
   f->inicio = TAMMAX - 1;
   f->fim = TAMMAX - 1;
}

int vazia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

int cheia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

void enfileirar(Fila *f, int x) {
   if(f->fim == (TAMMAX - 1)) {
      f->fim = 0;
   } else {
      f->fim++;
   }
   if(cheia(f)) {
      printf("\nERRO: Fila cheia.\n");
      f->fim--;
      if(f->fim == -1) {
         f->fim = TAMMAX - 1;
      }
      return;
   }
   f->itens[f->fim] = x;
}

int desenfileirar(Fila *f) {
   int aux = 0;
   
   if(!vazia(f)) {
      if(f->inicio == TAMMAX - 1) {
         f->inicio = 0;
      } else {
         f->inicio++;
      }
      aux = f->itens[f->inicio];
   } else {
      printf("\nERRO: Fila Vazia.\n");
   }

   return aux;
}

void imprimir(Fila *f) {
   int i = (f->inicio + 1) % TAMMAX;
   if(!vazia(f)) {
      printf("\nFila: ");
      while(i != ((f->fim + 1) % TAMMAX)) {
         printf("%d ", f->itens[i]);
         i = (i+1) % TAMMAX;
      }
   } else {
      printf("\n Fila Vazia.");
   }
}

int calcula_tamanho(Fila *f) {
   if(f->inicio < f->fim) {
      return f->fim - f->inicio;
   } else {
      return (TAMMAX-f->fim-(TAMMAX-f->inicio + 1));
   }
}

int verifica_maior(Fila *f1, Fila *f2) {
   if(calcula_tamanho(f1) > calcula_tamanho(f2)) {
      return 1;
   } else {
      if(calcula_tamanho(f2) > calcula_tamanho(f1)) {
         return 2;
      } else {
         return 0;
      }
   }
}

int main() {
   Fila fila, fila2;
   inicializa(&fila);
   inicializa(&fila2);

   int temp;

   printf("\nFila 1:\n");
   do {
      printf("Informe um número (-1 para sair): ");
      scanf("%d", &temp);
      if(temp != -1) {
         enfileirar(&fila, temp);
      }
   } while(temp != -1);

   printf("\nFila 2:\n");
   do {
      printf("Informe um número (-1 para sair): ");
      scanf("%d", &temp);
      if(temp != -1) {
         enfileirar(&fila2, temp);
      }
   } while(temp != -1);

   printf("\nTam. Fila 1: %d.\n", calcula_tamanho(&fila));
   printf("\nTam. Fila 2: %d.\n", calcula_tamanho(&fila2));
   printf("\nFila maior (0 = tamanhos iguais.): %d.\n", verifica_maior(&fila, &fila2));
   return 0;
}
