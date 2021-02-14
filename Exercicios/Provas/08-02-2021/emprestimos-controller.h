void create_emprestimo() {
   system("cls");
   print_header("CADASTRO DE EMPRESTIMOS");

   Emprestimo emprestimo = read_emprestimo();

   if(emprestimo.codigo_aluno != -1) {
      update_livro_situacao(find_by_tombo(emprestimo.codigo_livro), 'E');
      save_emprestimo(emprestimo);
   } 
}

void index_emprestimos() {
   system("cls");
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
   system("cls");
   print_header("LISTAGEM DE EMPRESTIMOS ATRASADOS");

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

void emprestimos_aluno() {
   system("cls");
   print_header("LISTAGEM DE EMPRESTIMOS POR ALUNO");

   int pront;

   printf("Informe o prontuário para busca: PE");
   scanf("%d", &pront);

   system("cls");
   print_header("EMPRESTIMOS POR ALUNO");
   printf("PRONTUÁRIO: PE%d.\n\n", pront);

   int i = find_emprestimos_by_pront(pront);

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void emprestimos_curso() {
   system("cls");
   print_header("LISTAGEM DE EMPRESTIMOS POR CURSO");

   char curso[4];

   setbuf(stdin, NULL);
   printf("Informe o curso para busca: ");
   readString(curso, 4);

   system("cls");
   print_header("EMPRESTIMOS POR CURSO");
   printf("CURSO: %s.\n", curso);

   int i = count_emprestimos_by_curso(curso);

   if(i<=0) {
      printf("Não existem emprestimos desse curso para serem contados.\n");
   } else {
      printf("Quantidade de Emprestimos: %d.\n", i);
   }

   printf("\nPressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
   getchar();

}

void finalizar_emprestimo() {
   system("cls");
   print_header("DEVOLUCAO DE EMPRESTIMO");

   int tombo;

   int i = list_emprestimos('P');

   if(i<=0) {
      printf("Não existem emprestimos para serem devolvidos.\n");
      
      printf("Pressione Enter para continuar...");
      setbuf(stdin, NULL);
      getchar();

   } else {
      printf("Informe o tombo do livro: ");
      scanf("%d", &tombo);

      Livro livro = find_livro_by_index(find_by_tombo(tombo));
      
      if(livro.situacao == 'E' && livro.status == 'A') {
         int indexEmprestimo = find_emprestimo_by_tombo(tombo, 'P');
         if(indexEmprestimo == -1) {
            printf("Empréstimo inválido. Verifique os livros emprestados e tente novamente.\n");
            
            printf("Pressione Enter para continuar...");
            setbuf(stdin, NULL);
            getchar();

         } else {
            Emprestimo emprestimo = find_emprestimo_by_index(indexEmprestimo);
            system("cls");
            print_header("DEVOLUCAO DE EMPRESTIMO");
            printf("Emprestimo a ser finalizado: ");
            print_emprestimo(emprestimo, 1);
            printf("\nConfirmar Devolucao [S/N]: ");
            char continua;
            scanf(" %c", &continua);
            if(continua == 'S') {
               update_livro_situacao(find_by_tombo(tombo), 'D');
               update_emprestimo_situacao(indexEmprestimo, 'F');
            }
         }
      } else {
         printf("Livro inválido. Verifique os livros emprestados e tente novamente.\n");
         printf("Pressione Enter para continuar...");
         setbuf(stdin, NULL);
         getchar();
      }
   }
}

void emprestimos_livro() {
   system("cls");
   print_header("TOTAL DE EMPRESTIMOS POR LIVRO");

   int i = list_emprestimos_livros();

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}