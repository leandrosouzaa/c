#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   printf("Criacao de Processos - Leandro Ribeiro de Souza \n\n");

   int quantidade;

   printf("Informe o numero de processos que deseja criar: ");
   scanf("%d", &quantidade);

   for(int i = 0; i < quantidade; i++) {
      if(fork() == 0) {
         printf("[%d] - Processo numero %d.\n", getpid(), i+1);
         exit(0);
      }
   }

   while(wait(0) != -1) {

   }
   printf("\nTodos processos finalizados.\n");

   return 0;
}