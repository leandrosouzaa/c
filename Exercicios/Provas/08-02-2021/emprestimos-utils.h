Emprestimo read_emprestimo() {
   int temp, indexAluno, isValid = 0, indexLivro = 0;
   char continua;
   Aluno aluno;
   Livro livro;
   Emprestimo emprestimo;
   emprestimo.status= 'A';
   emprestimo.situacao = 'P';

   do {
      system("cls");
      print_header("CADASTRO DE EMPRESTIMOS");
      temp = list_alunos('A');

      if(temp <= 0) {
         printf("Não existem alunos. Verifique e tente novamente.\n");
         
         setbuf(stdin, NULL);
         getchar();

         emprestimo.codigo_aluno = -1;
         return emprestimo;
      } 
      printf("\nInforme o prontuário do Aluno..: PE");
      scanf("%d", &temp);
      indexAluno = find_by_pront(temp);
      if(indexAluno < 0) {
         printf("Prontuario inválido. Verifique e tente novamente.\n");
         
         setbuf(stdin, NULL);
         getchar();
      } else { 
         aluno = find_aluno_by_index(indexAluno);
         if(aluno.status == 'I') {
            printf("Esse aluno esta excluido. Volte ao meu e reeative o registro.\n");
            
            setbuf(stdin, NULL);
            getchar();
         } else {
            system("cls");
            print_header("CADASTRO DE EMPRESTIMOS");
            printf("Aluno encontrado:\n");
            print_aluno(aluno);
            printf("\nConfirmar Aluno [S/N]: ");

            setbuf(stdin, NULL);
            scanf("%c", &continua);

            if(continua == 'S') {
               isValid = 1;
            }
         }
      }
   } while(isValid == 0);
   isValid = 0;
   emprestimo.codigo_aluno = temp;

   do {
      system("cls");
      print_header("CADASTRO DE EMPRESTIMOS");
      temp = list_livros('A', 'D');

      if(temp <= 0) {
         printf("Não existem livros disponíveis. Verifique e tente novamente.\n");
         
         setbuf(stdin, NULL);
         getchar();

         emprestimo.codigo_aluno = -1;
         return emprestimo;
      } 

      printf("Informe o tombo do Livro......: ");
      scanf("%d", &temp);
      indexLivro = find_by_tombo(temp);
      if(indexLivro < 0) {
         printf("Tombo inválido. Verifique e tente novamente.");
         setbuf(stdin, NULL);
         getchar();

      } else {
         Livro livro = find_livro_by_index(indexLivro);

         if(livro.status == 'I') {
            printf("Esse livro esta excluido. Volte no meu e reeative o registro.");
            setbuf(stdin, NULL);
            getchar();
            
         } else {
            if(livro.situacao == 'E') {
               printf("Esse livro esta emprestado. Finalize o emprestimo antigo primeiro.");
               setbuf(stdin, NULL);
               getchar();

            } else {
               print_header("CADASTRO DE EMPRESTIMOS");
               system("cls");
               printf("\nLivro encontradao:\n");
               print_livro(livro, 0);
               printf("\nConfirmar Livro [S/N]: ");

               setbuf(stdin, NULL);
               scanf("%c", &continua);

               if(continua == 'S') {
                  isValid = 1;
               }
            }
         }
      }
   } while(isValid == 0);
   emprestimo.codigo_livro = temp;
   system("cls");
   print_header("CADASTRO DE EMPRESTIMOS");
   printf("Aluno: \n");
   print_aluno(aluno);
   printf("\n");
   printf("Livro: \n");
   print_livro(livro, 0);
   printf("\n");

   printf("Informe o dia do emprestimo: ");
   scanf("%d", &emprestimo.dia);
   printf("Informe o mes do emprestimo: ");
   scanf("%d", &emprestimo.mes);

   emprestimo.dia_devolucao = emprestimo.dia + 7;
   if(emprestimo.dia > 30) {
      emprestimo.dia-=30;
      emprestimo.mes_devolucao = emprestimo.mes + 1;
   } else {
      emprestimo.mes_devolucao = emprestimo.mes;
   }

   system("cls");

   print_header("CADASTRO DE EMPRESTIMOS");
   printf("Aluno: \n");
   print_aluno(aluno);
   printf("\n");
   printf("Livro:\n");
   print_livro(livro, 0);
   printf("Emprestimo: ");
   printf("\nData do emprestimo: %s%d/%s%d/2020.\n",emprestimo.dia < 10 ? "0" : "" , emprestimo.dia, emprestimo.mes < 10 ? "0" : "", emprestimo.mes);
   printf("Data de devolucao: %s%d/%s%d/2020.\n",emprestimo.dia_devolucao < 10 ? "0" : "" , emprestimo.dia_devolucao, emprestimo.mes < 10 ? "0" : "", emprestimo.mes_devolucao);
   printf("\nConfirmar Emprestimo [S/N]: ");
   scanf(" %c", &continua);

   if(continua == 'S') {
      return emprestimo;
   } else {
      emprestimo.codigo_aluno = -1;
      return emprestimo;
   }
}

void print_emprestimo(Emprestimo emprestimo, int printAluno) {
   printf("\n");
   int temp = find_by_pront(emprestimo.codigo_aluno);
   Aluno aluno = find_aluno_by_index(temp);

   if(printAluno) {
      printf("ALUNO: \n");
      if(temp < 0 || aluno.status == 'I') {
         printf("ALUNO DELETADO.");
         aluno.status == 'I' ? printf("VOLTE AO MENU PARA RECUPERAR O REGISTRO\n") : printf("\n");
      } else {
         print_aluno(aluno);
      }
   }

   temp = find_by_tombo(emprestimo.codigo_livro);
   Livro livro = find_livro_by_index(temp);

   printf("\nLIVRO: \n");
   if(temp < 0 || livro.status == 'I') {
      printf("LIVRO DELETADO.");
      livro.status == 'I' ? printf("VOLTE AO MENU PARA RECUPERAR O REGISTRO\n"):printf("\n");
   } else {
      print_livro(livro, 0);
   }
   
   printf("Data do emprestimo: %s%d/%s%d/2020.\n",emprestimo.dia < 10 ? "0" : "" , emprestimo.dia, emprestimo.mes < 10 ? "0" : "", emprestimo.mes);
   printf("Data de devolucao: %s%d/%s%d/2020.\n",emprestimo.dia_devolucao < 10 ? "0" : "" , emprestimo.dia_devolucao, emprestimo.mes < 10 ? "0" : "", emprestimo.mes_devolucao);
   printf("\nSITUACAO: %s (%c).\n\n", emprestimo.situacao == 'P' ? "PENDENTE" : "FINALIZADO", emprestimo.situacao);
   printf("+-+-+-+-+-+-+-+-+-+-+\n\n");
};