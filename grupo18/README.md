# Gather around my friends this is a roulette for IC.


# **IC: Projeto Roleta**
## Trabalho Realizado por: Rodrigo Pinheiro_a21802488 e Tomás Franco_a21803301.
#### [Repositório do github](https://github.com/RodrigoPrinheiro/IC_Roleta).
### Solução
  + Ao início, como queriamos aprender melhor como trabalhar com o git, procurámos dar setup do repositório que usámos do github. Dávamos update a partir do [gitbash](https://help.github.com/articles/adding-an-existing-project-to-github-using-the-command-line/) utilizando uma pasta local .git. Após termos isto resolvido, acabámos por simplesmente dar merge no master branch sempre que tinhamos algo novo de relevante no código.
  + Grande parte do trabalho foi entender que funções é que eram mesmo necessárias ou utéis ter e separar do que facilmente pode ser feito e implementado na função main().
  + Separar o código principal das funções usadas com mais um ficheiro .c
  + implementação da nossa propria header file (func_roleta.h) para usarmos no arroz.c. Isto foi alcançado pela informação que tinhamos das aulas e uma pequena ajuda do [StackOverflow](https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c).
  + Criação de um sistema para gravar o dinheiro ganho num jogo anterior, podendo fechar e abrir o programa, e partir de um ficheiro extra e com o uso das funcoes fprintf, fscanf, fopen e fclose, carregar o dinheiro ganho numa sessão anterior. Visto que não foi matéria dada usamos o site [Learn C](https://www.programiz.com/c-programming/c-file-input-output) para este feature.
  + Como queriamos uma roleta o mais real possivel adicionamos as escolhas de cor (preto e vermelho), fizemos esta opcao com o uso de 2 arrays red e black contendo os numeros correspondentes as cores para comprar o valor que saía do rollr().
#### Solução Código
  + A nossa roleta nao usa quaisqueres variaveis globais sendo as necessárias declaradas dentro da função main(). Temos um vetor com 5 posições para solucionarmos as escolhas e guardarmo-las todas na mesma variável. Após a declaração das variaveis chamamos a função Start() para apresentar o jogo ao jogador e de seguida apresenta uma prompt para se desejar carregar algum jogo guardado anteriormente com uma simples pergunta de sim/nao. Depois de importar as informações de créditos da ultima vez que se jogou (se assim o jogador desejou), a roleta pergunta para selecionar a dificuldade do jogo, isto depois de carregar a save file para nao bloquear o jogador na sua dificuldade antiga. Só depois deste início é que chamamos a comand_list() a mostrar os créditos do jogador e todos os comandos necessários para jogar ao jogo, esta função é diferente da help() poís tambem mostra os créditos do jogador.
  + Após a parte introdutória do jogo, o código entra no loop principal (formado com um while de condição créditos > 0) em que damos scan do input principal do jogador (caracteres correspondentes às escolhas principais). Entrando numa condição switch asseguir para pedir o input do correspondente ao escolhido anteriormente (dinheiro, numero a apostar).
  + O jogador tem duas formas de sair do jogo, durante as escolhas pode carregar 'l' que saira do programa apos 2 segundos ou perder todos os seus creditos que irá dár print de uma mensagem esperar 2 segundos e sair do programa.

### Referencias
##### Bibliotecas usadas
+ As bibliotecas utilizadas foram o <stdio.h>, <time.h> e <stdlib.h>.
##### Competencias
+ Como jogar Roleta.
+ Melhor percepção do que é programar em equipa.
+ Mais conhecimentos gerais sobre C e bases de git(push, pull etc...).
+ Familiarização com a consola Ubuntu.
+ Criação de "save files" para variaveis no jogo.
+ Aprendemos a usar o goto e labels durante um switch.

##### Troca de Ideias
+ É um jogo de roleta, tens um aviso no inicio a dar os controlos (comand_list()) e de seguida o jogo vai te pedir oque queres fazer, de acordo com esses controlos, após inserires um valor para apostar com a opcao b podes escolher um nr para apostar e depois disso podes dar roll para saberes se ganhaste ou não.
+ Tudo em comandos separados.
+ O even e o odd sao controlos que nao precisas de escolher qual é o nr em que apostas especificamente (o mesmo se aplica as cores RED e BLACK), mas tens de pedir para dar roll posteriormente de escolheres essas opcoes.
Depois o jogo fica num loop em que pede os controlos do jogador e da a resposta adequada ATÉ ficar sem dinheiro ou selecionar a opcao s(sair) para sair do jogo.
+ Houve troca de ideias entre o nosso grupo e o aluno João David do mesmo turno para a criação correta das funções save_game() e load_game()
