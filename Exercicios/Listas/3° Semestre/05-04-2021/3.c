#define TAMF 10
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int valor[TAMF], n; 
} LISTA;

int lista_cheia(LISTA *L) {
   return (L->n + 1) == TAMF ? 1 : 0; 
}

int lista_vazia(LISTA *L) {
   return (L->n + 1) == 0 ? 1 : 0; 
}

void inicializa_lista(LISTA *L) {
   L->n = -1;
}
int lista_inserir(LISTA *L, int valor) {
   if(lista_cheia(L) == 1) {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }

   int posicao;

   posicao = L->n+1;
   if(lista_vazia(L)) {
      posicao = 0;
   }

   for(int i=0; i < (L->n+1); i++) {
      if(L->valor[i] > valor) {
         posicao = i;
         break;
      }
   }

   for(int i = (L->n+1); i>posicao; i--) {
      L->valor[i] = L->valor[i-1];
   }

   L->valor[posicao] = valor;
   L->n+=1;

   return 0;
};

int lista_apresenta(LISTA *L) {
   if(lista_vazia(L) == 1) {
      printf("\nERRO - Lista vazia.\n");
      return 1;
   }   
   for(int i=0; i<(L->n+1); i++) {
      printf("Lista[%d] - %d.\n", i, L->valor[i]);
   }

   return 0;
}

int main() {
   int opcao, temp;

   LISTA lista;
   inicializa_lista(&lista);

   do {
      printf("\n\nLista - Leandro Ribeiro de Souza \n\n");
      
      printf("1 - Inserir.\n");
      printf("2 - Remover Valor indicado.\n");
      printf("3 - Apresentar Lista.\n");
      printf("0 - Finalizar.");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            printf("\nEscolha o valor: ");
            scanf("%d", &temp);
            lista_inserir(&lista, temp);
            break;

         case 2:
            printf("\nEscolha o valor: ");
            scanf("%d", &temp);
            break;

         case 3:
            printf("Lista: \n");
            lista_apresenta(&lista);

         default:
            break;
      }
   } while(opcao != 0);

   return 0;
}
