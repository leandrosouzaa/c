#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct sNo {
   int info;
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
   printf("%d ", celula->info);
}

void insere(No **raiz, int valor) {
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
      if((*raiz)->info > valor) {
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

int calcula_nos(No *raiz) {
   int total = 1;
   if(raiz == NULL) {
      return 0;
   } else {
      total += calcula_nos(raiz->esq) + calcula_nos(raiz->dir);
      return total;
   }
}

int calcula_folhas(No *raiz) {
   if(raiz == NULL) {
      return 0;
   } else {
      if(!raiz->esq && !raiz->dir) {
         return 1;
      }

      return calcula_folhas(raiz->esq) + calcula_folhas(raiz->dir);
   }
}

int calcula_profundidade(No *raiz) {
   if(raiz == NULL) {
      return 0;
   } else {
      int a = calcula_profundidade(raiz->esq);
      int b = calcula_profundidade(raiz->dir);
      
      if(a > b) {
         return a + 1;
      } else {
         return b + 1;
      }
   }
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int height(No* raiz) {
    if (raiz == NULL)
        return 0;
 
    return 1 + max(height(raiz->esq), height(raiz->dir));
}

int balanceada(No* raiz) {
    int ae; 
    int ad;
 
    if (raiz == NULL)
        return 1;
 
    ae = height(raiz->esq);
    ad = height(raiz->dir);
 
    if (abs(ae - ad) <= 1 && balanceada(raiz->esq) && balanceada(raiz->dir))
        return 1;
 
    return 0;
}

int nivel(No* raiz, int valor) {
   if(raiz == NULL || raiz->info == valor) {
      return 0;
   }

   if(raiz->info > valor) {
      return nivel(raiz->esq, valor) + 1;
   } else {
      return nivel(raiz->dir, valor) + 1;
   }
}

int qtdAncestrais(No *raiz, int valor, int k) {
   if(k < 0 || raiz == NULL) {
      return -1;
   }

   int nivelValor = nivel(raiz, valor);

   if(nivelValor == calcula_profundidade(raiz) || k > nivelValor) {
      return -1;
   }

   return nivelValor - k + 1;
}

No* minValueNode(No *node) {
    No *atual = node;
 
    while (atual && atual->esq != NULL)
        atual = atual->dir;
 
    return atual;
}

No* remover(No  *raiz, int k) {
    if (raiz == NULL)
        return raiz;
 
    if (k < raiz->info)
        raiz->esq = remover(raiz->esq, k);
 
    else if (k > raiz->info)
        raiz->dir = remover(raiz->dir, k);
 
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
 
        raiz->dir = remover(raiz->dir, temp->info);
    }
    return raiz;
}

No* pesquisa(int valor, No *raiz) {
   if(raiz->info == valor) {
      return raiz;   
   }

   if(raiz->info > valor) {
      pesquisa(valor, raiz->esq);
   } else {
      pesquisa(valor, raiz->dir);
   }

   return NULL;
}

void print2DUtil(No *root, int space) {
    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2DUtil(root->dir, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
 
    print2DUtil(root->esq, space);
}
 
void print2D(No *root) {
   print2DUtil(root, 0);
}

int main() {
   No *raiz;
   inicializa(&raiz);

   No *busca;

   int temp, num, k;

   do {
      printf("\nArvore Binaria - Leandro Ribeiro de Souza \n\n");

      printf("Informacoes: \n");
      printf("Quantidade de Nos: %d.\n", calcula_nos(raiz));
      printf("Quantidade de Folhas: %d.\n", calcula_folhas(raiz));
      printf("Altura: %d.\n", calcula_profundidade(raiz));
      printf("Balanceada: %s.\n", balanceada(raiz) ? "Sim" : "Nao");
 
      printf("\n1 - Inserir\n");
      printf("2 - Apresentar Pre Ordem\n");
      printf("3 - Apresentar em Ordem\n");
      printf("4 - Apresentar Pos Ordem\n");
      printf("5 - Buscar\n");
      printf("6 - Remover\n");
      printf("7 - Desenhar\n");
      printf("8 - Contar Ancestrais");

      printf("\n0 - Sair\n");

      printf("\nEscolha um item: ");
      scanf("%d", &temp);
      
      setbuf(stdin, NULL);
      fflush(stdin);

      switch (temp) {
         case 1:
            printf("Informe um valor para inserir: ");
            scanf("%d", &num);
            insere(&raiz, num);
            break;
         
         case 2:
            printf("\nPre Ordem: ");
            pre_ordem(raiz);
            getchar();
            break;

         case 3:
            printf("\nEm Ordem: ");
            em_ordem(raiz);
            getchar();
            break;

         case 4:
            printf("\nPos Ordem: ");
            pos_ordem(raiz);
            getchar();
            break;

         case 5:
            printf("Informe um valor para buscar: ");
            scanf("%d", &num);
            busca = pesquisa(num, raiz);
            if(busca) {
               printf("O valor %d esta presente no endereco %x.\n", busca->info, busca);
            }
            break;

         case 6:
            printf("Informe um valor para excluir: ");
            scanf("%d", &num);
            raiz = remover(raiz, num);
            break;

         case 7:
            print2D(raiz);
            break;

         case 8:
            printf("Informe um valor para contar: ");
            scanf("%d", &num);
            printf("Informe um valor para contar: ");
            scanf("%d", &k);

            printf("Informe um nivel para buscar: ");
            printf("Quantidade de nos ancestrais: %d.\n", qtdAncestrais(raiz, num, k));
            printf("Se quantidade de nos ancestrais for igual a -1, nao eh opssivel realizar a operacao.\n");

            break;

         case 0:
            printf("\nEncerrando sistema...\n\n");
            break;

         default:
            printf("\nItem invalido, tente novamente.\n\n");
            break;
      }
   } while(temp != 0);

   return 0;
};