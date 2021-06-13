#include <stdio.h>
#include <stdlib.h>

typedef struct sCELL {
   char info;
   struct sCELL *next;
} CELL;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void init(CELL **list) {
   *list = NULL;
}

int isEmpty(CELL **list) {
   return *list == NULL ? 1 : 0;
}


void insert(CELL **list, char value) {
   CELL *atual = *list;
   CELL *anterior = NULL;
   CELL *q = getNode();

   if(q != NULL) {
      q->info = value;
      q->next = NULL;

      while(atual != NULL && atual->info > value) {
         anterior = atual;
         atual = atual->next;
      }

      if(atual == *list) {
         q->next = *list;
         *list = q;
      } else {
         anterior->next = q;
         q->next = atual;
      }
   } else {
      printf("\nERRO na alocacao do no.\n");
   }
}

void print(CELL **list) {
   CELL *aux = *list;

   if(isEmpty(list)) {
      printf("\nLista Vazia.\n");
      return;
   }

   printf("\n");
   while(aux != NULL) {
      printf("%c ", aux->info);
      aux = aux->next;
   }
   printf("\n");
}

int main() {
   printf("Ordem Decrescente - Leandro Ribeiro de Souza \n\n");
   
   CELL *lista;
   init(&lista);

   insert(&lista, 'f');
   insert(&lista, 'c');
   insert(&lista, 'b');
   insert(&lista, 'a');
   insert(&lista, 'e');
   insert(&lista, 'd');

   print(&lista);
   return 0;
}