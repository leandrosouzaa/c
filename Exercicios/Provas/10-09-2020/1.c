#include <stdio.h>

int main() {
   printf("Pedal - Leandro Ribeiro de Souza \n\n");

   float distancia, velocidadeMedia, velocidadeMediaSemParadas;
   int qtdCiclos, tempoParadas, tempoGasto, tempoPedalada;

   printf("Informe a distância percorrida (metros):");
   scanf("%f", &distancia);

   printf("Informe o tempo demorado (minutos): ");
   scanf("%i", &tempoGasto);   

   qtdCiclos = (tempoGasto/40);
   tempoParadas = qtdCiclos * 5;
   tempoPedalada = tempoGasto - qtdCiclos * 5;
   velocidadeMedia = (distancia / tempoGasto) * 0.06;
   velocidadeMediaSemParadas = (distancia / tempoPedalada) * 0.06;

   printf("\nRELATÓRIO FINAL\n");
   printf("Total de Paradas: %i.\n", qtdCiclos);
   printf("Tempo Gasto com Paradas: %i.\n", tempoParadas);
   printf("Tempo efetivo de Pedalada: %i.\n", tempoPedalada);
   printf("Velocidade média do percurso (contando paradas): %0.2f km/h.\n", velocidadeMedia);
   printf("Velocidade média em movimento (sem paradas): %0.2f km/h.", velocidadeMediaSemParadas);

   return 0;
}
