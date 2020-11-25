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

char* copia_string(char str[], char str2[]) {
   int i;
   
   for(i=0; str[i]!='\0'; i++) {
      str2[i]=str[i];
   }

   return str;
}

void concatena_string(char str[], char str2[]) {
   int i;

   int tamanho_str1 = tamanho_string(str);
   for(i=0;str2[i]!='\0'; i++) {
      str[i + tamanho_str1] = str2[i];    
   };
}

void separa_email(char email[], char usuario[], char endereco[]) {
   int i,j;

   for(i=0; email[i]!='\0'; i++) {
      if(email[i] == '@') {
         for(j=i - 1; j >= 0; j--){
            usuario[j] = email[j];
         }
         usuario[i] = '\0';
         for(j=0; email[i+j+1] != '\0'; j++) {
            endereco[j] = email[i+j+1];
         }
         endereco[j] = '\0';
      }
   }
   puts(usuario);
   printf("\n");
   puts(endereco);
};

