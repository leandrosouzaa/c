int tamanho_string(char str[]) {
   int i = 0;
   
   while(str[i] != '\0') {
      i++;
   } 

   return i;
};

void incializa_string(char str[]) {
   str[0] = '\0';
}

void copia_string(char str[], char str2[]) {
   int i=0;
   while(str[i] != '\0') {
      str2[i]=str[i];
      i++;
   };
   str[i] = '\0';
}

void concatena_string(char str[], char str2[]) {
   int i = 0;

   int tamanho_str1 = tamanho_string(str);
   
   while(str2[i] != '\0') {
       str[i + tamanho_str1] = str2[i];   
       i++;
   };
   
   str[i + tamanho_str1] = '\0';
   
   puts(str);
}

void separa_email(char email[], char usuario[], char endereco[]) {
   int i = 0,j;

    while(email[i] != '@') {
        usuario[i] = email[i];
        printf("%d x %i\n", i, i);
        i++;
    }
    usuario[i] = '\0';
   
   i++;
   j = 0;
   printf("Loop do Email\n");
   while(email[i] != '\0') {
       endereco[j] = email[i];
       printf("%d x %i\n", i, j);
       i++;j++;
   }
   endereco[j] = '\0';
   
   puts(usuario);
   printf("\n");
   puts(endereco);
};
