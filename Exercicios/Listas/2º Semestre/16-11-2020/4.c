#include <stdio.h>

int readTickets(char tickets[200]) {
   int logicalSize = 0, age;
   char status;
   do {
      printf("\nIngresso %d.\n", logicalSize + 1);
      do {
         printf("Idade: ");
         scanf("%d", &age);
      } while(age <= 0);

      if(age >= 65) {
         tickets[logicalSize] = 'G';
      } else {
         if(age <= 12) {
            tickets[logicalSize] = 'M';
         } else {
            tickets[logicalSize] = 'I';
         }
      }
      switch (tickets[logicalSize]) {
         case 'G':
            printf("Tipo: Gratuito");
            break;
         case 'M':
            printf("Tipo: Meia");
            break;
         case 'I':
            printf("Tipo: Inteira");
            break;
         default:
            break;
      }
      logicalSize++;
      printf("\nExistem mais clientes [S/N]: ");
      scanf(" %c", &status);
   } while(logicalSize < 200 && status == 'S');
   return logicalSize;
}

int getQuantityByType(char tickets[200], int logicalSize, char type) {
   int i=0;
   int quantity = 0;
   for(i=0; i<logicalSize; i++) {
      if(tickets[i] == type) {
         quantity++;
      }
         
   }
   return quantity;
}

float getTotalValue(char tickets[200], int logicalSize) {
   int i;
   float total = 0;
   for(i=0; i<logicalSize; i++) {
      switch (tickets[i]) {
         case 'M':
            total+= (18/2);
            break;
         case 'I':
            total+= 18;
            break;
         default:
            break;
      }
   }
   return total;
}

float getChildrenPercentage(char tickets[200], int logicalSize) {
   int totalChildrens = getQuantityByType(tickets, logicalSize, 'M');
   int totalPaying = totalChildrens + getQuantityByType(tickets, logicalSize, 'I');

   return ((totalChildrens*100.0) / totalPaying);
}

int main() {
   printf("Controle de Cinema - Leandro Ribeiro de Souza \n\n");
   char tickets[200];   

   int logicalSize = readTickets(tickets);
   int freeTickets = getQuantityByType(tickets, logicalSize, 'G');
   float totalValue = getTotalValue( tickets, logicalSize);
   float childrenPercentage = getChildrenPercentage(tickets, logicalSize);

   printf("\nRELATÓRIO FINAL:\n\n");
   printf("Quantidade de ingressos gratuitos: %d.\n", freeTickets);
   printf("Porcentagem Crianças entre os pagantes: %0.2f%%.", childrenPercentage);
   printf("\n\nTOTAL DA SESSÃO: R$%0.2f.", totalValue);
   return 0;
}
