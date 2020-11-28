#include <stdio.h>
#include "strings.h"

void generateEmail(char email[], char primeiroNome[], char ultimoNome[]) {
   concatena_string(email, primeiroNome);
   concatena_string(email, ultimoNome);
   concatena_string(email, "@gmail.com");
}

int main() {
   printf("Usando Funções próprias - Leandro Ribeiro de Souza \n\n");

   char nome[100], email[110], primeiroNome[30], ultimoNome[30];

   printf("Digite seu nome: ");
   readString(nome, 100);
   // fgets(nome, 100, stdin);

   int quantidadePalavras = conta_palavras(nome);
   int quantidadeCaracters = tamanho_string(nome);
   
   pega_primeira_palavra(nome, primeiroNome);
   pega_ultima_palavra(nome, ultimoNome);

   generateEmail(email, primeiroNome, ultimoNome);
   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de nomes: %d.\n", quantidadePalavras);
   printf("Quantidade de Caracters: %d.\n", quantidadeCaracters);
   printf("Sugestão de E-mail: ");
   puts(email);

   int i = localiza_caracter(nome, ' ');
   while(i != -1) {
      excluir_posicao(nome, i);
      i = localiza_caracter(nome, ' ');
   }
   printf("Nome sem espaços: ");
   puts(nome);

   int caracteresSemEspaco = tamanho_string(nome);
   printf("Quantidade de Caracters (sem espaço): %d.\n", caracteresSemEspaco);

   getchar();
   return 0;
}
