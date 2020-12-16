#include "models.h"

int procura_prontuario(int prontuario,Aluno alunos[], int tl) {
   int i;

   for(i=0; i < tl; i++) {
      if(alunos[i].prontuario == prontuario)
         return i;
   }

   return -1;
}

int procura_tombo(int tombo, Livro livros[], int tl) {
   int i;

   for(i=0; i < tl; i++) {
      if(livros[i].tombo == tombo)
         return i;
   }

   return -1;
}
