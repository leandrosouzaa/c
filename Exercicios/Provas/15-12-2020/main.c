#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void preencher_dados(Aluno alunos[50], Livro livros[50], Emprestimo emprestimos[100]) {
   {
      alunos[0].prontuario = 1232121;
      strcpy(alunos[0].nome, "Antonio Marcos de Oliveira");
      strcpy(alunos[0].curso, "BCC");

      alunos[1].prontuario = 1312128;
      strcpy(alunos[1].nome, "Maria Eduarda de Freitas");
      strcpy(alunos[1].curso, "ADS");

      alunos[2].prontuario = 1423221;
      strcpy(alunos[2].nome, "Olavo Siqueira");
      strcpy(alunos[2].curso, "TII");

      alunos[3].prontuario = 1876518;
      strcpy(alunos[3].nome, "Marcia da Silva");
      strcpy(alunos[3].curso, "BCC");

      alunos[4].prontuario = 1765452;
      strcpy(alunos[4].nome, "Marcelo Pereira de Almeida");
      strcpy(alunos[4].curso, "BCC");

      alunos[5].prontuario = 1764562;
      strcpy(alunos[5].nome, "Joao Carlos de Souza");
      strcpy(alunos[5].curso, "TII");
   }

   {
      livros[0].tombo = 1;
      strcpy(livros[0].titulo, "Aprendendo C com Dificuldade");
      strcpy(livros[0].autores, "Andre e Danilo");
      livros[0].ano = 2019;
      livros[0].situacao = 'D';

      livros[1].tombo = 2;
      strcpy(livros[1].titulo, "Tropecando no código fonte em C");
      strcpy(livros[1].autores, "Melissa");
      livros[1].ano = 2018;
      livros[1].situacao = 'E';

      livros[2].tombo = 3;
      strcpy(livros[2].titulo, "Linguagem C: Agora vai");
      strcpy(livros[2].autores, "Andre, Melissa e Danilo");
      livros[2].ano = 2017;
      livros[2].situacao = 'E';

      livros[3].tombo = 4;
      strcpy(livros[3].titulo, "Java. E agora.... Socorro...");
      strcpy(livros[3].autores, "Cesar e Vilson");
      livros[3].ano = 2018;
      livros[3].situacao = 'D';

      livros[4].tombo = 5;
      strcpy(livros[4].titulo, "Orientacao a Objetos: o que e isso");
      strcpy(livros[4].autores, "Andre e Vilson");
      livros[4].ano = 2017;
      livros[4].situacao = 'E';
   }

   {
      emprestimos[0].dia = 3;
      emprestimos[0].mes = 4;
      emprestimos[0].dia_devolucao = 10;
      emprestimos[0].mes_devolucao = 4;
      emprestimos[0].codigo_livro = 1;
      emprestimos[0].codigo_aluno = 1423221;
      emprestimos[0].situacao = 'F';
      
      emprestimos[1].dia = 10;
      emprestimos[1].mes = 4;
      emprestimos[1].dia_devolucao = 17;
      emprestimos[1].mes_devolucao = 4;
      emprestimos[1].codigo_livro = 3;
      emprestimos[1].codigo_aluno = 1765452;
      emprestimos[1].situacao = 'F';

      emprestimos[2].dia = 11;
      emprestimos[2].mes = 4;
      emprestimos[2].dia_devolucao = 18;
      emprestimos[2].mes_devolucao = 4;
      emprestimos[2].codigo_livro = 4;
      emprestimos[2].codigo_aluno = 1876518;
      emprestimos[2].situacao = 'F';

      emprestimos[3].dia = 20;
      emprestimos[3].mes = 4;
      emprestimos[3].dia_devolucao = 27;
      emprestimos[3].mes_devolucao = 4;
      emprestimos[3].codigo_livro = 5;
      emprestimos[3].codigo_aluno = 1312128;
      emprestimos[3].situacao = 'P';

      emprestimos[4].dia = 25;
      emprestimos[4].mes = 4;
      emprestimos[4].dia_devolucao = 2;
      emprestimos[4].mes_devolucao = 5;
      emprestimos[4].codigo_livro = 2;
      emprestimos[4].codigo_aluno = 1232121;
      emprestimos[4].situacao = 'F';

      emprestimos[5].dia = 26;
      emprestimos[5].mes = 4;
      emprestimos[5].dia_devolucao = 3;
      emprestimos[5].mes_devolucao = 5;
      emprestimos[5].codigo_livro = 1;
      emprestimos[5].codigo_aluno = 1423221;
      emprestimos[5].situacao = 'F';

      emprestimos[6].dia = 30;
      emprestimos[6].mes = 4;
      emprestimos[6].dia_devolucao = 7;
      emprestimos[6].mes_devolucao = 5;
      emprestimos[6].codigo_livro = 3;
      emprestimos[6].codigo_aluno = 1876518;
      emprestimos[6].situacao = 'P';

      emprestimos[7].dia = 7;
      emprestimos[7].mes = 5;
      emprestimos[7].dia_devolucao = 14;
      emprestimos[7].mes_devolucao = 5;
      emprestimos[7].codigo_livro = 4;
      emprestimos[7].codigo_aluno = 1232121;
      emprestimos[7].situacao = 'F';

      emprestimos[8].dia = 10;
      emprestimos[8].mes = 5;
      emprestimos[8].dia_devolucao = 17;
      emprestimos[8].mes_devolucao = 5;
      emprestimos[8].codigo_livro = 2;
      emprestimos[8].codigo_aluno =  1765452;
      emprestimos[8].situacao = 'P';
   }
};


