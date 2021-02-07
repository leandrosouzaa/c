void index_aluno() {
   int limpa;
   system("clear");

   printf("RELATÓRIO DE ALUNOS\n\n");
   list_alunos('T');

   printf("\nPressione Enter para finalizar...");
   
   setbuf(stdin, NULL);
   getchar();
   getchar();
}

Aluno create_aluno() {
   system("clear");

   Aluno aluno = read_aluno();
   save_aluno(aluno);
   
   return aluno;
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

         printf("\nExcluir aluno? [S/N]: ");
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

            printf("\nReativar aluno? [S/N]: ");
            char continua;

            scanf(" %c", &continua);

            if(continua == 'S') {
               update_status(index, 'A');
            }
         }
      }
   } else {
      printf("Não existem alunos para serem recuperados.\n");
   }

}