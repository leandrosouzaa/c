#include <stdio.h>

typedef struct sProduto {
   int id, qtdDisponivel;
   float preco_venda;
   char nome[50];
} Produto;


int main() {
   printf("Produtos - Leandro Ribeiro de Souza \n\n");
   Produto produtos[10];

   return 0;
}