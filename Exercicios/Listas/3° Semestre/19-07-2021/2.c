#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sSITE {
   char nome[50], endereco[100];
} SITE;

typedef struct sCELL {
   SITE info;
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

void print(CELL *list) {
   if(isEmpty(list)) {
      printf("\nAVISO: Lista Vazia.\n");
   }

   CELL *aux;
   aux = list;

   while(aux) {
      printf("\nNome do Site: %s\n", (aux->info).nome);
      printf("Endereco: %s\n", (aux->info).endereco);
      
      aux = aux->next;
   }
   printf("\n");
}

void reallocCell(CELL **list, CELL *q) {
   CELL *aux = *list;
   
   if(q == aux) {
      return;
   } else {
      while(aux->next != q) {
         aux = aux->next;
      }
      aux->next = q->next;
      q->next = *list;
      *list = q;
   }
}

CELL* findByValue(CELL **list, char nome[50]) {
   if(isEmpty(*list)) {
      printf("\nAVISO: Lista Vazia.\n");
   } else {
      CELL *aux = *list;
      while(aux != NULL) {
         if(strcmp(nome, (aux->info).nome) == 0) {
            reallocCell(list, aux);
            return aux;
         }
         aux = aux->next;
      }
   }

   return NULL;
}

void insert(CELL **list, SITE x) {
   CELL *q;
   CELL *aux;

   q = getNode();
   q->next = NULL;
   q->info = x;

   if(!q) {
      printf("\nERRO: Nao foi possivel alocar uma nova celula.\n");
      return;
   } else {
      if(isEmpty(*list)) {
         *list = q;
      } else {
         aux = *list;
         while(aux->next != NULL)
            aux = aux->next;
         aux->next = q;
      }
   }
}

SITE createSite(const char nome[50], const char endereco[100]) {
   SITE site;
   strcpy(site.nome, nome);
   strcpy(site.endereco, endereco);

   return site;
};

void start(CELL **lista) {
   insert(lista, createSite("Moodle", "www.moodle.com"));
   insert(lista, createSite("SUAP", "www.suap.com"));
   insert(lista, createSite("AprendaED", "www.aprendaed.com"));
   insert(lista, createSite("TranqueAgora", "www.tranqueagora.com"));
}

int main() {
   CELL *lista;
   init(&lista);

   int opcao;
   SITE site_temp;
   char nome[50];
   CELL *celulaEncontrada;

   // PROFESSOR, CRIEI ALGUNS REGISTROS
   // ESTASTICOS PARA FACILITAR A TESTAGEM
   // POREM A INSERCAO DINAMICA FUNCIONA NORMALMENTE
   start(&lista);

   do {
      printf("\nCadastro De Sites - Leandro Ribeiro de Souza \n\n");
      printf("1 - Cadastrar Website\n");
      printf("2 - Buscar Website\n");
      printf("3 - Listar Todos\n");
      printf("\n0 - Encerrar Sistema.\n\n");
      printf("Escolha um item: ");
      scanf("%d", &opcao);

      switch(opcao) {
         case 1:
            printf("Informe o Nome do Site: ");
            setbuf(stdin, NULL);
            readString(site_temp.nome, 50);
            printf("Informe o Endereco do Site: ");
            setbuf(stdin, NULL);
            readString(site_temp.endereco, 100);

            insert(&lista, site_temp);
            break;

         case 2:
            printf("Nome do Site para a Busca: ");
            setbuf(stdin, NULL);
            readString(nome, 50);

            celulaEncontrada = findByValue(&lista, nome);

            if(celulaEncontrada != NULL) {
               printf("Nome do Site: %s\n", (celulaEncontrada->info).nome);
               printf("Endereco: %s\n", (celulaEncontrada->info).endereco);
            } else {
               printf("Site nao encontrado!\n");
            }
            break;

         case 3:
            printf("\nLista de Todos Websites Cadastrados: \n");
            print(lista);
            break;

         case 0:
            printf("\nEncerrando Sistema...");
            break;

         default:
            printf("Valor invalido. Tente novamente\n");
            break;
      }

   } while(opcao != 0);
   
   return 0;
}