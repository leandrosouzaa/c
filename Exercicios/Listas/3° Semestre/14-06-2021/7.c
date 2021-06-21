#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   int info;
   struct sCELL *next, *prev;
} CELL;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void freeNode(CELL *cell) {
   free(cell);
}

void init(CELL **list) {
   *list = NULL;
}

int isEmpty(CELL *list) {
   return list == NULL ? 1 : 0;
}

CELL* findByValue(CELL *list, int x) {
   CELL *aux = list;

   if(isEmpty(list)) {
      printf("\nErro: Falha na alocacao de no.\n");
      exit(1);
   }

   while(aux->next != NULL) {
      if(aux->info == x) {
         return aux;
      }
      aux = aux->next;
   }

   return NULL;   
}

void insert_start(CELL **list, int x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nErro: Falha na alocacao de no.\n");
      exit(1);
   }

   q->info = x;
   q->prev = NULL;
   q->next = *list;
   (*list)->prev = q;
   *list = q;
}

void insert_end(CELL **list, int x) {
   CELL *q = getNode();
   CELL *aux = *list;
   if(!q) {
      printf("\nErro: Falha na alocacao de no.\n");
      exit(1);
   }

   q->info = x;
   q->next = NULL;
   q->prev = NULL;

   if(isEmpty((*list))) {
      *list = q;
   } else {
      while(aux->next != NULL) {
         aux = aux->next;
      }
      aux->next = q;
      
      q->prev = aux;
   }
}

void remove_start(CELL **list) {
   CELL *aux = *list;

   if(isEmpty(*list)) {
      printf("\nErro: Lista vazia.\n");
      exit(1);
   }

   *list = (*list)->next;
   (*list)->prev = NULL;

   freeNode(aux);
}

void remove_end(CELL **list) {
   CELL *aux = *list;

   if(isEmpty(*list)) {
      printf("\nErro: Lista vazia.\n");
      exit(1);
   }

   while(aux->next != NULL) {
      aux = aux->next;
   }

   aux->prev->next = NULL;
   freeNode(aux);
}

int remove_value(CELL **list, int x) {
   CELL *q;

   if((q = findByValue(*list, x)) == NULL) {
      return 0;
   }

   if(*list == q) {
      remove_start(list);
   } else {
      CELL *aux = q->prev;
      (q->prev)->next = q->next;
      if(q->next != NULL)
         (q->next)->prev = q->prev;
      freeNode(q);
   }

   return 1;
}

void print(CELL *list) {
   CELL *aux = list;

   if(aux == NULL) {
      printf("\nNao ha elemento na lista.");
      return;
   }

   do {
      printf("%d\t", aux->info);
      aux = aux->next;
   } while(aux != NULL);
   printf("\n");
}

int main() {

   printf("Lista Duplamente Encadeada - Leandro Ribeiro de Souza \n\n");
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