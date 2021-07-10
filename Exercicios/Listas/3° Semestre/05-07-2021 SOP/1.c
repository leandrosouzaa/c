#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   printf("Criacao de Processos - Leandro Ribeiro de Souza \n\n");

   int quantidade, tempo;

   printf("Informe o numero de processos que deseja criar: ");
   scanf("%d", &quantidade);

   printf("Informe o tempo que deseja bloquear cada processo: ");
   scanf("%d", &tempo);

   for(int i = 0; i < quantidade; i++) {
      if(fork() == 0) {
         printf("[%d] - Processo numero %d iniciado.\n", getpid(), i+1);
         sleep(tempo);
         printf("[%d] - Processo numero %d finalizado.\n", getpid(), i+1);
         exit(0);
      }
   }

   wait(0);

   printf("\nTodos processos finalizados.\n");

   return 0;
}