#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   printf("Inverte Frase - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *destino;
   char *lidos, frase[200];
   int i, tamanho;

   arquivo = fopen("inverte.txt", "r");
   destino = fopen("invertido.txt", "w");

   if(arquivo == NULL || destino == NULL) {
      printf("Erro na criação ou abertura de arquivo. Tente novamente");
      exit(1);
   }

   lidos = fgets(frase, 199, arquivo);

   while(lidos!= NULL) {
      tamanho = strlen(frase);
      if(frase[tamanho - 1] == 10) {
         frase[tamanho-1] = '\0';
         tamanho--;
      }
      for(i= tamanho - 1; i >= 0; i--) {
         fputc(frase[i], destino);
      }
      fputc(10, destino);

      lidos = fgets(frase, 199, arquivo);
   }

   printf("Arquivo invertido para \"invertido.txt\"");

   exit(0);
}