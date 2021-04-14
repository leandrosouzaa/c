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

   L->valor[L->n+1] = valor;
   L->n+=1;

   return 0;
};


void lista_concatenar(LISTA *L,LISTA *L2) {
   if((L->n+2+L2->n) > TAMF) {
      printf("\nERRO - Lista 1 com espaço suficiente.\n");
      return 1;
   }
   for(int i=0; i < L2->n+1; i++) {
      lista_inserir(L, L2->valor[i]); 
   }
}

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
   printf("Concatenar Listas - Leandro Ribeiro de Souza \n\n");
   LISTA lista, lista2;

   inicializa_lista(&lista);
   inicializa_lista(&lista2);

   int num;
   do {
      scanf("%d", &num);
      if(num != -1) {
         lista_inserir(&lista, num);
      }
   } while(num != -1 && lista.n+1 < TAMF);

   do {
      scanf("%d", &num);
      if(num != -1) {
         lista_inserir(&lista2, num);
      }
   } while(num != -1 && lista2.n+1 < TAMF);

   lista_concatenar(&lista, &lista2);
   printf("\n\nLista Concatenada: \n");
   lista_apresenta(&lista);

   return 0;
}