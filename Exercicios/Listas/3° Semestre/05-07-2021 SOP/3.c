#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
   int i=2, j=1;
   printf("\nPID: %d\n",getpid());
   fork();
   j=wait(0);
   if(j==-1)
      i++;
   else
      i--;
   printf("PID: %d - Valor de i %d\n",getpid(),i);
   fork();
   j=wait(0);
   if(j==-1)
      i++; 
   else
      i--;
   printf("PID: %d - Valor de i %d\n",getpid(),i);
}