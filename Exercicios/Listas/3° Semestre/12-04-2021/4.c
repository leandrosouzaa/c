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

int isPalindromo(STACK *S) {
   int i, j = S->topo+1;
   char temp[TAM];
   int isPalindromo = 1;

   for(i = S->topo;i >= 0; i--) {
      temp[i] = pop(S);
   };

   for(i=0; i < j; i++) {
      push(S, temp[i]);
   };

   for(i=0; i < j; i++) {
      if(pop(S) != temp[i]) {
         isPalindromo = 0;
         break;
      };
   };

   for(i; i >= 0; i--) {
      push(S, temp[j-1-i]);
   }

   return isPalindromo;
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

   int palindromo = isPalindromo(&S);

   

   if(palindromo) {
      printf("\nA palavra e Palindromo");
   } else {
      printf("\nA palavra nao e Palindromo");
   }
   return 0;
}