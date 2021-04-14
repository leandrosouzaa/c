#define TAM 50
#include <stdio.h>
#include <string.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

typedef struct sLocatorio {
   int cpf;
   char nome[40]; 
} LOCATORIO;

typedef struct sBarraca {
   char aluguel;
   LOCATORIO locatorio;
   int produto;
} BARRACA;

typedef struct sLista {
   int n;
   BARRACA barracas[TAM];
} LISTA;

void lista_inicializar(LISTA *L) {
   L->n = -1;
}

int lista_inserir(LISTA *l, BARRACA item) {
   if(l->n+1 == TAM) {
      printf("\nERRO - Lista cheia");
      return 1;
   };

   l->barracas[++l->n] = item;

   return 0;
}

void relatorio_inadiplentes(LISTA *l) {
   for(int i=0; i < l->n+1; i++) {
      if(l->barracas[i].aluguel == 'I') {
         printf("\nBARRACA INADIPLENTE: ", i+1);
         printf("CPF: %d.\n", l->barracas[i].locatorio.cpf);
         printf("Nome: %s.\n", l->barracas[i].locatorio.nome);
      }
   }
}

void relatorio_barracas(LISTA *l) {
   int livres = 0, ocupadas = 0;
   for(int i=0; i < TAM; i++) {
      printf("\nCódigo: %d.\n", i+1);
      printf("\nSituação: ");
      if(i > l->n) {
         printf("Ocupada.\n");
         ocupadas++;
      } else {
         livres++;
         printf("Disponível.\n");
      }
   }

   printf("\nTotal de Barracas Livres: %d.\n", livres);
   printf("\nTotal de Barracas Ocupadas: %d.\n", ocupadas);
}


int main() {
   LISTA l;
   lista_inicializar(&l);

   int opcao;
   do {
      printf("\nSistema de Barracas - PE3005739.\n\n");
      printf("1 - Cadastrar Nova Barraca.\n");
      printf("2 - Relatório de Inadiplentes.\n");
      printf("3 - Barracas Livres.\n");

      printf("\nSelecione um item: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         BARRACA barraca;
         printf("Dados do Locatorio: \n");
         printf("CPF: ");
         scanf("%d", &barraca.locatorio.cpf);
         printf("Nome: ");
         scanf("%d");
         readString(barraca.locatorio.nome, 40);
         printf("\nSituação do Aluguel (P ou I): ");
         scanf(" %c", &barraca.aluguel);
         printf("\nTipo de Produto: \n");
         printf("1 - Bebida.\n");
         printf("2 - Lanches.\n");
         printf("3 - Artigos Geral.\n");
         printf("Informe o código de venda: ");
         scanf("%d", &barraca.produto);

         lista_inserir(&l, barraca);
         break;

      case 2:
         relatorio_inadiplentes(&l);
         break;

      case 3:
         relatorio_barracas(&l);
         break;

      default:
         break;
      }
   } while(1);

   return 0;
}