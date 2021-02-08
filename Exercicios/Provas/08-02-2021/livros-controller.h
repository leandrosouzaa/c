void index_livros() {
   int limpa;
   system("clear");
   print_header("RELATÓRIO DE LIVROS");

   int i = list_livros('A','T');

   if(i==0) {
      printf("Não existem livros para serem listados.\n");
   }

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

void create_livro() {
   system("clear");
   print_header("REGISTRO DE LIVROS");

   Livro livro = read_livro(NULL);
   save_livro(livro);
}

void filter_livros() {
   int limpa;
   char type;

   system("clear");
   print_header("RELATÓRIO DE LIVROS");

   printf("Selecione um tipo para ser listado: \n");
   printf("D - Disponível\n");
   printf("E - Emprestado\n");
   printf("Tipo desejado: ");
   scanf("%c", &type);

   system("clear");
   type == 'D' ? print_header("RELATÓRIO DE LIVROS DISPONIVEIS") : print_header("RELATORIO DE LIVROS EMPRESTADOS");
   

   int i = list_livros('A',type);

   if(i==0) {
      printf("Não existem livros para serem listados.\n");
   }

   printf("Pressione Enter para continuar...");
   
   setbuf(stdin, NULL);
   getchar();
}

// void invalidate_aluno() {
//    system("clear");
//    print_header("REMOCAO DE ALUNOS");
//    int pront;

//    int i = list_alunos('A');
//    if(i==0) {
//       printf("Não existem alunos para serem excluidos.\n");         
//       printf("\nPressione Enter para continuar...");

//       setbuf(stdin, NULL);
//       getchar();
      
//    } else {
//       printf("\nProntuario para exclusao: PE");
//       scanf("%d", &pront);

//       int index = find_by_pront(pront);

//       system("clear");
//       if(index == -1) {
//          printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
//          printf("\nPressione Enter para continuar...");

//          setbuf(stdin, NULL);
//          getchar();

//       } else {
//          Aluno aluno = find_by_index(index);

//          if(aluno.status != 'A') {
//             printf("Este Aluno ja foi desativado. Para excluir da base de dados volte ao menu e escolha a opcao REMOCAO FISICA.\n");
//             printf("Pressione enter para continuar.");
//             getchar();
//          } else {
//             printf("ALUNO ENCONTRADO:\n\n");
//             printf("Prontuario..: PE%d.\n",aluno.prontuario);
//             printf("Nome........: %s.\n", aluno.nome);
//             printf("Curso.......: %s.\n", aluno.curso);

//             printf("\nExcluir aluno [S/N]: ");
//             char continua;

//             scanf(" %c", &continua);

//             if(continua == 'S') {
//                update_status(index, 'I');
//             }
//          }
//       }
//    }
// }

// void show_aluno() {
//    system("clear");
//    printf("BUSCA DE ALUNO POR PRONTUÁRIO\n\n");
//    int pront;

//    printf("Prontuário para busca: PE");
//    scanf("%d", &pront);

//    int index = find_by_pront(pront);

//    system("clear");
//    if(index == -1) {
//       printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
//       printf("Pressione Enter para continuar...");

//    } else {
//       Aluno aluno = find_by_index(index);

//       printf("ALUNO ENCONTRADO:\n\n");
//       printf("Prontuario..: PE%d.\n",aluno.prontuario);
//       printf("Nome........: %s.\n", aluno.nome);
//       printf("Curso.......: %s.\n", aluno.curso);
      
//    }

//    getchar();
//    getchar();
// }

// void recover_aluno() {
//    system("clear");

//    print_header("RECUPERACAO DE ALUNOS");

//    printf("Alunos disponiveis:\n");
//    int i = list_alunos('I');

//    if(i != 0) {
//       int pront;

//       printf("Prontuario para recuperacao: PE");
//       scanf("%d", &pront);

//       int index = find_by_pront(pront);

//       system("clear");
//       if(index == -1) {
//          printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
//          printf("Pressione Enter para continuar...");

//          setbuf(stdin, NULL);
//          getchar();
//       } else {
//          Aluno aluno = find_by_index(index);

//          if(aluno.status != 'I') {
//             printf("Este Aluno não está desativado. Para desativar volte ao menu e escolha a opcao REMOVER ALUNO.\n");
//          } else {
//             printf("ALUNO ENCONTRADO:\n\n");
//             printf("Prontuario..: PE%d.\n",aluno.prontuario);
//             printf("Nome........: %s.\n", aluno.nome);
//             printf("Curso.......: %s.\n", aluno.curso);

//             printf("\nReativar aluno [S/N]: ");
//             char continua;

//             scanf(" %c", &continua);

//             if(continua == 'S') {
//                update_status(index, 'A');
//             }
//          }
//       }
//    } else {
//       printf("Não existem alunos para serem recuperados.\n");
//       printf("\nPressione Enter para continuar...");

//       setbuf(stdin, NULL);
//       getchar();
//    }
// }

// void update_aluno() {
//    system("clear");
//    print_header("ATUALIZACAO DE ALUNOS");

//    printf("Alunos disponiveis:\n");
//    int i = list_alunos('A');

//    if(i==0) {
//       printf("Não existem alunos para serem atualizados.\n");
//       printf("\nPressione Enter para continuar...");

//       getchar();
//    } else {
//       int pront;

//       printf("Prontuario para atualizacao: PE");
//       scanf("%d", &pront);

//       int index = find_by_pront(pront);

//       system("clear");
//       if(index == -1) {
//          printf("Não foi encontrado nenhum aluno com o prontuario PE%d.\n", pront);
//          printf("\nPressione Enter para continuar...");

//          setbuf(stdin, NULL);
//          getchar();
//       } else {
//          Aluno aluno = find_by_index(index);

//          if(aluno.status != 'A') {
//             printf("Este Aluno esta desativado. Para atualizar os dados do mesmo reative o registro na opcao de RECUPERACAO.\n");
//             printf("\nPressione Enter para continuar...");

//             setbuf(stdin, NULL);
//             getchar();
//          } else {
//             printf("ALUNO ENCONTRADO:\n\n");
//             printf("Prontuario..: PE%d.\n",aluno.prontuario);
//             printf("Nome........: %s.\n", aluno.nome);
//             printf("Curso.......: %s.\n", aluno.curso);

//             printf("\nAtualizar aluno[S/N]: ");
//             char continua;

//             scanf(" %c", &continua);

//             if(continua == 'S') {
//                system("clear");
//                printf("ATUALIZACAO DE ALUNO\n\n");
//                aluno = read_aluno(aluno.prontuario);
//                save_update_aluno(index, aluno);
//             }
//          }
//       }
//    }
// }

// void remove_alunos() {
//    system("clear");

//    print_header("EXCLUSAO DE ALUNOS");

//    int i = list_alunos('I');

//    char continua;
//    printf("\nDeseja realmente excluir DEFINITVAMENTE esses registros [S/N]: ");
//    scanf(" %c", &continua);

//    if(continua == 'S') {
//       clear_alunos();
//    }
// }