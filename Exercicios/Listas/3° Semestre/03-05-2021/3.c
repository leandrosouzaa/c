#include <stdio.h>
#include <stdlib.h>

typedef struct sData {
   int mes;
   int ano;
} Data;

typedef struct sBovino {
   int codigo;
   float leite, alim;
   char abate;
   Data data; 
} Bovino;

typedef struct sDatabase {
   int n;
   Bovino *bovinos;
} Database;

int inicializa(Database *database, int size) {
   database->n = -1;
   database->bovinos = (Bovino *) malloc(sizeof(Bovino) * size);
   if(database->bovinos == NULL) {
      printf("\nERRO: Memória insuficiente.");
      return 0;
   }
}

int main() {
   printf("Abatedouro 2000 - Leandro Ribeiro de Souza \n\n");

   Database *database;
   int temp;

   database = (Database *) malloc(sizeof(Database));
   // 
   printf("Informe a quantidade máximo de bovinos: ");
   scanf("%d", &temp);
   inicializa(database, temp);

   return 0;
}