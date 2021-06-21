#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sInfo {
   int num;
   char name[50];
} INFO;

typedef struct sCHANNEL {
   INFO info;
   struct sCHANNEL *next, *prev;
} CHANNEL;

CHANNEL* getNode() {
   return (CHANNEL*) malloc(sizeof(CHANNEL));
};

void init(CHANNEL **list) {
   *list = NULL;
}

int isEmpty(CHANNEL *list) {
   return list == NULL ? 1 : 0;
}

void freeNode(CHANNEL *CHANNEL) {
   free(CHANNEL);
}

void insert_end(CHANNEL **list, INFO x) {
   CHANNEL *q = getNode();

   if(q == NULL) {
      printf("\nErro na alocacao de no.\n");
      exit(1);
   }
   q->info = x;
   q->prev = *list;

   if(isEmpty(*list)) {
      q->next = q;
   } else {
      q->next = (*list)->next;
      (*list)->next = q;
   }
   *list = q;
}

void remove_start(CHANNEL **list) {
   CHANNEL *aux;

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

void remove_end(CHANNEL **list) {
   CHANNEL *aux;

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

void print(CHANNEL *list) {
   CHANNEL *aux = list->next;

   if(aux == NULL) {
      printf("\nNao ha elemento na lista.");
      return;
   }

   do {
      printf("\nCANAL %d.\n", aux->info.num);
      printf("Nome: %s.\n", aux->info.name);
      aux = aux->next;
   } while(aux != list->next);
   printf("\n");
}

void changeChannel(CHANNEL **list, int status) {
   if(status) {
      *list = (*list)->next;
   } else {
      *list = (*list)->prev;
   }
   printf("\nCANAL %d.\n", (*list)->info.num);
   printf("Nome: %s.\n", (*list)->info.name);
}

INFO createChannel(int num, const char name[50]) {
   INFO info;
   info.num = num;
   strcpy(info.name, name);

   return info;
}

int main() {
   printf("Lista Simplesmente Encadeada Circular - Leandro Ribeiro de Souza \n\n");

   CHANNEL *list;
   init(&list);

   insert_end(&list, createChannel(1,"Fox"));
   insert_end(&list, createChannel(2,"Megapix"));
   insert_end(&list, createChannel(3,"Universal"));
   insert_end(&list, createChannel(4,"GNT"));
   insert_end(&list, createChannel(5,"SBT"));
   print(list);

   changeChannel(&list,1);
   changeChannel(&list,1);
   changeChannel(&list,1);
   changeChannel(&list,0);
   changeChannel(&list,1);
   changeChannel(&list,1);
   changeChannel(&list,0);
   return 0;
}