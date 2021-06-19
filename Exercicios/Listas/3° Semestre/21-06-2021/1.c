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
   *list = NULL;
}

int isEmpty(CELL *list) {
   return list == NULL ? 1 : 0;
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
      q->next = q;
   } else {
      q->next = (*list)->next;
      (*list)->next = q;
   }
   *list = q;
}

void insert_start(CELL **list, int x) {
   CELL *q = getNode();

   if(q == NULL) {
      printf("\nErro na alocacao de no.\n");
      exit(1);
   }
   q->info = x;
   
   if(isEmpty(*list)) {
      q->next = q;
   } else {
      CELL *aux = (*list)->next;
      q->next = aux;
      (*list)->next = q;
   }
}

void remove_start(CELL **list) {
   CELL *aux;

   if(isEmpty(*list)) {
      printf("\nErro: Lista vazia.\n");
      exit(1);  
   }

   if((*list) == (*list)->next) {
      freeNode(*list);
      *list = NULL;
   } else {
      aux = (*list)->next;
      (*list)->next = aux->next;
      freeNode(aux);
   }
}

void remove_end(CELL **list) {
   CELL *aux;

   if(isEmpty(*list)) {
      printf("\nErro: Lista vazia.\n");
      exit(1);  
   }

   if((*list) == (*list)->next) {
      freeNode(*list);
      *list = NULL;
   } else {
      aux = *list;
      
      while(aux->next != *list) {
         aux = aux->next;
      }

      aux->next = (*list)->next;
      free(*list);
      *list = aux;
   }
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
   } while(aux != list->next);
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
   remove_start(&list);
   print(list);

   insert_start(&list, 3);
   insert_start(&list, 1);
   print(list);

   remove_end(&list);
   remove_end(&list);
   print(list);
   return 0;
}