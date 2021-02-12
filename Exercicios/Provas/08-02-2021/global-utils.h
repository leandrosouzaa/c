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
   printf("  00 - CADASTRAR NOVO EMPRESTIMO.\n");
   printf("  01 - DEVOLUCAO.\n");
   printf("  02 - EMPRESTIMOS EM ATRASO.\n");
   printf("  03 - Cadastrar Novo Aluno.\n");
   printf("  04 - Cadastrar Novo Livro.\n");

   printf("\nAlunos:\n");
   printf("  05 - Atualizar.\n");
   printf("  06 - Excluir.\n");
   printf("  07 - Listagem.\n");
   printf("  08 - Busca por Prontuario.\n");
   printf("  09 - Recuperar Registros.\n");
   printf("  10 - Limpar Registros.\n");

   printf("\nLivros:\n");
   printf("  11 - Atualizar.\n");
   printf("  12 - Excluir.\n");
   printf("  13 - Listagem.\n");
   printf("  14 - Busca por Tombo.\n");
   printf("  15 - Filtro por situacao (D/E).\n");
   printf("  16 - Recuperar Registros.\n");
   printf("  17 - Limpar Registros.\n");

   printf("\nEmprestimos:\n");
   printf("  18 - Relatorio por Alunos.\n");
   printf("  19 - Relatorio por Curso.\n");
   printf("  20 - Relatorio por Livro.\n");

   printf("\n21 - Finalizar sessao.\n");

   printf("\nEscolha uma operacao: ");
   scanf("%d", &opcao);

   return opcao;
};
