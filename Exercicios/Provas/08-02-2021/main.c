#include "imports.h"

int main() {
   printf("Sistemas\n\n");

   Aluno aluno = create_aluno();

   printf("%d", aluno.prontuario);

   return 0;
}