#include <stdio.h>

void readPurchase(float purchase[20]) {
   int i = 0;
   char status;
   do {
      printf("\nProduto : %d.\n", i + 1);
      printf("Valor: R$");
      scanf("%f", &purchase[i]);

      if(purchase[i] <= 0) {
         printf("Valor inválido, tente novamente...");
      } else {
         printf("Existem mais produtos [S/N]: ");
         scanf(" %c", &status);
         i++;
      }
   } while(i < 20 && status == 'S');
};

float getPurchaseValue(float purchase[20]) {
   int i, temp = 0;
   for(i=0; i < 20; i++) {
      temp+= purchase[i];
   }
   return temp;
};

float getExpansivePurchase(float purchase1Value, float purchase2Value) {
   return purchase1Value > purchase2Value ? purchase1Value : purchase2Value;
}

float getExpansiveItem(float purchase[20]) {
   int i;
   int itemValue = purchase[0];
   for(i=1; i < 20; i++) {
      if(purchase[i] > purchase[0]) {
         itemValue = purchase[i];
      }
   }
   return itemValue;
}

int main() {
   printf("Duas Compras - Leandro Ribeiro de Souza \n\n");
   float purchase1[20] = {0}, purchase2[20] = {0}, purchase1Value, purchase2Value, purchase1Item, purchase2Item;

   printf("COMPRA 1");
   readPurchase(purchase1);

   printf("\nCOMPRA 2");
   readPurchase(purchase2);

   purchase1Value = getPurchaseValue(purchase1);
   purchase2Value = getPurchaseValue(purchase2);
   purchase1Item = getExpansiveItem(purchase1);
   purchase2Item = getExpansiveItem(purchase2);


   printf("\nValor da Compra mais Cara: R$%0.2f.\n", getExpansivePurchase(purchase1Value, purchase2Value));
   printf("Valor da Compra 1: R$%0.2f.\n", purchase1Value);
   printf("Valor da Compra 2: R$%0.2f.\n", purchase2Value);
   printf("Item mais caro da compra 1: R$%0.2f.\n", purchase1Item);
   printf("Item mais caro da compra 2: R$%0.2f.\n", purchase2Item);

   return 0;
}
