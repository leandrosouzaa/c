#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float localiza_maior(int array[20]) {
   int i=0, maior = array[0];
   for(i=1; i<20; i++) {
      if(array[i] > maior)
         maior = array[i];
   }
   return maior;
}

int localiza_menor(int array[20]) {
   int i=0, menor = array[0];
   for(i=1; i<20; i++) {
      if(array[i] < menor)
         menor = array[i];
   }
   return menor;
}

int localiza_maiores(int array[20], int numero) {
   int i=0, quantidade = 0;
   for(i=0; i<20; i++) {
      if(array[i] > numero)
         quantidade++;
   }
   return quantidade;
}

int localiza_intervalo(int array[20], int numero1, int numero2) {
   int i=0, quantidade = 0;
   if(numero1 > numero2) {
      for(i=0; i<20; i++) {
         if(array[i] > numero2 && array[i] < numero1)
            quantidade++;
      }
   } else {
      for(i=0; i<20; i++) {
         if(array[i] > numero1 && array[i] < numero2)
            quantidade++;
      }
   }
   return quantidade;
}

int soma_intervalo(int array[20], int numero1, int numero2) {
   int i=0, total = 0;
   if(numero1 > numero2) {
      for(i=0; i<20; i++) {
         if(array[i] > numero2 && array[i] < numero1)
            total+= array[i];
      }
   } else {
      for(i=0; i<20; i++) {
         if(array[i] > numero1 && array[i] < numero2)
            total+= array[i];
      }
   }
   return total;
}

int soma_intervalo_index(int array[20], int numero1, int numero2) {
   int i=0, total = 0;
      for(i=numero1; i<numero2; i++) {
            total+= array[i];
      }
   return total;
}

int soma_total(int array[20]) {
   int i=0, total = 0;
   for(i=0; i<20; i++) {
      total+= array[i];
   }
   return total;
}

int localiza_elemento(int array[20], int numero) {
   int i=0;
   for(i=0; i<20; i++) {
      if(array[i] == numero)
         return i;
   }
   return -1;
}

void preencher_vetor(int array[20]) {  
   srand(time(NULL));
   int i;
   for(i=0; i<20; i++) {
      array[i] = rand() % 31;
      printf("Número na posição %d: %d.\n", i, array[i]);
   }
}

void preencher_vetor_digitando(int array[20]) {  
   srand(time(NULL));
   int i;
   for(i=0; i<20; i++) {
      printf("Número na posição %d: ", i + 1);
      scanf("%d", &array[i]);
   }
}

void apresentar_vetor(int array[20]) {
   int i;
   for(i=0; i<20; i++) {
      printf("%d ", array[i]);
   }
}

void apresentar_vetor_maior(int array[20], int num) {
   int i;
   for(i=0; i<20; i++) {
      if(array[i] > num)
         printf("%d ", array[i]);
   }
}

int definir_amplitude(int array[20]) {
   return localiza_maior(array) - localiza_menor(array);
};

int acha_maior(int numeros[20]) {
   return soma_intervalo_index(numeros, 0, 10) > soma_intervalo_index(numeros, 10, 20) ? 1 : 2;
}

int main() {
   printf("Funções - Leandro Ribeiro de Souza \n\n");
   int numeros[20];

   // preencher_vetor_digitando(numeros);
   preencher_vetor(numeros);
   int amplitude = definir_amplitude(numeros);
   printf("A amplitude é %d.\n", amplitude);
   int elementos = localiza_intervalo(numeros, 0, 9) + localiza_intervalo(numeros, 10, 19) + localiza_intervalo(numeros, 20,30);
   printf("Quantidade de elementos no intervalo: %d.\n", elementos);
   printf("Elementos acima da média: ");
   apresentar_vetor_maior(numeros, soma_total(numeros)/20);
   int maior = acha_maior(numeros);
   printf("\nMetade com maior valor: %d.\n", maior);
   printf("Maior item: %d.\n", localiza_elemento(numeros, localiza_maior(numeros)));
   printf("Menor item: %d.\n", localiza_elemento(numeros, localiza_menor(numeros)));
   printf("Vetor: ");
   apresentar_vetor(numeros);
   return 0;
}
