#define TAMMAX 11
#include <stdio.h>

typedef struct sDeque {
   int itens[TAMMAX];
   int inicio, fim;
} Deque;

void inicializa(Deque *d) {
   d->inicio = TAMMAX - 1;
   d->fim = TAMMAX - 1;
}

int vazia(Deque *d) {
   return d->fim == d->inicio ? 1 : 0;
}

int cheia(Deque *d) {
   return d->fim == d->inicio ? 1 : 0;
}

void inserirInicio(Deque *d, int x) {
   if(d->inicio == 0) {
      d->inicio = TAMMAX - 1;
   } else {
      d->inicio--;
   }
   if(cheia(d)) {
      printf("\nERRO: Deque Cheia.\n");
      d->inicio = (d->inicio+1) % TAMMAX;
      return;
   }
   d->itens[(d->inicio+1) % TAMMAX] = x;
}

void inserirFim(Deque *d, int x) {
   if(d->fim == (TAMMAX - 1)) {
      d->fim = 0;
   } else {
      d->fim++;
   }
   if(cheia(d)) {
      printf("\nERRO: Deque cheia.\n");
      d->fim--;
      if(d->fim == -1) {
         d->fim = TAMMAX - 1;
      }
      return;
   }
   d->itens[d->fim] = x;
}

int removerInicio(Deque *d) {
   int aux = 0;
   
   if(!vazia(d)) {
      if(d->inicio == TAMMAX - 1) {
         d->inicio = 0;
      } else {
         d->inicio++;
      }
      aux = d->itens[d->inicio];
   } else {
      printf("ERRO: Deque Vazia.\n");
   }

   return aux;
}

int removerFim(Deque *d) {
   int aux = 0;
   
   if(!vazia(d)) {
      if(d->fim == 0) {
         d->fim == TAMMAX - 1;
      } else {
         d->fim--;
      }
      aux = d->itens[d->fim];
   } else {
      printf("ERRO: Deque Vazia.\n");
   }

   return aux;
}

void imprimir(Deque *d) {
   int i = (d->inicio + 1) % TAMMAX;
   if(!vazia(d)) {
      printf("\nDeque: ");
      while(i != ((d->fim + 1) % TAMMAX)) {
         printf("%d ", d->itens[i]);
         i = (i+1) % TAMMAX;
      }
   } else {
      printf("\n Deque Vazia.");
   }
}

void imprimirClassica(Deque *d) {
   int vetAux[TAMMAX-1], j = 0;
   if(!vazia(d)) {
      printf("\nDeque: ");
      while(!vazia(d)) {
         vetAux[j] = removerInicio(d);
         printf("%d ", vetAux[j]);
         j++;
      }
      for(int i=j-1; i >= 0; i--) {
         inserirInicio(d, vetAux[i]);
      }
   } else {
      printf("\n Deque Vazia.");
   }
}

int main() {
   int opcao;
   int temp;

   Deque deque;
   inicializa(&deque);

   do {
      printf("\n\nDeque - Leandro Ribeiro de Souza \n\n");

      printf("1 - Inserir inicio.\n");
      printf("2 - Inserir Fim.\n");
      printf("3 - Remover Inicio.\n");
      printf("4 - Remover Fim.\n");
      printf("5 - Impressao Classica.\n");
      printf("6 - Impressao Nao Clasica.\n");
      printf("0 - Finalizar.\n");
      printf("\nEscolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         printf("Informe um numero: ");
         scanf("%d", &temp);

         inserirInicio(&deque, temp);
         break;

      case 2:
         printf("Informe um numero: ");
         scanf("%d", &temp);

         inserirFim(&deque, temp);
         break;

      case 3:
         removerInicio(&deque);
         break;

      case 4:
         removerFim(&deque);
         break;

      case 5:
         imprimirClassica(&deque);
         break;

      case 6:
         imprimir(&deque);
         break;
      
      default:
         break;
      }
   } while(opcao != 0);

   return 0;
}