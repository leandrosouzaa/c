Livro read_livro(int tombo) {
      Livro livro;
      livro.situacao = 'D';
      livro.status = 'A';

      if(tombo) {
         livro.tombo = tombo;
         printf("Tombo do livro..: %d.\n", livro.tombo);
         setbuf(stdin, NULL);

         printf("Novo nome do livro...: ");
         readString(livro.titulo, 99);
         setbuf(stdin, NULL);

         printf("Novos autores do livro...: ");
         readString(livro.autores, 149);
         setbuf(stdin, NULL);

         printf("Nova data do livro..: ");
         scanf("%d", &livro.ano);

      } else {
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

         printf("Informe o titulo do livro....: ");
         readString(livro.titulo, 99);
         setbuf(stdin, NULL);

         printf("Informe os autores do livro..: ");
         readString(livro.autores, 149);
         setbuf(stdin, NULL);
         
         printf("Infome o ano do livro........: ");
         scanf("%d", &livro.ano);
      }

   return livro;
}