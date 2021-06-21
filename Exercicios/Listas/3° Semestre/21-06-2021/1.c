#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   float info;
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

void push(CELL **stack, float x) {
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

float stackTop(CELL *stack) {
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

int main() {
   printf("Pilha Dinamica - Leandro Ribeiro de Souza \n\n");
   
   CELL *stack;
   init(&stack);

   push(&stack, 1);
   push(&stack, 2);
   push(&stack, 3);
   push(&stack, 4);
   push(&stack, 5);

   print(stack);

   pop(&stack);
   pop(&stack);
   pop(&stack);

   print(stack);
   printf("\nElemento no topo: %0.2f.\n", stackTop(stack));

   push(&stack, 6);
   push(&stack, 7);

   print(stack);

   return 0;
}