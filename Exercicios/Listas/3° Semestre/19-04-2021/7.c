// a: Uma lista com implementação circular, padrão FIFO (First In, Last Out).
// Essa é a mais recomendada pois as musicas são organizadas em forma de fila e toda
// vez que uma musica é tocada, ela vai para o final da fila.
// b: 99 músicas
#include <stdio.h>

typedef struct sMusica {
   char nome[50], genero[50];
} Musica;

typedef struct sPasta {
   Musica musicas[100];
   int inicio, fim;
} Pasta;

int main() {
   printf("Fila Estática - Leandro Ribeiro de Souza \n\n");

   return 0;
}