#include <stdio.h>

int main() {

    /* 
        Por padrão é comum definir um valor de variável assim que a mesma é criada.
        Caso contrário, o compilador gera um valor aleatório para ela. 
        Não é possível mudar o valor o tipo da variável durante a execução do código. 
        4 caracteristicas basicas de uma variável
            1) Toda variável possui um nome;
            2) Toda variável possui um tipo;
            3) Toda variável possui um tamanho;
            4) Toda variável possui um valor
            
        Informações sobre variáveis
            a) O seu armazenamento é temporário;
            b) Quando o programa for fechado, tudo que estiver na memória é apagado;
            c) valores armazenados na memórias são voláteis;
            d) Os valores da variáveis sao sobrepostos, ou seja, ao definir um novo valor, o valor antigo é perdido;
            e) Não é possível colocar um número no primeiro caracter do nome de uma variável; 
            f) Não é permitido utilizar caracters especias no nome de uma variável;

        A estrutura básica da váriavel é 'tipo nomeDaVariavel = valorPadrao


        Existem 5 tipos de variáveis
            1) Char: caracters (ocupa 1 Byte);
            2) int: inteiros (varia conforme a arquitetura do SO, normalmente 2 Bytes, (-32768 <= i <= 32767));
            3) float: decimais (ocupta normalmente 4 Bytes);
            4) void: vazio
            5) double: decimal com grande quantidade de casas decimais (8 Bytes)
    */

    int num = 0;

    int num1, num2 = 0;


    return 0;


}