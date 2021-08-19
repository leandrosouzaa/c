#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   float info;
   struct sCELL *next;
} CELL;

typedef struct sDEQUE {
   CELL *start;
   CELL *end;
} DEQUE;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void freeNode(CELL *cell) {
   free(cell);
} 

int isEmpty(DEQUE deque) {
   return deque.start == NULL ? 1 : 0;
}

void init(DEQUE *deque) {
   deque->end = NULL;
   deque->start = NULL;
}

void insert_start(DEQUE *deque, float x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }
   
   q->info = x;

   if(isEmpty(*deque)) {
      q->next = NULL;
      deque->start = deque->end = q;
   } else {
      q->next = deque->start;
      deque->start = q;
   }
}

void insert_end(DEQUE *deque, float x) {
   CELL *q = getNode();
   
   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }
   q->info = x;
   q->next = NULL;

   if(isEmpty(*deque)) {
      q->next = NULL;
      deque->start = q;
   } else {
      CELL *aux = deque->end;
      aux->next = q;
   }
   deque->end = q;
}

float remove_start (DEQUE *deque) {
   if(isEmpty(*deque)) {
      printf("\nERRO: Fila Vazia.\n");
      exit(1);
   }

   float temp = (deque->start)->info;
   if(deque->end == deque->start) {
      freeNode(deque->start);
      deque->start = deque->end = NULL;
   } else {
      CELL *aux = deque->start;
      deque->start =aux->next;
      freeNode(aux);
   }

   return temp;
}

float remove_end(DEQUE *deque) {
   if(isEmpty(*deque)) {
      printf("\nERRO: Fila Vazia.\n");
      exit(1);
   }

   int temp = deque->end->info;

   if(deque->start == deque->end) {
      freeNode(deque->end);
      deque->start = deque->end = NULL;
   } else {
      CELL *aux = deque->start;
      while(aux->next != deque->end) {
         aux = aux->next;
      }
      freeNode(deque->end);
      aux->next = NULL;
      deque->end = aux;
   }

   return temp;
}

void print(DEQUE DEQUE) {
   CELL *aux = DEQUE.start;

   if(isEmpty(DEQUE)) {
      printf("\nFila Vazia.\n");
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
   printf("Deque  - Leandro Ribeiro de Souza \n\n");
   DEQUE deque;
   init(&deque);

   insert_start(&deque, 1);
   insert_start(&deque, 2);
   insert_end(&deque, 3);
   insert_start(&deque, 4);
   insert_start(&deque, 5);
   print(deque);

   remove_end(&deque);
   remove_end(&deque);
   remove_end(&deque);
   print(deque);

   return 0;
}