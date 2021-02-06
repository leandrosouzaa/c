#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   printf("Gerador de NFaaaaaaaaaaaaa - Leandro Ribeiro de Souza \n\n");

   FILE *arquivo, *destino;
   char nome[100], *nomeTemp;
   float valor, total = 0;
   int qtd, qtdRegitros, retorno;

   arquivo = fopen("teste.txt", "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo \"teste.txt\". Tente novamente.");
      exit(1);
   }

   destino = fopen("nota-fiscal.txt", "w");
   if(destino == NULL) {
      printf("Erro na criação do arquivo \"nota-fiscal.txt\". Tente novamente.");
      exit(1);
   }

   fprintf(destino,"============================================================\n");
   fprintf(destino,"Supermercado Periférico\n");
   fprintf(destino,"============================================================\n");
   fprintf(destino,"                  NOTA FISCAL AO CONSUMIDOR                 \n");
   fprintf(destino,"------------------------------------------------------------\n");
   fprintf(destino, "%-30s %-11s %-5s %11s\n", "Produto", "Valor", "Quant", "Subtotal");
   fprintf(destino,"------------------------------------------------------------\n");

   retorno = fscanf(arquivo, "%d\n", &qtdRegitros);
   if(retorno == EOF) {
      printf("Nenhum registro encontrado.");
      exit(1);
   }

   for(int i=0; i < qtdRegitros; i++) {
      fgets(nome,99, arquivo);

      if(nome[strlen(nome)-1]=='\n')
         nome[strlen(nome)-1] = '\0';

      retorno = fscanf(arquivo,"%f %d\n", &valor, &qtd);

      total+= qtd * valor;
      fprintf(destino, "%-30s %-11.2f %5d %11.2f\n", nome, valor, qtd, qtd*valor);
   }
   fprintf(destino,"------------------------------------------------------------\n");
   fprintf(destino, "Total da Nota Fiscal: %38.2f", total);

   printf("Nota fiscal gerada no arquivo \"nota-fiscal.txt\".");

   fclose(arquivo);
   fclose(destino);

   exit(0);
}