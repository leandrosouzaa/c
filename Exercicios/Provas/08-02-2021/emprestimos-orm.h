void save_emprestimo(Emprestimo emprestimo) {
   FILE * file;

   file = fopen("emprestimos.dat", "ab");
   if(file == NULL) {
      internalError("Criacao de Arquivo", "Nao foi possivel manipular o arquivo solicitado \"emprestimos.dat\". Finalizando o sistema...");
   }

   fwrite(&emprestimo, sizeof(Emprestimo), 1, file);
   fclose(file);
}