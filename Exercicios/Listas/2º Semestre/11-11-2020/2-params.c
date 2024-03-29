#include <stdio.h>

int readAndCalculate(int array[10]) {
   int i,j, abonos = 0;
   char situacao;

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
               array[j]++;
               abonos++;
               break;
            case 'P':
               printf("Situação: Presente");
               array[j]++;
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

   return abonos;
}

void generateReports(int vetor[10], int abonos) {
   int i,presenca, qtdAprovados = 0;
   printf("\n\nRELATÓRIO INDIVIDUAL");
   for(i=0;i<10;i++) {
      printf("\n\nALUNO %d\n", i + 1);
      presenca = (vetor[i]*(100/20));
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
   printf("Quantidade de REPROVADOS: %d.\n", 10 - qtdAprovados);
   printf("Faltas ABONADAS: %d.\n", abonos);
}

int main() {
   int alunos[10] = {0}, qtdAbonos;

   printf("Controle de Frequência - Leandro Ribeiro de Souza");

   qtdAbonos = readAndCalculate(alunos);
   generateReports(alunos, qtdAbonos);
}
