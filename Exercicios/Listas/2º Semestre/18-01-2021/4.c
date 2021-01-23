#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
   printf("Embaralha - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *destino;
   char c;
   char nome[100];

   if(argc != 2) {
      printf("Nao foi digitada a quantidade correta de parametros.\n");
      printf("Sintaxe: %s <ArquivoParaEmbaralhar> \n", argv[0]);
      
      exit(1);
   }

   arquivo = fopen(argv[1], "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo.");
      exit(1);   
   }
   
   strcpy(nome, argv[1]);
   strcat(nome,"-embaralhado.txt");

   destino = fopen(nome, "w");
   if(destino == NULL) {
      printf("Erro na criação do arquivo de destino.");
      exit(1);   
   }

   c = fgetc(arquivo);

   while (c != EOF) {
      if(c == 'a') {
         fputc('x', destino);
      } else {
         if(c == 'x') {
            fputc('a', destino);
         } else {
            if(c == 'e') {
               fputc('s', destino);
            } else {
               if(c == 's') {
                  fputc('e', destino);
                  } else {
                     if(c == 'r') {
                        fputc('i', destino);
                     } else {
                        if(c=='i') {
                           fputc('r', destino);
                        } else {
                           if(c=='o') {
                              fputc('g', destino);
                           } else {
                              if(c=='g') {
                                 fputc('o', destino);
                              } else {
                                 fputc(c, destino);
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      c = fgetc(arquivo);
   }

   fclose(arquivo);
   fclose(destino);

   printf("Arquivo copiado e embaralhado para %s... Encerrando programa.", nome);
   exit(0);
}