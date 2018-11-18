# 1º Projeto de introdução à computação 2018/2019
## Autores:
- Carolina Bastos, Nºa21802579;
- Henrique Antunes, Nºa21803297.
## Solução:
1.Teste:

- Definiram-se as variáveis de início, para uma visualização mais fácil das mesmas. Na função "int main()" encontra-se o menu, onde se define as opções e teclas para jogar sendo que "int escolher_opcao()" é o código que "lê" a opção selecionada pelo jogador.

- Para a dificuldade utilizou-se um ciclo onde o jogador escolhe uma letra, e dependendo da letra, retorna-se um valor a "opcao".

- Para limitar o jogador nas apostas utiliza-se condições simples, comparando as variáveis correspondentes ao dinheiro que o jogador tem e a dificuldade que escolheu, se passar os requerimentos o código demonstra ao jogador o que está a apostar.

- A função "void tensao()" é um temporizador que faz aparecer reticências, só para um pouco mais de realismo.

- Para as apostas utilizou-se um "scanf" para guardar o número inteiro e uma condição para definir o limite entre 0 a 36, que são as casas apostáveis. 

- Na função "int escolha_num()" encontra-se a matemática do jogo no caso em que se aposte numa casa, utilizando condições para definir quando se perde ou se ganha e redefinindo os valores dentro da variável "balance". 

- Em "unsigned short par(int number) define-se o que é um número par para o computador e em "unsigned short impar(int number)" define-se o que é um número ímpar.

- Então se o jogador escolher par o computador corre a função "int escolha_par()" que utiliza as mesmas variáveis do início e uma condição para aplicar as contas. Se o jogador escolher ímpar o código é similar, trocando as condições de vitória.

- No fim está definida a variável utilizada na aposta de uma casa específica, utilizando um temporizador (Novamente só para realismo) e um número aleatório, que será mostrado no ecrã e atribuído à variável "int rolar()".

2.Extras:

- Implementação dos três níveis de dificuldade;
- Implementação de um temporizador que atrase a obtenção dos números para o realismo;
- Tentativa da correta utilização do Git. 



## Conclusões e matéria aprendida:
### Conclusões:
- Trabalho com premissa simples mas dificuldade de resolução apropriada.
### Matéria aprendida:
- Funções, ciclos, arrays, variáveis globais, git e Markdown simples.
## Referências
- No chat de turma perguntou-se aos colegas como tornar o código mais eficiente, além de certas dúvidas sobre ideias mais específicas de como criar um menu.
- Utilização das seguintes bibliotecas: "<stdio.h>,<time.h>,<stdlib.h>,<unistd.g>".  