int menu(int tlAlunos, int tlLivros, int tlEmprestimos) {
   setbuf(stdin, NULL);
   system("cls");

   int opcao;

   printf("CONTROLE DE EMPRESTIMOS 1.0 - BIBLOTECA IFSP PEP\n\n");
   printf("Cadastros e Devolucoes:\n");
   printf("  01 - CADASTRAR NOVO EMPRESTIMO.\n");
   printf("  02 - DEVOLUCAO.\n");
   printf("  03 - Cadastrar Novo Aluno.\n");
   printf("  04 - Cadastrar Novo Livro.\n");

   printf("\nRelatórios:\n");
   printf("  05 - Emprestimos em atraso.\n");
   printf("  06 - Emprestimo por aluno.\n");
   printf("  07 - Livros por situacao (D/E).\n");

   printf("\n  08 - Geral de Alunos.\n");
   printf("  09 - Geral de Livros.\n");
   printf("  10 - Geral de Emprestimos.\n");
   
   printf("\n  11 - Quantidade de Emprestimos por curso (BCC/ADS/TII).\n");
   printf("  12 - Quantidade de Emprestimos por livro.\n");

   printf("\n13 - Finalizar sessao.\n");

   printf("\nQuantidade de Alunos: %d.\n", tlAlunos);
   printf("Quantidade de Livros: %d.\n", tlLivros);
   printf("Quantidade de Emprestimos: %d.\n", tlEmprestimos);

   printf("\nEscolha uma operacao: ");
   scanf("%d", &opcao);

   return opcao;
};

