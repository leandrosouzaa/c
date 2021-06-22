#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPRATO {
   char cor[50];
   char formato[50];
} PRATO;

typedef struct sCELL {
   PRATO info;
   struct sCELL *next;
} CELL;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void init(CELL **stack) {
   *stack = NULL;
}

void freeNode(CELL *cell) {
   free(cell);
}

int isEmpty(CELL *stack) {
   return stack == NULL ? 1 : 0;
}

void push(CELL **stack, PRATO x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }

   q->info = x;
   q->next = *stack;
   *stack = q;
}

void pop(CELL **stack) {
   CELL *aux = *stack;

   *stack = (*stack)->next;
   freeNode(aux);
}

PRATO stackTop(CELL *stack) {
   return stack->info;
}

void print(CELL *stack) {
   CELL *aux = stack;

   if(isEmpty(stack)) {
      printf("\nPilha Vazia.\n");
      return;
   }

   printf("\n");
   while(aux != NULL) {
      printf("%.02f\t", aux->info);
      aux = aux->next;
   }
   printf("\n");
}

PRATO createPrato(const char cor[50], const char formato[50]) {
   PRATO prato;
   strcpy(prato.cor, cor);
   strcpy(prato.formato, formato);

   return prato;
};

int main() {
   printf("Pilha Dinamica - Leandro Ribeiro de Souza \n\n");
   
   CELL *stack;
   init(&stack);

   push(&stack, createPrato("Roxo", "Redondo"));
   push(&stack, createPrato("Branca", "Quadrado"));
   push(&stack, createPrato("Preto", "Retangular"));
   push(&stack, createPrato("Azul", "Quadrado"));
   push(&stack, createPrato("Roxo", "Retangular"));

   pop(&stack);
   pop(&stack);
   pop(&stack);

   return 0;
}