#include <stdio.h>

int main() {
   int alunos[10] = {0,0,0,0,0,0,0,0,0,0}, i, j, presenca, qtdAprovados = 0, qtdReprovados = 0, qtdAbonos = 0; 
   char situacao;

   printf("Controle de Frequência - Leandro Ribeiro de Souza");

   for(i=0;i<20;i++) {
      for (j=0;j<10;j++) {
         printf("\n\nCHAMADA DA AULA %d\n", i+1);
         printf("Situação do Aluno %d: ", j + 1);
         scanf(" %c", &situacao);
         // Validação de Entrada
         if (!(situacao == 'F' || situacao == 'A' || situacao == 'P')) {
            printf("Entrada inválida, informe novamente.\n");
            j--;
         }
         switch(situacao) {
            case 'A':
               printf("Situação: Falta (Abonada)");
               alunos[j]++;
               qtdAbonos++;
               break;
            case 'P':
               printf("Situação: Presente");
               alunos[j]++;
               break;
            case 'F':
               printf("Situação: Falta");
               break;
            default:
               // não precisa validar pois já validou em cima
               break;
         }
      }
   }

   printf("\n\nRELATÓRIO INDIVIDUAL");
   for(i=0;i<10;i++) {
      printf("\n\nALUNO %d\n", i + 1);
      presenca = alunos[i] * 5;
      printf("Percentual de presença: %d%%.\n", presenca);
      if (presenca >= 75) {
         printf("SITUAÇÃO FINAL: APROVADO");
         qtdAprovados++;
      } else {
         printf("SITUAÇÃO FINAL: REPROVADO");
      }
   }

   printf("\n\nRELATÓRIO FINAL\n");
   printf("Quantidade de APROVADOS: %d.\n", qtdAprovados);
   printf("Quantidade de REPROVADOS: %d.\n", 20 - qtdAprovados);
   printf("Faltas ABONADAS: %d.\n", qtdAbonos);

   return 0;
}
