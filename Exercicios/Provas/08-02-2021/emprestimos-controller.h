void create_emprestimo() {
   system("clear");
   print_header("CADASTRO DE EMPRESTIMOS");

   Emprestimo emprestimo = read_emprestimo();

   if(emprestimo.codigo_aluno != -1) {
      update_livro_situacao(find_by_tombo(emprestimo.codigo_livro), 'E');
      save_emprestimo(emprestimo);
   } 
}