#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   int codigo;
   char descricao[100];
   float preco;
   int qtd_estoque;
} Produto;

void read_produtos_from_file() {
   FILE *arquivo, *destino;
   Produto produto;
   int qtdRegistros;

   arquivo = fopen("produtos.txt", "r");
   if(arquivo == NULL) {
      printf("Erro na abertura do arquivo \"produtos.txt\". Tente novamente.");
      exit(1);
   }

   destino = fopen("produtos.dat", "ab+");
   if(destino == NULL) {
      printf("Erro na criação do arquivo \"produtos.dat\". Tente novamente.");
      exit(1);
   }

   int retorno = fscanf(arquivo, "%d\n", &qtdRegistros);
   if(retorno == EOF) {
      printf("Nenhum registro encontrado.");
      exit(1);
   }

   for(int i=0; i <qtdRegistros; i++) {
      retorno = fscanf(arquivo, "%d\n", &produto.codigo);

      fgets(produto.descricao, 99, arquivo);
      if(produto.descricao[strlen(produto.descricao)-1]=='\n')
         produto.descricao[strlen(produto.descricao)-1] = '\0';

      retorno = fscanf(arquivo, "%f %d\n", &produto.preco, &produto.qtd_estoque);

      fwrite(&produto, sizeof(Produto), 1, destino);
   }

   fclose(arquivo);
   fclose(destino);
};

void print_produto(Produto produto, int qtd) {
   printf("Código............: %d.\n", produto.codigo);
   printf("Descricao.........: %s.\n", produto.descricao);
   printf("Valor.............: R$%.2f.\n", produto.preco);
   printf("Estoque...........: %d.\n", produto.qtd_estoque);
   qtd != 0 ? printf("Quantidade Venda..: %d.\n", qtd) : printf("\0"); 
   printf("\n--------------------------------\n\n");
};

int print_produtos() {
   FILE *arquivo;
   Produto produto;
   int i;

   arquivo = fopen("produtos.dat", "rb");

   if(arquivo == NULL) {
      i = -1;
   } else {
      i = 0;

      fread(&produto, sizeof(Produto), 1, arquivo);
      while(!feof(arquivo)) {
         print_produto(produto, 0);
         fread(&produto, sizeof(Produto), 1, arquivo);
         i++;
      }
   }
   fclose(arquivo);

   return i;
}

int find_by_codigo(int codigo) {
   FILE *arquivo;
   Produto produto;
   int posicao = -1, i = 0;

   arquivo = fopen("produtos.dat", "rb");

   if(arquivo == NULL) {
      printf("\nNão foi possível abrir o arquivo \"produtos.dat\", verifique a existência do arquivo e importe a base de dados.\n");
      exit(1);
   }
   else {
      fread(&produto, sizeof(Produto), 1, arquivo);

      while(!feof(arquivo) && posicao == -1)
      {
         if (produto.codigo == codigo)
         {
            posicao = i;
            fseek(arquivo, 0, SEEK_END);
         }
         fread(&produto, sizeof(Produto), 1, arquivo);
         i++;
      }
      fclose(arquivo);
   }

   return posicao;
}

Produto find_by_index(int posicao) {
   FILE *file;
   Produto produto;

   file = fopen("produtos.dat", "rb");
   if (file == NULL) {
      printf("\nNão foi possível abrir o arquivo \"produtos.dat\", verifique a existência do arquivo e importe a base de dados.\n");
      exit(1);
   } else {
      fseek(file, posicao*sizeof(Produto), SEEK_SET);
      fread(&produto, sizeof(Produto), 1, file);

      fclose(file);
   }

   return produto;
};

int update_estoque(int posicao, int qtd) {
   FILE *file;
   Produto produto;

   file = fopen("produtos.dat", "rb+");

   if (file == NULL) {
      printf("\nNão foi possível abrir o arquivo \"produtos.dat\", verifique a existência do arquivo e importe a base de dados.\n");
      exit(1);
   } 
   fseek(file, posicao*sizeof(Produto), SEEK_SET);
   fread(&produto, sizeof(Produto), 1, file);
   
   produto.qtd_estoque-= qtd;
   
   fseek(file, posicao*sizeof(Produto), SEEK_SET);
   fwrite(&produto, sizeof(Produto), 1, file);
   fclose(file);
   
   return produto.qtd_estoque;
};

void read_save_venda() {
   Produto produto;

   system("clear");
   printf("CADASTRO DE PRODUTOS\n-------------------------------\n\n");
   
   print_produtos();

   int indexProduto, codigo, isValid;
   do {
      printf("Informe o codigo do produto..: ");
      scanf("%d", &codigo);
      indexProduto = find_by_codigo(codigo);
      if(indexProduto == -1 ) {
         printf("Produto inexistente. Tente outro.\n");
         isValid = 0;
      } else {
         produto = find_by_index(indexProduto);
         if(produto.qtd_estoque == 0) {
            printf("Produto sem estoque. Escolha outro\n");
            isValid = 0;
         } else {
            isValid = 1;
         }
      } 

   } while(isValid == 0);

   system("clear");
   printf("CADASTRO DE PRODUTOS\n-------------------------------\n\n");
   print_produto(produto, 0);
   int qtd;
   do {
      printf("Quantidade da venda: ");
      scanf("%d", &qtd);
      
      if(qtd > produto.qtd_estoque) {
         printf("Não é permitido vender mais produtos do que existe em estoque. Tente novamente.\n");
      }
   } while(qtd > produto.qtd_estoque);
   
   char continua;
   
   system("clear");
   printf("CADASTRO DE PRODUTOS\n-------------------------------\n\n");
   print_produto(produto, qtd);
   printf("Confirmar Venda [S/N]: ");
   scanf(" %c", &continua);
   if(continua == 'S') {
      printf("\nVenda confirmada. Alterando valores...\n");
      printf("Novo total em estoque: %d", update_estoque(indexProduto, qtd));
   } else {
      printf("\nVenda cancelada...\n");
   }

};

int main() {
   printf("Mané do Portugueis - Leandro Ribeiro de Souza \n\n");

   // read_produtos_from_file();

   read_save_venda();

   return 0;
}