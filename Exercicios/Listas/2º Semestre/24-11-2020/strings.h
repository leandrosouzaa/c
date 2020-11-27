int tamanho_string(char str[]) {
   int i = 0;
   
   while(str[i] != '\0') {
      i++;
   } 

   return i;
};

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = tamanho_string(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
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
      if ((str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))) {
         quantidade_palavras++;
      }
      i++;
   };

   return quantidade_palavras;
}

int conta_caracter(char str[], char caracter) {
   int i=0, quantidade_caracters=0;

   while(str[i] != '\0') {
      if(str[i] != caracter)
         quantidade_caracters++;
      i++;
   }

   return quantidade_caracters;
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
      ultimo_espaco++;
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

   str2[j] = '\0';
}

void pega_primeira_palavra(char str[], char str2[]) {
   int i=0;
   int primeiro_espaco = localiza_caracter(str, ' ');

   while(str[i] != '\0' && (i < primeiro_espaco || primeiro_espaco == -1)) {
      str2[i] = str[i];
      i++;
   }
   str2[i] = '\0';
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

   str2[j] = '\0';
}

// Se não encontra retorna -1
void excluir_posicao(char str[], int index) {
   // puts(str);
   while (str[index] != '\0') {
      str[index] = str[index+1];
      index++;
   }
   str[index] = '\0';
}
