void print_livro(Livro livro) {
   printf("Tombo..............: %d.\n", livro.tombo);
   printf("Titulo.............: %s.\n", livro.titulo);
   printf("Autore(s)..........: %s.\n", livro.autores);
   printf("Ano de Publicacao..: %d.\n", livro.ano);
   printf("Situacao...........: %s (%c).\n\n", livro.situacao == 'D' ? "Disponivel" : "Emprestado", livro.situacao);
   printf("+-+-+-+-+-+-+-+-+-+-+\n\n");
}