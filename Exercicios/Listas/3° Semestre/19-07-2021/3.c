#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sASTRO {
   char nome[50];
   float dim;
   int qtdExistente;
} ASTRO;

typedef struct sCELL {
   ASTRO info;
   struct sCELL *next;
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

int isEmpty(CELL *list) {
   return list == NULL ? 1 : 0; 
}

void insert(CELL **list, ASTRO value) {
   CELL *atual = *list;
   CELL *anterior = NULL;
   CELL *q = getNode();

   if(q != NULL) {
      q->info = value;
      q->next = NULL;

      while(atual != NULL && atual->info.qtdExistente > value.qtdExistente) {
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
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
   }

   CELL *aux;
   aux = list;

   while(aux) {
      printf("\nNome do Astro: %s.\n", (aux->info).nome);
      printf("Dimensao media: %.2fkm².\n", (aux->info).dim);
      printf("Quantidade Existente: %d.\n", (aux->info).qtdExistente);
      
      aux = aux->next;
   }
   printf("\n");
}

int main() {
   int opcao;
   ASTRO temp_astro;
   CELL *list;
   init(&list);

   do {
      printf("\nToninho Dos Astros - Leandro Ribeiro de Souza\n\n");

      printf("1 - Inserir Astro\n");
      printf("2 - Listar Astros\n");
      printf("\n0 - Encerrar Sistema\n\n");
      printf("Escolha um item: ");
      scanf("%d", &opcao);

      switch(opcao) {
         case 1:
            printf("Nome do Astro: ");
            setbuf(stdin, NULL);
            readString(temp_astro.nome, 50);
            printf("Dimensao media (km²): ");
            scanf("%f", &temp_astro.dim);
            printf("Quantidade: ");
            scanf("%d", &temp_astro.qtdExistente);

            insert(&list, temp_astro);
            break;

         case 2:
            printf("\nLista de Astros Cadastrados: \n");
            print(list);
            break;
         
         case 0:
            printf("Encerrando o sistema...");
            break;
         
         default:
            printf("Valor invalido. Tente novamente\n");
            break;
      }
   } while(opcao != 0);

   return 0;
}