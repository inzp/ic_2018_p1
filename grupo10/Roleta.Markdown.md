# Título
Jogo da Roleta

# Autores

Trabalho realizado por:
	Hugo Feliciano - a21805809
	Pedro Fernandes  - a21803791


# Descrição da solução

   Para criar este jogo, criámos primeiro uma função _delay_ para atrasar o programa durante _x_ segundos.

   Em seguida, criámos a função principal do jogo, onde estão todas as variáveis e listas do programa. A variável _carteira_, que guarda a quantidade de dinheiro que o jogador tem, é definida como 100.

   Primeiro temos um _loop while_ para jogar, que repete até o jogador decidir que já não quer jogar mais.

   Dentro desse _loop while_, temos outro loop que pergunta qual o nível de dificuldade que o jogador deseja. Quando o jogador define um valor válido, sai do loop.

   Em seguida, temos outro _loop while_ para cada jogada.
   Mostra todas as opções do jogador, que são rolar a bola, mudar de aposta ou levantar o dinheiro e ir para casa.
   
   Só é possível rolar a bola quando a aposta estiver definida. Quando a aposta estiver definida, a bola é lançada, há um delay para efeitos de suspense e depois é revelado onde calha a bola. O dinheiro que o jogador aposta é retirado da variável _carteira_. De acordo com o tipo de aposta do jogador (utilizando _if's_), o programa compara a aposta com o numero que calhou. Se o jogador ganhar, imprime mensagem de vitória e remunera o jogador de acordo com a quantia que apostou e com o sítio onde apostou. Se o jogador perder, imprime uma mensagem de derrota.
   
   O jogador pode também mudar a sua aposta sempre que quiser, o programa pergunta onde o jogador quer jogar e quanto quer apostar. Essas informações são guardadas na variável para serem utilizadas quando o jogador rolar a bola.
   
   Por último, o jogador pode levantar o dinheiro e ir para casa, e o programa imprime uma mensagem de acordo com o dinheiro com que o jogador saiu do jogo.
   
   Quando o dinheiro do jogador foi inferior ao da aposta mínima, o programa pergunta ao jogador se quer jogar novamente. Se sim, as variáveis são reiniciadas para o próximo jogo. Se não, imprime uma mensagem de despedida.

# Conclusões

   Através deste projeto, o grupo foi capaz de por em prática vários dos conhecimentos obtidos em aula. Estes variando entre ciclos _while_ e _for_, comandos como _fgets()_ e _sscan()_ e funções _Time_ e _Random_, concluindo o trabalho com um conhecimento mais detalhado de C e com raciocínio lógico mais apurado, sendo este necessário para programação.

# Referências

   Foi utilizada uma versaõ nossa da função do site _geeksforgeeks_ (link - https://www.geeksforgeeks.org/time-delay-c/) para o delay.

   Não sabíamos como restringir o input a apenas um caractér, e utilizámos as linha de código _#define MAX 256_ e a combinação das linhas _fgets(line, MAX, stdin);_  e _sscanf(line, " %c ", &(variável));_ como sugerido pelo professor Pedro Serra.

