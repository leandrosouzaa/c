// O EDITOR NÃO RECONHECE PORÉM FUNCIONA NORMALMENTE
#include <sys/stat.h>

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

int cfileexists(const char* filename){
   struct stat buffer;
   int exist = stat(filename,&buffer);
   if(exist == 0)
      return 1;
   else // -1
      return 0;
}