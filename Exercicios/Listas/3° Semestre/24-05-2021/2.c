#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char str[], int size) {
   setbuf(stdin, NULL);
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sFormando {
   int pront;
   char nome[50];
   char curso[10];
   int ano_ingresso;
   char endereco[100];
   char telefone[2][50];
} FORMANDO;

typedef struct sCell {
   FORMANDO formando;
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

CELL* insertStart(CELL *list, FORMANDO f) {
   CELL *q = getnode();
   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return NULL;
   }
   q->formando = f;
   q->next = list;
   list = q;

   return list;
}

CELL* insertEnd(CELL *list, FORMANDO f) {
   CELL *q;
   CELL *aux;

   q=getnode();
   q->next = NULL;
   q->formando = f;

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return NULL;
   } else {
      if(isEmpty(list)) {
         list = insertStart(list, f);
      } else {
         aux = list;
         while(aux->next != NULL)
            aux = aux->next;
         aux->next = q;
      }
      return list; 
   }
   
   aux = list;
   while(aux != NULL) {
      aux = aux->next;
   }
   aux->next = q;
}

FORMANDO readFormando() {
   FORMANDO f;

   printf("\nProntuario: PE");
   scanf("%d", &f.pront);

   printf("Nome: ");
   readString(f.nome, 50);

   printf("Curso: ");
   readString(f.curso, 10);

   printf("Endereco: ");
   readString(f.endereco, 100);

   printf("Telefone 1: ");
   readString(f.telefone[0], 50);

   printf("Telefone 2: ");
   readString(f.telefone[1], 50);

   printf("Ano de Ingresso: ");
   scanf("%d", &f.ano_ingresso);

   return f;
}

void printByCurso(CELL *list, char str[]) {
   CELL *aux = list;
   while(aux != NULL) {
      if(strcmp(str, aux->formando.curso) == 0) {
         printf("\nProntuario: PE%d.\n", aux->formando.pront);
         printf("Nome: %s.\n",aux->formando.nome);
         printf("Curso: %s.\n",aux->formando.curso);
         printf("Endereco: %s.\n",aux->formando.endereco);
         printf("Telefone 1: %s.\n",aux->formando.telefone[0]);
         printf("Telefone 2: %s.\n",aux->formando.telefone[1]);
         printf("Ano de Ingresso: %d.\n",aux->formando.ano_ingresso);
      }      
      aux = aux->next;
   }
}

void printByAno(CELL *list, int ano) {
   CELL *aux = list;
   while(aux != NULL) {
      if(aux->formando.ano_ingresso == ano) {
         printf("\nProntuario: PE%d.\n", aux->formando.pront);
         printf("Nome: %s.\n",aux->formando.nome);
         printf("Curso: %s.\n",aux->formando.curso);
         printf("Endereco: %s.\n",aux->formando.endereco);
         printf("Telefone 1: %s.\n",aux->formando.telefone[0]);
         printf("Telefone 2: %s.\n",aux->formando.telefone[1]);
         printf("Ano de Ingresso: %d.\n",aux->formando.ano_ingresso);
      }      
      aux = aux->next;
   }
}

int main() {
   int opcao, temp;
   CELL *list, *q;
   char str[50];
   list = init(list);   
   
   do {
      printf("\n\nBaile de Formatura - Leandro Ribeiro de Souza \n\n");
      
      printf("1 - Cadastrar Formando.\n");
      printf("2 - Relatorio Por Ano.\n");
      printf("3 - Relatorio Por Inicio.\n");
      printf("0 - Encerrar Aplicacao.\n");

      printf("\nInforme um item: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         printf("\nCADASTRO DE ALUNO\n-----------------");
         list = insertEnd(list, readFormando());
         break;
      case 2:
         printf("\nRELATORIO POR CURSO\n-----------------\n");
         printf("Curso: ");
         readString(str, 50);
         printByCurso(list, str);
         break;
      case 3:
         printf("\nRELATORIO POR ANO\n-----------------\n");
         printf("Ano: ");
         scanf("%d", &temp);
         printByAno(list, temp);
         break;
      case 0:
         printf("\nEncerrando Sistema....");
         break;
      default:
         break;
      }
   } while(opcao != 0);

   return 0;
}