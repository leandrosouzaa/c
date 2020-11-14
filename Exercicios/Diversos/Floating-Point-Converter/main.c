#include <stdio.h>
#include <math.h>

#define clrscr() printf("\e[1;1H\e[2J")

typedef struct {
   int  exponent, significand;
} Architecture;

typedef struct {
   long double bigPositive, bigNegative, smallNegative, smallPositve; 
} ArchitectureValues;


Architecture setArchitecture() {
   printf("\nCONFIGURAÇÃO DE ARQUITETURA\n\n");
   Architecture architecture;

   printf("Informe a quantidade de bits reservadas para o expoente: ");
   scanf("%d", &architecture.exponent);

   printf("Informe a quantidade de bits reservadas para o significando: ");
   scanf("%d", &architecture.significand);

   return architecture;
}

ArchitectureValues generateArchitectureValues(Architecture architecture) {
   ArchitectureValues architectureValues;
   int significand[256], exponent[256], i;

   int excess = pow(2, architecture.exponent - 1);
   long double floatingNumber = 0;

   // Calcula maior positivo   
   for(i=1; i <= architecture.significand; i++) {
      floatingNumber+= pow(2, -1 * i);
   }

   int exponentValue = pow(2, architecture.exponent);
   int elevateNumber = exponentValue - excess;
   architectureValues.bigPositive = floatingNumber * pow(2, elevateNumber);
   architectureValues.smallNegative = architectureValues.bigPositive * -1;
} 

int main() {
   printf("Conversor para Ponto Flutuante - Leandro Ribeiro de Souza \n\n");
   
   Architecture architecture = setArchitecture();
   clrscr();

   ArchitectureValues architectureValues = generateArchitectureValues(architecture);

   return 0;
}
