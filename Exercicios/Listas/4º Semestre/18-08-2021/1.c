#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sCarro {
   char placa[10];
   char dono[100];
} CARRO;

CARRO readCARRO() {
   CARRO carro;
   printf("Placa: ");
   readString(carro.placa, 10);
   printf("Dono: ");
   readString(carro.dono, 100);

   return carro;
};

typedef struct sCELL {
   CARRO info;
   struct sCELL *next;
} CELL;

typedef struct sQUEUE {
   CELL *start;
   CELL *end;
} QUEUE;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void init(CELL **list) {
   *list = NULL;
}

void initQUEUE(QUEUE *queue) {
   queue->end = NULL;
   queue->start = NULL;
}

void freeNode(CELL *cell) {
   free(cell);
}

int isEmpty(CELL **list) {
   return *list == NULL ? 1 : 0;
}

int isEmptyQUEUE(QUEUE queue) {
   return queue.start == NULL ? 1 : 0;
   return queue.start == NULL ? 1 : 0;
}

CELL* findByValue(CELL **list, char placa[10]) {
   if(isEmpty(list)) {
      printf("\nEstacionamento Vazio.\n");
   } else {
      CELL *aux = *list;
      while(aux != NULL) {
         if(strcmp(placa, aux->info.placa) == 0) {
            return aux;
         }
         aux = aux->next;
      }
   }
   return NULL;
}

CELL* findByValueQUEUE(QUEUE queue, char placa[10]) {
   CELL *temp = queue.start;
   
   if(isEmpty(&temp)) {
      printf("\nEstacionamento Vazio.\n");
   } else {
      CELL *aux = temp;
      while(aux != NULL) {
         if(strcmp(placa, aux->info.placa) == 0) {
            return aux;
         }
         aux = aux->next;
      }
   }
   return NULL;
}

void insertQUEUE(QUEUE *queue, CARRO x) {
   CELL *q = getNode();
   
   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }
   q->info = x;
   q->next = NULL;

   if(isEmptyQUEUE(*queue)) {
      q->next = NULL;
      queue->start = q;
   } else {
      CELL *aux = queue->end;
      aux->next = q;
   }
   queue->end = q;
}

CARRO remove(QUEUE *queue) {
   CARRO temp = (queue->start)->info;
   if(queue->end == queue->start) {
      freeNode(queue->start);
      queue->start = queue->end = NULL;
   } else {
      CELL *aux = queue->start;
      queue->start =aux->next;
      freeNode(aux);
   };

   return temp;
}

int removeQUEUE(QUEUE *queue, char placa[10]) {
   CELL *aux = findByValueQUEUE(*queue, placa);
   CELL *temp = queue->start;
   CARRO carro;

   if(aux == NULL) {
      return 0;
   }

   while(strcmp(queue->start->info.placa, placa) != 0) {
      carro = remove(queue);
      insertQUEUE(queue, carro);
   }

   remove(queue);

   return 1;
}

void insertSTACK(CELL **stack, CARRO x) {
   CELL *q = getNode();

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar o no.\n");
      exit(1);
   }

   q->info = x;
   q->next = *stack;
   *stack = q;
}

CARRO pop(CELL **stack) {
   CELL *aux = *stack;

   CARRO carro = aux->info;

   *stack = (*stack)->next;
   freeNode(aux);

   return carro;
}

int removeSTACK(CELL **stack, char placa[10]) {
   CELL *temp = *stack;
   CELL *aux = findByValue(stack, placa);
   init(&temp);

   if(aux == NULL) {
      return 0;
   }

   while(*stack != aux) {
      insertSTACK(&temp, pop(stack));
   }

   pop(stack);

   while(!isEmpty(&temp)) {
      insertSTACK(stack, pop(&temp));
   }

   return 1;
}

int removeLIST(CELL **list, char placa[10]) {
   CELL *q;
   CELL *aux = *list;
   q = findByValue(list, placa);
   if(q != NULL) {
      if(q == aux) {
         *list = q->next;
         free(q);

         return 1;
      } else {
         while(aux->next != q) {
            aux = aux->next;
         }
         aux->next = q->next;
         free(q);

         return 1;
      }
   }

   return 0;
}


