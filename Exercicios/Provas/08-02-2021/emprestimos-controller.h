void create_emprestimo() {
   system("clear");
   print_header("CADASTRO DE EMPRESTIMOS");

   Emprestimo emprestimo = read_emprestimo();

   if(emprestimo.codigo_aluno != -1) {
      update_livro_situacao(find_by_tombo(emprestimo.codigo_livro), 'E');
      save_emprestimo(emprestimo);
   } 
}

void index_emprestimos() {
   system("clear");
   print_header("LISTAGEM DE EMPRESTIMOS");

   int i = list_emprestimos('T');

   if(i<=0) {
      printf("Não existem emprestimos para serem listados.\n");
   }

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void emprestimos_atraso() {
   system("clear");
   print_header("LISTAGEM DE EMPRESTIMOS");

   int day, month;

   printf("Informe a dia de hoje: ");
   scanf("%d", &day);

   printf("Informe o mês de hoje: ");
   scanf("%d", &month);

   int i = list_emprestimos_atrasados(day, month);

   if(i<=0) {
      printf("Não existem emprestimos atrasados para serem listados.\n");
   }

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}