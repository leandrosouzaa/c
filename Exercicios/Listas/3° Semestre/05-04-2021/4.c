#define TAMF 10
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int valor[TAMF], n; 
} LISTA;

typedef struct listaMaior {
   int valor[TAMF * 2], n; 
} LISTAMAIOR;


int lista_cheia_maior(LISTAMAIOR *L) {
   return (L->n + 1) == (2*TAMF) ? 1 : 0; 
}

int lista_cheia(LISTA *L) {
   return (L->n + 1) == TAMF ? 1 : 0; 
}

int lista_vazia_maior(LISTAMAIOR *L) {
   return (L->n + 1) == 0 ? 1 : 0; 
}

int lista_vazia(LISTA *L) {
   return (L->n + 1) == 0 ? 1 : 0; 
}

void inicializa_lista_maior(LISTAMAIOR *L) {
   L->n = -1;
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

int lista_inserir_maior(LISTAMAIOR *L, int valor) {
   if(lista_cheia_maior(L) == 1) {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }

   L->valor[L->n+1] = valor;
   L->n+=1;

   return 0;
};

void lista_concatenar(LISTAMAIOR *L,LISTA *L2,LISTA *L3) {
   for(int i=0; i < L2->n+1; i++) {
      lista_inserir_maior(L, L2->valor[i]); 
   }

   for(int i = 0; i <L3->n+1; i++) {
      lista_inserir_maior(L, L3->valor[i]);
   }
}

int lista_apresenta(LISTAMAIOR *L) {
   if(lista_vazia_maior(L) == 1) {
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
   LISTA lista2, lista3;
   LISTAMAIOR lista;

   inicializa_lista_maior(&lista);
   inicializa_lista(&lista2);
   inicializa_lista(&lista3);

   int num;
   do {
      scanf("%d", &num);
      if(num != -1) {
         lista_inserir(&lista2, num);
      }
   } while(num != -1 && lista2.n+1 < TAMF);

   do {
      scanf("%d", &num);
      if(num != -1) {
         lista_inserir(&lista3, num);
      }
   } while(num != -1 && lista3.n+1 < TAMF);

   lista_concatenar(&lista, &lista2, &lista3);
   printf("\n\nLista Concatenada: \n");
   lista_apresenta(&lista);

   return 0;
}