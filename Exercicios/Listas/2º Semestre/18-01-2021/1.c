#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   printf("Leitura de Arquivo - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo;
   char c;
   int linhas = 1, caracteres = 0, espacos = 0, digitos = 0;

   if(argc != 2) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <ArquivoParaContagem> \n", argv[0]);
      
      exit(1);
   }

   arquivo = fopen(argv[1], "r");

   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }
   system("cls");

   printf("Arquivo lido: \n");
   c = fgetc(arquivo);

   while(c != EOF) {
      if(c > 47 && c < 58) {
         digitos++;
      } else {
         if(c == 10) {
            linhas++;
         } else {
            if(c == 32) {
               espacos++;
            } else {
               caracteres++;
            }
         }
      }

      printf("%c", c);

      c = fgetc(arquivo);
   }

   fclose(arquivo);

   printf("\n\nRELATÓRIO FINAL:\n");
   printf("Quantidade de linhas..............:%d.\n",linhas); 
   printf("Quantidade de dígitos.............:%d.\n",digitos);
   printf("Quantidade de caracteres..........:%d.\n",caracteres);
   printf("Quantidade de espaços em branco...:%d.\n",espacos);

   exit(0);
}