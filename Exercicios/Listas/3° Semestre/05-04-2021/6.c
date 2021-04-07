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
}

void lista_inverter(LISTA *L, LISTA *L2) {
   for(int i = L->n; i>-1; i--) {
      lista_inserir(L2, L->valor[i]);
      printf("%d.\n", i);
   }
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
   printf("Intercalar Listas - Leandro Ribeiro de Souza \n\n");
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

   lista_inverter(&lista, &lista2);
   printf("\n\nLista Intercalada: \n");
   lista_apresenta(&lista2);

   return 0;
}
