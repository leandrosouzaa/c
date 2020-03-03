#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

    printf("Calculadora de Média 1.0 - Leandro Ribeiro de Souza\n\n");

    float media,n1,n2,n3,n4,n5;
    char nome[50], materia[50];

    printf("Aluno: ");
    scanf("%s", nome);

    printf("Matéria: ");
    scanf("%s", materia);

    system("clear");

    printf("\nInforme as notas do aluno %s na disciplina de %s.", nome, materia);

    printf("\n\nAvaliação Bimestral(Peso 5): ");
    scanf("%f", &n5);
    printf("Seminário Bimestral(Peso 4): ");
    scanf("%f", &n4);
    printf("Observação Direta(Peso 3): ");
    scanf("%f",&n3);
    printf("Atividades extras(Peso 2): ");
    scanf("%f", &n2);
    printf("Lista de Exercícios(Peso 1): ");
    scanf("%f", &n1);

    system("clear");

    media = ((n1*1)+(n2*2)+(n3*3)+(n4*4)+(n5*5))/15;

    printf("Aluno: %s        Matéria:%s\n\n", nome,materia);
    printf("Avaliação Bimestral:       %12.2f\n",n5);
    printf("Seminário Bimestral:       %12.2f\n",n4);
    printf("Observação Direta:         %12.2f\n",n3);
    printf("Atividades Extras:         %12.2f\n",n2);
    printf("Lista de Exercícios:       %12.2f\n",n1);

    printf("Média Final: %.2f\n\n", media);
    if (media <6) {
        printf("Situação Final: REPROVADO");
    } else {
        printf("Situação Final: APROVADO");
    };


    return 0;
};