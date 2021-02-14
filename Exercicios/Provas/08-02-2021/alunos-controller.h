void index_alunos() {
   int limpa;
   system("cls");
   print_header("RELATÓRIO DE ALUNOS");

   int i = list_alunos('A');

   if(i==0) {
      printf("Não existem alunos para serem listados.\n");
   }

   printf("\nPressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void create_aluno() {
   system("cls");
   print_header("REGISTRO DE ALUNOS");

   Aluno aluno = read_aluno(NULL);
   save_aluno(aluno);
}

void invalidate_aluno() {
   system("cls");
   print_header("REMOCAO DE ALUNOS");
   int pront;

   int i = list_alunos('A');
   if(i<=0) {
      printf("Não existem alunos para serem excluidos.\n");         
      printf("\nPressione Enter para continuar...");

      setbuf(stdin, NULL);
      getchar();
      
   } else {
      printf("\nProntuario para exclusao: PE");
      scanf("%d", &pront);

      int index = find_by_pront(pront);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
         printf("\nPressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();

      } else {
         Aluno aluno = find_aluno_by_index(index);

         if(aluno.status != 'A') {
            printf("Este Aluno ja foi desativado. Para excluir da base de dados volte ao menu e escolha a opcao REMOCAO FISICA.\n");
            printf("Pressione enter para continuar.");
            getchar();
         } else {
            printf("ALUNO ENCONTRADO:\n\n");
            print_aluno(aluno);

            printf("\nExcluir aluno [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_aluno_status(index, 'I');
            }
         }
      }
   }
}

void show_aluno() {
   system("cls");
   printf("BUSCA DE ALUNO POR PRONTUÁRIO\n\n");
   int pront;

   printf("Prontuário para busca: PE");
   scanf("%d", &pront);

   int index = find_by_pront(pront);

   system("cls");
   if(index == -1) {
      printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
      printf("Pressione Enter para continuar...");

   } else {
      Aluno aluno = find_aluno_by_index(index);

      printf("ALUNO ENCONTRADO:\n\n");
      print_aluno(aluno);
   }

   getchar();
   getchar();
}

void recover_aluno() {
   system("cls");

   print_header("RECUPERACAO DE ALUNOS");

   printf("Alunos disponiveis:\n");
   int i = list_alunos('I');

   if(i != 0) {
      int pront;

      printf("Prontuario para recuperacao: PE");
      scanf("%d", &pront);

      int index = find_by_pront(pront);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
         printf("Pressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();
      } else {
         Aluno aluno = find_aluno_by_index(index);

         if(aluno.status != 'I') {
            printf("Este Aluno não está desativado. Para desativar volte ao menu e escolha a opcao REMOVER ALUNO.\n");
         } else {
            printf("ALUNO ENCONTRADO:\n\n");
            print_aluno(aluno);

            printf("\nReativar aluno [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_aluno_status(index, 'A');
            }
         }
      }
   } else {
      printf("Não existem alunos para serem recuperados.\n");
      printf("\nPressione Enter para continuar...");

      setbuf(stdin, NULL);
      getchar();
   }
}

void update_aluno() {
   system("cls");
   print_header("ATUALIZACAO DE ALUNOS");

   printf("Alunos disponiveis:\n");
   int i = list_alunos('A');

   if(i<=0) {
      printf("Não existem alunos para serem atualizados.\n");
      printf("\nPressione Enter para continuar...");

      getchar();
   } else {
      int pront;

      printf("Prontuario para atualizacao: PE");
      scanf("%d", &pront);

      int index = find_by_pront(pront);

      system("cls");
      if(index == -1) {
         printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
         printf("\nPressione Enter para continuar...");

         setbuf(stdin, NULL);
         getchar();
      } else {
         Aluno aluno = find_aluno_by_index(index);

         if(aluno.status != 'A') {
            printf("Este Aluno esta desativado. Para atualizar os dados do mesmo reative o registro na opcao de RECUPERACAO.\n");
            printf("\nPressione Enter para continuar...");

            setbuf(stdin, NULL);
            getchar();
         } else {
            printf("ALUNO ENCONTRADO:\n\n");
            print_aluno(aluno);

            printf("\nAtualizar aluno[S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               system("cls");
               printf("ATUALIZACAO DE ALUNO\n\n");
               aluno = read_aluno(aluno.prontuario);
               save_update_aluno(index, aluno);
            }
         }
      }
   }
}

void remove_alunos() {
   system("cls");

   print_header("EXCLUSAO DE ALUNOS");

   int i = list_alunos('I');

   char continua;
   printf("\nDeseja realmente excluir DEFINITVAMENTE esses registros [S/N]: ");
   scanf(" %c", &continua);

   if(continua == 'S') {
      cls_alunos();
   }
}