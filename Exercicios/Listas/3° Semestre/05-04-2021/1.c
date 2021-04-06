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

int lista_inserir_posicao(LISTA *L, int posicao, int valor) {
   if(lista_cheia(L) == 1) {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }
   if(posicao > (L->n + 1) || posicao < 0) {
      printf("\nERRO - Fora dos limites.\n");
      return 1;
   }

   for(int i =(L->n+1); i<posicao; i--) {
      L->valor[i] = L->valor[i-1];
   }

   L->valor[posicao] = valor;
   L->n+=1;
   return 0;
};

int lista_remover_posicao(LISTA *L, int posicao) {
   if(lista_vazia(L) == 1) {
      printf("\nERRO - Lista vazia.\n");
      return 1;
   }
   if(posicao > (L->n + 1) || posicao < 0) {
      printf("\nERRO - Fora dos limites.\n");
      return 1;
   }

   for(int i=posicao; i<L->n+1; i++) {
      L->valor[i] = L->valor[i+1];
   }

   L->n-=1;
   return 0;
}

int lista_acessa_posicao(LISTA *L, int posicao) {
   if(posicao > (L->n + 1) || posicao < 0) {
      printf("\nERRO - Fora dos limites.\n");
   } else {
      return L->valor[posicao];
   }
}

int lista_busca_valor(LISTA *L, int valor) {
   if(lista_vazia(L) == 1) {
      printf("\nERRO - Lista vazia.\n");
      return -1;
   }   
   
   for(int i=0; i<(L->n+1); i++) {
      if(L->valor[i] == valor) {
         return i;
      }
   }

   return -1;
}

void lista_apresenta(LISTA *L) {
   if(lista_vazia(L) == 1) {
      printf("\nERRO - Lista vazia.\n");
   }   
   for(int i=0; i<(L->n+1); i++) {
      printf("Lista[%d] - %d.\n", i, L->valor[i]);
   }
}

int main() {
   int opcao, posicao,valor;

   LISTA lista;
   inicializa_lista(&lista);

   do {
      printf("\n\nLista - Leandro Ribeiro de Souza \n\n");
      
      printf("1 - Inserir Elemento em posicao especifica.\n");
      printf("2 - Remove elemento de uma posicao especifica.\n");
      printf("3 - Acessar elemento de uma posicao especifica.\n");
      printf("4 - Procurar determinado elemento.\n");
      printf("5 - Exibir Lista.\n");
      printf("0 - Finalizar");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            printf("\nEscolha uma posição para inserir: ");
            scanf("%d", &posicao);
            printf("Valor para inserir: ");
            scanf("%d", &valor);
            lista_inserir_posicao(&lista, posicao, valor);
            break;

         case 2:
            printf("\nEscolha uma posição para remover: ");
            scanf("%d", &posicao);
            lista_remover_posicao(&lista, posicao);
            break;

         case 3:
            printf("\nEscolha uma posição para visualizar: ");
            scanf("%d", &posicao);
            lista_acessa_posicao(&lista, posicao);
            break;

         case 4:
            printf("\nEscolha um valor para buscar: ");
            scanf("%d", &valor);
            lista_busca_valor(&lista, valor);
            break;

         case 5:
            printf("Lista: \n");
            lista_apresenta(&lista);

         default:
            break;
      }
   } while(opcao != 0);

   return 0;
}