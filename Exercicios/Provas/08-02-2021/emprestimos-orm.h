void save_emprestimo(Emprestimo emprestimo) {
   FILE * file;

   file = fopen("emprestimos.dat", "ab");
   if(file == NULL) {
      internalError("Criacao de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   }

   fwrite(&emprestimo, sizeof(Emprestimo), 1, file);
   fclose(file);
}

int list_emprestimos(char filter) {
   FILE *file;
   int i = 0;

   Emprestimo emprestimo;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");
      printf("caiu");
      return -1;
   }

   file = fopen("emprestimos.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      fread(&emprestimo, sizeof(Emprestimo), 1, file);

      switch(filter) {
         case 'T':
            while(!feof(file)) {
               print_emprestimo(emprestimo, 1);
               i++;
               fread(&emprestimo, sizeof(Emprestimo), 1, file);
            }
            break;
         default:
            while(!feof(file)) {
               if(emprestimo.situacao == filter) {
                  print_emprestimo(emprestimo, 1);
                  i++;
               }
               fread(&emprestimo, sizeof(Emprestimo), 1, file);
            }
            break;
      }
   }
   return i;
}

int list_emprestimos_livros() {
   FILE *file, *file_livros;
   int i = 0;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");
      return -1;
   }

   if(!cfileexists("livros.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");
      return -1;
   }

   file = fopen("emprestimos.dat", "rb");
   file_livros = fopen("livros.dat", "rb");

   Livro livro;
   Emprestimo emprestimo;

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      if(file_livros == NULL) {
         internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"livros.dat\". Finalizando o sistema...");
      } else {
         fread(&livro, sizeof(Livro), 1, file_livros);
         fread(&emprestimo, sizeof(Emprestimo), 1, file);

         while(!feof(file_livros)) {
            i=0;
            while(!feof(file)) {
               if(emprestimo.codigo_livro == livro.tombo) {
                  i++;
               }
               fread(&emprestimo, sizeof(Emprestimo), 1, file);
            }
            fread(&livro, sizeof(Livro), 1, file_livros);
            fseek(file, 0, SEEK_SET);
            print_livro(livro, 0);
            printf("Quantidade de Emprestimos: %d.\n", i);
            printf("+-+-+-+-+-+-+-+-+-+-+\n\n");
         }
      }
   }
   return i;
}

int list_emprestimos_atrasados(int day, int month) {
   FILE *file;
   int i = 0;

   Emprestimo emprestimo;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");

      return -1;
   }

   file = fopen("emprestimos.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      fread(&emprestimo, sizeof(Emprestimo), 1, file);

      while(!feof(file)) {
         if( emprestimo.situacao == 'P' && (month > emprestimo.mes_devolucao ||(day > emprestimo.dia_devolucao && (month >= emprestimo.mes_devolucao)))) {
            print_emprestimo(emprestimo, 1);
            i++;
         }
         fread(&emprestimo, sizeof(Emprestimo), 1, file);
      }
   }
   return i;
}

int find_emprestimos_by_pront(int pront) {
   FILE *file;
   int i = 0;

   Emprestimo emprestimo;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");

      return -1;
   }

   file = fopen("emprestimos.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      fread(&emprestimo, sizeof(Emprestimo), 1, file);

      while(!feof(file)) {
         if(emprestimo.codigo_aluno == pront) {
            print_emprestimo(emprestimo, 0);
            i++;
         }
         fread(&emprestimo, sizeof(Emprestimo), 1, file);
      }
   }
   return i;
}

int find_emprestimo_by_tombo(int tombo, char filter) {
   FILE *file;
   int i = 0, posicao = -1;

   Emprestimo emprestimo;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");
      return posicao;
   }

   file = fopen("emprestimos.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      fread(&emprestimo, sizeof(Emprestimo), 1, file);

      while(!feof(file)) {
         if(emprestimo.codigo_livro == tombo && emprestimo.situacao == filter) {
            posicao = i;
            fseek(file, 0, SEEK_END);
         }
         fread(&emprestimo, sizeof(Emprestimo), 1, file);
      }
   }
   return posicao;

}

Emprestimo find_emprestimo_by_index(int posicao) {
   FILE *file;
   Emprestimo emprestimo;

   file = fopen("emprestimos.dat", "rb");
   if (file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
   } else {
      fseek(file, posicao*sizeof(Emprestimo), SEEK_SET);
      fread(&emprestimo, sizeof(Emprestimo), 1, file);

      fclose(file);
   }

   return emprestimo;
};

int count_emprestimos_by_curso(char curso[4]) {
   FILE *file;
   int i = 0;

   Emprestimo emprestimo;

   if(!cfileexists("emprestimos.dat")) {
      printf("Não existem emprestimos para serem exibidos.\n");

      return -1;
   }

   file = fopen("emprestimos.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   } else {
      fread(&emprestimo, sizeof(Emprestimo), 1, file);
      Aluno aluno;
      while(!feof(file)) {
         aluno = find_aluno_by_index(find_by_pront(emprestimo.codigo_aluno));
         if(strcmp(aluno.curso, curso) == 0) 
            i++;

         fread(&emprestimo, sizeof(Emprestimo), 1, file);
      }
   }
   return i;
}

int update_emprestimo_situacao(int index, char status) {
   FILE *file;
   Emprestimo emprestimo;

   file = fopen("emprestimos.dat", "rb+");

   if (file == NULL) {
      internalError("Abertura de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
      return 0;

   } 
   fseek(file, index*sizeof(Emprestimo), SEEK_SET);
   fread(&emprestimo, sizeof(Emprestimo), 1, file);
   
   emprestimo.situacao = status;
   
   fseek(file, index*sizeof(Emprestimo), SEEK_SET);
   fwrite(&emprestimo, sizeof(Emprestimo), 1, file);
   fclose(file);
   
   return 1;
}