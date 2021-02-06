void save_aluno(Aluno aluno) {
   FILE * file;

   file = fopen("alunos.dat", "ab");
   if(file == NULL)
   {
      printf("ERRO INTERNO: NÃO FOI POSSÍVEL MANIPULAR O ARQUIVO SOLICITADO \"alunos.dat\".\n ENCERRANDO SISTEMA");
      exit(1);
   }

   fwrite(&aluno, sizeof(Aluno), 1, file);
   fclose(file);
}

int find_by_pront(int prontuario)
{
   FILE *file;
   Aluno aluno;
   int posicao = -1, i = 0;

   file = fopen("alunos.dat", "rb");

   if(!cfileexists("alunos.dat")) {
      return -1;
   }

   if(file == NULL) {
      printf("ERRO INTERNO: NÃO FOI POSSÍVEL MANIPULAR O ARQUIVO SOLICITADO \"alunos.dat\".\n ENCERRANDO SISTEMA");
      posicao = -2;
   }
   else {
      fread(&aluno, sizeof(Aluno), 1, file);

      while(!feof(file) && posicao == -1)
      {
         if (aluno.prontuario == prontuario)
         {
            posicao = i;
            fseek(file, 0, SEEK_END);
         }
         fread(&aluno, sizeof(Aluno), 1, file);
         i++;
      }
      fclose(file);
   }
   return posicao;
}
