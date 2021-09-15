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


void remover(No **raiz, Arquivo arquivo) {
   if(*raiz == NULL)
      return;
   else if (strcmp(arquivo.nome, (*raiz)->info.nome) < 0)
      remover(&(*raiz)->esq, arquivo);
   else if (strcmp(arquivo.nome, (*raiz)->info.nome) > 0)
      remover(&(*raiz)->esq, arquivo);
   else {
      if((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
         free(*raiz);
         *raiz = NULL;
         printf("EXCLUIDO COM SUCESSO 1: %s.\n\n", arquivo.nome);

      } else if ((*raiz)->esq == NULL){
         No *temp = *raiz;
         *raiz = (*raiz)->dir;
         free(temp);
         printf("EXCLUIDO COM SUCESSO 2: %s.\n\n", arquivo.nome);
      } else if ((*raiz)->dir == NULL){
         No *temp = *raiz;
         *raiz = (*raiz)->esq;
         free(temp);
         printf("EXCLUIDO COM SUCESSO 3: %s.\n\n", arquivo.nome);
      } else {
         printf("deslocou");
         No *pai = *raiz;
         No *f = (*raiz)->esq;
         while(f->dir != NULL) {
            pai = f;
            f = f->dir;
         }
         (*raiz)->info = f->info;
         f->info = arquivo;
         remover(&(*raiz)->esq, arquivo);
      }
   }
}

void faxina(No **raiz, int data) {
   if(*raiz == NULL) {
      return;
   }

   if((*raiz)->info.ultimoAcesso <= data) {
      printf("O ARQUIVO %s FOI ENVIADO PARA EXCLUSAO.\n", (*raiz)->info.nome);
      remover(raiz, (*raiz)->info);
   }

   faxina(&(*raiz)->esq, data);
   faxina(&(*raiz)->dir, data);
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
   faxina(&arvore, 5);

   printf("Filmes em Ordem Alfabetica: \n");
   em_ordem(arvore);

   return 0;
}