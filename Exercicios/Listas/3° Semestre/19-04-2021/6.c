#define TAMMAX 10
#include <stdio.h>

typedef struct sFila {
   int itens[TAMMAX];
   int inicio, fim;
} Fila;

void inicializa(Fila *f) {
   f->inicio = TAMMAX - 1;
   f->fim = TAMMAX - 1;
}

int vazia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

int cheia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

void enfileirar(Fila *f, int x) {

   if(f->fim == (TAMMAX - 1)) {
      f->fim = 0;
   } else {
      f->fim++;
   }
   if(cheia(f)) {
      printf("\nERRO: Fila cheia.\n");
      f->fim--;
      if(f->fim == -1) {
         f->fim = TAMMAX - 1;
      }
      return;
   }
   f->itens[f->fim] = x;
}

int desenfileirar(Fila *f) {
   int aux = 0;
   
   if(!vazia(f)) {
      if(f->inicio == TAMMAX - 1) {
         f->inicio = 0;
      } else {
         f->inicio++;
      }
      aux = f->itens[f->inicio];
   } else {
      printf("\nERRO: Fila Vazia.\n");
   }

   return aux;
}

void imprimir(Fila *f) {
   int i = (f->inicio + 1) % TAMMAX;
   if(!vazia(f)) {
      printf("\nFila: ");
      while(i != ((f->fim + 1) % TAMMAX)) {
         printf("%d ", f->itens[i]);
         i = (i+1) % TAMMAX;
      }
   } else {
      printf("\n Fila Vazia.");
   }
}

void clona_fila(Fila *f, Fila *f2) {
   if(vazia(f)) {
      printf("\nERRO: Fila Vazia.\n");
   }
   int temp;
   while(!vazia(f)) {
      temp = desenfileirar(f);
      enfileirar(f, temp);
      enfileirar(f2, temp);
   };
}

int calcula_total(Fila *f) {
   int total = 0;
   if(vazia(f)) {
      printf("\nERRO: Fila Vazia.\n");
      total = 0;
   }
   Fila f2;
   inicializa(&f2);
   clona_fila(f, &f2);

   while(!vazia(&f2)) {
      total = desenfileirar(&f2);
   };

   return total;
};

int calcula_tamanho(Fila *f) {
   if(f->inicio < f->fim) {
      return f->fim - f->inicio;
   } else {
      return (TAMMAX-f->fim-(TAMMAX-f->inicio + 1));
   }
}

int calcula_media(Fila *f) {
   return calcula_total(f)/calcula_tamanho(f);
}

int acha_maior(Fila *f) {
   int maior = 0;
   if(vazia(f)) {
      printf("\nERRO: Fila Vazia.\n");
      maior = 0;
   }
   Fila f2;
   inicializa(&f2);
   clona_fila(f, &f2);

   int temp;
   while(!vazia(&f2)) {
      temp = desenfileirar(&f2);

      if(temp > maior) {
         maior = temp;
      }
   };

   return maior;
}

int acha_menor(Fila *f) {
   int menor = 0;
   if(vazia(f)) {
      printf("\nERRO: Fila Vazia.\n");
      menor = 0;
   }
   Fila f2;
   inicializa(&f2);
   clona_fila(f, &f2);

   int temp;
   while(!vazia(&f2)) {
      temp = desenfileirar(&f2);

      if(menor > temp) {
         menor = temp;
      }
   };

   return menor;
}

int main() {
   printf("Fila Estática - Leandro Ribeiro de Souza \n\n");

   Fila fila;
   inicializa(&fila);
   int temp;
   do {
      printf("Informe um número (-1 para sair): ");
      scanf("%d", &temp);
      if(temp != -1) {
         enfileirar(&fila, temp);
      }
   } while(temp != -1);

   imprimir(&fila);
   printf("\nMaior Elemento: %d.", acha_maior(&fila));
   printf("\nMenor Elemento: %d.", acha_menor(&fila));
   printf("\nMédia dos Elementos: %d.", calcula_media(&fila));

   return 0;
}