#include <stdio.h>
#include "strings.h"

int main() {
   printf("Teste de Strings - Leandro Ribeiro de Souza \n\n");

   char str[] = "Testando";
   char str2[] = "12345";
   char email[] = "leandro@gmail.com";
   char usuario[]="0000000";
   char endereco[]="00000";
   // char usuario[]="\0";
   // char endereco[]="\0";

   // printf("%d", tamanho_string(str));
   // incializa_string(&str2);

   separa_email(email, usuario, endereco);

   return 0;
}
