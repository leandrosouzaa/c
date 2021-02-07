void index_aluno() {
   int limpa;
   system("clear");

   printf("RELATÓRIO DE ALUNOS\n\n");
   int i = list_alunos('T');

   if(i==0) {
      printf("Não existem alunos para serem listados.\n");
   }

   printf("\nPressione Enter para finalizar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void create_aluno() {
   system("clear");
   printf("REGISTRO DE ALUNOS\n\n");

   Aluno aluno = read_aluno(NULL);
   save_aluno(aluno);
}

void invalidate_aluno() {
   system("clear");
   printf("REMOÇÃO DE ALUNO\n\n");
   int pront;

   printf("Prontuario para exclusao: PE");
   scanf("%d", &pront);

   int index = find_by_pront(pront);

   system("clear");
   if(index == -1) {
      printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
      printf("Pressione Enter para continuar...");

   } else {
      Aluno aluno = find_by_index(index);

      if(aluno.status != 'A') {
         printf("Este Aluno ja foi desativado. Para excluir da base de dados volte ao menu e escolha a opcao REMOCAO FISICA.\n");
      } else {
         printf("ALUNO ENCONTRADO:\n\n");
         printf("Prontuario..: PE%d.\n",aluno.prontuario);
         printf("Nome........: %s.\n", aluno.nome);
         printf("Curso.......: %s.\n", aluno.curso);

         printf("\nExcluir aluno [S/N]: ");
         char continua;

         scanf(" %c", &continua);

         if(continua == 'S') {
            update_status(index, 'I');
         }
      }
   }
}

void show_aluno() {
   system("clear");
   printf("BUSCA DE ALUNO POR PRONTUÁRIO\n\n");
   int pront;

   printf("Prontuário para busca: PE");
   scanf("%d", &pront);

   int index = find_by_pront(pront);

   system("clear");
   if(index == -1) {
      printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
      printf("Pressione Enter para continuar...");

   } else {
      Aluno aluno = find_by_index(index);

      printf("ALUNO ENCONTRADO:\n\n");
      printf("Prontuario..: PE%d.\n",aluno.prontuario);
      printf("Nome........: %s.\n", aluno.nome);
      printf("Curso.......: %s.\n", aluno.curso);
      
   }

   getchar();
   getchar();
}

void recover_aluno() {
   system("clear");

   printf("ALUNOS DISPONÍVEIS PARA RECUPERAÇÃO\n\n");
   int i = list_alunos('I');

   if(i != 0) {
      int pront;

      printf("Prontuario para recuperação: PE");
      scanf("%d", &pront);

      int index = find_by_pront(pront);

      system("clear");
      if(index == -1) {
         printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
         printf("Pressione Enter para continuar...");

      } else {
         Aluno aluno = find_by_index(index);

         if(aluno.status != 'I') {
            printf("Este Aluno não está desativado. Para desativar volte ao menu e escolha a opcao REMOVER ALUNO.\n");
         } else {
            printf("ALUNO ENCONTRADO:\n\n");
            printf("Prontuario..: PE%d.\n",aluno.prontuario);
            printf("Nome........: %s.\n", aluno.nome);
            printf("Curso.......: %s.\n", aluno.curso);

            printf("\nReativar aluno [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_status(index, 'A');
            }
         }
      }
   } else {
      printf("Não existem alunos para serem recuperados.\n");
      printf("\nPressione Enter para finalizar...");


      setbuf(stdin, NULL);
      getchar();
   }
}

void update_aluno() {
   system("clear");
   printf("ATUALIZACAO DE ALUNO\n\n");
   int pront;

   printf("Prontuario para atualizacao: PE");
   scanf("%d", &pront);

   int index = find_by_pront(pront);

   system("clear");
   if(index == -1) {
      printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
      printf("Pressione Enter para continuar...");

   } else {
      Aluno aluno = find_by_index(index);

      if(aluno.status != 'A') {
         printf("Este Aluno esta desativado. Para atualizar os dados do mesmo reative o registro na opcao de RECUPERACAO.\n");
      } else {
         printf("ALUNO ENCONTRADO:\n\n");
         printf("Prontuario..: PE%d.\n",aluno.prontuario);
         printf("Nome........: %s.\n", aluno.nome);
         printf("Curso.......: %s.\n", aluno.curso);

         printf("\nAtualizar aluno[S/N]: ");
         char continua;

         scanf(" %c", &continua);

         if(continua == 'S') {
            system("clear");
            printf("ATUALIZACAO DE ALUNO\n\n");
            aluno = read_aluno(aluno.prontuario);
            save_update_aluno(index, aluno);
         }
      }
   }
}

void remove_alunos() {
   system("clear");

   printf("ALUNOS DISPONÍVEIS QUE SERAM EXCLUIDOS\n\n");
   int i = list_alunos('I');

   char continua;
   printf("\nDeseja realmente excluir DEFINITVAMENTE esses registros [S/N]: ");
   scanf(" %c", &continua);

   if(continua == 'S') {
      clear_alunos();
   }
}