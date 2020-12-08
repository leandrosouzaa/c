#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nome[50];
   int fornecedor, qtdEstoque, qtdMinima;
   float preco;
} Produto;

typedef struct {
   int codigo;
   char nome[50], telefone[15];
} Fornecedor;

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

void preenche_tabelas(Produto produtos[], Fornecedor fornecedores[]) {
   fornecedores[0].codigo = 1;
   strcpy(fornecedores[0].nome, "Ambev");
   strcpy(fornecedores[0].telefone, "(18)99887-9876");

   fornecedores[1].codigo = 2;
   strcpy(fornecedores[1].nome, "Femsa");
   strcpy(fornecedores[1].telefone, "(18)99111-3221");

   fornecedores[2].codigo = 3;
   strcpy(fornecedores[2].nome, "Lindoya");
   strcpy(fornecedores[2].telefone, "(18)98352-1121");

   strcpy(produtos[0].nome, "Cerveja Antartica");
   produtos[0].fornecedor = 1;
   produtos[0].preco = 8.5;
   produtos[0].qtdEstoque = 48;
   produtos[0].qtdMinima = 24;

   strcpy(produtos[1].nome, "Cerveja Brahma");
   produtos[1].fornecedor = 1;
   produtos[1].preco = 9;
   produtos[1].qtdEstoque = 15;
   produtos[1].qtdMinima = 30;

   strcpy(produtos[2].nome, "Guarana Antartica");
   produtos[2].fornecedor = 1;
   produtos[2].preco = 6.5;
   produtos[2].qtdEstoque = 12;
   produtos[2].qtdMinima = 6;

   strcpy(produtos[3].nome, "Coca Cola 1l");
   produtos[3].fornecedor = 2;
   produtos[3].preco = 6;
   produtos[3].qtdEstoque = 25;
   produtos[3].qtdMinima = 12;

   strcpy(produtos[4].nome, "Fanta Uva 290ml");
   produtos[4].fornecedor = 2;
   produtos[4].preco = 3.5;
   produtos[4].qtdEstoque = 3;
   produtos[4].qtdMinima = 10;

   strcpy(produtos[5].nome, "Cerveja Bavaria Lata");
   produtos[5].fornecedor = 2;
   produtos[5].preco = 8.5;
   produtos[5].qtdEstoque = 48;
   produtos[5].qtdMinima = 6;

   strcpy(produtos[6].nome, "Agua Mineral 500ml");
   produtos[6].fornecedor = 3;
   produtos[6].preco = 2.5;
   produtos[6].qtdEstoque = 24;
   produtos[6].qtdMinima = 10;
}

int menu(int tlProdutos, int tlFornecedores) {
   int opcao;
 
   setbuf(stdin, NULL);
   system("clear");
   printf("GESTÃO DE PRODUTOS - 1.0\n\n");
   printf("1 - Cadastrar Produtos.\n");
   printf("2 - Apresentar Produtos.\n");
   printf("3 - Apresentar Produtos com fornecedores.\n");
   printf("4 - Apresentar todos os produtos de um fornecedor.\n");
   printf("5 - Apresentar todos os produtos com estoque baixo.\n");
   printf("6 - Pesquisar Produto.\n");
   printf("7 - Balanco de Estoque.\n");
   printf("8 - Encerrar Sistema.\n");
   printf("\nProdutos Cadastrados: %d.\n", tlProdutos);
   printf("Fornecedores Cadastrados: %d.\n", tlFornecedores);

   printf("\nEscolha uma opção: ");
   scanf("%d", &opcao);
   
   return opcao;
}

int procuraFornecedorId(Fornecedor forncedores[], int tl, int codigo) {
   int i;
   for(i=0; i < tl; i++) {
      if(forncedores[i].codigo == codigo)
         return i;
   }
   return -1;
}

void apresenta_fornecedor(Fornecedor fornecedor) {
   printf("Codigo: %d.\n", fornecedor.codigo);
   printf("Nome: ");
   puts(fornecedor.nome);
   printf("Telefone: ");
   puts(fornecedor.telefone);
}

void apresenta_fornecedores(Fornecedor fornecedores[], int tl) {
   int i;
   for(i=0; i < tl; i++) {
      apresenta_fornecedor(fornecedores[i]);
      printf("\n");
   }
}

void cadastra_produto(Produto *produto ,int *tl, Fornecedor fornecedores[], int tlFornecedor) {
   system("clear");
   setbuf(stdin, NULL);
   if (*tl>9) {
      printf("Quantidade máxima de produtos atingida. Reinicie o sistema e tente novamente.\n");
      getchar();
   } else {
      printf("CADASTRO DE PRODUTO.\n\n");
      printf("Informe o nome do produto: ");
      readString(produto->nome, 50);
      printf("Informe o preco do produto: R$");
      scanf("%f", &produto->preco);
      printf("Informe a quantidade em estoque: ");
      scanf("%d", &produto->qtdEstoque);
      printf("Informe a quantidade minima permitida em estoque: ");
      scanf("%d", &produto->qtdMinima);
      printf("\nFornecedores Cadastrados: ");
      apresenta_fornecedores(fornecedores, tlFornecedor);
      do {
         printf("Informe um fornecedor válido: ");
         scanf("%d", &produto->fornecedor);
      } while(procuraFornecedorId(fornecedores, tlFornecedor, produto->fornecedor) == -1);

      *tl+=1;
      printf("PRODUTO CADASTRADA COM SUCESSO.");
   }
}

