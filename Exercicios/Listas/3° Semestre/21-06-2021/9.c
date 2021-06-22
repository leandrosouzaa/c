#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   float info;
   struct sCELL *next;
} CELL;

typedef struct sQUEUE {
   CELL *start;
   CELL *end;
} QUEUE;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void freeNode(CELL *cell) {
   free(cell);
} 

int isEmpty(QUEUE queue) {
   return queue.start == NULL ? 1 : 0;
}

void init(QUEUE *queue) {
   queue->end = NULL;
   queue->start = NULL;
}

void insert(QUEUE *queue, float x) {
   CELL *q = getNode();
   
   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }
   q->info = x;

   if(isEmpty(*queue)) {
      q->next = NULL;
      queue->start = q;
   } else {
      CELL *aux = queue->end;
      aux->next = q;
   }
   queue->end = q;
}

float remove(QUEUE *queue) {
   if(isEmpty(*queue)) {
      printf("\nERRO: Fila Vazia.\n");
      exit(1);
   }

   float temp = (queue->start)->info;
   if(queue->end == queue->start) {
      freeNode(queue->start);
      queue->start = queue->end = NULL;
   } else {
      CELL *aux = queue->start;
      queue->start =aux->next;
      freeNode(aux);
   }

   return temp;
}

void print(QUEUE queue) {
   CELL *aux = queue.start;

   if(isEmpty(queue)) {
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
   printf("Fila Duplamente Encadeada - Leandro Ribeiro de Souza \n\n");
   QUEUE queue;
   init(&queue);

   insert(&queue, 1);
   insert(&queue, 2);
   insert(&queue, 3);
   insert(&queue, 4);
   insert(&queue, 5);
   print(queue);

   remove(&queue);
   remove(&queue);
   print(queue);



   return 0;
}