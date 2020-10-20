#include <stdio.h>

int main() {
   printf("Menu - Leandro Ribeiro de Souza \n\n");

   float n1, n2, temperatura, media;
   int item, qtdPessoas = 0, qtdMulheres = 0, qtdOutros = 0, qtdHomens = 0, somaIdades = 0, idade;
   char sexo;

   do {
      printf("\nSELECIONE UMA OPÇÃO:\n");
      printf("1 - Soma de dois Números.\n");
      printf("2 - Conversão de Celsius para Farenheit.\n");
      printf("3 - Senso de Pessoas.\n");
      printf("4 - Encerrar Programa.\n");
      printf("Opção: ");
      scanf("%i", &item);
      
      switch (item)
      {
      case 1:
         printf("\nSOMA DE DOIS NÚMEROS\n");
         printf("Informe um número: ");
         scanf("%f", &n1);

         printf("Informe um número: ");
         scanf("%f", &n2);
         printf("Soma de %0.2f + %0.2f = %0.2f.\n", n1, n2, n1 + n2);
         break;
      
      case 2:
         printf("\nCONVERSÃO DE CELIUS PARA FARENHEIT\n");
         printf("Informe uma temperatura em °C: ");
         scanf("%f", &temperatura);
         
         if (temperatura > 40 || temperatura < 0) {
            printf("Temperatura Inválida...\n");
            printf("Voltando ao Menu...\n");
            break;
         }
         printf("%0.2f°C em farenheit é %0.2f\n", temperatura, temperatura * 1.8 + 32);
         break;

      case 3:
         printf("\nCONVERSÃO DE CELIUS PARA FARENHEIT\n");
         qtdPessoas = 0; qtdHomens = 0; qtdMulheres = 0; qtdOutros = 0; media = 0; somaIdades = 0;

         do {
            printf("\nCÓDIGO DA PESSOA: %i.\n", qtdPessoas + 1);
            printf("Idade da Pessoa: ");
            scanf("%i", &idade);
            printf("Sexo da Pessoa (M para Masculino e F para Feminino): ");
            scanf(" %c", &sexo);

            if (idade > 0 && idade < 100) {
               qtdPessoas++;
               somaIdades+= idade;
               if (sexo == 'F') {
                  qtdMulheres++;
               } else {
                  if (sexo == 'M') {
                     qtdHomens++;
                  } else {
                     qtdOutros++;
                  }
               }
            }
         } while (idade > 0 && idade < 100);

         media = somaIdades / qtdPessoas;

         printf("\nRELATÓRIO FINAL\n");
         printf("Total de pessoas: %i.\n", qtdPessoas);
         printf("Total de homens: %i.\n", qtdHomens);
         printf("Total de mulheres: %i.\n", qtdMulheres);
         printf("Total de outros: %i.\n", qtdOutros);
         printf("Idade média do Grupo: %0.2f.\n", media);
         printf("Total de mulheres: %i.\n", qtdMulheres);         
         break;
      
      case 4:
         printf("\nFinalizando Programa...\n");
         break;

      default:
         printf("\nEntrada inválida...\n");
         printf("Voltando para o Menu...\n");
         break;
      }
   } while (item != 4);

   return 0;
}
