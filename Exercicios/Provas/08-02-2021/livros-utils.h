Livro read_livro(int tombo, char situacao) {
      Livro livro;
      livro.status = 'A';

      if(tombo && situacao) {
         livro.tombo = tombo;
         livro.situacao = situacao;
         printf("Tombo do livro............: %d.\n", livro.tombo);
         setbuf(stdin, NULL);

         printf("Novo nome do livro........: ");
         readString(livro.titulo, 99);
         setbuf(stdin, NULL);

         printf("Novos autore(s) do livro..: ");
         readString(livro.autores, 149);
         setbuf(stdin, NULL);

         printf("Nova data do livro........: ");
         scanf("%d", &livro.ano);

      } else {
         livro.situacao = 'D';

         int temp, isValid;

         do {
            printf("Informe o tombo do livro.....: ");
            scanf("%d", &temp);

            isValid = find_by_tombo(temp);
            if(isValid != -1 && isValid != -2) {
               printf("Tombo duplicado. Verifique e tente novamente.\n");
            }
         } while(isValid != -1);

         livro.tombo = temp;
         setbuf(stdin, NULL);

         printf("Informe o titulo do livro......: ");
         readString(livro.titulo, 99);
         setbuf(stdin, NULL);

         printf("Informe os autore(s) do livro..: ");
         readString(livro.autores, 149);
         setbuf(stdin, NULL);
         
         printf("Infome o ano do livro..........: ");
         scanf("%d", &livro.ano);
      }

   return livro;
}