void insertLIST(CELL **list, CARRO value) {
   CELL *atual = *list;
   CELL *anterior = NULL;
   CELL *q = getNode();

   if(q != NULL) {
      q->info = value;
      q->next = NULL;

      while(atual != NULL && strcmp(value.placa, atual->info.placa) > 0) {
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
      printf("\nEstacionamento Vazio.\n");
      return;
   }

   printf("\n");
   while(aux != NULL) {
      printf("\nPlaca: %s.\n",aux->info.placa);
      printf("Dono: %s.\n",aux->info.dono);
      aux = aux->next;
   }
   printf("\n");
}

void menuQUEUE(QUEUE *queue) {
   int temp;
   char placa[10];

   system("clear");

   do {
      printf("\nFila - Estacionamento\n\n");

      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Listar\n");

      printf("\n0 - Sair\n");

      printf("\nEscolha um item: ");
      scanf("%d", &temp);
      
      switch (temp) {
      case 1:
         setbuf(stdin, NULL);
         printf("\nCadastro de Carro - FILA: \n");
         insertQUEUE(queue, readCARRO());
         break;

      case 2:
         printf("\nRemocao de Carro - FILA: \n");
         printf("Informe uma placa: ");
         setbuf(stdin, NULL);
         readString(placa, 10);
         if (removeQUEUE(queue, placa) == 0) {
            printf("Nao foi possivel remover. Verifique e tente novamente.\n");
         }
         break;
         
      case 3:
         printf("\nListagem de Carro - FILA:");
         print(&queue->start);
         break;

      default:
         printf("\nItem invalido, tente novamente.\n\n");
         break;
      }
   } while(temp != 0);
}

void menuSTACK(CELL **stack) {
   int temp;
   char placa[10];

   system("clear");

   do {
      printf("\nPilha - Estacionamento\n\n");

      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Listar\n");

      printf("\n0 - Sair\n");

      printf("\nEscolha um item: ");
      scanf("%d", &temp);
      
      switch (temp) {
      case 1:
         setbuf(stdin, NULL);
         printf("\nCadastro de Carro - PILHA: \n");
         insertSTACK(stack, readCARRO());
         break;

      case 2:
         printf("\nRemocao de Carro - PILHA: \n");
         printf("Informe uma placa: ");
         setbuf(stdin, NULL);
         readString(placa, 10);
         if (removeSTACK(stack, placa) == 0) {
            printf("Nao foi possivel remover. Verifique e tente novamente.\n");
         }
         break;
         
      case 3:
         printf("\nListagem de Carro - PILHA:");
         print(stack);
         break;

      default:
         printf("\nItem invalido, tente novamente.\n\n");
         break;
      }
   } while(temp != 0);
}

void menuLIST(CELL **list) {
   int temp;
   char placa[10];

   system("clear");

   do {
      printf("\nLista - Estacionamento\n\n");

      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Listar\n");

      printf("\n0 - Sair\n");

      printf("\nEscolha um item: ");
      scanf("%d", &temp);
      
      switch (temp) {
      case 1:
         setbuf(stdin, NULL);
         printf("\nCadastro de Carro - LISTA: \n");
         insertLIST(list, readCARRO());
         break;

      case 2:
         printf("\nRemocao de Carro - LISTA: \n");
         printf("Informe uma placa: ");
         setbuf(stdin, NULL);
         readString(placa, 10);
         if (removeLIST(list, placa) == 0) {
            printf("Nao foi possivel remover. Verifique e tente novamente.\n");
         }
         break;
         
      case 3:
         printf("\nListagem de Carro - LISTA:");
         print(list);
         break;

      default:
         printf("\nItem invalido, tente novamente.\n\n");
         break;
      }
   } while(temp != 0);
}

int main() {
   CELL *lista, *stack;
   QUEUE queue;
   initQUEUE(&queue);
   init(&lista);
   init(&stack);
   int temp;

   do {
      printf("\nEstacionamento - Leandro Ribeiro de Souza \n\n");

      printf("1 - Pilha\n");
      printf("2 - Fila\n");
      printf("3 - Lista\n");

      printf("\n0 - Sair\n");

      printf("\nEscolha um item: ");
      scanf("%d", &temp);
      
      switch (temp) {
      case 1:
         menuSTACK(&stack);
         break;

      case 2:
         menuQUEUE(&queue);
         break;
      
      case 3:
         menuLIST(&lista);
         break;

      case 0:
         printf("\nEncerrando sistema...\n\n");
         break;

      default:
         printf("\nItem invalido, tente novamente.\n\n");
         break;
      }
   } while(temp != 0);

   return 0;
}