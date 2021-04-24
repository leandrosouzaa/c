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
      printf("ERRO: Fila Vazia.\n");
   }

   return aux;
}

void imprimir(Fila *f) {
   int i = (f->inicio + 1) % TAMMAX;
   if(!vazia(f)) {
      printf("\nFila: ");
      while(i != ((f->fim + 1) % TAMMAX)) {
         printf("%d ", f->itens[i]);
         printf("\nI: %d.\n", i);
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

int main() {
   printf("Fila Estática - Leandro Ribeiro de Souza \n\n");

   Fila fila;

   int temp = 0;

   do {
      printf("Informe um elemento (-1 para sair): ");
      scanf("%d", &temp);
      if(temp != -1) {
         enfileirar(&fila, temp);
      }
   } while(temp != -1);

   printf("\n");
   imprimir(&fila);
   printf("\n\n%d",calcula_tamanho(&fila));

   return 0;
}