void devolucao_emprestimo(Aluno alunos[], Livro livros[], Emprestimo emprestimos[], int *tlEmprestimos, int tlAlunos, int tlLivros) {
   setbuf(stdin, NULL);
   system("cls");

   if(tlEmprestimos == 0) {
      printf("Dados insfucientes. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i, tombo, indexTombo, cont;

      for(i=0; i < tlLivros; i++) {
         if(livros[i].situacao == 'E') {
            cont++;
            printf("\n");
            apresenta_livro(livros[i]);
            printf("\n-------------------------------\n");
         }
      }
      if(cont == 0) {
         printf("Nenhum livro disponivel. Aguarde a finalizacao de algum emprestimo.");
         setbuf(stdin, NULL);
         getchar();
      } else {
         int indexEmprestimo;

         do {
            printf("Informe o tombo do livro que deseja devolver: ");
            scanf("%d", &tombo);
            indexTombo = procura_tombo(tombo, livros, tlLivros);
            if(indexTombo == -1) {
               printf("Tombo Invalido. Verifique a lista e escolha novamente.\n");
            }
            if(indexTombo != -1 && livros[indexTombo].situacao == 'D') {
               printf("Nao e possivel devolver um livro que nao foi emprestado. Verifique a lista e escolha novamente.\n");
            }
         } while(indexTombo == -1 || livros[indexTombo].situacao == 'D');

         system("cls");
         setbuf(stdin, NULL);

         indexEmprestimo = procura_emprestimo_pendente_tombo(tombo, emprestimos, *tlEmprestimos);
         apresenta_emprestimo_completo(emprestimos[indexEmprestimo], alunos[procura_prontuario(emprestimos[indexEmprestimo].codigo_aluno , alunos, *tlEmprestimos)], livros[procura_tombo(emprestimos[indexEmprestimo].codigo_livro,livros, tlAlunos)]);

         printf("\n\nDevolver emprestimo [S/N]: ");
         if(getchar() == 'S') {
            emprestimos[indexEmprestimo].situacao = 'F';
            livros[procura_tombo(emprestimos[indexEmprestimo].codigo_livro,livros, tlAlunos)].situacao = 'D';
         };

      }
   }
}


void cadastra_emprestimo(Aluno alunos[], Livro livros[], Emprestimo emprestimos[], int *tlEmprestimos, int tlAlunos, int tlLivros) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlAlunos == 0 || tlEmprestimos == 0) {
      printf("Dados insfucientes. Pressione ENTER para retornar ao menu.\n");
   } else {
      int prontuario, indexAluno, i, tombo, indexTombo, cont = 0;

      for(i=0; i < tlAlunos; i++) {
         printf("\n");
         apresenta_aluno(alunos[i]);
         printf("\n-------------------------------\n");
      }

      do {
         printf("Informe um prontuario valido: PE");
         scanf("%d", &prontuario);

         indexAluno = procura_prontuario(prontuario, alunos, tlAlunos);
         if(indexAluno == -1) {
            printf("Prontuario Invalido. Verifique a lista e escolha novamente.\n");
         }
      } while(indexAluno == -1);

      system("cls");

      for(i=0; i < tlLivros; i++) {
         if(livros[i].situacao == 'D') {
            cont++;
            printf("\n");
            apresenta_livro(livros[i]);
            printf("\n-------------------------------\n");
         }
      }
      if(cont == 0) {
         printf("Nenhum livro disponivel. Aguarde a finalizacao de algum emprestimo.");
         setbuf(stdin, NULL);
         getchar();
      } else {
         do {
            printf("Informe um tombo valido: ");
            scanf("%d", &tombo);

            indexTombo = procura_tombo(tombo, livros, tlLivros);
            if(indexTombo == -1) {
               printf("Tombo Invalido. Verifique a lista e escolha novamente.\n");
            }
            if(indexTombo != -1 && livros[indexTombo].situacao == 'E') {
               printf("Livro emprestado. Verifique a lista e escolha novamente.\n");
            }
         } while(indexAluno == -1 || livros[indexTombo].situacao == 'E');

         system("cls");

         printf("Aluno:\n");
         apresenta_aluno(alunos[indexAluno]);
         printf("\nLivro: \n");
         apresenta_livro(livros[indexTombo]);

         printf("\nInforme o dia do emprestimo: ");
         scanf("%d", &emprestimos[*tlEmprestimos].dia);
         printf("Informe o mes do emprestimo: ");
         scanf("%d", &emprestimos[*tlEmprestimos].mes);

         system("cls");
         emprestimos[*tlEmprestimos].dia_devolucao = emprestimos[*tlEmprestimos].dia + 7;
         if(emprestimos[*tlEmprestimos].dia_devolucao > 30) {
            emprestimos[*tlEmprestimos].dia_devolucao-=30;
            emprestimos[*tlEmprestimos].mes_devolucao = emprestimos[*tlEmprestimos].mes + 1;
         } else {
            emprestimos[*tlEmprestimos].mes_devolucao = emprestimos[*tlEmprestimos].mes;
         }

         printf("Aluno:\n");
         apresenta_aluno(alunos[indexAluno]);
         printf("\nLivro: \n");
         apresenta_livro(livros[indexTombo]);
         printf("\nData do emprestimo: %s%d/%s%d/2020.\n",emprestimos[*tlEmprestimos].dia < 10 ? "0" : "" , emprestimos[*tlEmprestimos].dia, emprestimos[*tlEmprestimos].mes < 10 ? "0" : "", emprestimos[*tlEmprestimos].mes);
         printf("Data de devolucao: %s%d/%s%d/2020.\n",emprestimos[*tlEmprestimos].dia_devolucao < 10 ? "0" : "" , emprestimos[*tlEmprestimos].dia_devolucao, emprestimos[*tlEmprestimos].mes < 10 ? "0" : "", emprestimos[*tlEmprestimos].mes_devolucao);
         printf("\nConfirmar Emprestimo [S/N]:");

         setbuf(stdin, NULL);
         if(getchar() == 'S') {
            emprestimos[*tlEmprestimos].codigo_aluno = prontuario;
            emprestimos[*tlEmprestimos].codigo_livro = tombo;
            emprestimos[*tlEmprestimos].situacao = 'P';
            livros[indexTombo].situacao = 'E';

            *tlEmprestimos+=1;
         }
      }
   }
}

