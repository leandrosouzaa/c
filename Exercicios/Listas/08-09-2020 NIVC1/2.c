#include <stdio.h>

int main() {
   printf("Pessoas - Leandro Ribeiro de Souza \n\n");

   char sexo;
   int idade = 0, soma = 0, qtdPessoas = 0, qtdHomens = 0, qtdHomensAcima60 = 0, qtdMulheres = 0, qtdMlheresAte20 = 0, qtdPessoasEntre30e60 = 0, qtdOutros = 0;
   float media;
   while (idade >= 0 && idade < 100) {
      printf("\n\nInforme o sexo da pessoa (M ou F): ");
      scanf(" %c", &sexo);

      printf("Informe idade da pessoa: ");
      scanf("%i", &idade);

      if (idade >= 0 && idade < 100) {
         qtdPessoas++;
         soma = soma + idade;
         if (sexo == 'M') {
            qtdHomens++;
            if (idade > 60) {
               qtdHomensAcima60++;
            }
         } else {
            if (sexo == 'F') {
               qtdMulheres++;
               if (idade <= 20) {
                  qtdMlheresAte20++;
               }
            } else {
               if (sexo != 'F' && sexo != 'M') {
                  qtdOutros++;
               } 
            }
         }
         if (idade > 30 && idade <= 60) {
            qtdPessoasEntre30e60++;
         }
      }

   }

   media = soma / qtdPessoas;

   printf("\nRELATÓRIO FINAL\n");
   printf("Total de pessoas: %i.\n", qtdPessoas);
   printf("Total de homens: %i.\n", qtdHomens);
   printf("Total de mulheres: %i.\n", qtdMulheres);
   printf("Total de Pessoas com outro sexo: %i.\n", qtdOutros);
   printf("Total de homens acima de 60 anos: %i.\n", qtdHomensAcima60);
   printf("Total de mulheres até 20 anos: %i.\n", qtdMlheresAte20);
   printf("Total de pessoas entre 30 e 60 anos: %i.\n", qtdPessoasEntre30e60);
   printf("Média das idades informadas: %f.", media);

   return 0;
}
