#define TAM 5
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

int reverse(STACK *S) {
   int i, temp[TAM], j = S->topo+1;
   

   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia\n");
      return 1;
   }

   for(i=0;i < j; i++) {
      temp[i] = pop(S);
   }

   for(i=0; i < j; i++) {
      push(S, temp[i]);
   }

   return 0;
}

int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK S;
   init(&S);
   int temp, i = 0;

   while(i<TAM) {
      printf("Insira um valor: ");
      scanf("%d", &temp);

      push(&S, temp);

      i++;
   };

   reverse(&S);

   printf("\nPilha invertida: \n");
   for(i=S.topo; i >= 0; i--) {
      printf("Valor: %d.\n", pop(&S));
   }

   return 0;
}
