void print_aluno(Aluno aluno) {
   printf("Prontuario..: PE%d.\n",aluno.prontuario);
   printf("Nome........: %s.\n", aluno.nome);
   printf("Curso.......: %s.\n", aluno.curso);
}

void print_aluno_header() {
   printf("+-----------+----------------------------------------------------+--------+\n");
   printf("| %-9s | %-50s | %-6s |", "Pront.", "Nome", "Curso");
   printf("\n+-----------+----------------------------------------------------+--------+\n");
}

void print_aluno_linha(Aluno aluno) {
   printf("| PE%-7d | %-50s | %-6s |", aluno.prontuario , aluno.nome, aluno.curso);
   printf("\n+-----------+----------------------------------------------------+--------+\n");
}

void print_livro(Livro livro, int dashed) {
   printf("Tombo..............: %d.\n", livro.tombo);
   printf("Titulo.............: %s.\n", livro.titulo);
   printf("Autore(s)..........: %s.\n", livro.autores);
   printf("Ano de Publicacao..: %d.\n", livro.ano);
   printf("Situacao...........: %s (%c).\n\n", livro.situacao == 'D' ? "Disponivel" : "Emprestado", livro.situacao);
   dashed ? printf("+-+-+-+-+-+-+-+-+-+-+\n\n") : printf("\0");
}