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

typedef struct sStack {
   int itens[TAMMAX];
   int topo;
} STACK;

void init(STACK *S) {
   S->topo = -1;
}

int isEmpty(STACK *S) {
   return S->topo == -1 ? 1 : 0;
}

int isFull(STACK *S) {
   return S->topo+1 == TAMMAX ? 1 : 0;
}

int push(STACK *S, int value) {
   if(isFull(S)) {
      printf("ERRO - A Pilha está cheia.\n");
      return 1;
   }

   S->itens[++S->topo] = value;

   return 0;
}

int pop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo--];
}

int stackTop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo];
}

void inverteFila(Fila *f) {
   if(vazia(f)) {
      printf("\nERRO: Fila Vazia.\n");
   }
   STACK pilha;
   init(&pilha);

   while(!vazia(f)) {
      push(&pilha ,desenfileirar(f));
   };
   while(!isEmpty(&pilha)) {
      enfileirar(f, pop(&pilha));
   };
};

int main() {
   Fila fila;
   inicializa(&fila);
   int temp;
   do {
      printf("Informe um número (-1 para sair): ");
      scanf("%d", &temp);
      if(temp != -1) {
         enfileirar(&fila, temp);
      }
   } while(temp != -1);

   inverteFila(&fila);

   imprimir(&fila);

   return 0;
}
