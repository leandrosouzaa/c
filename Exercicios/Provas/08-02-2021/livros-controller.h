void index_livros() {
   int limpa;
   system("cls");
   print_header("RELATÓRIO DE LIVROS");

   int i = list_livros('A','T');

   if(i<=0) {
   }

   printf("\nPressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void create_livro() {
   system("cls");
   print_header("REGISTRO DE LIVROS");

   Livro livro = read_livro(NULL, NULL);
   save_livro(livro);
}

void filter_livros() {
   int limpa;
   char type;

   system("cls");
   print_header("RELATÓRIO DE LIVROS");

   printf("Selecione um tipo para ser listado: \n");
   printf("D - Disponível\n");
   printf("E - Emprestado\n");
   printf("Tipo desejado: ");
   scanf(" %c", &type);

   system("cls");
   type == 'D' ? print_header("RELATÓRIO DE LIVROS DISPONIVEIS") : print_header("RELATORIO DE LIVROS EMPRESTADOS");
   

   int i = list_livros('A',type);

   printf("\nPressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
   getchar();

}

void invalidate_livro() {
   system("cls");
   print_header("REMOCAO DE LIVROS");
   int tombo;

   int i = list_livros('A','T');
   if(i<=0) {
      printf("\nPressione Enter para continuar...");

      setbuf(stdin, NULL);
      getchar();
      
   } else {
      printf("\nTombo do livro para exclusao: ");
      scanf("%d", &tombo);

      int index = find_by_tombo(tombo);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum livro com o tombo %d.\n", tombo);
         printf("\nPressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();

      } else {
         Livro livro = find_livro_by_index(index);

         if(livro.status != 'A') {
            printf("Este livro ja foi desativado. Para excluir da base de dados volte ao menu e escolha a opcao REMOCAO FISICA.\n");
            printf("Pressione enter para continuar.");

            setbuf(stdin, NULL);
            getchar();
         } else {
            printf("LIVRO ENCONTRADO:\n\n");
            print_livro(livro, 1);

            printf("\nExcluir livro [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_livro_status(index, 'I');
            }
         }
      }
   }
}

void show_livro() {
   system("cls");
   print_header("BUSCA DE LIVRO POR TOMBO");
   int tombo;

   printf("Tombo para busca: ");
   scanf("%d", &tombo);

   int index = find_by_tombo(tombo);

   system("cls");
   if(index == -1) {
      printf("Não foi encontrado nenhum livro com o tombo %d.\n", tombo);
      printf("Pressione Enter para continuar...");

   } else {
      Livro livro = find_livro_by_index(index);
      print_livro(livro, 1);
   }

   getchar();
   getchar();
}

void recover_livro() {
   system("cls");

   print_header("RECUPERACAO DE LIVROS");

   printf("Livros disponiveis:\n");
   int i = list_livros('I', 'T');

   if(i > 0) {
      int tombo;

      printf("Tombo para recuperacao: ");
      scanf("%d", &tombo);

      int index = find_by_tombo(tombo);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum livro com o tombo %d.\n", tombo);
         printf("Pressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();
      } else {
         Livro livro = find_livro_by_index(index);

         if(livro.status != 'I') {
            printf("Este livro não está desativado. Para desativar volte ao menu e escolha a opcao REMOVER ALUNO.\n");
         } else {
            printf("LIVRO ENCONTRADO:\n\n");
            print_livro(livro, 1);

            printf("\nReativar livro [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_livro_status(index, 'A');
            }
         }
      }
   } else {
      printf("\nPressione Enter para continuar...");

      setbuf(stdin, NULL);
      getchar();
   }
}

void update_livro() {
   int tombo;

   system("cls");
   print_header("ATUALIZACAO DE LIVROS");

   printf("Livros disponiveis:\n");
   int i = list_livros('A', 'T');

   if(i<=0) {
      printf("\nPressione Enter para continuar...");

      setbuf(stdin, NULL);
      getchar();
   } else {

      printf("Tombo para atualizacao: ");
      scanf("%d", &tombo);
   
      int index = find_by_tombo(tombo);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum livro com o tombo %d.\n", tombo);
         printf("\nPressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();
      } else {

         Livro livro = find_livro_by_index(index);

         if(livro.status != 'A') {
            printf("Este livro esta desativado. Para atualizar os dados do mesmo reative o registro na opcao de RECUPERACAO.\n");
            printf("\nPressione Enter para continuar...");

            setbuf(stdin, NULL);
            getchar();
         } else {
            printf("LIVRO ENCONTRADO:\n\n");
            print_livro(livro, 0);

            printf("\nAtualizar Livro[S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               system("cls");
               printf("ATUALIZACAO DE LIVRO\n\n");
               livro = read_livro(livro.tombo, livro.situacao);
               save_update_livro(index, livro);
            }
         }
      }
   }
}

void remove_livros() {
   system("cls");

   print_header("EXCLUSAO DE LIVROS");

   int i = list_livros('I','T');

   char continua;
   printf("\nDeseja realmente excluir DEFINITVAMENTE esses registros [S/N]: ");
   scanf(" %c", &continua);

   if(continua == 'S') {
      cls_livros();
   }
}