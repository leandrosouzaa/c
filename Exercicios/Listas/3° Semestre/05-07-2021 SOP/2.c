#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct sCELL {
   int info;
   struct sCELL *next;
} CELL;

CELL* getNode() {
   return (CELL *) malloc(sizeof(CELL));
}

void init(CELL **list) {
   *list = NULL;
}

void killProcess(int pid) {
   kill(pid, SIGKILL);
}

int isEmpty(CELL *list) {
   return list == NULL ? 1 : 0;
}

void insert(CELL **list, int value) {
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

void print(CELL *list) {
   CELL *aux = list;
   int i = 1;

   if(isEmpty(list)) {
      // printf("\nTodos os processos filhos foram encerrados. Chegou a vez do pai.\n");
      // exit(0);
   }

   printf("\n");
   while(aux != NULL) {
      printf("[%d] - Processo Filho numero %d.\n", aux->info, i);
      i++;
      aux = aux->next;
   }
   printf("\n");
}

CELL* findByValue(CELL **list, int x) {
   if(isEmpty(*list)) {
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

void removePosition(CELL **list, int x) {
   CELL *q;
   CELL *aux = *list;
   q = findByValue(list, x);
   if(q != NULL) {
      killProcess(x);
      if(q == aux) {
         CELL *q= *list;
         *list = q->next;
         free(q);
      } else {
         while(aux->next != q) {
            aux = aux->next;
         }
         aux->next = q->next;
         free(q);
      }
      printf("Processo encerrado. Pressione Enter para continuar.");
   } else {
      printf("Processo nao localizado. Pressione Enter para continuar.");
   }
}

int main() {
   printf("Manipulacao e Exclusao de Processos - Leandro Ribeiro de Souza \n\n");
   
   sCELL *list;
   init(&list);
   
   int temp, quantidade, cPid;

   printf("Informe o numero de processos que deseja criar: ");
   scanf("%d", &quantidade);

   for(int i = 0; i < quantidade; i++) {
      cPid = fork();
      if(cPid == 0) {
         while(1);
      } else {
         insert(&list, cPid);
      }
   }
   cPid = fork();

   if(fork != 0) {
      killProcess(cPid);

      while(wait(0) != -1) {
         system("clear");

         printf("Processo pai: %d.\n\n", getpid());
         printf("Lista de Processos Filhos em execucao: ");
         
         print(list);
         
         printf("Digite um PID para matar: ");
         scanf("%d", &temp);
         
         if(temp == getpid()) {
            printf("Nao e possivel finalizar o processo pai. Pressione Enter para continuar.");
         } else {
            removePosition(&list, temp);
         }
         
         setbuf(stdin, NULL);
         getchar();
      }  
   }

   printf("aaaaaa");
   return 0;
}