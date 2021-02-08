void save_livro(Livro livro) {
   FILE * file;

   file = fopen("livros.dat", "ab");
   if(file == NULL) {
      internalError("Criacao de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"livros.dat\". Finalizando o sistema...");
   }

   fwrite(&livro, sizeof(Livro), 1, file);
   fclose(file);
}

// int update_status(int index, char status) {
//    FILE *file;
//    Aluno aluno;

//    file = fopen("alunos.dat", "rb+");

//    if (file == NULL) {
//       internalError("Abertura de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
//       return 0;

//    } 
//    fseek(file, index*sizeof(Aluno), SEEK_SET);
//    fread(&aluno, sizeof(Aluno), 1, file);
   
//    aluno.status = status;
   
//    fseek(file, index*sizeof(Aluno), SEEK_SET);
//    fwrite(&aluno, sizeof(Aluno), 1, file);
//    fclose(file);
   
//    return 1;
// }

// int save_update_aluno(int index, Aluno aluno) {
//    FILE *file;

//    file = fopen("alunos.dat", "rb+");

//    if (file == NULL) {
//       internalError("Abertura de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
//       return 0;
//    } 

//    fseek(file, index*sizeof(Aluno), SEEK_SET);
//    fwrite(&aluno, sizeof(Aluno), 1, file);
//    fclose(file);

//    return 1;
// }

// Aluno find_by_index(int posicao) {
//    FILE *file;
//    Aluno aluno;

//    file = fopen("alunos.dat", "rb");
//    if (file == NULL) {
//       internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
//    } else {
//       fseek(file, posicao*sizeof(Aluno), SEEK_SET);
//       fread(&aluno, sizeof(Aluno), 1, file);

//       fclose(file);
//    }

//    return aluno;
// };

int find_by_tombo(int tombo) {
   FILE *file;
   Livro livro;
   int posicao = -1, i = 0;

   if(!cfileexists("livros.dat")) {
      return -1;
   }

   file = fopen("livros.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"livro.dat\". Finalizando o sistema...");
   }
   else {
      fread(&livro, sizeof(Livro), 1, file);

      while(!feof(file))
      {
         if (livro.tombo == tombo) {
            posicao = i;
            fseek(file, 0, SEEK_END);
         }
         fread(&tombo, sizeof(Livro), 1, file);
         i++;
      }
      fclose(file);
   }
   return posicao;
}

int list_livros(char status, char filter) {
   FILE *file;

   Livro livro;

   if(!cfileexists("livros.dat")) {
      printf("Não existem livros para serem exibidos.\n");

      return -1;
   }

   file = fopen("livros.dat", "rb");

   if(file == NULL) {
      internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"livros.dat\". Finalizando o sistema...");
   } else {
      int i = 0;
      fread(&livro, sizeof(Livro), 1, file);

      switch (status) {
         case 'T':
            switch (filter) {
               case 'T':
                  while(!feof(file)) {
                     print_livro(livro);
                     fread(&livro, sizeof(Livro), 1, file);
                     i++;
                  }
                  break;

               default:
                  while(!feof(file)) {
                     if(livro.situacao == filter) {
                        print_livro(livro);
                        fread(&livro, sizeof(Livro), 1, file);
                        i++;
                     }
                  }
                  break;
         }
      default:
         switch (filter) {
            case 'T':
               while(!feof(file)) {
                  if(livro.status == status) {
                     print_livro(livro);
                     fread(&livro, sizeof(Livro), 1, file);
                     i++;
                  }
               }
               break;

            default:
               while(!feof(file)) {
                  if(livro.situacao == filter && livro.status == status) {
                     print_livro(livro);
                     fread(&livro, sizeof(Livro), 1, file);
                     i++;
                  }
               }
               break;
         }
         break;
      }

      fclose(file);
      return i;
   }

   return -1;
}

// void clear_alunos() {
//    FILE *file, *destiny;

//    Aluno aluno;

//    file = fopen("alunos.dat", "rb");
//    destiny = fopen("novo.dat", "wb");

//    if(!cfileexists("alunos.dat")) {
//       printf("Não existem alunos para serem lidos.");   
//    }

//    if(file == NULL) {
//       internalError("Leitura de Arquivo", "Nao foi possivel acessar o arquivo solicitado \"alunos.dat\". Finalizando o sistema...");
//    }

//    if(destiny == NULL) {
//       internalError("Criacao de Arquivo", "Nao foi possivel criar o arquivo solicitado \"novo.dat\". Finalizando o sistema...");
//    } else {
//       fread(&aluno, sizeof(Aluno), 1, file);

//       while(!feof(file)) {
//          if (aluno.status == 'A')
//             fwrite(&aluno, sizeof(Aluno), 1, destiny);

//          fread(&aluno, sizeof(Aluno), 1, file);
//       }

//       fclose(file);
//       fclose(destiny);

//       remove("alunos.dat");
//       rename("novo.dat", "alunos.dat");
//    }
// }