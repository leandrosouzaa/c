typedef struct {
   int prontuario;
   char nome[100];
   char curso[4];
   char status;
} Aluno;

typedef struct {
   int tombo;
   char titulo[100];
   char autores[150];
   int ano;
   char situacao;
   char status;
} Livro;

typedef struct {
   int dia;
   int mes;
   int dia_devolucao;
   int mes_devolucao;
   int codigo_livro;
   int codigo_aluno;
   char situacao;
   char status;
} Emprestimo;
