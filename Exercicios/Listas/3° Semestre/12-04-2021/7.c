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

void validate(STACK *S, int value) {
   STACK S2;
   init(&S2);

   if(value % 2 == 0) {
      int j = S->topo+1;
      int i = 0;
      while(i < j && (stackTop(S) % 2 == 1)) {
         push(&S2, pop(S));
         printf("%d\n", i);
         i++;
      }
      push(S, value);
      while(S2.topo != -1) {
         push(S, pop(&S2));
      }
   } else {
      push(S, value);
   }
};

int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK S;
   init(&S);
   int temp, i = 0;

   while(i<TAM) {
      printf("Insira um valor: ");
      scanf("%d", &temp);

      validate(&S, temp);

      i++;
   };

   for(i=S.topo; i >= 0; i--) {
      printf("%d.\n", pop(&S));
   }

   return 0;
}
