#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sSite{

    char nome[30];
    char link[30];
}SITE;

typedef struct cell{

    SITE site;
    struct cell *nextSite;

}CELULA;

CELULA* getnode(){
    return (CELULA *)malloc (sizeof(CELULA));
}

void freenode(CELULA *q){
    free(q);
}

void inicializa(CELULA **lista){

    *lista=NULL;
}

int empty(CELULA *lista)
{
    if(lista==NULL)
    {
        return 1;
    }
    return 0;
}

void insere_inicio(CELULA **lista,SITE s){
    CELULA *q;

    q=getnode();

    if(q!=NULL){
        q->site = s;
        q->nextSite = *lista;
        *lista = q;
    }
    else{
        printf("Erro: Falha na alocacao do no.\n");
        exit(1);
    }
}


void insere_fim(CELULA **lista,SITE s){
    CELULA *q;
    CELULA *aux;

    q = getnode();

    if(q!=NULL){
        q->site = s ;
        q->nextSite = NULL;

        if(empty(*lista))
            *lista = q;
        else{
            aux=*lista;
            while(aux->nextSite != NULL)
                aux = aux->nextSite;

            aux->nextSite = q;
        }
    }
    else{
        printf("\nErro na alocacao do no.\n");
        exit(1);
    }
}

void remove_inicio(CELULA **lista){
    CELULA *q;

    q= *lista;

    if(!empty(*lista)){
        *lista = q->nextSite;
        freenode(q);
    }
    else{
        printf("\nErro:lista vazia.\n");
        exit(1);
    }
}

void exibe_lista(CELULA **lista){

    CELULA *aux;
    int i=0;

    aux= *lista;

    if(aux!=NULL){
        do{
            printf("\n\tSite numero %d\n",i+1);

            printf("\nNome do site: %s \n", aux->site.nome);
            printf("Nome do link: %s \n", aux->site.link);
            aux = aux->nextSite;

            i++;
        }while(aux!=NULL);
    }
    else{
        printf("\n Nao ha elemento na lista.");
    }
    printf("\n");
    
}

SITE lerSite(char nome[],char link[]){

    SITE s;

    strcpy(s.nome,nome);
    strcpy(s.link,link);

    return s;

}

void pesquisa(CELULA *lista,char nome[]){

    CELULA *aux;
    char link[30];

    aux=lista;

    while(aux!=NULL){
        if(strcmp(aux->site.nome, nome)==0 ){
            strcpy(link,aux->site.link);
        }
        aux = aux->nextSite;
    }

    printf("\nLink do site buscado: %s \n",link);
}

int main()
{
    CELULA *ptrlista;
    char nome[30],link[30];
    char pesquisaNome[30];

    int op;


    do{
        printf("1 - Cadastrar site.\n");
        printf("2 - Listar.\n");
        printf("3 - Pesquisar.\n");
        scanf("%d",&op);
        fflush(stdin);

        switch (op){
        case 1: 
                printf("Digite o nome do site:");
                fgets(nome, 30, stdin);
                
                printf("Digite o link do site:");
                fgets(link, 30, stdin);


                insere_inicio(&ptrlista,lerSite(nome,link));
                break;
        
        case 2: exibe_lista(&ptrlista);
                break;

        case 3: printf("Digite o nome do site para busca:");
                fgets(pesquisaNome, 30, stdin);
                pesquisa(ptrlista,pesquisaNome);
                break;

        case 0:break;
        }
        
    }while(op!=0);
}