void cadastra_aluno(Aluno alunos[], int *tl) {
   system("cls");
   setbuf(stdin, NULL);

   if (*tl>49) {
      printf("Quantidade maxima de alunos atingida. Reinicie o sistema e tente novamente.\n");
      getchar();
   } else {
      int temp, valido;

      do {
         printf("Informe o prontuario do aluno: ");
         scanf("%d", &temp);

         valido = procura_prontuario(temp, alunos, *tl);
         if(valido != -1) {
            printf("Prontuario duplicado. Verifique e tente novamente.\n");
         }
         // prontuario pode ter no maximo 7 digitos.
         if(temp > 9999999 || temp < 0) {
            printf("Prontuario invalido. Tente novamente.\n");
            valido = 0;
         }
      } while(valido != -1);

      alunos[*tl].prontuario = temp;
      setbuf(stdin, NULL);

      printf("Informe o nome do aluno: ");
      readString(alunos[*tl].nome, 100);
      setbuf(stdin, NULL);
      
      printf("Infome o curso do aluno: ");
      readString(alunos[*tl].curso, 4);
      *tl+= 1;
   }
};

void cadastra_livro(Livro livros[], int *tl) {
   system("cls");
   setbuf(stdin, NULL);

   if (*tl>49) {
      printf("Quantidade maxima de livros atingida. Reinicie o sistema e tente novamente.\n");
      getchar();
   } else {
      int temp, valido;

      do {
         printf("Informe o tombo do livro: ");

         scanf("%d", &temp);

         valido = procura_tombo(temp, livros, *tl);
         if(valido != -1) {
            printf("Tombo duplicado. Verifique e tente novamente.\n");
         }
      } while(valido != -1);
      livros[*tl].tombo = temp;
      setbuf(stdin, NULL);

      printf("Informe o titulo do livro: ");
      readString(livros[*tl].titulo, 100);
      setbuf(stdin, NULL);

      printf("Informe os autores do livro: ");
      readString(livros[*tl].autores, 150);
      setbuf(stdin, NULL);

      printf("Informe o ano de publicacao: ");
      scanf("%d", &livros[*tl].ano);

      livros[*tl].situacao = 'D';      
      
      *tl+= 1;
   }
};

