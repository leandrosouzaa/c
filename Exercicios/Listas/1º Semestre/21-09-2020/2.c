#include <stdio.h>

int main() {
   printf("Frases - Leandro Ribeiro de Souza \n\n");

   int tl = 0, i, qtdA = 0;
   char frase[20], letra;

   printf("Informe uma frase de até 20 caracteres: ");

   do {
      scanf("%c", &frase[tl]);
      if ((frase[tl] == 'A' || frase[tl] == 'a')  && (tl < 20 )) {
         qtdA++;
      }
   } while(tl< 20 && frase[tl++] != 10);
   if (tl < 20 ) {
      tl--;
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Frase informada: ");
   for(i=0;i<tl;i++) {
      printf("%c", frase[i]);
   }
   printf("\nTotal de Letras \"A\" na frase: %i", qtdA);
   printf("\nFrase invertida: ");
      for(i=tl - 1;i >= 0;i--) {
         printf("%c", frase[i]);
   }
   return 0;
}
