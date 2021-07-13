#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   printf("Criacao de Processos - Leandro Ribeiro de Souza \n\n");

   int quantidade, tempo, w;

   printf("Informe o numero de processos que deseja criar: ");
   scanf("%d", &quantidade);

   printf("Informe o tempo que deseja bloquear cada processo: ");
   scanf("%d", &tempo);

   for(int i = 0; i < quantidade; i++) {
      if(fork() == 0) {
         printf("[%d] - Processo numero %d iniciado.\n", getpid(), i+1);
         sleep(tempo);
         exit(0);
      }
   }

   w = wait(0);

   while(w != -1) {
      printf("[%d] - Processo finalizado.\n", w);
      w = wait(0);
   }

   printf("[%d] - Processo pai finalizado.\n", getpid());

   return 0;
}