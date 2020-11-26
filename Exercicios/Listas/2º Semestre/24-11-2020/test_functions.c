#include <stdio.h>
#include "strings.h"

int main() {
   printf("Teste de Strings - Leandro Ribeiro de Souza \n\n");

   char str[100] = "Leandro Ribeiro de Souza";
   char str2[100] = "";
   char email[100] = "leandro@gmail.com";
   char usuario[100]="0000000";
   char endereco[100]="00000";
   // printf("%d", tamanho_string(str));
   // incializa_string(&str2);

   // separa_email(email, usuario, endereco);
   // printf("%d", localiza_caracter(str, ' '));
   // pega_ultima_palavra(str, str2);
   // retorna_iniciais(str, str2);
   excluir_posicao(str, 1);
   puts(str);

   return 0;
}
