Aluno read_aluno(int pront) {
      Aluno aluno;
      aluno.status = 'A';
      int clear;

      if(pront) {
         aluno.prontuario = pront;
         printf("Prontuario do aluno..: PE%d.\n", aluno.prontuario);
         printf("Novo nome do aluno...: ");
         scanf("%d", &clear);
         readString(aluno.nome, 100);
         setbuf(stdin, NULL);

         printf("Novo curso do aluno..: ");
         readString(aluno.curso, 4);

      } else {
         int temp, isValid;

         do {
            printf("Informe o prontuario do aluno..: PE");
            scanf("%d", &temp);

            isValid = find_by_pront(temp);
            if(isValid != -1 && isValid != -2) {
               printf("Prontuario duplicado. Verifique e tente novamente.\n");
            }
            if(temp > 9999999 || temp < 0) {
               printf("Prontuario invalido. Tente novamente.\n");
               isValid = 0;
            }
         } while(isValid != -1);

         aluno.prontuario = temp;
         setbuf(stdin, NULL);

         printf("Informe o nome do aluno........: ");
         readString(aluno.nome, 100);
         setbuf(stdin, NULL);
         
         printf("Infome o curso do aluno........: ");
         readString(aluno.curso, 4);
      }

   return aluno;
}