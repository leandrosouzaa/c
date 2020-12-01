#include <stdio.h>
#include <string.h>
#include "strings.h"
#include <stdlib.h>

int menu(int tl) {
   int opcao;

   setbuf(stdin, NULL);
   system("clear");
   printf("SISTEMA DE GERENCIAMENTO DE ALUNOS - 1.0\n\n");
   
   printf("1 - Cadastrar Alunos.\n");
   printf("2 - Procurar Aluno.\n");
   printf("3 - Relação de Alunos.\n");
   printf("4 - Relação de Alunos por letra.\n");
   printf("5 - Relação de Alunos por sequência (inicio).\n");
   printf("6 - Relação de Alunos por sequência (qualquer).\n");
   printf("7 - Encerrar Sistema.\n");
   printf("\nAlunos cadastrados: %d.\n", tl);

   printf("\nEscolha uma opção: ");
   scanf("%d", &opcao);

   return opcao;
}

void cadastra_aluno(char alunos[256][100], int *tl) {
   system("clear");
   setbuf(stdin, NULL);
   if(*tl > 255) {
      printf("Número máximo de alunos atingidos. Pressione Enter para continuar.");
      getchar();
   } else {
      printf("Informe o nome do aluno: ");
      readString(alunos[*tl], 100);
      *tl+=1;
   }
}

void mostra_alunos(char alunos[256][100], int tl) {
   system("clear");
   setbuf(stdin, NULL);
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
   } else {
      int i;
      printf(" Nº | Nome do Aluno\n");
      printf("————+——————————————————————————————————————————————————\n");
      for(i=0; i < tl; i++) {
         printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
         printf("| ");
         puts(alunos[i]);
         printf("————+——————————————————————————————————————————————————\n");
      }
   }
   getchar();
}

void procura_alunos_letra(char alunos[256][100], int tl) {
   setbuf(stdin, NULL);
   system("clear");
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();
   } else {
      char letra[1];
      printf("Informe uma letra para buscar: ");
      scanf(" %c", &letra[0]);
      system("clear");

      printf("ALUNOS COM A LETRA %s.\n\n", letra);

      int i;
      printf(" Nº | Nome do Aluno\n");
      printf("————+——————————————————————————————————————————————————\n");
      for(i=0; i < tl; i++) {
         if(strncasecmp(alunos[i],letra, 1) == 0) {
            printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
            printf("| ");
            puts(alunos[i]);
            printf("————+——————————————————————————————————————————————————\n");
         }
      }
      // não adiantou limpar o buffer.
      // setbuf(stdin, NULL);

      getchar();
      getchar();
   }
}

void mostra_alunos_sequencia(char alunos[256][100], int tl) {
   setbuf(stdin, NULL);
   system("clear");
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();
   } else {
      char sequencia[30];

      printf("Digite uma sequência de até 30 caracters: ");
      readString(sequencia, 30);
      int tamanho_sequencia = strlen(sequencia);
      system("clear");

      printf("ALUNOS COM A SEQUÊNCIA: ");
      puts(sequencia);

      int i;
      printf("\n Nº | Nome do Aluno\n");
      printf("————+——————————————————————————————————————————————————\n");
      for(i=0; i < tl; i++) {
         if(strncasecmp(alunos[i],sequencia, tamanho_sequencia) == 0) {
            printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
            printf("| ");
            puts(alunos[i]);
            printf("————+——————————————————————————————————————————————————\n");
         }
      }
      getchar();
   }
}

void mostra_alunos_sequencia_str(char alunos[256][100], int tl) {
   setbuf(stdin, NULL);
   system("clear");
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();
   } else {
      char sequencia[30];

      printf("Digite uma sequência de até 30 caracters: ");
      readString(sequencia, 30);
      int tamanho_sequencia = strlen(sequencia);
      system("clear");

      printf("ALUNOS COM A SEQUÊNCIA: ");
      puts(sequencia);

      int i;
      printf("\n Nº | Nome do Aluno\n");
      printf("————+——————————————————————————————————————————————————\n");
      for(i=0; i < tl; i++) {
         if(strstr(alunos[i],sequencia)) {
            printf("%s%s%d ", i < 99 ? "0" : "", i < 9 ? "0" : "",i + 1);
            printf("| ");
            puts(alunos[i]);
            printf("————+——————————————————————————————————————————————————\n");
         }
      }
      getchar();
   }
}

void procura_aluno_nome(char alunos[256][100], int tl) {
   setbuf(stdin, NULL);
   system("clear");
   
   if(tl == 0) {
      printf("O sistema não possui alunos cadastrado. Pressione Enter para Continuar.");
      getchar();
   } else {
      char nome[30];
      int index = -1, i;

      printf("Digite o nome do aluno: ");
      readString(nome, 100);
      int tamanho_nome = strlen(nome);
      system("clear");

      printf("NOME DO ALUNO: ");
      puts(nome);

      for(i=0; i < tl; i++) {
         if(strncasecmp(alunos[i],nome, tamanho_nome) == 0) {
            printf("Código do Aluno: %d.\n", i + 1);
            index = i;
         }
      }
      if(index== -1)
         printf("Nenhum Aluno enontrado. Escolha outro nome.");

      getchar();
   }
}

int main() {
   printf("Gerenciamento de Alunos - Leandro Ribeiro de Souza \n\n");

   char alunos[256][100];
   int opcao, tl = 0;

   do {
      opcao = menu(tl);
      switch (opcao) {
         case 1:
            cadastra_aluno(alunos, &tl);
            break;
         case 2:
            procura_aluno_nome(alunos, tl);
            break;
         case 3:
            mostra_alunos(alunos, tl);
            break;
         case 4:
            procura_alunos_letra(alunos, tl);
            break;
         case 5:
            mostra_alunos_sequencia(alunos, tl);
            break;
         case 6:
            mostra_alunos_sequencia_str(alunos, tl);
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
