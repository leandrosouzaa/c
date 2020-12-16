#include "models.h"

int procura_prontuario(int prontuario,Aluno alunos[], int tl) {
   int i;

   for(i=0; i < tl; i++) {
      if(alunos[i].prontuario == prontuario)
         return i;
   }

   return -1;
}

int procura_tombo(int tombo, Livro livros[], int tl) {
   int i;

   for(i=0; i < tl; i++) {
      if(livros[i].tombo == tombo)
         return i;
   }

   return -1;
}

void apresenta_aluno(Aluno aluno) {
  printf("Prontuario: PE%d.\n", aluno.prontuario);
  printf("Nome: ");
  puts(aluno.nome);
  printf("Curso: ");
  puts(aluno.curso);
}

void apresenta_livro(Livro livro) {
  printf("Tombo: %d.\n", livro.tombo);
  printf("Titulo: ");
  puts(livro.titulo);
  printf("Autore(s): ");
  puts(livro.autores);
  printf("Ano de Publicacao: %d.\n", livro.ano);
  printf("Situação: %s (%c).\n", livro.situacao == 'D' ? "Disponivel" : "Emprestado", livro.situacao);
}

void apresenta_emprestimo(Emprestimo emprestimo, Aluno aluno, Livro livro) {
  printf("ALUNO: \n");
  apresenta_aluno(aluno);
  printf("\nLIVRO: \n");
  apresenta_livro(livro);
  printf("\nData do emprestimo: %s%d/%s%d/2020.\n",emprestimo.dia < 10 ? "0" : "" , emprestimo.dia, emprestimo.mes < 10 ? "0" : "", emprestimo.mes);
  printf("Data de devolução: %s%d/%s%d/2020.\n",emprestimo.dia_devolucao < 10 ? "0" : "" , emprestimo.dia_devolucao, emprestimo.mes < 10 ? "0" : "", emprestimo.mes_devolucao);
  printf("\nSITUAÇÃO: %s (%c).\n", emprestimo.situacao == 'P' ? "PENDENTE" : "FINALIZADO", emprestimo.situacao);
}

int calcula_emprestimos_curso(Emprestimo emprestimos[], int tlEmprestimos, Aluno alunos[], int tlAlunos, char curso[4]) {
  int i, cont = 0;

  for(i=0; i < tlEmprestimos; i++) {
    if(strcmp(alunos[procura_prontuario(emprestimos[i].codigo_aluno, alunos, tlAlunos)].curso, curso) == 0) 
      cont++;
  }

  return cont;
}
