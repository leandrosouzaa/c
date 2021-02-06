Aluno read_aluno() {
      Aluno aluno;
      aluno.status = 'A';
      
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

      return aluno;
}