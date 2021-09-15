#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sArquivo {
   int ultimoAcesso;
   char nome[50];
} Arquivo;

typedef struct sNo {
   Arquivo info;
   struct sNo* esq;
   struct sNo* dir;
} No;

void inicializa(No **raiz) {
   *raiz = NULL;
}

No* getNo() {
   return (No*) malloc(sizeof(No));
}

void acessa(No *celula) {
   printf("\nNome do Arquivo: %s.\n", celula->info.nome);
   printf("Ultimo acesso: %d.\n", celula->info.ultimoAcesso);
}

void insere(No **raiz, Arquivo valor) {
   if(*raiz == NULL) {
      No *celula = getNo();
      
      if(celula == NULL) {
         printf("\nERRO: Falha na alocacao de memoria. Encerrando programa.\n");
         exit(1);
      }

      celula->esq = NULL;
      celula->dir = NULL;
      celula->info = valor;
      *raiz = celula ;
   } else {
      if(strcmp(valor.nome, (*raiz)->info.nome) < 0) {
         insere(&(*raiz)->esq, valor);
      } else {
         insere(&(*raiz)->dir, valor);
      }
   }
};

void pre_ordem(No *raiz) {
   if(raiz != NULL) {
      acessa(raiz);
      pre_ordem(raiz->esq);
      pre_ordem(raiz->dir);
   }
};

void pos_ordem(No *raiz) {
   if(raiz != NULL) {
      pos_ordem(raiz->esq);
      pos_ordem(raiz->dir);
      acessa(raiz);
   }
}

void em_ordem(No *raiz) {
   if(raiz != NULL) {
      em_ordem(raiz->esq);
      acessa(raiz);
      em_ordem(raiz->dir);
   }
}

No* minValueNode(No *node) {
    No *atual = node;
 
    while (atual && atual->esq != NULL)
        atual = atual->dir;
 
    return atual;
}

No* remover(No  *raiz, char nome[50]) {
    if (raiz == NULL)
        return raiz;
 
    if (strcmp(nome, raiz->info.nome) < 0)
        raiz->esq = remover(raiz->esq, nome);
 
    else if (strcmp(nome, raiz->info.nome) > 0)
        raiz->dir = remover(raiz->dir, nome);
 
    else {
        if (raiz->esq == NULL) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }
 
        No *temp = minValueNode(raiz->dir);
 
        raiz->info = temp->info;
 
        raiz->dir = remover(raiz->dir, temp->info.nome);
    }
    return raiz;
}

No* faxina(No *raiz, int data) {
   if(raiz == NULL) {
      return NULL;
   }

   if(raiz->info.ultimoAcesso <= data) {
      printf("Removendo o No %s...",raiz->info.nome);
      raiz = remover(raiz, (raiz)->info.nome);
      printf("Removido com sucesso.\n");

   }

   raiz = faxina(raiz->esq, data);
   raiz = faxina(raiz->dir, data);

   return raiz;
}

Arquivo criarArquivo(char nome[50], int ultimoAcesso) {
   Arquivo a;
   strcpy(a.nome, nome);
   a.ultimoAcesso = ultimoAcesso;

   return a;
}

int main() {
   printf("Gerenciador de Arquivos - Leandro Ribeiro de Souza \n\n");

   No *arvore;
   inicializa(&arvore);

   insere(&arvore, criarArquivo("Apresentacao.ppt", 2));
   insere(&arvore, criarArquivo("Procuracao.docx", 8));
   insere(&arvore, criarArquivo("TCC.doc", 10));
   insere(&arvore, criarArquivo("TCC-OFICIAL.doc", 1));
   insere(&arvore, criarArquivo("Roteiro Bee-Movie.rar", 13));
   insere(&arvore, criarArquivo("Sherek-3.mkv", 5));
   insere(&arvore, criarArquivo("Os Traplahoes.mp4", 20));
   insere(&arvore, criarArquivo("Clube da Luta.mov", 30));

   printf("Filmes em Ordem Alfabetica: \n");
   em_ordem(arvore);

   printf("Remocao de todos os filmes apos o dia 5.\n");
   arvore = faxina(arvore, 2);

   printf("Filmes em Ordem Alfabetica: \n");
   em_ordem(arvore);

   return 0;
}