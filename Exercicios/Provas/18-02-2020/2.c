#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isVowel(char character) {
   character = toupper(character);

   if(character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') {
      return 1;
   } else {
      return 0;   
   }
}

int main(int argc, char* argv[]) {
   printf("Separa Letras - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *destino;
   char c;

   if(argc != 3) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <ArquivoParaSeparaacao> <ArquivoDestino \n", argv[0]);
      exit(1);
   }

   arquivo = fopen(argv[1], "r");
   destino = fopen(argv[2], "w");

   c = fgetc(arquivo);
   while( c != EOF) {
      if(!isVowel(c))
         fputc(c, destino);
      c = fgetc(arquivo);
   }
   
   fseek(arquivo, 0, SEEK_SET);
   fputc(10, destino);
   c = fgetc(arquivo);

   while( c != EOF) {
      if(isVowel(c))
         fputc(c, destino);
      c = fgetc(arquivo);
   }

   fclose(arquivo);
   fclose(destino);

   return 0;
}