typedef struct {
   int prontuario;
   char nome[100];
   char curso[3];
} Aluno;

typedef struct {
   int tombo;
   char titulo[100];
   char autores[150];
   int ano;
   char situacao;
} Livro;

typedef struct {
   int dia;
   int mes;
   int dia_devolucao;
   int mes_devolucao;
   int codigo_livro;
   char codigo_aluno[8];
   char situacao;
} Emprestimo;