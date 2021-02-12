// O EDITOR NÃO RECONHECE PORÉM FUNCIONA NORMALMENTE
#include <sys/stat.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

int cfileexists(const char* filename){
   struct stat buffer;
   int exist = stat(filename,&buffer);
   if(exist == 0)
      return 1;
   else
      return 0;
}

void print_header(const char* title) {
   printf("%s\n", title);
   printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
}

int menu() {
   setbuf(stdin, NULL);
   system("cls");

   int opcao;

   printf("CONTROLE DE EMPRESTIMOS 1.0 - BIBLOTECA IFSP PEP\n\n");
   printf("ATALHOS:\n");
   printf("  01 - CADASTRAR NOVO EMPRESTIMO.\n");
   printf("  02 - DEVOLUCAO.\n");
   printf("  03 - EMPRESTIMOS EM ATRASO.\n");
   printf("  05 - Cadastrar Novo Aluno.\n");
   printf("  06 - Cadastrar Novo Livro.\n");

   printf("\nAlunos:\n");
   printf("  06 - Atualizar.\n");
   printf("  07 - Excluir.\n");
   printf("  08 - Listagem.\n");
   printf("  09 - Busca por Prontuario.\n");
   printf("  10 - Recuperar Registros.\n");
   printf("  11 - Limpar Registros.\n");

   printf("\nLivros:\n");
   printf("  12 - Atualizar.\n");
   printf("  13 - Excluir.\n");
   printf("  14 - Listagem.\n");
   printf("  15 - Busca por Tombo.\n");
   printf("  16 - Filtro por situacao (D/E).\n");
   printf("  17 - Recuperar Registros.\n");
   printf("  18 - Limpar Registros.\n");

   printf("\nEmprestimos:\n");
   printf("  19 - Relatorio por Alunos.\n");
   printf("  20 - Relatorio por Curso.\n");
   printf("  21 - Relatorio por Livro.\n");

   printf("\n22 - Finalizar sessao.\n");

   printf("\nEscolha uma operacao: ");
   scanf("%d", &opcao);

   return opcao;
};
