#include <stdio.h>

int main() {
   printf("Eleições Municipais - Leandro Ribeiro de Souza \n\n");

   int voto, votosAlibaba = 0, votosAlcapone = 0, votosBrancos = 0, votosNulos = 0, totalVotos = 0;

   do {
      printf("Número dos Candidatos\n");
      printf("Alibabá: 83.\n");
      printf("Alcapone: 93.\n");
      printf("Branco: 00.\n");
      printf("Para sair digite -1.\n");
      printf("Nulo: Qualquer outra opção.\n");

      printf("Número do Candidato: ");
      scanf("%i", &voto);

      printf("\n\n");

      switch (voto) {
         case 83:
            votosAlibaba++;
            totalVotos++;
            break;
         case 93:
            votosAlcapone++;
            totalVotos++;
            break;
         case 00:
            votosBrancos++;
            totalVotos++;
            break;
         case -1:
            break;      
         default:
            votosNulos++;
            totalVotos++;
            break;
      }
   } while (voto != -1);

   printf("RELATÓRIO FINAL\n");
   printf("Total de Votos: %i votos.\n", totalVotos);
   printf("Alibabá: %i votos.\n", votosAlibaba);
   printf("Alcapone: %i votos.\n", votosAlcapone);
   printf("Votos Brancos: %i votos.\n", votosBrancos);
   printf("Votos Nulos: %i votos.\n", votosNulos);

   if (votosAlibaba > votosAlcapone) {
      printf("VENCEDOR: Alibabá.");
   } else {
      if (votosAlcapone > votosAlibaba) {
         printf("VENCEDOR: Alcapone.");
      } else {
         printf("VENCEDOR: Não Houve");
      }
   }

   return 0;
}
