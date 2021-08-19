#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   int i, processos[5], pid;
   
   for(int i = 0; i < 5; i++) {
      pid = fork();
      if(pid == 0) {
         while(1);
      } else {
         processos[i] = pid;
      }
   }
   i = 0;
   while(i < 5) {
      sleep(10);
      
      kill(processos[i], 9);
      i++;
      printf("processo com pid %d foi morto\n", processos[i]);
   }  

   printf("todos os filhos morreram");

   return 0;
}