#include <stdio.h>

int readName(char nome[30]) {
   int logicalSize = 0;
   do {
      scanf("%c", &nome[logicalSize]);
   } while(logicalSize< 30 && nome[logicalSize++] != 10);
   if (logicalSize < 30 ) {
      logicalSize--;
   }
   return logicalSize;
}

int calculateWords(char name[30], int logicalSize) {
   int wordsQuantity = 0, i;
   for (i = 0; i < logicalSize; i++) {
      if ((name[i] != ' ' && name[i + 1] == ' ')) {
         wordsQuantity++;
      }
   }
   return wordsQuantity;
}

int calculateLetters(char name[30], int logicalSize) {
   int lettersQuantity = 0, i;
   for (i = 0; i < logicalSize; i++) {
      if (name[i] != ' ') {
         lettersQuantity++;
      }
   }
   return lettersQuantity;
}

void showName(char name[30], int logicalSize) {
   int i;
   for (i=0; i < logicalSize; i++) {
      printf("%c", name[i]);
   }
}

void showFirstName(char name[30], int logicalSize) {
   int i = 0;
   while (i < logicalSize && name[i] != ' ') {
      printf("%c", name[i]);
      i++;
   }

}

void generateReports(char name[30], int logicalSize,int lettersQuantity, int wordsQuantity) {
   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Palavras: %i.\n", lettersQuantity);
   printf("Quantidade de Espaços: %i.\n", wordsQuantity);
   printf("Nome completo: ");
   showName(name, logicalSize);
   printf("\nPrimeiro Nome: ");
   showFirstName(name, logicalSize);

}

int main() {
   printf("Nome Completo - Leandro Ribeiro de Souza \n\n");

   char name[30];
   int logicalSize, wordsQuantity = 1, lettersQuantity, i;

   printf("Informe um nome: ");
   logicalSize = readName(name);
   lettersQuantity = calculateLetters(name, logicalSize); 
   wordsQuantity = calculateWords(name, logicalSize);
   generateReports(name, logicalSize, lettersQuantity, wordsQuantity);
   return 0;
}
