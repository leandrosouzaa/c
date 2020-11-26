#include <stdio.h>
#include <string.h>
#include "strings.h"
#include <stdlib.h>

int cadastra_alunos(char alunos[256][100], int tl) {
   setbuf(stdin, NULL);
   char continua;
   do {
      system("clear");
      setbuf(stdin, NULL);
      printf("Informe o nome do aluno: ");
      readString(alunos[tl], 100);

      tl++;
      printf("Cadastrar mais alunos[S/N]: ");
      scanf(" %c", &continua);
   } while(tl < 256 && continua == 'S');

   return tl;
}

void mostra_alunos(char alunos[256][100], int tl) {
   system("clear");
   setbuf(stdin, NULL);
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();

      return;
   }

   int i;
   printf(" Nº | Nome do Aluno\n");
   printf("————+——————————————————————————————————————————————————\n");
   for(i=0; i < tl; i++) {
      printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
      printf("| ");
      puts(alunos[i]);
      printf("————+——————————————————————————————————————————————————\n");
   }
   getchar();
}

void mostra_alunos_letra(char alunos[256][100], int tl) {
   system("clear");
   setbuf(stdin, NULL);
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();

      return;
   }
   char letra;
   printf("Informe uma letra para buscar: ");
   scanf("%c", &letra);
   char teste[1];
   teste[0] = letra;
   system("clear");

   printf("ALUNOS COM A LETRA %c.\n\n", letra);

   int i;
   printf(" Nº | Nome do Aluno\n");
   printf("————+——————————————————————————————————————————————————\n");
   for(i=0; i < tl; i++) {
      if(strncasecmp(alunos[i],teste, 1) >= 0) {
         printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
         printf("| ");
         puts(alunos[i]);
         printf("————+——————————————————————————————————————————————————\n");

      }
   }
   getchar();
   getchar();

}


int main() {
   printf("Gerenciamento de Alunos - Leandro Ribeiro de Souza \n\n");

   char alunos[256][100], continua, letra;
   int opcao, tl = 0;

   do {
      system("clear");
      printf("SISTEMA DE GERENCIAMENTO DE ALUNOS - 1.0\n\n");
      
      printf("1 - Cadastrar Alunos.\n");
      printf("2 - Procurar Aluno.\n");
      printf("3 - Relação de Alunos.\n");
      printf("4 - Relação de Alunos por letra.\n");
      printf("5 - Relação de Alunos por sequência (inicio).\n");
      printf("6 - Relação de Alunos por sequeência (qualquer).\n");
      printf("7 - Encerrar Sistema.\n");
      printf("\nAlunos cadastrados: %d.\n", tl);

      printf("\nEscolha uma opção: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         // tl = cadastra_alunos(alunos, tl);]
         system("clear");
         setbuf(stdin, NULL);
         printf("Informe o nome do aluno: ");
         readString(alunos[tl], 100);
         tl++;
         break;
      case 2:
         break;
      case 3:
         mostra_alunos(alunos, tl);
         break;
      case 4:
         mostra_alunos_letra(alunos, tl);
         break;
      case 5:
         
         break;
      case 6:
         
         break;
      case 7:
         printf("Encerrando sistema...");
         break;
      default:
         break;
      }


   } while(opcao != 7);

   return 0;
}
