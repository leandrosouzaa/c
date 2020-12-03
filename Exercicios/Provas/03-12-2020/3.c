#include <stdio.h>

void ler_array(char array[15]) {
   int i;
   
   for (i=0; i < 15; i++) {
   printf("Resposta da QUESTÃO %i: ", i + 1);
   scanf(" %c", &array[i]);
   // Verifica uma entrada inválida
      if (!(array[i] == 'A' || array[i] == 'B' || array[i] == 'C' || array[i] == 'D' || array[i] == 'E')) {
         printf("Alternativa inválida, informe novamente...\n");
         /*
         Se tiver uma entra inválida o i é decrementado em 1 e
         consequentemente é solicitado ao usuários informar
         novamente um valor válido para a posição.
         */
         i--;
      }
   }
}

int gera_resultado(char respostas[15], char gabarito[15]) {
   int i, cont = 0;
   for(i=0; i<15; i++) {
      if(respostas[i] == gabarito[i])
         cont++;
   }
   return cont;
}

void imprime_resultados(int resultado[8]) {
   int i;   
   for(i=0; i<8; i++) {
      printf("\nCANDIDATO %d:\n", i+1);
      printf("Quantidade de acertos: %d.\n", resultado[i]);
   }
}

int procura_selecionado(int resultados[8]) {
   int i, indexMaior = 0;
   for(i=1; i<8; i++) {
      if(resultados[i] > resultados[indexMaior])
         indexMaior = i;
   }
   return indexMaior;
}

int main() {
   printf("Correção de Questão - Leandro Ribeiro de Souza \n\n");
   char gabarito[15], respostas[8][15];
   int resultado[8] = {0};
   int i;

   printf("GABARITO:\n");
   ler_array(gabarito);

   printf("\nRESPOSTAS DOS CANDIDATOS: ");
   for(i=0; i < 8; i++) {
         printf("\nCANDIDATO %d: \n", i + 1);
         ler_array(respostas[i]);
   }

   for(i=0; i<8; i++) {
      resultado[i] = gera_resultado(respostas[i], gabarito);
   }

   printf("\nRESULTADO INDIVIDUAL: \n");
   imprime_resultados(resultado);

   int selecionado = procura_selecionado(resultado);
   printf("\nCandidato selecionado: %d", selecionado + 1);

   return 0;
}
