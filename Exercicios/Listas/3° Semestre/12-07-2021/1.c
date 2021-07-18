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

int size(CELL *list) {
   if(list == NULL) {
      return 0;
   }
   
   return size(list->next) + 1;
}

int sum(CELL *list) {
   if(list == NULL) {
      return 0;
   }
   
   return sum(list->next) + list->info;
}

int multiplication(CELL *list) {
   if(list == NULL) {
      return 1;
   }
   
   return multiplication(list->next) * list->info;
}

void showOdd(CELL *list) {
   if(list == NULL) {
      return;
   }

   if(list->info % 2 == 1) {
      printf("%d ", list->info);
   }

   showOdd(list->next);
}

void showInverse(CELL *list) {
   if(list == NULL) {
      return;
   }

   showInverse(list->next);

   printf("%d ", list->info);
};

int main() {
   CELL *list;
   init(&list);

   insertEnd(&list, 1);
   insertEnd(&list, 3);
   insertEnd(&list, 5);
   insertEnd(&list, 7);
   insertStart(&list,10);
   insertStart(&list,11);
   insertStart(&list,12);
   insertStart(&list,13);
   insertEnd(&list, 9);

   print(&list);

   printf("Tamanho da lista: %d.\n", size(list));
   printf("Soma da lista: %d.\n", sum(list));
   printf("Soma da lista: %d.\n", multiplication(list));
   printf("Impares: ");
   showOdd(list);
   printf("\nLista ao contrario: ");
   showInverse(list);

   return 0;
}