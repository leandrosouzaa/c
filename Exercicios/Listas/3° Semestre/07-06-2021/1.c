#include <stdio.h>
#include <stdlib.h>

typedef struct sCell {
   int info;
   struct sCell *next;
} CELL;

void init(CELL **list) {
   *list = NULL;
}

CELL* getNode() {
   return (CELL *) malloc (sizeof(CELL));
}

void freenode(CELL *q) {
   free(q);
}

int isEmpty(CELL **list) {
   return *list == NULL ? 1 : 0; 
}

void print(CELL **list) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
   }

   CELL *aux;
   aux = *list;

   printf("\n");
   while(aux) {
      printf("%d ", aux->info);
      aux = aux->next;
   }
   printf("\n");
}

CELL* findByValue(CELL **list, int x) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
   } else {
      CELL *aux = *list;
      while(aux != NULL) {
         if(aux->info == x) {
            return aux;
         }
         aux = aux->next;
      }
   }
   return NULL;
}

void insertStart(CELL **list, int x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return;
   }

   q->info = x;
   q->next = *list;
   *list = q;
}

void insertEnd(CELL **list, int x) {
   CELL *q;
   CELL *aux;

   q = getNode();
   q->next = NULL;
   q->info = x;

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return;
   } else {
      if(isEmpty(list)) {
         *list = q;
      } else {
         aux = *list;
         while(aux->next != NULL)
            aux = aux->next;
         aux->next = q;
      }
   }
}

void removeStart(CELL **list) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
      return;
   }
   CELL *q= *list;
   *list = q->next;
   free(q);
}

void removePosition(CELL **list, int x) {
   CELL *q;
   CELL *aux = *list;
   q = findByValue(list, x);
   if(q != NULL) {
      if(q == aux) {
         removeStart(list);
      } else {
         while(aux->next != q) {
            aux = aux->next;
         }
         aux->next = q->next;
         free(q);
      }
   }
}

int size(CELL *list) {
   CELL *aux;
   aux = list;
   int count = 0;
   while (aux != NULL) {
      aux = aux->next;
      count++;
   }

   return count;      
}

void removeEnd(CELL **list) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
      return;
   }

   CELL *aux = *list;
   CELL *q;

   if(aux->next == NULL) {
      removeStart(list);
   } else {
      while((aux->next)->next != NULL) {
         aux = aux->next;
      }

      q = aux->next;
      aux->next = NULL;
      free(q);
   }
}

CELL* concat(CELL *list1, CELL *list2) {
   CELL *aux1, *aux2, *q;
   aux1 = list1;
   aux2 = list2;

   if(size(list1) >= size(list2)) {
      while(aux1 != NULL) {
         if(aux2 != NULL) {
            q = getNode();

            q->info = aux2->info;
            q->next = aux1->next;
            aux1->next = q;

            aux2 = aux2->next;
            aux1 = (aux1->next)->next;

         } else {
            aux1 = aux1->next;
         }
      }
   } else {
      while(aux1 != NULL) {
         q = getNode();

         q->info = aux2->info;
         q->next = aux1->next;
         aux1->next = q;

         aux2 = aux2->next;
         aux1 = (aux1->next)->next;
      }
      q = getNode();

      q->info = aux2->info;
      q->next = aux2->next;
      aux1 = q;
      aux2 = aux2->next;

      while(aux2 != NULL) {
         q = getNode();
         q->info = aux2->info;
         q->next = aux1->next;
         aux1->next = q;
         aux2 = aux2->next;
      }

   }

   return list1;
}

int main() {
   CELL *list;
   init(&list);

   insertEnd(&list, 1);
   insertEnd(&list, 3);
   insertEnd(&list, 5);
   insertEnd(&list, 7);
   removeEnd(&list);
   removeStart(&list);

   print(&list);
   return 0;
}