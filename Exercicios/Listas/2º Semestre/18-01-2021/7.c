#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
   printf("Leitura de Estilos - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo;
   char c;
   int identificadores = 0, classes = 0, redefinicoes = 0;

   if(argc != 2) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <ArquivoCSS> \n", argv[0]);
      
      exit(1);
   }

   arquivo = fopen(argv[1], "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }

   printf("Regras Encontradas: \n");

   c = fgetc(arquivo);
   while (c != EOF) {
      while(c != 123 && c != EOF) {
         printf("%c", c);
         if(c == '#') {
            identificadores++;
         } else {
            if(c == '.') {
               classes++;
            } else {
               if((c > 64 && c < 91)||(c > 96 && c < 123)) {
                  redefinicoes++;
                  printf("%c", c);
               }
            }
         }
         c = fgetc(arquivo);
      }

      while(c != 125 && c != EOF) {
         c = fgetc(arquivo);
      }
      c = fgetc(arquivo);

   }

   printf("RELATÓRIO FINAL: \n");
   printf("Quantidade de redefinicoes:%d.\n", redefinicoes);
   printf("Quantidade de identificadores:%d.\n", identificadores);
   printf("Quantidade de :%d.\n", classes);

   fclose(arquivo);

   exit(0);
}