void apresenta_produto(Produto produto) {
   printf("Nome do Produto: ");
   puts(produto.nome);
   printf("Preço: R$%0.2f.\n", produto.preco);
   printf("Quantidade em estoque: %d.\n", produto.qtdEstoque);
   printf("Quantidade minima permitida em estoque: %d.\n", produto.qtdMinima);
}

void apresenta_produtos(Produto produtos[], int tl) {
   system("clear");
   setbuf(stdin, NULL);

   int i;
   for(i=0; i < tl; i++) {
      apresenta_produto(produtos[i]);
      printf("\n--------------------------------\n\n");
   }

   getchar();
};


void apresenta_produtos_fornecedor(Produto produtos[], int tlProdutos, Fornecedor fornecedores[], int tlFornecedores) {
   system("clear");
   setbuf(stdin, NULL);

   int i;
   for(i=0; i < tlProdutos; i++) {
      apresenta_produto(produtos[i]);
      printf("\nFORNECEDOR:\n");
      apresenta_fornecedor(fornecedores[procuraFornecedorId(fornecedores, tlFornecedores, produtos[i].fornecedor)]);
      printf("\n--------------------------------\n\n");
   }

   getchar();
}

void apresenta_produtos_estoqueBaixo(Produto produtos[], int tl) {
   system("clear");
   setbuf(stdin, NULL);
   printf("PRODUTOS COM BAIXO ESTOQUE: \n\n");
   int i;
   for(i=0; i < tl; i++) {
      if(produtos[i].qtdMinima > produtos[i].qtdEstoque) {
         apresenta_produto(produtos[i]);
         printf("\n--------------------------------\n\n");
      }
   }
   getchar();
};

void procura_produto(Produto produtos[], int tlProdutos, Fornecedor fornecedores[], int tlFornecedores) {
   system("clear");
   setbuf(stdin, NULL); 
   
   char busca[50];
   printf("Informe um nome de produto para ser buscado: ");
   readString(busca,50);
   
   system("clear");
   printf("Produtos que tem o nome compativel com ");
   puts(busca);
   printf("\n");
   int i;
   for(i=0; i < tlProdutos; i++) {
      if(strstr(produtos[i].nome, busca)) {
         apresenta_produto(produtos[i]);
         printf("\nFORNECEDOR:\n");
         apresenta_fornecedor(fornecedores[procuraFornecedorId(fornecedores, tlFornecedores, produtos[i].fornecedor)]);
         printf("\n--------------------------------\n\n");
      };
   }
   getchar();
}

float calcula_valorEstoque(Produto produto) {
   return produto.preco * produto.qtdEstoque;
}

void balanco_estoque(Produto produtos[], int tl) {
   system("clear");
   setbuf(stdin, NULL); 

   int i;
   float valorEstoque = 0, valorUnitario;
   
   for(i=0; i < tl; i++) {
      apresenta_produto(produtos[i]);
      valorUnitario = calcula_valorEstoque(produtos[i]);
      valorEstoque+=valorUnitario;
      printf("Valor em Estoque: R$%0.2f.\n", valorUnitario);
      printf("\n--------------------------------\n\n");
   }
   printf("Valor total do Estoque: R$%0.2f.", valorEstoque);
   getchar();
}

int main() {
   printf("Gestão de Produtos - Leandro Ribeiro de Souza \n\n");
   Produto produtos[10];
   Fornecedor fornecedores[3];
   int tlProdutos = 7, tlFornecedores = 3, opcao;
   preenche_tabelas(produtos, fornecedores);

   do {
      opcao = menu(tlProdutos, tlFornecedores);

      switch (opcao) {
         case 1: 
            cadastra_produto(&produtos[tlProdutos], &tlProdutos, fornecedores, tlFornecedores);
            break;
         case 2:
            apresenta_produtos(produtos, tlProdutos);
            break;
         case 3:
            apresenta_produtos_fornecedor(produtos, tlProdutos, fornecedores, tlFornecedores);
            break;
         case 4:
            break;
         case 5:
            apresenta_produtos_estoqueBaixo(produtos, tlProdutos);
            break;
         case 6:
            procura_produto(produtos, tlProdutos, fornecedores, tlFornecedores);
            break;
         case 7:
            balanco_estoque(produtos, tlProdutos);
         case 8:
            printf("Encerrando sistema...\n");
            break;
         default:
            break;
      };
   } while(opcao != 7);


   return 0;
}
