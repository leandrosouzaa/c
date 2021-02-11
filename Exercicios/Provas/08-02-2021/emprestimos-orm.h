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
               print_emprestimo(emprestimo);
               i++;
               fread(&emprestimo, sizeof(Emprestimo), 1, file);
            }
            break;
         default:
            while(feof(file)) {
               if(emprestimo.situacao == filter) {
                  print_emprestimo(emprestimo);
                  i++;
               }
               fread(&emprestimo, sizeof(Emprestimo), 1, file);
            }
            break;
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
            print_emprestimo(emprestimo);
            i++;
         }
         fread(&emprestimo, sizeof(Emprestimo), 1, file);
      }
   return i;
}


