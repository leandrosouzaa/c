#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
   printf("Copy 2 - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *arquivo2, *destino;
   char c;

   if(argc != 4) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <Arquivo1> <Arquivo2> <ArquivoDeDestino> \n", argv[0]);
      
      exit(1);
   }

   arquivo = fopen(argv[1], "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }

   arquivo2 = fopen(argv[2], "r");
   if(arquivo2 == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }

   destino = fopen(argv[3], "w");
   if(destino == NULL) {
      printf("Erro na criação do arquivo de destino.");
      exit(1);   
   }

   c = fgetc(arquivo);
   while (c != EOF) {
      fputc(c, destino);
      c = fgetc(arquivo);
   }
   fclose(arquivo);

   c = fgetc(arquivo2);
   while (c != EOF) {
      fputc(c, destino);
      c = fgetc(arquivo2);
   }
   fclose(arquivo2);

   fclose(destino);

   printf("Arquivo copiado para %s... Encerrando programa.", argv[3]);
   exit(0);
}