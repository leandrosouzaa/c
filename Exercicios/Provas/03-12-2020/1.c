#include <stdio.h>

int tamanho_string(char str[]) {
   int i = 0;
   
   while(str[i] != '\0') {
      i++;
   } 

   return i;
};

// Função para leitura já que o FGETS lê o \n.
// Conversei com o senhor pelo discord.
void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = tamanho_string(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

void trocar_caracter(char str[], char a, char b) {
   int i = 0;
   while (str[i] != '\0') {
      if(str[i] == a)
         str[i] = b;
      i++;
   }
   
};

void trocar_strings(char str[], char str2[]) {
   int i = 0;
   char temp[tamanho_string(str)];
   while (str[i] != '\0') {
      temp[i] = str[i];
      i++;
   }

   i=0;
   while (str2[i] != '\0') {
      str[i] = str2[i];
      i++;
   }
   str[i] = '\0';

   i=0;
   while (temp[i] != '\0') {
      str2[i] = temp[i];
      i++;
   }
   str2[i] = '\0';
}

void inverter_string(char str[]) {
   int i = 0;
   int tamanho = tamanho_string(str);
   char temp[tamanho];
   tamanho--;
   while (str[i] != '\0') {
      temp[i] = str[tamanho - i];
      i++;
   }
   i = 0;
   while (temp[i] != '\0') {
      str[i] = temp[i];
      i++;
   }
   
}


int main() {
   printf("Manipulação de String - Leandro Ribeiro de Souza \n\n");

   char str[100], str2[100], a,b;

   printf("Informe uma string: ");
   readString(str, 100);

   printf("Informe um caracter para ser substituido: ");
   scanf(" %c", &a);

   printf("Informe outro caracter para ser utilizado no lugar de %c: ", a);
   scanf(" %c", &b);

   trocar_caracter(str,a,b);

   printf("\nString com os caracters trocados: ");
   puts(str);

   setbuf(stdin, NULL);
   printf("\nInforme uma segunda string: ");
   readString(str2, 100);
   trocar_strings(str, str2);

   printf("\nNovo valor da primeira string: ");
   puts(str);

   printf("Novo valor da Segunda string: ");
   puts(str2);

   printf("\nInvertendo a string: ");
   puts(str);

   inverter_string(str);

   printf("String invertida: ");
   puts(str);

   return 0;
}