void relatorio_alunos(Aluno alunos[], int tl) {
   system("cls");
   setbuf(stdin, NULL);

   
   if(tl == 0) {
      printf("Nenhum aluno cadastrado. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i;
   
      for(i=0; i < tl; i++) {
         printf("\n");
         apresenta_aluno(alunos[i]);
         printf("\n-------------------------------\n");
      }
   }

   getchar();
}

void relatorio_livros(Livro livros[], int tl) {
   system("cls");
   setbuf(stdin, NULL);
   
   if(tl == 0) {
      printf("Nenhum livro cadastrado. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i;

      for(i=0; i < tl; i++) {
         printf("\n");
         apresenta_livro(livros[i]);
         printf("\n-------------------------------\n");
      }
   }

   getchar();
}

void relatorio_livros_situacao(Livro livros[], int tl) {
   system("cls");
   setbuf(stdin, NULL);
   
   char situacao;
   do {
      printf("Informe uma situacao para buscar (E/D): ");
      scanf(" %c", &situacao);
   } while(!(situacao == 'D' || situacao == 'E'));

   system("cls");
   
   if(tl == 0) {
      printf("Nenhum livro cadastrado. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i;
      printf("Livros com situacao %s (%c).", situacao == 'D' ? "DISPONIVEL" : "EMPRESTADO", situacao);
      for(i=0; i < tl; i++) {
         if(livros[i].situacao == situacao) {
            printf("\n");
            apresenta_livro(livros[i]);
            printf("\n-------------------------------\n");
         }
      }
   }
   setbuf(stdin, NULL);

   getchar();
   getchar();
}

void relatorio_emprestimos(Aluno alunos[], Livro livros[], Emprestimo emprestimos[], int tlEmprestimos, int tlAlunos, int tlLivros) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlEmprestimos == 0) {
      printf("Nenhum livro cadastrado. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i;
      for(i=0; i < tlEmprestimos; i++) {
         printf("\n");
         apresenta_emprestimo_completo(emprestimos[i], alunos[procura_prontuario(emprestimos[i].codigo_aluno , alunos, tlEmprestimos)], livros[procura_tombo(emprestimos[i].codigo_livro,livros, tlAlunos)]);
         printf("\n-------------------------------\n");
      }
   }

   getchar();
};

void emprestimos_por_curso(Emprestimo emprestimos[], int tlEmprestimos, Aluno alunos[], int tlAlunos) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlEmprestimos == 0 || tlAlunos == 0) {
      printf("Dados insuficientes. Pressione ENTER para retornar ao menu.\n");
   } else {
      printf("Quantidade de Emprestimos realizados por curso:\n");
      printf("BCC: %d.\n", calcula_emprestimos_curso(emprestimos, tlEmprestimos, alunos,tlAlunos, "BCC"));
      printf("ADS: %d.\n", calcula_emprestimos_curso(emprestimos, tlEmprestimos, alunos,tlAlunos, "ADS"));
      printf("TII: %d.\n", calcula_emprestimos_curso(emprestimos, tlEmprestimos, alunos,tlAlunos, "TII"));
   }

   getchar();
}

void relatorio_emprestimos_aluno(Aluno alunos[], Livro livros[], Emprestimo emprestimos[], int tlEmprestimos, int tlAlunos, int tlLivros) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlAlunos == 0 || tlEmprestimos == 0) {
      printf("Dados insfucientes. Pressione ENTER para retornar ao menu.\n");
   } else {
      int prontuario, indexAluno, i;

      for(i=0; i < tlAlunos; i++) {
         printf("\n");
         apresenta_aluno(alunos[i]);
         printf("\n-------------------------------\n");
      }

      do {
         printf("Informe um prontuario valido para busca: PE");
         scanf("%d", &prontuario);

         indexAluno = procura_prontuario(prontuario, alunos, tlAlunos);
         if(indexAluno == -1) {
            printf("Prontuario Invalido. Verifique a lista e escolha novamente.\n");
         }
      } while(indexAluno == -1);
      system("cls");
      
      printf("ALUNO:\n");
      apresenta_aluno(alunos[indexAluno]);
      
      printf("\nEMPRESTIMOS:\n");
      for(i=0; i < tlEmprestimos; i++) {
         if(emprestimos[i].codigo_aluno == prontuario) {
            printf("\n");
            printf("LIVRO\n");
            apresenta_livro(livros[procura_tombo(emprestimos[i].codigo_livro, livros, tlLivros)]);
            printf("\nEMPRESTIMO");
            apresenta_emprestimo(emprestimos[i]);
            printf("\n-------------------------------\n");
         }
      }
   }

   getchar();
}

