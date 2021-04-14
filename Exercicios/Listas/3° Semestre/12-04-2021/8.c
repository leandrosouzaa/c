#define TAM 20
#include <stdio.h>

typedef struct sStack {
   char itens[TAM];
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

int push(STACK *S, char value) {
   if(isFull(S)) {
      printf("ERRO - A Pilha está cheia.\n");
      return 1;
   }

   S->itens[++S->topo] = value;

   return 0;
}

char pop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo--];
}

char stackTop(STACK *S) {
   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia.\n");
      return -1;
   }

   return S->itens[S->topo];
}

int reverse(STACK *S) {
   int i, temp[TAM], j = S->topo+1;
   

   if(isEmpty(S)) {
      printf("\nERRO - A Pilha está vazia\n");
      return 1;
   }

   for(i=0;i < j; i++) {
      temp[i] = pop(S);
   }

   for(i=0; i < j; i++) {
      push(S, temp[i]);
   }

   return 0;
}

void validate(STACK *S, int value) {
   STACK S2;
   init(&S2);

   if(value % 2 == 0) {
      int j = S->topo+1;
      int i = 0;
      while(i < j && (stackTop(S) % 2 == 1)) {
         push(&S2, pop(S));
         printf("%d\n", i);
         i++;
      }
      push(S, value);
      while(S2.topo != -1) {
         push(S, pop(&S2));
      }
   } else {
      push(S, value);
   }
};

void validate(STACK *S, int value) {
   STACK S2;
   init(&S2);

   if(value % 2 == 0) {
      int j = S->topo+1;
      int i = 0;
      while(i < j && (stackTop(S) % 2 == 1)) {
         push(&S2, pop(S));
         printf("%d\n", i);
         i++;
      }
      push(S, value);
      while(S2.topo != -1) {
         push(S, pop(&S2));
      }
   } else {
      push(S, value);
   }
};


int main() {
   printf("Pilha - Leandro Ribeiro de Souza \n\n");

   STACK S;
   init(&S);

   int opcao, temp;

   do {
      printf("1 - Inserir item na pilha.\n");
      printf("2 - Remover item da pilha.\n");
      printf("3 - Inserir item na pilha com validação.\n");
      printf("4 - Trocar extremos da pilha.\n");
      printf("5 - Inverter Pilha.\n");
      printf("0 - Encerrar execução.\n");

      printf("\nInforme a opção desejada: ");
      scanf("%d", &opcao);

      switch(opcao) {
         case 1:
            printf("\nDigite um valor para inserir na pilha: ");
            scanf("%d", &temp);
            push(&S, temp);
            break;

         case 2:
            printf("\nValor excluido da pilha: %d.\n", pop(&S));
      
         case 3:
            printf("\nDigite um valor para inserir na pilha: ");
            scanf("%d", &temp);
            validate(&S, temp);
            break;

         case 4:
            printf("\nInvertendo extremos da Pilha...");
            reverseExtremes(&S);
            printf("\nOperacao concluida.");
            break;

         case 5:
            printf("\nInvertendo Pilha...");
            reverse(&S);
            printf("\nOperacao concluida.");
            break;

         case 0:
            printf("\nEncerrando o sistema...");

      }
   } while(1);
   return 0;
}