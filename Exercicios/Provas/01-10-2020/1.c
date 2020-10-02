#include <stdio.h>

int main() {
   printf("Empresa Telefone sem Fio - Leandro Ribeiro de Souza \n\n");

   int ddd, dddChamada, qtdChamadas = 0;
   float qtdMinutosChamada = 0, qtdMinutosLocais = 0, qtdMinutosAreas = 0, credito, qtdMinutosTotal = 0;

   printf("Informe o seu DDD: ");
   scanf("%i", &ddd);

   printf("Valor da Recarga: R$");
   scanf("%f", &credito);

   while (credito > 0) {
      qtdChamadas++;
      printf("\nCHAMADA NÚMERO : %i\n", qtdChamadas);
      printf("Crédito disponível: R$%0.2f.\n", credito);
      
      printf("DDD da Chamada: ");
      scanf("%i", &dddChamada);
      
      printf("Minutos demorados: ");
      scanf("%f", &qtdMinutosChamada);

      if (ddd == dddChamada) {
         credito-= qtdMinutosChamada * 0.3;
         qtdMinutosLocais+= qtdMinutosChamada;
      } else {
         credito-= qtdMinutosChamada * 0.75;
         qtdMinutosAreas+= qtdMinutosChamada;
      }
   };

   qtdMinutosTotal = qtdMinutosAreas + qtdMinutosLocais;

   printf("\nRELATÓRIO FINAL\n");
   printf("Total de Chamadas: %i.\n", qtdChamadas);
   printf("Total de Minutos totais: %0.2f.\n", qtdMinutosTotal);
   printf("Total de Minutos Locais: %0.2f.\n", qtdMinutosLocais);
   printf("Total de Minutos entre áreas: %0.2f.\n", qtdMinutosAreas);
   printf("SALDO FINAL: R$%0.2f.", credito);

   return 0;
}
