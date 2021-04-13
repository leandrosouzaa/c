#define TAM 20
#include <stdio.h>

typedef struct sStack {
   int itens[TAM];
   int topo;
} STACK;

void init(STACK *S) {
   S->topo = -1;
}

int isEmpty(STACK *S) {
   return S->topo == -1 ? 1 : 0;
}

int isFull(STACK *S) {
   return S->topo+1 == TAM ? 1 : 0;
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

int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK P, N;
   init(&P);
   init(&N);

   int temp, i = 0;

   while(i<TAM) {
      printf("Insira um valor: ");
      scanf("%d", &temp);

      if(temp>0) {
         push(&P, temp);
      } else {
         if (temp < 0) {
            push(&N, temp);
         } else {
            pop(&P);
            pop(&N);
         }
      };

      i++;
   };

   return 0;
}