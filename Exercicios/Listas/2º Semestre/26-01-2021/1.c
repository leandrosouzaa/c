#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   printf("Nota Fiscal - Leandro Ribeiro de Souza \n\n");
   FILE *arquivo;

   int qtd;
   float valor, total = 0;
   char nome[30], limpa, continua;

   arquivo = fopen("nota-fiscal.txt", "w");
   if(arquivo == NULL) {
      printf("Problema na criação do arquivo \"nota-fiscal.txt\". Tente novamente.");
      exit(1);
   }
   fprintf(arquivo,"============================================================\n");
   fprintf(arquivo,"Supermercado Periférico\n");
   fprintf(arquivo,"============================================================\n");
   fprintf(arquivo,"                  NOTA FISCAL AO CONSUMIDOR                 \n");
   fprintf(arquivo,"------------------------------------------------------------\n");
   fprintf(arquivo, "%-30s %-11s %-5s %11s\n", "Produto", "Valor", "Quant", "Subtotal");
   fprintf(arquivo,"------------------------------------------------------------\n");


   do {      
      printf("Nome do Produto: ");
      fgets(nome, 29, stdin);
      nome[strlen(nome) - 1] = '\0';

      printf("Valor: R$");
      scanf("%f", &valor);

      printf("Quantidade: ");
      scanf("%d", &qtd);

      total+=qtd*valor;

      fflush(stdin);
      setbuf(stdin, NULL);

      printf("\nCadastrar mais produtos [S/N]: ");
      scanf("%c", &continua);

      scanf("%c", &limpa);

      fprintf(arquivo, "%-30s %-11.2f %5d %11.2f\n", nome, valor, qtd, qtd*valor);

      system("clear");

   } while(continua == 'S');

   fprintf(arquivo,"------------------------------------------------------------\n");
   fprintf(arquivo, "Total da Nota Fiscal: %38.2f", total);

   printf("Nota fiscal gerada no arquivo \"nota-fiscal.txt\".");

   fclose(arquivo);

   exit(0);
}