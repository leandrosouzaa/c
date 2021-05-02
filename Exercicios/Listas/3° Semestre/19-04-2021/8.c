#include <stdio.h>
#include <string.h>

#define TAMMAX 41

typedef struct sPassageiro {
   char nome[50];
   int idade;
} PASSAGEIRO;

typedef struct sOnibus {
   PASSAGEIRO passageiros[TAMMAX];
   int inicio, fim;
} ONIBUS;

void inicia(ONIBUS *onibus) {
   onibus->inicio = TAMMAX-1;
   onibus->fim = TAMMAX-1;
};

int vazia (ONIBUS *onibus) {
   return onibus->fim == onibus->inicio ? 1 : 0;
}

int cheia (ONIBUS *onibus) {
   return onibus->fim == onibus->inicio ? 1 : 0;
}

void entradaFrente(ONIBUS *onibus, PASSAGEIRO p) {
   if(onibus->inicio == 0) {
      onibus->inicio = TAMMAX - 1;
   } else {
      onibus->inicio--;
   }

   if(cheia(onibus)) {
      printf("\nERRO: Onibus lotado.\n");
      onibus->inicio = (onibus->inicio+1) % TAMMAX;
      return;
   }

   onibus->passageiros[(onibus->inicio+1) % TAMMAX] = p;
};

void entradaTras(ONIBUS *onibus, PASSAGEIRO p) {
   if(onibus->fim == (TAMMAX - 1)) {
      onibus->fim = 0;
   } else {
      onibus->fim++;
   }
   if(cheia(onibus)) {
      printf("\nERRO: Onibus lotado.\n");
      onibus->fim--;
      if(onibus->fim == -1) {
         onibus->fim = TAMMAX - 1;
      }

      return;
   }
   onibus->passageiros[onibus->fim] = p;
}

PASSAGEIRO desce(ONIBUS *onibus) {
   PASSAGEIRO aux;
   
   if(!vazia(onibus)) {
      if(onibus->inicio == TAMMAX - 1) {
         onibus->inicio = 0;
      } else {
         onibus->inicio++;
      }
      aux = onibus->passageiros[onibus->inicio];
   } else {
      printf("\nERRO: Onibus lotado.\n");
   }

   return aux;
}

void entrada(ONIBUS *onibus, PASSAGEIRO p) {
   if(p.idade > 59) {
      entradaFrente(onibus, p);
      /*
         O CÓDIGO ABAIXO VERIFICA O CASO DE RESPEITAR O LIMITE
         MAXIMO DE IDOSOS (2 IDOSOS POR ONIBUS).
      */
      // PASSAGEIRO temp[2];

      // temp[0] = descer(onibus);
      // if(temp[0].idade < 59) {
      //    entradaFrente(onibus, p);
      //    return;
      // }

      // temp[1] = descer(onibus);
      // if(temp[1].idade < 59) {
      //    entradaFrente(onibus, p);
      //    return;
      // }

      // entradaFrente(onibus, temp[1]);
      // entradaFrente(onibus, temp[0]);

      // entradaTras(onibus, p);
   } else {
      entradaTras(onibus, p);
   }
}

PASSAGEIRO criaPassageiro(int idade, char nome[]) {
   PASSAGEIRO p;
   p.idade = idade;
   strcpy(p.nome, nome);

   return p;
};

void imprimir(ONIBUS *onibus) {

   printf("\nPASSAGEIROS:");
   if(vazia(onibus)) {
      printf("\nOnibus Vazio.\n");
      return;
   }

   int i = (onibus->inicio+1) % TAMMAX;
   while(i != ((onibus->fim + 1) % TAMMAX)) {
      printf("\nPassageiro: %s.\n", onibus->passageiros[i].nome);
      printf("Idade: %d.\n", onibus->passageiros[i].idade);
      i = (i+1) % TAMMAX;
   }
};

int main() {
   printf("TransPass - Leandro Ribeiro de Souza \n\n");

   ONIBUS onibus;
   inicia(&onibus);

   printf("SAIU DA GARAGEM.\n");
   imprimir(&onibus);

// PRESIDENTE EPITÁCIO
   printf("\n\nPARADA: PRESIDENTE EPITACIO: \n");
   entrada(&onibus, criaPassageiro(20, "Bart"));
   entrada(&onibus, criaPassageiro(19, "Lisa"));
   entrada(&onibus, criaPassageiro(62, "Homer Simpson"));
   entrada(&onibus, criaPassageiro(65, "Marge Simpson"));
   entrada(&onibus, criaPassageiro(15, "Maggie"));

   imprimir(&onibus);

// PRESIDENTE VENCESLAU
   printf("\n\nPARADA: PRESIDENTE VENCESLAU: \n");
   entrada(&onibus, criaPassageiro(70, "Papai Smurf"));
   entrada(&onibus, criaPassageiro(18, "Smurfette"));
   entrada(&onibus, criaPassageiro(25, "Desastrado"));
   entrada(&onibus, criaPassageiro(30, "Preguica"));
   entrada(&onibus, criaPassageiro(95, "Vovô Smurf"));

   imprimir(&onibus);

// SANTO ANASTACIO
   printf("\n\nPARADA: SANTO ANASTACIO: \n");
   entrada(&onibus, criaPassageiro(10, "Bob Esponja"));
   entrada(&onibus, criaPassageiro(12, "Patrick"));
   entrada(&onibus, criaPassageiro(62, "Seu Serigueijo"));

   imprimir(&onibus);
   printf("\nPARADA FINAL: PRESIDENTE PRUDENTE: \n");

   while(!vazia(&onibus)) {
      printf("O passageiro %s desceu.\n", desce(&onibus).nome);
   }

   printf("\n\nSITUACAO FINAL.\n");
   imprimir(&onibus);

   return 0;
}