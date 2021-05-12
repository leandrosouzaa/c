#define TAM 30

#include <stdio.h>
#include <string.h>

typedef struct sPessoa {
   char nome[50];
   int idade;
   char sexo;
} Pessoa;

typedef struct sStack {
   Pessoa pessoas[TAM];
   int topo;
} STACK;

void init(STACK *S) {
   S->topo = -1;
}

int isEmpty(STACK *S) {
   return S->topo == -1 ? 1 : 0;
}

int isFull(STACK *S) {
   return S->topo+1 == TAM ? 1 : 0;
}

int push(STACK *S, Pessoa pessoa) {
   if(isFull(S)) {
      printf("ERRO - A Pilha está cheia.\n");
      return 1;
   }

   S->pessoas[++S->topo] = pessoa;
   return 0;
}

Pessoa pop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      Pessoa p;
      p.idade = -1;
      return p;
   }

   return S->pessoas[S->topo--];
}

Pessoa stackTop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      Pessoa p;
      p.idade = -1;
      return p;
   }

   return S->pessoas[S->topo];
}

void printStack(STACK *s) {
   Pessoa temp[TAM]; 
   int i = 0;
   if(isEmpty(s)) {
      printf("\nERRO - A Pilha está vazia.\n");
   }

   while(!isEmpty(s)) {
      temp[i] = pop(s);
      printf("\nNome: %s.\n", temp[i].nome);
      printf("Idade: %d.\n", temp[i].idade);
      printf("Sexo: ");
      if(temp[i].sexo == 'F') {
         printf("Feminino.\n");
      } else {
         printf("Masculino.\n");
      }
      i++;
   }

   for(int j = i-1; j > -1; j--) {
      push(s, temp[j]);
   }
};

void filter(STACK *P, STACK *PM, STACK *PF) {
   Pessoa temp[TAM]; 
   int i = 0;

   while(!isEmpty(P)) {
      temp[i] = pop(P);
      if(temp[i].sexo == 'M') {
         push(PM, temp[i]);
      } else {
         if(temp[i].sexo == 'F') {
            push(PF, temp[i]);
         }
      }
      i++;
   }

   for(int j = i-1; j > -1; j--) {
      push(P, temp[j]);
   }
}

Pessoa criaPessoa(int idade, const char* nome, char sexo) {
   Pessoa p;
   p.idade = idade;
   p.sexo = sexo;
   strcpy(p.nome, nome);

   return p;
};

int main() {
   printf("Cadastro de Pessoas - Leandro Ribeiro de Souza \n\n");

   STACK P, PM, PF;
   init(&P);
   init(&PM);
   init(&PF);

   push(&P, criaPessoa(18, "Leandro", 'M'));
   push(&P, criaPessoa(94, "Osmar", 'M'));
   push(&P, criaPessoa(23, "Andreia", 'F'));
   push(&P, criaPessoa(56, "Josefina", 'F'));
   push(&P, criaPessoa(10, "Cleiton Rasta", 'M'));
   push(&P, criaPessoa(18, "Jose", 'M'));
   push(&P, criaPessoa(18, "Claudia", 'F'));
   push(&P, criaPessoa(18, "Ferreira", 'F'));

   filter(&P, &PM, &PF);

   printf("\n\nPilha Normal: \n");
   printStack(&P);

   printf("\n\nPilha Masculina: \n");
   printStack(&PM);

   printf("\n\nPilha Feminina: \n");
   printStack(&PF);

   return 0;
}