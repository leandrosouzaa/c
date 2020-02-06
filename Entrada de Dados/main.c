#include <stdlib.h>
#include <stdio.h>

int main() {
    
    /*
        O 'scanf' funcionar de maneira similar ao printf
        a estrutura báscia do scanf é 'scanf("tipo_de_entrada", &variável_que_recebera);
        Para ler 2 valores e salvar em 2 variáveis:
            scanf("%tipo1%tipo2", &var1, &var2);
    */
   int x,y = 0;
    printf("Por favor, informe um número:\n");
    scanf("%i",&x);
    printf("O número digitado foi %i\n", x);

    
    return 0;
}