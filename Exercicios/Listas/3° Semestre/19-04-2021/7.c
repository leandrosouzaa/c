// a: Uma lista com implementação circular, padrão FIFO (First In, Last Out).
// Essa é a mais recomendada pois as musicas são organizadas em forma de Fila e toda
// vez que uma musica é tocada, ela vai para o final da Fila.
// b: 99 músicas
#define TAMMAX 100

#include <stdio.h>
#include <string.h>

typedef struct sMusica {
   char nome[50], genero[50];
} Musica;

typedef struct sPasta {
   Musica musicas[100];
   int inicio, fim;
} Pasta;

void inicializa(Pasta *p) {
   p->inicio = TAMMAX - 1;
   p->fim = TAMMAX - 1;
}

int vazia (Pasta *p) {
   return p->fim == p->inicio ? 1 : 0;
}

int cheia (Pasta *p) {
   return p->fim == p->inicio ? 1 : 0;
}

void enfileirar(Pasta *p, Musica musica) {
   if(p->fim == (TAMMAX - 1)) {
      p->fim = 0;
   } else {
      p->fim++;
   }
   if(cheia(p)) {
      printf("\nERRO: Pasta cheia.\n");
      p->fim--;
      if(p->fim == -1) {
         p->fim = TAMMAX - 1;
      }
      return;
   }
   p->musicas[p->fim] = musica;
}

Musica desenfileirar(Pasta *p) {
   Musica aux;
   
   if(!vazia(p)) {
      if(p->inicio == TAMMAX - 1) {
         p->inicio = 0;
      } else {
         p->inicio++;
      }
      aux = p->musicas[p->inicio];
   } else {
      printf("\nERRO: Pasta Vazia.\n");
   }

   return aux;
}

void imprimir(Pasta *p) {
   int i = (p->inicio + 1) % TAMMAX;
   if(!vazia(p)) {
      printf("\nPasta: \n");
      while(i != ((p->fim + 1) % TAMMAX)) {
         printf("Nome: %s.\n", p->musicas[i].nome);
         printf("Genero: %s.\n\n", p->musicas[i].genero);
         i = (i+1) % TAMMAX;
      }
   } else {
      printf("\nPasta Vazia.");
   }
}


int main() {
   printf("Fila Estática - Leandro Ribeiro de Souza \n\n");
   Pasta pasta;
   inicializa(&pasta);

   Musica musica;
   
   strcpy(musica.genero, "Infantil");
   strcpy(musica.nome, "Ilariê");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Sertanejo");
   strcpy(musica.nome, "Ai se eu te Pego");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Pop");
   strcpy(musica.nome, "Paparazzi");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Rock");
   strcpy(musica.nome, "Céu Azul");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Pagode");
   strcpy(musica.nome, "Ta vendo Aquela Lua");
   enfileirar(&pasta, musica);

   imprimir(&pasta);

   enfileirar(&pasta,desenfileirar(&pasta));
   enfileirar(&pasta,desenfileirar(&pasta));

   printf("\nApós tocar duas músicas: \n");
   imprimir(&pasta);

   strcpy(musica.genero, "Infantil");
   strcpy(musica.nome, "ABC");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Rock");
   strcpy(musica.nome, "Beautiful Day");
   enfileirar(&pasta, musica);

   enfileirar(&pasta,desenfileirar(&pasta));
   printf("\nApós tocar uma músicas: \n");
   imprimir(&pasta);


   enfileirar(&pasta,desenfileirar(&pasta));
   printf("\nApós tocar outra músicas: \n");
   imprimir(&pasta);

   return 0;
}