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
        i++;
    }
    usuario[i] = '\0';
   
   i++;
   j = 0;
   while(email[i] != '\0') {
       endereco[j] = email[i];
       i++;j++;
   }
   endereco[j] = '\0';
   
   puts(usuario);
   printf("\n");
   puts(endereco);
};

int conta_palavras(char str[]) {
   int i = 0, quantidade_palavras = 0;
   
   while(str[i] != '\0') {
      if ((str[i] != ' ' && str[i + 1] == ' ')) {
         quantidade_palavras++;
      }
      i++;
   };

   return quantidade_palavras;
}

int conta_caracter(char str[]) {
   int i=0, quantidade_letras=0;

   while(str[i] != '\0') {
      if(str[i] != ' ')
         quantidade_letras++;
      i++;
   }

   return quantidade_letras;
}

int localiza_caracter(char str[], char caracter) {
   int i=0;
   while(str[i] != '\0') {
      if(str[i] == caracter)
         return i;
      i++;
   };

   return -1;
}

void pega_ultima_palavra(char str[], char str2[]) {
   int i=0, j=0;
   int ultimo_espaco = -1;

   while(str[i] != '\0') {
      if(str[i] == ' ')
         ultimo_espaco = i;
      i++;
   };

   if(ultimo_espaco != -1) {
      while (str[ultimo_espaco + j] != '\0') {
         str2[j] = str[ultimo_espaco + j];
         j++;
      }
   } else {
      j=0;
      while(str[j] != '\0') {
         str2[j] = str[j];
         j++;
      }
   }

   str[j] = '\0';

   printf("%s", str2);
}

void pega_primeira_palavra(char str[], char str2[]) {
   int i=0;
   int primeiro_espaco = localiza_caracter(str, ' ');

   while(str[i] != '\0' && (i < primeiro_espaco || primeiro_espaco == -1)) {
      str2[i] = str[i];
      i++;
   }
   str2[i] = '\0';

   puts(str2);
}

void retorna_iniciais(char str[], char str2[]) {
   int i = 1,j = 1;
   str2[0] = str[0];
   while(str[i] != '\0') {
      if ((str[i] != ' ' && str[i - 1] == ' ')) {
         str2[j] = str[i];
         j++;
      }
      i++;
   };
   

   puts(str2);
}

// Se não encontra retorna -1
void excluir_posicao(char str[], int index) {
   while (str[index] != '\0') {
      str[index] = str[index+1];
      index++;
   }
   str[index] = '\0';
}