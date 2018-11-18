# Primeiro Trabalho

**Jogo da Roleta**

André Cunha, nº 21803907

Bernardo Baltazar, nº 21804153

```
Descriçao da soluçao
```

Começamos por criar funçôes que definiriam o tipo de aposta (par,impar,numero), como também o valor da aposta do jogador
Ao iniciar a funçao main ,esta terá já variáveis definidas como a quantidade de dinheiro (100 euros) e o numero que irá calhar na roleta, que se trata de uma variável com funçao random de 0 a 36. Main está maioritariamente dentro de um while que irá manter o jogador dentro do jogo até o mesmo decidir sair. De seguida, criámos no algoritmo uma maneira de identificar se o numero que calhou (random) foi par ou impar com a condiçao (numero%2==0), assim saberiamos quando era par: par_impar= 'p'. E quando era impar: par:impar='i', com estes char's conseguiriamos assim comunicar com o menu caso o jogador escolhesse a opçao par(p) ou impar (i).

A seguir estabelecemos 3 caminhos para o codigo:

- Se o tipo de aposta fosse apostar num numero de 1 a 36
- Ou entao se o tipo de aposta entre par ou impar correspondesse com o numero aleatório (tipo de aposta em char==numero aleatoria par ou impar em char)
- por fim se nao entrasse em nenhum desses caminhos significava que o jogador perdiria aquela rodada de jogo

No final de cada rodada verificamos se a variável da montante de dinheiro está a 0 ,pois nesse caso era automaticamente Game over e o programa terminava ,se a montante ainda fosse superior a 0 perguntariamos ao jogador se quer continuar a jogar, dando lhe a escolha de sair do jogo ou permanecer o programa ativo
```
Conclusões e matéria aprendida
```
Com este projeto concluímos que quando se trata de um jogo cria-se muito a noçao de um ciclo e a interatividade do programa obriga a repetiçao de muito codigo por isso é bastante util a utilizaçao de várias funçoes atribuidas a especificas execuções, como por exemplo a criaçao do menu de opçoes de aposta cada vez que inicia um nova rodada, ou cada vez que é pedido a quantia para apostar
Consolidámos conhecimentos da linguagem em uso e da utilizaçao da consola terminal
```
Referências
```
Bibliotecas:

- stdio
- time
- stdlib
- unistd

Este trabalho permitiu bastante interatividade entres os dois autores do mesmo, tudo criado em conjunto debantendo ideias e soluçoes para o problema.
Como utensilio de procura utilizamos os slides das aulas disponiveis no moodle da universidade.