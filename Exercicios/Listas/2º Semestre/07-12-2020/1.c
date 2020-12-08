#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nome[50];
   float nota1, nota2, frequencia;
} Disciplina;

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

void preenche_tabela(Disciplina disciplinas[]) {
   strcpy(disciplinas[0].nome, "Matematica");
   disciplinas[0].frequencia=100;
   disciplinas[0].nota1 = 4;
   disciplinas[0].nota2 = 4;

   strcpy(disciplinas[1].nome, "Portugues");
   disciplinas[1].frequencia=70;
   disciplinas[1].nota1 = 8;
   disciplinas[1].nota2 = 8;

   strcpy(disciplinas[2].nome, "Historia");
   disciplinas[2].frequencia=60;
   disciplinas[2].nota1 = 4;
   disciplinas[2].nota2 = 3;

   strcpy(disciplinas[3].nome, "Geografia");
   disciplinas[3].frequencia=80;
   disciplinas[3].nota1 = 7;
   disciplinas[3].nota2 = 8;

}

int menu(int tl) {
   int opcao;
 
   setbuf(stdin, NULL);
   system("clear");
   printf("GESTÃO DE BOLETINS - 1.0\n\n");
   printf("1 - Incluir Disciplinas.\n");
   printf("2 - Apresentar Relatório.\n");
   printf("3 - Localizar disciplina.\n");
   printf("4 - Apresentar disciplina com menor nota.\n");
   printf("5 - Apresentar disciplina com maior nota.\n");
   printf("6 - Apresentar disciplina com aprovação.\n");
   printf("7 - Encerrar Sistema.\n");
   printf("\nDisciplinas Cadastradas: %d.\n", tl);

   printf("\nEscolha uma opção: ");
   scanf("%d", &opcao);
   
   return opcao;
}

float calcula_media(Disciplina disciplina) {
   return (disciplina.nota1 + disciplina.nota2)/2;
}

void cadastra_disciplina(Disciplina *disciplina,int *tl) {
   system("clear");
   setbuf(stdin, NULL);
   if (*tl>9) {
      printf("Quantidade máxima de disciplinas atingida. Reinicie o sistema e tente novamente.\n");
      getchar();
   } else {
      printf("CADASTRO DE DISCIPLINA.\n\n");
      printf("Informe o nome da disciplina: ");
      readString(disciplina->nome, 50);
      printf("Informe a primeira nota: ");
      scanf("%f", &disciplina->nota1);
      printf("Informe a segunda nota: ");
      scanf("%f", &disciplina->nota2);
      printf("Informe a frequencia na disciplina: ");
      scanf("%f", &disciplina->frequencia);
      *tl+=1;
      printf("DISCIPLINA CADASTRADA COM SUCESSO.");
   }
}

void apresenta_disciplina(Disciplina disciplina) {
   printf("Disciplina: ");
   puts(disciplina.nome);
   printf("Nota 1: %0.2f\n", disciplina.nota1);
   printf("Nota 2: %0.2f\n", disciplina.nota2);
   printf("Frequência: %0.2f%%.\n", disciplina.frequencia);
}

void gera_relatorio(Disciplina disciplinas[10], int tl) {
   system("clear");  
   setbuf(stdin, NULL);
   if(tl == 0) {
      printf("Nenhuma disciplina cadastrada. Pressione enter para retornar.");
   } else {
      printf("RELATÓRIO DE DISCIPLINAS: \n");

      float media, mediaGlobal = 0;
      int i;

      for(i=0; i < tl; i++) {
         printf("\n");
         apresenta_disciplina(disciplinas[i]);

         media = calcula_media(disciplinas[i]);
         printf("Media: %0.2f.\n", media);
         mediaGlobal+=media;

         if(media >= 6 && disciplinas[i].frequencia >= 75) {
            printf("\nSituação: APROVADO.\n");
         } else {
            printf("\nSituação: REPROVADO.\n");
            printf("Retido por %s%s%s.\n", disciplinas[i].frequencia < 75 ? "Faltas" : "", media < 6 && disciplinas[i].frequencia < 75 ? " e " : "", media < 6 ? "Nota" : "");
         }
         printf("-------------------------------------");
      }
      mediaGlobal= mediaGlobal / tl;

      printf("\nMedia Global do Aluno: %0.2f.\n", mediaGlobal);
   }
   getchar();
}

