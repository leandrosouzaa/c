// biblotecas padrões
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// models
#include "utils.h"

// #include "models.h"

int menu(int tlAlunos, int tlLivros, int tlEmprestimos) {
   system("clear");

   int opcao;

   printf("CONTROLE DE EMPRÉSTIMOS 1.0 - BIBLOTECA IFSP PEP\n\n");
   printf("Cadastros e Devoluções:\n");
   printf("  01 - CADASTRAR NOVO EMPRÉSTIMO.\n");
   printf("  02 - DEVOLUÇÃO.\n");
   printf("  03 - Cadastrar Novo Aluno.\n");
   printf("  04 - Cadastrar Novo Empréstimo.\n");

   printf("\nRelatórios:\n");
   printf("  05 - Empréstimos em atraso.\n");
   printf("  06 - Empréstimo por aluno.\n");
   printf("  07 - Procurar Emréstimo.\n");
   printf("  08 - Livros por situação (D/E).\n");

   printf("\n  09 - Geral de Alunos .\n");
   printf("  10 - Geral de Livros.\n");
   printf("  11 - Geral de Empréstimos.\n");
   
   printf("\n  12 - Quantidade de Empréstimos por curso (BCC/ADS/TII).\n");

   printf("\nQuantidade de Alunos: %d.\n", tlAlunos);
   printf("Quantidade de Livros: %d.\n", tlLivros);
   printf("Quantidade de Empréstimos: %d.\n", tlEmprestimos);

   printf("\nEscolha uma operação: ");
   scanf("%d", &opcao);

   return opcao;
};

int main() {
   int tlAlunos = 0, tlLivros = 0, tlEmprestimos = 0;

   Banco banco;
   menu(tlAlunos, tlLivros, tlEmprestimos);

   return 0;
}