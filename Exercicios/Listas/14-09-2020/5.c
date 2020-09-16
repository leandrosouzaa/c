#include <stdio.h>

int main() {
   printf("Entrada do Show - Leandro Ribeiro de Souza \n\n");

   int idade, qtdMenores = 0, qtdIdosos = 0, qtdOutros = 0;

   do {
      printf("\nDigite 0 para Sair.\n");
      printf("Informe a idade da pessoa: ");
      scanf("%i", &idade);

      if ( idade > 0 && idade < 18) {
         qtdMenores++;
      } else {
         if (idade > 60){
            qtdIdosos++;
         } else {
            if (idade >= 18 && idade <= 60) {
               qtdOutros++;
            }
         }
      }
   } while (idade > 0);

   printf("RELATÓRIO FINAL\n");
   printf("Pessoas com menos de 18 anos: %i.\n", qtdMenores);
   printf("Pessoas com mais de 60 anos: %i.\n", qtdIdosos);
   printf("Pessoas entre 18 anos e 60 anos: %i.\n", qtdOutros);

   return 0;
}
