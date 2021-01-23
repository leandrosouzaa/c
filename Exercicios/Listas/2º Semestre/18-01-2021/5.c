#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
   printf("Criptografia - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *destino;
   int c;
   char nome[100];

   if(argc != 2) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <ArquivoParaCriptografar> \n", argv[0]);
      
      exit(1);
   }

   arquivo = fopen(argv[1], "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }
   
   strcpy(nome, argv[1]);
   strcat(nome,"-criptografado.txt");

   destino = fopen(nome, "w");
   if(destino == NULL) {
      printf("Erro na criação do arquivo de destino.");
      exit(1);   
   }

   c = fgetc(arquivo);

   while (c != EOF) {
      fputc(c + 28, destino);
      c = fgetc(arquivo);
   }

   fclose(arquivo);
   fclose(destino);

   printf("Arquivo criptografado para %s... Encerrando programa.", nome);
   exit(0);
}