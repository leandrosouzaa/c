# Lista da Semana 18/01/2021

- [x] 1. Fazer um programa em linguagem C capaz de receber por linha de comando o nome de um arquivo e seja capaz de apresentar um relatório contendo os seguintes dados:
```
Quantidade de linhas..............: 
Quantidade de dígitos.............:
Quantidade de caracteres..........:
Quantidade de espaços em branco...:
````
- [x] 2. Fazer um programa em linguagem C que receba por linha de comando o nome de um arquivo texto e seja capaz de gerar um outro arquivo que deverá conter os dados do arquivo anterior, porém eliminando os espaços em branco.

- [x] 3. Fazer um programa que receba por linha de comando 3 nomes de arquivos, onde os dois primeiros devem existir e terceiro deve ser criado a partir da união dos dois primeiros, ou seja, o arquivo criado deve ter todo o conteúdo o primeiro arquivo seguido do conteúdo do segundo arquivo.

- [x] 4. Fazer um programa de "bagunçar a coisa toda" e seja capaz de receber o nome de um arquivo texto e gerar um segundo arquivo todo bagunçado trocando:  a por x,  x por a, e por s, s por e, r por i, i por r, o por g e g por o.

- [x] 5. "Criptografar um arquivo texto" capaz de pegar cada um dos caracteres ASCII do arquivo original e adicionar o valor inteiro 28 a esses caracteres e salvar em um novo arquivo.

- [x] 6. Fazer um programa em C capaz de receber um arquivo criptografado pelo algoritmo do exercício 5 e seja capaz de apresentar seu conteúdo como era inicialmente.

- [x] 7. Fazer um programa em C que receba como linha de comando um nome de arquivo de CSS e seja capaz de apresentar todos os estilos definidos nesse arquivo. Abaixo é apresentado um arquivo CSS.
```
body {
    background-color: darkslategrey;
    color: azure;
    font-size: 1.1em;
}
h1 {
    color: coral;
}
#intro {
    font-size: 1.3em;
}
.colorful {
    color: orange;
}
```
Para a resolução desse problema considere que as regras de estilo estão sempre no início da linha. As regras que não iniciam por ponto (.) ou hashtag (#) são redefinições de TAGs do HTML, as iniciadas por ponto são classes e as iniciadas por hashtag são regras de identificadores.

Como saída o programa deverá apresentar a quantidade de regras existentes, apresentar todas as regras e o tipo delas.

- [x] 8. Fazer um programa em linguagem C capaz de ler um arquivo texto existente e criar um novo arquivo, colocando no novo arquivo as palavras do arquivo antigo, uma palavra em cada linha, ou seja, após o término de cada palavra inserir um salto de linha. Ao final do processamento deve-se apresentar a quantidade de palavras existente no novo arquivo.
