#include "imports.h"

int main() {
   // remove_alunos();
   // update_aluno();
   // recover_aluno();
   // invalidate_aluno();
   // create_aluno();
   // index_alunos();

   // create_livro();
   // index_livros();
   // update_livro();
   // remove_livros();
   // invalidate_livro();
   // recover_livro();
   // filter_livros();

   // create_emprestimo();
   // devolver_emprestimo();
   // index_emprestimos();
   // emprestimos_atraso();
   // emprestimos_aluno();
   // emprestimos_curso();
   // finalizar_emprestimo();
   int opcao;
   do {
      opcao = menu();

      switch(opcao) {
         case 1:
            break;
         case 2:
            create_emprestimo();
            break;
         case 3:
            finalizar_emprestimo();
            break;
         case 4:
            create_aluno();
            break;
         case 5:
            create_livro();
            break;
         case 6:
            update_aluno();
            break;
         case 7:
            invalidate_aluno();
            break;
         case 8:
            index_alunos();
            break;
         case 9:
            show_aluno();
            break;
         case 10:
            recover_aluno();
            break;
         case 11:
            remove_alunos();
            break;

         case 12:
            update_livro();
            break;
         case 13:
            invalidate_livro();
            break;
         case 14:
            index_livros();
            break;
         case 15:
            show_livro();
            break;
         case 16:
            filter_livros();
            break;
         case 17:
            recover_livro();
            break;
         case 18:
            remove_livros();
            break;
            
         case 19:
            emprestimos_aluno();
            break;
         case 20:
            emprestimos_curso();
            break;
         case 21:
            emprestimos_livro();
            break;
         case 22:
            printf("\nFinalizando o sistema...");
            break;
         default:
            printf("\n Opção inválida, tente novamente.");
            break;
      }
   } while (opcao != 22); 

   return 0;
}
