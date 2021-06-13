#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sContato {
   char nome[50];
} CONTATO;

typedef struct sCell {
   CONTATO contato;
   struct sCell *next; 
} CELL;

CELL* init(CELL *list) {
   list = NULL;

   return list;
}

CELL* getnode() {
   return (CELL *) malloc(sizeof(CELL));
}

void freenode(CELL *q) {
   free(q);
}

int isEmpty(CELL *list) {
   return list == NULL ? 1 : 0; 
}

int findPosition(CELL *list, char str[]) {
   CELL *aux = list;
   int i = 1;
   printf("\n");
   while(aux != NULL) {
      int r = strcmp(aux->contato.nome, str);
      if(r < 0) {
         printf("caiu");
         return i;
      }
      i++;
      aux = aux->next;
   }

   return 0;
}

void print(CELL *list) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
   }

   CELL *aux;
   aux = list;

   printf("\n");
   while(aux) {
      printf("%s\n", aux->contato.nome);
      aux = aux->next;
   }
   printf("\n");
}

CELL* insert(CELL *list, CONTATO c) {
   CELL *q = getnode();
   CELL *aux = list;

   int position = findPosition(list, c.nome);
   printf("position %d\n", position);
   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return NULL;
   }
   if(position == 0) {
      printf("%s.\n", list->contato.nome);
      q->contato = c;
      q->next = list;
      list = q;
   } else {
      if(position != 1) {
         for(int i = 0; i < position ; i++) {
            aux = aux->next;
         }
      } else {
         q->contato = c;
         q->next = aux->next;
         aux->next = q;
      }

   }

   return list;
}

CONTATO criaContato(const char* nome) {
   CONTATO c;
   strcpy(c.nome, nome);

   return c;
};

int main() {

   printf("Telefones - Leandro Ribeiro de Souza \n\n");

   CELL *list;

   list = init(list);

   list = insert(list, criaContato("bbbbb"));

   list = insert(list, criaContato("ccccc"));

   list = insert(list, criaContato("ddddd"));


   print(list);

   return 0;
}