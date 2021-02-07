void index_aluno() {
   int limpa;
   system("clear");

   printf("RELATÓRIO DE ALUNOS\n\n");
   list_alunos();

   printf("\nPressione Enter para finalizar...");
   
   setbuf(stdin, NULL);
   getchar();
   getchar();
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
      printf("Não foi encontrado nenhum aluno com o prontuário PE%d.\n", pront);
      printf("Pressione Enter para continuar...");

   } else {
      Aluno aluno = find_by_index(index);

      printf("ALUNO ENCONTRADO:\n\n");
      printf("Prontuário..: PE%d.\n",aluno.prontuario);
      printf("Nome........: %s.\n", aluno.nome);
      printf("Curso.......: %s.\n", aluno.curso);
      
   }

   getchar();
   getchar();
}

Aluno create_aluno() {
   Aluno aluno = read_aluno();
   save_aluno(aluno);
   
   return aluno;
}