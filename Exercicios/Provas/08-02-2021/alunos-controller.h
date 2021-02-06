void index_aluno() {
   system("clear");

   printf("RELATÓRIO DE ALUNOS:\n\n");
   list_alunos();

   printf("\nPressione Enter para finalizar...");
   getchar();
   getchar();
}


Aluno create_aluno() {
   Aluno aluno = read_aluno();
   save_aluno(aluno);
   
   return aluno;
}