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
   printf("CONFIGURAÇÃO DE ARQUITETURA\n\n");
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

   // Calcula menor negativo.
   architectureValues.smallNegative = architectureValues.bigPositive * -1;

   // Calcula menor positivo.
   exponentValue = 0;
   elevateNumber = exponentValue - excess;
   floatingNumber = pow(2, -1);
   architectureValues.smallPositve = floatingNumber * pow(2, elevateNumber); 

   // Calcula maior positivo
   architectureValues.bigNegative = architectureValues.smallPositve * -1; 

   return architectureValues;
};

void generateArchitectureReports(Architecture architecture, ArchitectureValues architectureValues) {
   int i;

   printf("Arquitetura de %db de expoente e %db de significando.", architecture.exponent, architecture.significand);

   printf("\n\nMaior Número Positivo (base 10): %Lf\n", architectureValues.bigPositive);
   printf("Maior Número Positivo (base 2):");
   printf("0");
   for(i=0; i < architecture.exponent; i++) {
      printf("1");
   };
   for(i=0; i < architecture.significand; i++) {
      printf("1");
   };

   printf("\n\nMenor Número Positivo (base 10): %Lf\n", architectureValues.smallPositve);
   printf("Menor Número Positivo (base 2):");
   printf("0");
   for(i=0; i < architecture.exponent; i++) {
      printf("0");
   };
   printf("1");
   for(i=1; i < architecture.significand; i++) {
      printf("0");
   };

   printf("\n\nMaior Número Negativo (base 10): %Lf\n", architectureValues.bigNegative);
   printf("Maior Número Negativo (base 2):");
   printf("1");
   for(i=0; i < architecture.exponent; i++) {
      printf("0");
   };
   for(i=0; i < architecture.significand; i++) {
      printf("0");
   };

   printf("\n\nMenor Número Negativo (base 10): %Lf\n", architectureValues.smallNegative);
   printf("Menor Número Negativo (base 2):");
   printf("1");
   for(i=0; i < architecture.exponent; i++) {
      printf("1");
   };
   for(i=0; i < architecture.significand; i++) {
      printf("1");
   };

   getchar();
}

int main() {
   printf("Conversor para Ponto Flutuante - Leandro Ribeiro de Souza \n\n");
   int option = 1;
   
   Architecture architecture = setArchitecture();
   clrscr();
   printf("Calculando pontas...");
   ArchitectureValues architectureValues = generateArchitectureValues(architecture);

   do {   
      clrscr();
      printf("Menu de Seleção\n\n");
      printf("1 - Modificar Arquitetura\n");
      printf("2 - Visualizar valores da Arquitetura.\n");
      printf("3 - Conversão: Decimal - Binário.\n");
      printf("4 - Conversão: Binário - Decimal.\n");
      printf("5 - Finalizar programa.\n");
      printf("Escolha um item do menu: ");
      scanf("%d", &option);

      switch (option) {
         case 1:
            clrscr();
            architecture = setArchitecture();
            clrscr();
            printf("Calculando pontas...");
            architectureValues = generateArchitectureValues(architecture);
            break;

         case 2:
            clrscr();
            generateArchitectureReports(architecture, architectureValues);
            getchar();
            break;

         case 3:
            break;

         case 4:
            break;

         case 5:
            break;

         default:
            break;
      }
   } while(option!=5);
   return 0;
}