void relatorio_emprestimos_atraso(Aluno alunos[], Livro livros[], Emprestimo emprestimos[], int tlEmprestimos, int tlAlunos, int tlLivros) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlEmprestimos == 0) {
      printf("Nenhum livro cadastrado. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i, dia, mes;

      printf("Informe o dia de hoje: ");
      scanf("%d", &dia);
      printf("Informe o mes de hoje: ");
      scanf("%d", &mes);

      system("cls");

      printf("Emprestimos em atraso a partida da data %s%d/%s%d/2020.\n",dia < 10 ? "0" : "" , dia, mes < 10 ? "0" : "", mes);

      for(i=0; i < tlEmprestimos; i++) {
         if( emprestimos[i].situacao == 'P' && (mes > emprestimos[i].mes_devolucao ||(dia > emprestimos[dia].dia_devolucao && (mes >= emprestimos[i].mes_devolucao)))) {
            printf("\n");
            apresenta_emprestimo_completo(emprestimos[i], alunos[procura_prontuario(emprestimos[i].codigo_aluno , alunos, tlEmprestimos)], livros[procura_tombo(emprestimos[i].codigo_livro,livros, tlAlunos)]);
            printf("\n-------------------------------\n");
         }
      }
   }

   setbuf(stdin, NULL);
   getchar();
};

void emprestimos_por_livro(Emprestimo emprestimos[], int tlEmprestimos, Livro livros[], int tlLivros) {
   system("cls");
   setbuf(stdin, NULL);

   if(tlEmprestimos == 0 || tlLivros == 0) {
      printf("Dados insuficientes. Pressione ENTER para retornar ao menu.\n");
   } else {
      int i;
      printf("Quantidade de Emprestimos realizados por livro:\n");
      for(i=0; i < tlLivros; i++) {
         printf("\n");
         apresenta_livro(livros[i]);
         printf("Quantidade de Emprestimos: %d.\n", quantidade_emprestimos(livros[i].tombo, emprestimos, tlEmprestimos));
         printf("\n-------------------------------\n");
      }
   }

   getchar();
}



int main() {
   int tlAlunos = 6, tlLivros = 5, tlEmprestimos = 9, opcao;
   Aluno alunos[50];
   Livro livros[50];
   Emprestimo emprestimos[100];
   preencher_dados(alunos, livros, emprestimos);


   do {
      opcao = menu(tlAlunos, tlLivros, tlEmprestimos);

      switch(opcao) {
         case 1:
            cadastra_emprestimo(alunos, livros, emprestimos, &tlEmprestimos, tlAlunos, tlLivros);
            break;

         case 2:
            devolucao_emprestimo(alunos, livros, emprestimos, &tlEmprestimos, tlAlunos, tlLivros);
            break;

         case 3:
            cadastra_aluno(alunos, &tlAlunos);
            break;

         case 4:
            cadastra_livro(livros, &tlLivros);
            break;

         case 5:
            relatorio_emprestimos_atraso(alunos, livros, emprestimos, tlEmprestimos, tlAlunos, tlLivros);
            break;

         case 6:
            relatorio_emprestimos_aluno(alunos, livros, emprestimos, tlEmprestimos, tlAlunos, tlLivros);
            break;

         case 7:
            relatorio_livros_situacao(livros, tlLivros);
            break;

         case 8:
            relatorio_alunos(alunos, tlAlunos);
            break;

         case 9:
            relatorio_livros(livros, tlLivros);
            break;

         case 10:
            relatorio_emprestimos(alunos, livros, emprestimos, tlEmprestimos, tlAlunos, tlLivros);
            break;

         case 11:
            emprestimos_por_curso(emprestimos, tlEmprestimos, alunos, tlAlunos);
            break;

         case 12:
            emprestimos_por_livro(emprestimos, tlEmprestimos, livros, tlLivros);
            break;

         case 13:
            printf("Finalizando programa...");
            break;

         default:
            break;
         }      
   } while(opcao != 13);

   return 0;
}
