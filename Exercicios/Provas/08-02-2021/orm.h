void save_aluno(Aluno aluno) {
   FILE * file;

   file = fopen("alunos.dat", "ab");
   if(file == NULL)
   {
      internalError("Criacao de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
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
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
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

void list_alunos() {
   FILE *file;

   Aluno aluno;

   if(!cfileexists("alunos.dat")) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
   }

   file = fopen("alunos.dat", "rb");

   if(file == NULL) {
      printf("Não existem alunos para serem exibidos.\n");
   } else {
      fread(&aluno, sizeof(Aluno), 1, file);
      
      printf("+-----------+----------------------------------------------------+--------+\n");
      printf("| %-9s | %-50s | %-6s |", "Pront.", "Nome", "Curso");
      printf("\n+-----------+----------------------------------------------------+--------+\n");
      
      while(!feof(file))
      {
         printf("| PE%-7d | %-50s | %-6s |", aluno.prontuario , aluno.nome, aluno.curso);
         printf("\n+-----------+----------------------------------------------------+--------+\n");

         fread(&aluno, sizeof(Aluno), 1, file);
      }
      fclose(file);
   }
}