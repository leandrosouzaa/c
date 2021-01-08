# Lista da Semana 24/08/2020

- [x] 1. Fazer um programa capaz de implementar um boletim escolar, onde cada uma das disciplinas de um aluno deverá conter: nome, nota1, nota2 e frequencia. Os alunos não tem mais que 10 disciplinas, porém podem ter 4, ou 5, dessa forma será necessário controlar a quantidade de registros utilizados. Considerando essas informações o programa deverá fazer:
  - Incluir disciplinas;
  - Apresentar o boletim, com todas as disciplinas, suas notas e frequência, como também a média aritmética do aluno nessas disciplinas e a situação do mesmo, podendo ser: Aprovado, Retido por Nota ou Retido por faltas; No final do boletim deve-se apresentar a média global do aluno.
  - Localizar uma determinada disciplina e apresentar os dados da mesma;
  - Apresentar a disciplina com a menor nota;
  - Apresentar a disciplina com  a maior nota;
  - Apresentar as disciplinas com  aprovação.
Obs. Implementar um menu, que permita ao usuário selecionar uma dessas opções, seria importante a implementação de uma função para preenche a tabela de disciplinas com dados iniciais. 
Obs2. Em vários locais é necessária a apresentação dos dados de uma disciplina, poderia ser implementada uma função para isso, onde é passada um registro como parâmetro.

- [x] 1. O Bar do Zé precisa de um controle dos produtos e seus respectivos fornecedores para poder realizar suas compras. O Zé, proprietário do bar, fez uma tabela no excel com o seguinte formato:

Produto
         <table>
          <tr>
           <td>Nome do Produto</td>
           <td>Nome do Fornecedor</td>
           <td>Telefone de Contato</td>
           <td>Preço</td>
           <td>Quant. Estoque</td>
           <td>Quant. Mínima</td>
          </tr>
          <tr>
           <td>Cerveja Antartica</td>
           <td>Ambev</td>
           <td>(18) 99887-9876</td>
           <td>8,5</td>
           <td>48</td>
           <td>24</td>
          </tr>
          <tr>
           <td>Cerveja Brahma</td>
           <td>Ambev</td>
           <td>(18) 99887-9876</td>
           <td>9,0</td>
           <td>15</td>
           <td>30</td>
          </tr>
          <tr>
           <td>Guarana Antartica</td>
           <td>Ambev</td>
           <td>(18) 99887-9876</td>
           <td>6,5</td>
           <td>12</td>
           <td>6</td>
          </tr>
          <tr>
           <td>Coca-cola 1l</td>
           <td>Femsa</td>
           <td>(18) 99111-3211</td>
           <td>6,0</td>
           <td>25</td>
           <td>12</td>
          </tr>
          <tr>
           <td>Fanta Uva 290ml</td>
           <td>Femsa</td>
           <td>(18) 99111-3211</td>
           <td>3,5</td>
           <td>3</td>
           <td>10</td>
          </tr>
          <tr>
           <td>Cerveja Bavária lata</td>
           <td>Femsa</td>
           <td>(18) 99111-3211</td>
           <td>8,5</td>
           <td>48</td>
           <td>6</td>
          </tr>
          <tr>
           <td>Água mineral 500ml</td>
           <td>Lindoya</td>
           <td>(18) 98352-1121</td>
           <td>2,5</td>
           <td>24</td>
           <td>10</td>
          </tr>
          <tr>
           <td></td>
           <td></td>
           <td></td>
           <td></td>
           <td></td>
           <td></td>
          </tr>
         </table>
O Zé, dono do bar, é um exímio otimizados de dados, e resolveu retirar as repetições de dados, dessa formar ele separou essa tabela em duas outras:

         <table>
          <tr>
           <td>Nome do Produto</td>
           <td>Código Fornecedor</td>
           <td>Preço</td>
           <td>Quant. Estoque</td>
           <td>Quant. Mínima</td>
          </tr>
          <tr>
           <td>Cerveja Antartica</td>
           <td>1</td>
           <td>8,5</td>
           <td>48</td>
           <td>24</td>
          </tr>
          <tr>
           <td>Cerveja Brahma</td>
           <td>1</td>
           <td>9,0</td>
           <td>15</td>
           <td>30</td>
          </tr>
          <tr>
           <td>Guarana Antartica</td>
           <td>1</td>
           <td>6,5</td>
           <td>12</td>
           <td>6</td>
          </tr>
          <tr>
           <td>Coca-cola 1l</td>
           <td>2</td>
           <td>6,0</td>
           <td>25</td>
           <td>12</td>
          </tr>
          <tr>
           <td>Fanta Uva 290ml</td>
           <td>2</td>
           <td>3,5</td>
           <td>3</td>
           <td>10</td>
          </tr>
          <tr>
           <td>Cerveja Bavária lata</td>
           <td>2</td>
           <td>8,5</td>
           <td>48</td>
           <td>6</td>
          </tr>
          <tr>
           <td>Água mineral 500ml</td>
           <td>3</td>
           <td>2,5</td>
           <td>24</td>
           <td>10</td>
          </tr>
         </table>
Fornecedor
         <table>
          <tr>
           <td>Código Fornecedor</td>
           <td>Nome do Fornecedor</td>
           <td>Telefone de Contato</td>
          </tr>
          <tr>
           <td>1</td>
           <td>Ambev</td>
           <td>(18) 99887-9876</td>
          </tr>
          <tr>
           <td>2</td>
           <td>Femsa</td>
           <td>(18) 99111-3211</td>
          </tr>
          <tr>
           <td>3</td>
           <td>Lindoya</td>
           <td>(18) 98352-1121</td>
          </tr>
         </table>
Com essa nova configuração dos seus dados, o Zé gostaria de:

  - Preencher as tabelas com esses dados;
  - Incluir novos produtos, somente para os fornecedores cadastrados;
  - Apresentar todos os produtos, com o preço e a quantidade;
  - Apresentar todos os produtos com os respectivos fornecedores;
  - Apresentar todos os produtos de um fornecedor;
  - Apresentar todos os produtos com estoque baixo;
  - Pesquisar por um produto e apresentar todos os dados desse produto com os dados do fornecedor desse produtos;
  - Apresentar o balanço de estoque, onde deverá ser apresentado o total em dinheiro de cada produto e o valor total do estoque.