void localiza_disciplina(Disciplina disciplinas[10], int tl) {
   system("clear");
   setbuf(stdin, NULL);

   if(tl==0) {
      printf("Nenhuma disciplina cadastrada. Pressione enter para retornar.");
   } else {
      char busca[50];
      int i;

      printf("Nome da disciplina desejada: ");
      readString(busca, 50);

      system("clear");

      printf("Disciplinas com a sequencia:");
      puts(busca);
      printf("\n");
      for(i=0; i < tl; i++) {
         if(strstr(disciplinas[i].nome, busca)) {
            apresenta_disciplina(disciplinas[i]);
            printf("-------------------------------------");
            printf("\n");
         };
      }
   }
   getchar();
}

void procura_maior(Disciplina disciplinas[10], int tl) {
   system("clear");  
   setbuf(stdin, NULL);

   if(tl == 0) {
      printf("Nenhuma disciplina cadastrada. Pressione enter para retornar.");
   } else {
      int i, index = 0;
   
      float media;
      float mediaMaior = calcula_media(disciplinas[0]);

      for(i=1; i < tl; i++) {
         media = calcula_media(disciplinas[i]);
         if(media > mediaMaior) {
            index = i;
            mediaMaior = media;
         }
      }

      apresenta_disciplina(disciplinas[index]);
      printf("Media: %0.2f.\n", mediaMaior);
   }
   getchar();
}

void procura_menor(Disciplina disciplinas[10], int tl) {
   system("clear");  
   setbuf(stdin, NULL);
   
   if(tl == 0) {
      printf("Nenhuma disciplina cadastrada. Pressione enter para retornar.");
   } else {
      int i, index = 0;
   
      float media;
      float mediaMenor = calcula_media(disciplinas[0]);

      for(i=1; i < tl; i++) {
         media = calcula_media(disciplinas[i]);
         if(media < mediaMenor) {
            index = i;
            mediaMenor = media;
         }
      }

      apresenta_disciplina(disciplinas[index]);
      printf("Media: %0.2f.\n", mediaMenor);
   }
   getchar();
}

void apresenta_aprovadas(Disciplina disciplinas[10], int tl) {
   system("clear");  
   setbuf(stdin, NULL);
   if(tl == 0) {
      printf("Nenhuma disciplina cadastrada. Pressione enter para retornar.");
   } else {
      float media;
      int i;

      printf("RELATÓRIO DE DISCIPLINAS: \n");
      for(i=0; i < tl; i++) {
         media = calcula_media(disciplinas[i]);

         if(media >= 6 && disciplinas[i].frequencia >= 75) {
            printf("\n");
            apresenta_disciplina(disciplinas[i]);

            printf("Media: %0.2f.\n", media);

            printf("-------------------------------------");
         }
      }
   }
   getchar();
}

int main() {
   printf("Boletim Escolar - Leandro Ribeiro de Souza \n\n");
   int opcao, tl = 4;
   Disciplina disciplinas[10];
   preenche_tabela(disciplinas);

   do {
      opcao = menu(tl);

      switch (opcao) {
         case 1: 
            cadastra_disciplina(&disciplinas[tl], &tl);
            break;
         case 2:
            gera_relatorio(disciplinas, tl);
            break;
         case 3:
            localiza_disciplina(disciplinas, tl);
            break;
         case 4:
            procura_menor(disciplinas, tl);
            break;
         case 5:
            procura_maior(disciplinas, tl);
            break;
         case 6:
            apresenta_aprovadas(disciplinas, tl);
            break;
         case 7:
            printf("Encerrando sistema...\n");
            break;
         default:
            break;
      };
   } while(opcao != 7);

   return 0;
}
