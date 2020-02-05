#include <stdio.h>

int main() {
    
    // Padrão
    printf("Olá Mundo  \n");

    // Especificando o tipo de saída printf("%tipo_de_saida", valor_a_ser_imprimido)

    /*
        Tipos de formatação para impressão:
            Integer: %i ou %d;
            Float / Double: %f;
            char: %c;
            string: %s;

            Módulo de um número: %u;
            Endereço de Meḿoria: %p;
            Imprimir número com notação cientifíca: %e ou %E;
            Porcentagem: %%;

        Para encadear impressões formatadas utiliza-se virgula: printf("%tipo_de_saida1 %tipo_de_saida2", "valor1 valor2")
    */

    // Exemplo

    int x = 10;
    printf("%i\n", x);

    float f = 4.12;
    printf("%f\n", f);

    printf("%i - %f ", x, f)/



    return 0;
};