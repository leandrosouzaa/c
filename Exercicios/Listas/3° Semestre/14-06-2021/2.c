#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sReceita {
   char titulo[50];
   char descricao[100];
   char tipo;
   char autor[50];
} Receita;

typedef struct sCELL {
   Receita info;
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

Receita createReceita(char titulo[50], char descricao[100], char tipo, char autor[50]) {
   Receita receita;
   strcpy(receita.titulo, titulo);
   strcpy(receita.descricao, descricao);
   strcpy(receita.autor, autor);
   receita.tipo = tipo;

   return receita;
};

void insert(CELL **list, Receita value) {
   CELL *atual = *list;
   CELL *anterior = NULL;
   CELL *q = getNode();

   if(q != NULL) {
      q->info = value;
      q->next = NULL;

      while(atual != NULL && strcmp(value.titulo, atual->info.titulo) > 0) {
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
      printf("\nTitulo: %s.\n",aux->info.titulo);
      printf("Descricao: %s.\n",aux->info.descricao);
      printf("Tipo: %s.\n",aux->info.tipo == 'S' ? "Salgado" : "Doce");
      printf("Autor: %s.\n",aux->info.autor);
      aux = aux->next;
   }
   printf("\n");
}

int main() {
   printf("Ordem Decrescente - Leandro Ribeiro de Souza \n\n");
   
   CELL *lista;
   init(&lista);

   insert(&lista, createReceita("Abacates ao Leite", "Abacate", 'D', "Leandro"));
   insert(&lista, createReceita("Bolo de Fuba", "Fuba", 'D', "Joaozinho"));
   insert(&lista, createReceita("Bolo de Cenoura", "Cenoura", 'D', "Pedrinho"));
   insert(&lista, createReceita("Bolo de Brigadeiro", "Brigadeiro", 'D', "Zezinho"));
   insert(&lista, createReceita("Lasanha de Frango", "Frango", 'S', "Vitinho"));
   insert(&lista, createReceita("Torta de Legumes", "Legumes", 'S', "Carlinhos"));
   int temp;
   Receita receita;
   do {
      printf("1 - Cadastrar\n");
      printf("2 - Listar\n");

      printf("0 - Sair\n");
      scanf("%d", &temp);
      
      switch (temp) {
      case 1:
         setbuf(stdin, NULL);
         printf("Titulo: ");
         readString(receita.autor, 50);
         printf("Descricao: ");
         readString(receita.descricao, 100);
         printf("Autor: ");
         readString(receita.autor, 50);
         printf("Tipo: ");
         scanf("%c", &receita.tipo);
         insert(&lista, receita);
         break;
      case 2:
         print(&lista);
      default:
         break;
      }
   } while(temp != 0);
   return 0;
}