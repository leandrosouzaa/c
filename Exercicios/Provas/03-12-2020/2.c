#include <stdio.h>
#include <string.h>
// Função para leitura já que o FGETS lê o \n.
// Conversei com o senhor pelo discord.
void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

void concatena(char str[140], char tipo[12], char logradouro[50], char numero[15], char bairro[30], char cidade[30], char estado[3]) {
   strcat(str,tipo);
   strcat(str, ": ");
   strcat(str, logradouro);
   strcat(str, ", ");
   strcat(str, numero);
   strcat(str," - ");
   strcat(str, bairro);
   strcat(str, " - ");
   strcat(str,cidade);
   strcat(str,", ");
   if(strcasecmp(estado, "SP") == 0) {
      strcat(str, "São Paulo");
   } else {
      if(strcasecmp(estado, "MG") == 0) {
         strcat(str, "Minas Gerais");
      } else {
         if(strcasecmp(estado, "MS") == 0) {
            strcat(str, "Mato Grosso do Sul");
         } else {
            strcat(str, estado);
         }
      }
   }

   strcat(str, ".");
}


int main() {
   printf("Formatando Endereço - Leandro Ribeiro de Souza \n\n");

   char tipo[12]; char logradouro[50]; char numero[15]; char bairro[30]; char cidade[30]; char estado[3];
   char endereco[140];

   printf("Informe o tipo de Logradouro: ");
   readString(tipo, 12);

   printf("\nInforme o nome do Logradouro: ");
   readString(logradouro, 50);

   printf("\nInforme o Numero da casa: ");
   readString(numero, 15);

   printf("\nInforme o Bairro: ");
   readString(bairro, 30);

   printf("\nInforme a Cidade: ");
   readString(cidade, 30);
      
   printf("\nInforme o Estado (sigla): ");
   readString(estado, 3);

   concatena(endereco, tipo, logradouro, numero, bairro, cidade, estado);

   printf("Endereço mascárado: \n");
   puts(endereco);

   return 0;
}
