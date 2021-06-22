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

void push(CELL **stack, int x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }

   q->info = x;
   q->next = *stack;
   *stack = q;
}

float pop(CELL **stack) {
   if(isEmpty(*stack)) {
      printf("\nPilha Vazia.\n");
      return NULL;
   }

   CELL *aux = *stack;
   int temp = aux->info;

   *stack = (*stack)->next;
   freeNode(aux);

   return temp;
}

float stackTop(CELL *stack) {
   if(isEmpty(stack)) {
      printf("\nPilha Vazia.\n");
      return NULL;
   }
   return stack->info;
}

void invert(CELL **stack) {
   CELL *aux;
   init(&aux);

   while((*stack) != NULL) {
      push(&aux, pop(stack));
   }

   *stack = aux;
};

void topToBase(CELL **stack) {
   CELL *aux;
   init(&aux);

   float top = pop(stack);
   while((*stack)->next) {
      push(&aux, pop(stack));
   }
   float base = pop(stack);


   push(stack, top);
   while(aux != NULL) {
      push(stack, pop(&aux));
   }
   push(stack, base);
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
   printf("Inversao de Pilha - Leandro Ribeiro de Souza\n\n");
   CELL *stack;
   init(&stack);

   push(&stack, 1);
   push(&stack, 2);
   push(&stack, 3);
   push(&stack, 4);
   push(&stack, 5);

   print(stack);
   invert(&stack);
   print(stack);
   topToBase(&stack);
   print(stack);


   return 0;
}