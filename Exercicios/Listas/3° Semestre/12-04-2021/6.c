#define TAM 20
#include <stdio.h>

typedef struct sStack {
   char itens[TAM];
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

int push(STACK *S, char value) {
   if(isFull(S)) {
      printf("ERRO - A Pilha está cheia.\n");
      return 1;
   }

   S->itens[++S->topo] = value;

   return 0;
}

char pop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo--];
}

char stackTop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo];
}

int reverseExtremes(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   int i, temp[TAM], j = S->topo+1;

   for(i=0;i < j; i++) {
      temp[i] = pop(S);
   }


   push(S, temp[0]);
   for(i=j-2; i>=1 ; i--) {
      push(S, temp[i]);
   }
   push(S, temp[j-1]);

   return 0;
}

int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK S;
   int i = 0; 
   char temp;

   init(&S);

   printf("Informe uma palavra: ");
   do {
      scanf("%c", &temp);
      if(temp!=10) {
         push(&S, temp);
      }
      i++;
   } while(i < TAM && temp != 10);

   reverseExtremes(&S);

   printf("\nPilha invertida: \n");
   for(i=S.topo; i >= 0; i--) {
      printf("%c\n", pop(&S));
   }

   return 0;
}