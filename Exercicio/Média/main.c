#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *toUpper (char nome[50]) {
    int len = strlen(nome);
    int i = 0;
    char *upper;

    for (i=0; i<len; i++) {
        upper[i] = toupper(nome[i]);
    }

    return upper;

}


int main() {

    printf("Calculadora de Média 1.0 - Leandro Ribeiro de Souza\n\n");

    int n1,n2,n3,n4,n5;
    float media;
    char nome[50], materia[50];

    printf("Aluno: ");
    scanf("%s", nome);
    printf("%s", toUpper(nome));

    // printf("Matéria: ");
    // scanf("%s", materia);


    // printf("INFORME AS NOTADOS DO ALUNO NA DISCIPLINA DE %s", toUpper(nome));


    return 0;
};