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

void imprimir(STACK *s) {
   int temp[TAM], i = 0;

   while(!isEmpty(s)) {
      temp[i] = pop(s);
      printf("%d.\n", temp[i]);
      i++;
   }

   for(int j = i-1; j > -1; j--) {
      push(s, temp[j]);
   }
};

int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK S;
   init(&S);
   int temp, i = 0;

   while(i<5) {
      printf("Insira um valor: ");
      scanf("%d", &temp);

      if(temp % 2 == 0) {
         push(&S, temp);
      } else {
         pop(&S);
      };

      i++;
   };

   imprimir(&S);

   printf("\nVERIFICAÇÃO\n");

   for(i=S.topo; i >= 0; i--) {
      printf("%d.\n", pop(&S));
   }

   return 0;
}
