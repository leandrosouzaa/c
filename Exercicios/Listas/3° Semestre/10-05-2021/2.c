#define TAMMAX 201

#include <stdio.h>
#include <string.h>

typedef struct sAluno {
   int prontuario;
   char nome[50];
} Aluno;

typedef struct sFila {
   Aluno alunos[TAMMAX];
   int inicio, fim;
} Fila;

void readString(char str[], int size) {
   fgets(str, size, stdin);
   int ultimaPosicao = strlen(str) - 1;
   if(str[ultimaPosicao] == '\n')
      str[ultimaPosicao] = '\0';
};

void inicializa(Fila *fila) {
   fila->fim = TAMMAX - 1;
   fila->inicio = TAMMAX - 1;
}

int vazia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

int cheia (Fila *f) {
   return f->fim == f->inicio ? 1 : 0;
}

void enfileirar(Fila *f, Aluno aluno) {
   if(f->fim == (TAMMAX - 1)) {
      f->fim = 0;
   } else {
      f->fim++;
   }
   if(cheia(f)) {
      printf("\nERRO: Fila cheia.\n");
      f->fim--;
      if(f->fim == -1) {
         f->fim = TAMMAX - 1;
      }
      return;
   }
   f->alunos[f->fim] = aluno;
}

Aluno desenfileirar(Fila *f) {
   Aluno aux;
   aux.prontuario = -1;
   
   if(!vazia(f)) {
      if(f->inicio == TAMMAX - 1) {
         f->inicio = 0;
      } else {
         f->inicio++;
      }
      aux = f->alunos[f->inicio];
   } else {
      printf("\nERRO: Fila Vazia.\n");
   }

   return aux;
}

void imprimir(Fila *f) {
   int i = (f->inicio + 1) % TAMMAX;
   int counter = 0;
   if(!vazia(f)) {
      while(i != ((f->fim + 1) % TAMMAX)) {
         printf("\nAluno na posição %d.\n", counter + 1);
         printf("Prontuario: PE%d.\n", f->alunos[i].prontuario);
         printf("Nome: %s.\n", f->alunos[i].nome);
         counter++;
         i = (i+1) % TAMMAX;
      }
   } else {
      printf("\nERRO: Fila Vazia.\n");
   }
}

void imprimirClassica(Fila *f) {
   int i = 0;
   Aluno temp[TAMMAX];
   if(!vazia(f)) {
      while(!vazia(f)) {
         temp[i] = desenfileirar(f);
         printf("\nAluno na posição %d.\n", i + 1);
         printf("Prontuario: PE%d.\n", temp[i].prontuario);
         printf("Nome: %s.\n", temp[i].nome);
         i++;
      }
      for(int j = 0; j < i; j++) {
         enfileirar(f, temp[j]);
      }
      
   } else {
      printf("\nERRO: Fila Vazia.\n");
   }
}

int main() {
   printf("Exercicio 2 - Leandro Ribeiro de Souza \n\n");

   int opcao;
   Fila fila;
   Aluno tempAluno;
   inicializa(&fila);

   do {
      printf("\nRefeitorio - Leandro Ribeiro de Souza \n\n");
      printf("1 - Cadastro de aluno na fila.\n");
      printf("2 - Remocao de Aluno.\n");
      printf("3 - Impressão (Não Classica).\n");
      printf("4 - Impressão (Classica).\n");
      printf("0 - Sair.\n");


      printf("\n\nEscolha um item: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
         printf("\nCadastro de Aluno:\n");
         printf("Prontuario: PE");
         scanf("%d", &tempAluno.prontuario);
         if(tempAluno.prontuario < 0) {
            printf("Prontuário invalido.");
            break;
         }
         printf("Nome: ");
         setbuf(stdin, NULL);
         readString(tempAluno.nome, 50);
         enfileirar(&fila, tempAluno);
         break;

      case 2:
         printf("\nAtendimento de Aluno:\n");
         printf("Aluno Atendido e removido da fila: \n");
         tempAluno = desenfileirar(&fila);
         if(tempAluno.prontuario != -1) {
            printf("Prontuário: PE%d.\n", tempAluno.prontuario);
            printf("Nome: %s.\n", tempAluno.nome);
         };
         break;

      case 3:
         printf("\nFila de alunos:\n");
         imprimir(&fila);
         break;

      case 4:
         printf("\nFila de Alunos:\n");
         imprimirClassica(&fila);
         break;

      default:
         break;
      }
   } while (opcao != 0);

   return 0;
}