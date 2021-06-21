#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   int info;
   struct sCELL *next;
} CELL;

CELL* getNode() {
   return (CELL*) malloc(sizeof(CELL));
};

void init(CELL **list) {
   CELL *q = getNode();
   q->info = 0;
   q->next = NULL;

   *list = q;
}

int isEmpty(CELL *list) {
   return list->next == NULL ? 1 : 0;
}

void freeNode(CELL *cell) {
   free(cell);
}

void insert_end(CELL **list, int x) {
   CELL *q = getNode();

   if(q == NULL) {
      printf("\nErro na alocacao de no.\n");
      exit(1);
   }
   q->info = x;

   if(isEmpty(*list)) {
      (*list)->next = q;
      q->next = *list;
   } else {
      CELL *aux = (*list)->next;
      while(aux->next->info > 0) {
         aux = aux->next;
      }
      aux->next = q;
      q->next = *list;
   }
}

void remove_start(CELL **list) {
   CELL *aux;

   if(isEmpty(*list)) {
      printf("\nErro: Lista vazia.\n");
      exit(1);  
   }

   aux = (*list)->next;
   if((aux->next == *list)) {
      (*list)->next = NULL;
   } else {
      (*list)->next = aux->next;
   }

   freeNode(aux);
}

void print(CELL *list) {
   CELL *aux = list->next;

   if(aux == NULL) {
      printf("\nNao ha elemento na lista.");
      return;
   }

   do {
      printf("%d\t", aux->info);
      aux = aux->next;
   } while(aux->info > 0);
   printf("\n");
}

int main() {
   printf("Lista Simplesmente Encadeada Circular - Leandro Ribeiro de Souza \n\n");

   CELL *list;
   init(&list);

   insert_end(&list, 1);
   insert_end(&list, 3);
   insert_end(&list, 5);
   insert_end(&list, 7);
   insert_end(&list, 9);

   print(list);

   remove_start(&list);
   print(list);

   return 0;
}