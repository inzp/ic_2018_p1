#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 256

//Cria função delay que atrasa o proximo output durante x segundos
void delay(int segundos)
{
    int milisegundos = 1000 * segundos;

    clock_t inicio = clock();

    while (clock() < inicio + milisegundos){}
}

int main()
{
    //Declara as variáveis necessárias
    int i;
    int jogar = 1;
    int sair = 0;
    int reiniciar = 0;
    int carteira = 100;
    int valorAposta = 0;
    int tipoAposta = 0;
    int valido = 0;
    int acertou = 0;
    int carteiraDisplay;
    int apostaNumeros;
    int numero;
    int ganho;
    int apostaMinima;
    int lucro;
    int imprimirAposta;
    char opcao;
    char dificuldade;
    char novamente;
    char line[MAX];
    char *apostaDisplay;

    //Cria arrays com os valores das apostas nas cores e nas colunas
    int vermelho[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int preto[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    int coluna1[12] = {1,4,7,10,13,16,19,22,25,28,31,34};
    int coluna2[12] = {2,5,8,11,14,17,20,23,26,29,32,35};
    int coluna3[12] = {3,6,9,12,15,18,21,24,27,30,33,36};

    //Necessario para o random
    srand(time(NULL));

    //Loop que define quando o jogo esta a decorrer
    while(jogar == 1)
    {
        //Mensagem de boas vindas quando o programa corre pela primeira vez
        if(reiniciar == 0)
        {
            printf("\nBem vindo ao casino da Lusofuna! Vem jogar roleta!\n\n");
        }
        //Mensagem de boas vindaas quando o jogador decide jogar novamente
        else if(reiniciar == 1)
        {
            for (i = 0; i < 1; i++)
            {
                delay(1);
            }
            printf("\n\nIsso e que e determinacao, bem vindo de volta!\n\n");

            for (i = 0; i < 1; i++)
            {
                delay(1);
            }
        }

        //O utilizador define a dificuldade
        printf("\nEscolhe a alinea que melhor te descreve: Sou ............ a jogar roleta?:\n");
        printf("a) um iniciante\n");
        printf("b) experiente\n");
        printf("c) uma lenda\n\n");
        printf("Resposta: ");

        //Todos os while(valido == 0) servem para restringir o input do utilizador
        while(valido == 0)
        {
            fgets(line, MAX, stdin);
            sscanf(line, " %c ", &dificuldade);

            if(dificuldade == 'a')
            {
                valido = 1;
                apostaMinima = 1;
            }
            else if(dificuldade == 'b')
            {
                valido = 1;
                apostaMinima = 10;
              }
            else if(dificuldade == 'c')
            {
                valido = 1;
                apostaMinima = 20;
            }
            else
            {
                printf("Escolhe uma alinea valida.(a, b ou c) ");
            }
        }
        //Reinicia a validade para entrar no proximo loop
        valido = 0;

        printf("\nMuito bem...");

        //introduz um delay de 3 segundos para efeitos visuais
        for (i = 0; i < 1; i++)
        {
            delay(3);
        }

        printf("\n\nAposta minima definida: %deur\n", apostaMinima);

        //Loop de cada acao do jogaor, que corre ate ao jogador sair ou tiver menos que a aposta minima
        while(carteira >= apostaMinima && sair != 1)
        {
            carteiraDisplay = carteira - valorAposta;

            //introduz um delay para efeitos visuais
            for (i = 0; i < 1; i++)
            {
                delay(2);
            }

            //Imprime o dinheiro do jogador de acordo com a situacao
            if(valorAposta != 0 && carteiraDisplay >= 0)
            {
                printf("\n\nDinheiro: %deur na carteira + %deur na mesa (%deur no total)\n", carteiraDisplay, valorAposta, carteira);
            }
            else if (valorAposta != 0 && carteiraDisplay < 0)
            {
                imprimirAposta = 0;
                printf("\n\nDinheiro: %deur na carteira\n", carteira);
                printf("Nao tens dinheiro suficiente para fazeres uma aposta igual a ultima. Muda la isso...\n");
            }
            else if(valorAposta == 0)
            {
                printf("\n\nDinheiro: %deur na carteira\n", carteira);
            }

            //Imprime a aposta atual do jogador se ele tiver apostado num numero
            if(imprimirAposta == 1)
            {
                printf("Aposta atual (na mesa): %deur %s\n\n", valorAposta, apostaDisplay);
            }
            //Imprime a aposta atual do jogador se ele tiver nao tiver apostado num numero
            else if(imprimirAposta == 2)
            {
                printf("Aposta atual (na mesa): %deur no numero %d\n\n", valorAposta, apostaNumeros);
            }
            //Imprime se o jogador ainda nao tiver colocado uma aposta
            else
            {
                printf("Aposta atual: (nao definida)\n\n");
            }

            //Imprime as opcoes de jogada
            printf("Neste momento, podes:\n");
            printf("\tr - Rolar a bola\n");
            printf("\tm - Mudar aposta (a aposta vai ficar a mesma ate a mudares ou ate nao");
            printf("\t                          teres dinheiro suficiente para apostar esse valor)\n\n");
            printf("\tl - Levantar o dinheiro e sair do casino\n\n");
            printf("O que queres fazer? ");

            //Loop para validar input das opcoes
            while(valido == 0)
            {
                fgets(line, MAX, stdin);
                sscanf(line, " %c ", &opcao);

                //Se o jogador quiser rolar a bola
                if(opcao == 'r')
                {
                    valido = 1;

                    //Quando o jogador ainda não tem a aposta definida
                    if(valorAposta == 0 || imprimirAposta == 0)
                    {
                        printf("\nTens que definir uma aposta primeiro...\n\n");
                    }

                    //Quando a aposta já está definida
                    else if(valorAposta >=apostaMinima && valorAposta <= carteira)
                    {
                        carteira -= valorAposta;

                        //Seleciona um numero aleatorio entre 0 e 36 (inclusive)
                        for(i=0; i < 1; i++)
                        {
                            numero = (rand()% 37);
                        }

                        //Conjunto de mensagens e loops para efeitos de suspanse
                        printf("\n\nA bola e lancada.");

                        for(i = 0; i < 2; i++)
                        {
                            delay(1);
                            printf(".");
                        }

                        printf("Trocam-se olhares na mesa.");

                        for(i = 0; i < 3; i++)
                        {
                            delay(1);
                            printf(".");
                        }

                        //Imprime o numero que saiu
                        printf("\n\n\n---------------------------\n");
                        printf(" A bola caiu no numero %d!\n", numero);
                        printf("---------------------------\n\n\n");

                        acertou = 0;

                        //Quando sai zero
                        if(numero == 0)
                        {
                            printf("Pouca sorte, calhou o numero 0. Ninguem ganha nada!\n\n\n");
                        }
                        //Quando nao sai zero
                        else
                        {
                            //Define se o jogador acertou ou nao no numero
                            if(tipoAposta == 1)
                            {
                                if(numero == apostaNumeros)
                                {
                                    ganho = valorAposta * 36;
                                    carteira += ganho;
                                    printf("Quem diria, conseguiste acertar no numero... Ganhaste %deur.\n\n\n", ganho);
                                }
                                else
                                {
                                    printf("Nope, nao saiu o numero %d, perdeste %deur.\n\n\n", apostaNumeros, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não num numero vermelho
                            else if(tipoAposta == 2)
                            {
                                //Loop para verificar se o numero que calhou pertence à lista dos numeros vermelhos
                                for(i = 0 ; i < 17 ; i++)
                                {
                                    if (numero == vermelho[i])
                                    {
                                        acertou = 1;
                                    }
                                }
                                if (acertou ==1)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Que bom para ti, o %d e vermelho... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Ai que pena, saiu preto. Perdeste %deur.\n\n\n", valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não num numero preto
                            else if(tipoAposta == 3)
                            {
                                //Loop para verificar se o numero que calhou pertence à lista dos numeros pretos
                                for(i = 0 ; i < 17 ; i++)
                                {
                                    if (numero == preto[i])
                                    {
                                        acertou = 1;
                                    }
                                }
                                if (acertou ==1)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Que bom para ti, o %d e preto... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Ai que pena, saiu vermelho. Perdeste %deur.\n\n\n", valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não num numero par
                            else if(tipoAposta == 4)
                            {
                                if(numero % 2 == 0)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Sorte de principiante, o numero %d e par... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Ouch, nao sei se recuperas dessa. O numero %d e impar, perdeste %deur.\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não num numero impar
                            else if(tipoAposta == 5)
                            {
                                if(numero % 2 == 1)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Sorte de principiante, o numero %d e impar... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Ouch, nao sei se recuperas dessa. O numero %d e par, perdeste %deur.\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na primeira metade
                            else if(tipoAposta == 6)
                            {
                                if(numero < 19)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Wow, o numero %d esta na primeira metade... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("O numero %d esta na segunda metade, perdeste %deur. Na proxima acertas.\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na segunda metade
                            else if(tipoAposta == 7)
                            {
                                if(numero > 18 && numero < 37)
                                {
                                    ganho = valorAposta * 2;
                                    carteira += ganho;
                                    printf("Wow, o numero %d esta na segunda metade... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("O numero %d esta na primeira metade, perdeste %deur. Na proxima acertas.\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na primeira duzia
                            else if(tipoAposta == 8)
                            {
                                if(numero < 13)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Tiveste sorte, o numero %d está na primeira duzia... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else if(numero > 12 && numero < 25)
                                {
                                    printf("O numero %d esta na segunda duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                                else
                                {
                                    printf("O numero %d esta na terceira duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na segunda duzia
                            else if(tipoAposta == 9)
                            {
                                if(numero > 12 && numero < 25)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Tiveste sorte, o numero %d está na segunda duzia... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else if(numero < 13)
                                {
                                    printf("O numero %d esta na primeira duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                                else
                                {
                                    printf("O numero %d esta na terceira duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na terceira duzia
                            else if(tipoAposta == 10)
                            {
                                if(numero > 24 && numero < 37)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Tiveste sorte, o numero %d está na terceira duzia... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else if(numero < 13)
                                {
                                    printf("O numero %d esta na primeira duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                                else
                                {
                                    printf("O numero %d esta na segunda duzia, perdeste %deur. Oof...\n\n\n", numero, valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na primeira coluna
                            else if(tipoAposta == 11)
                            {
                                //Loop para verificar se o numero que calhou pertence à lista dos numeros da primeira coluna
                                for(i = 0 ; i < 17 ; i++)
                                {
                                    if (numero == coluna1[i])
                                    {
                                        acertou = 1;
                                    }
                                }
                                if (acertou ==1)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Parabens para ti, o numero %d esta na primeira coluna... Ganhaste %deur.\n\n\n", numero,ganho);
                                }
                                else
                                {
                                    printf("Nao foi desta, perdeste %deur.\n\n\n", valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na segunda coluna
                            else if(tipoAposta == 12)
                            {
                                //Loop para verificar se o numero que calhou pertence à lista dos numeros da segunda coluna
                                for(i = 0 ; i < 17 ; i++)
                                {
                                    if (numero == coluna2[i])
                                    {
                                        acertou = 1;
                                    }
                                }
                                if (acertou == 1)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Parabens para ti, o numero %d esta na segunda coluna... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Nao foi desta, perdeste %deur.\n\n\n", valorAposta);
                                }
                            }
                            //Define se a bola calhou ou não na terceira coluna
                            else if(tipoAposta == 13)
                            {
                                //Loop para verificar se o numero que calhou pertence à lista dos numeros da terceira coluna
                                for(i = 0 ; i < 17 ; i++)
                                {
                                    if (numero == coluna3[i])
                                    {
                                        acertou = 1;
                                    }
                                }
                                if (acertou ==1)
                                {
                                    ganho = valorAposta * 3;
                                    carteira += ganho;
                                    printf("Parabens para ti, o numero %d esta na terceira coluna... Ganhaste %deur.\n\n\n", numero, ganho);
                                }
                                else
                                {
                                    printf("Nao foi desta, perdeste %deur.\n\n\n", valorAposta);
                                }
                            }
                        }
                    }
                }

                //Se o jogador quiser mudar aposta
                else if(opcao == 'm')
                {
                    //Definir onde se aposta
                    printf("\nOpcoes de aposta:\n");
                    printf("\t1  - Numero (1-36) (35 para 1)\n");
                    printf("\t2  - Vermelho (1 para 1)\n");
                    printf("\t3  - Preto (1 para 1)\n");
                    printf("\t4  - Pares (1 para 1)\n");
                    printf("\t5  - Impares (1 para 1)\n");
                    printf("\t6  - Primeira Metade (1-18) (1 para 1)\n");
                    printf("\t7  - Segunda Metade  (19-36) (1 para 1)\n");
                    printf("\t8  - Primeira Duzia  (1-12) (2 para 1)\n");
                    printf("\t9  - Segunda Duzia   (13-24) (2 para 1)\n");
                    printf("\t10 - Terceira Duzia  (25-36) (2 para 1)\n");
                    printf("\t11 - Primeira Coluna (1,4,7,10,13,16,19,22,25,28,31,34) (2 para 1)\n");
                    printf("\t12 - Segunda Coluna  (2,5,8,11,14,17,20,23,26,29,32,35) (2 para 1)\n");
                    printf("\t13 - Terceira Coluna (3,6,9,12,15,18,21,24,27,30,33,36) (2 para 1)\n\n");
                    printf("Onde queres apostar? ");

                    //Loop para restingir a aposta
                    while(valido == 0)
                    {
                        scanf(" %d", &tipoAposta);

                        if(tipoAposta < 1 || tipoAposta > 13)
                        {
                            printf("\nEssa aposta nao existe. Onde queres apostar? (1-13) ");
                        }
                        else
                        {
                            valido = 1;
                        }
                    }
                    //Reinicia a validade para entrar no proximo loop
                    valido = 0;

                    //Quando o jogador quiser apostar num numero
                    if(tipoAposta == 1)
                    {
                        //Muda a forma como a aposta atual e apresentada no inicio de cada jogada
                        imprimirAposta = 2;

                        printf("\nQueres apostar em qual numero? (1-36) ");

                        //Loop para restringir o numero onde o jogador aposta
                        while(valido == 0)
                        {
                            scanf(" %d", &apostaNumeros);

                            //Se o numero nao for valido
                            if(apostaNumeros < 1 || apostaNumeros > 36)
                            {
                                printf("\nA aposta tem que ser entre 1 e 36. Tenta outra vez: ");
                            }
                            //Se o numero for valido
                            else
                            {
                                valido = 1;
                                printf("\nVais apostar no numero %d.\n\n", apostaNumeros);
                            }
                        }
                        //Reinicia a validade para entrar no proximo loop
                        valido = 0;
                    }
                    //Imprime mensagem de onde o jogador apostou e muda a variavel apostaDisplay para ser impressa no inicio de cada ciclo de opcoes de jogada
                    else
                    {
                        //Muda a forma como a aposta atual e apresentada no inicio de cada jogada
                        imprimirAposta = 1;

                        if(tipoAposta == 2)
                        {
                            apostaDisplay = "no vermelho";
                            printf("\nVais apostar no vermelho.\n\n");
                        }
                        else if(tipoAposta == 3)
                        {
                            apostaDisplay = "no preto";
                            printf("\nVais apostar no preto.\n\n");
                        }
                        else if(tipoAposta == 4)
                        {
                            apostaDisplay = "nos pares";
                            printf("\nVais apostar nos pares.\n\n");
                        }
                        else if(tipoAposta == 5)
                        {
                            apostaDisplay = "nos impares";
                            printf("\nVais apostar nos impares.\n\n");
                        }
                        else if(tipoAposta == 6)
                        {
                            apostaDisplay = "na primeira metade";
                            printf("\nVais apostar na primeira metade.\n\n");
                        }
                        else if(tipoAposta == 7)
                        {
                            apostaDisplay = "na segunda metade";
                            printf("\nVais apostar na segunda metade.\n\n");
                        }
                        else if(tipoAposta == 8)
                        {
                            apostaDisplay = "na primeira duzia";
                            printf("\nVais apostar na primeira duzia.\n\n");
                        }
                        else if(tipoAposta == 9)
                        {
                            apostaDisplay = "na segunda duzia";
                            printf("\nVais apostar na segunda duzia.\n\n");
                        }
                        else if(tipoAposta == 10)
                        {
                            apostaDisplay = "na terceira duzia";
                            printf("\nVais apostar na terceira duzia.\n\n");
                        }
                        else if(tipoAposta == 11)
                        {
                            apostaDisplay = "na primeira coluna";
                            printf("\nVais apostar na primeira coluna.\n\n");
                        }
                        else if(tipoAposta == 12)
                        {
                            apostaDisplay = "na segunda coluna";
                            printf("\nVais apostar na segunda coluna.\n\n");
                        }
                        else if(tipoAposta == 13)
                        {
                            apostaDisplay = "na terceira coluna";
                            printf("\nVais apostar na terceira coluna.\n\n");
                        }
                    }

                    //Definir o valor da aposta
                    printf("Quanto queres apostar? Tens %deur. ", carteira);

                    //Loop para restringir o valor da aposta
                    while(valido == 0)
                    {
                        scanf(" %d", &valorAposta);

                        //Se o valor apostado for maior que o dinheiro do jogador
                        if(valorAposta > carteira)
                        {
                            printf("\nCalma la, nao es assim tao rico. So tens %deur para apostar. ", carteira);
                        }
                        //Se o valor apostado for menor que a aposta minima
                        else if(valorAposta < apostaMinima)
                        {
                            printf("\nO valor de aposta minimo e %deur. Escolhe um valor valido. ", apostaMinima);
                        }
                        else
                        {
                            valido = 1;

                            //Quando o jogador nao aposta o seu dinheiro todo
                            if(valorAposta == carteira)
                            {
                                printf("\nVAIS FAZER ALL-IN?? Boa sorte com isso!\n\n");
                            }

                            //Quando o jogador nao aposta o seu dinheiro todo
                            else
                            {
                                printf("\nSo isso? Pronto, tu la sabes...\n\n");
                            }
                            printf("Vais apostar %deur.\n\n", valorAposta);
                        }
                    }
                }

                //Se o jogador quiser levantar o dinheiro e voltar para casa
                else if(opcao == 'l')
                {
                    valido = 1;
                    sair = 1;
                    jogar = 0;

                    //Conjunto de mensagens e delays para efeitos visuais
                    for (i = 0; i < 1; i++)
                    {
                        delay(1);
                    }

                    printf("\nJa vais para casa? ");

                    for (i = 0; i < 1; i++)
                    {
                        delay(1);
                    }
                    printf("Tao cedo? ");

                    for (i = 0; i < 1; i++)
                    {
                        delay(1);
                    }

                    printf("E pena...\n\n");

                    for (i = 0; i < 1; i++)
                    {
                        delay(3);
                    }

                    //Conjunto de if e else if's que definem a mensagem que e impressa quando o jogador sai, de acordo com o dinheiro que lhe sobra
                    if(carteira >= apostaMinima && carteira < 40)
                    {
                        printf("Fogo, perdeste quase tudo! O casino agradece o donativo de %deur!\n\n", lucro);
                    }
                    else if(carteira >= 40 && carteira < 100)
                    {
                        lucro = 100 - carteira;
                        printf("So perdeste %deur, podia ter sido pior!\n\n", lucro);
                    }
                    else if(carteira == 100)
                    {
                        printf("Bem, nao perdeste nem ganhaste nada, nem sei o que vieste ca fazer...\n\n\n\n");
                    }
                    else if(carteira > 100 && carteira < 500)
                    {
                        lucro = carteira - 100;
                        printf("Parece que hoje e o teu dia de sorte...\nVoltas a casa com %deur, tiveste um lucro de %deur.\n\n", carteira, lucro);
                    }
                    else if(carteira >= 500 && carteira < 1000)
                    {
                        lucro = carteira -100;
                        printf("Nada mau, ganhaste %deur de lucro e quase ficaste rico...\n\n", lucro);
                    }
                    else
                    {
                        printf("Assim levas o casino a falencia, para a proxima nao entras!\nParabens, vais para casa com %deur.\n\n", carteira);
                    }
                }
                //Se a aposta for vazia, ignora e continua a correr (fizemos isto porque se nao fizessemos, ia imprimir amensagem do else abaixo no inicio de cada jogada)
                else if(opcao == '\n')
                {
                    continue;
                }
                //Se a opcao nao for r, m ou l, o input e invalido e imprime esta mensagem
                else
                {
                    printf("\nOpcao invalida. Escolhe uma opcao valida (r, m ou l): ");
                }
                opcao = '\n';
            }
            //Reinicia as variaveis para a proxima jogada
            valido = 0;
            carteiraDisplay = carteira - valorAposta;
        }
        //Quando o dinheiro do jogador for menos que a aposta minima
        if(carteira < apostaMinima)
        {
            printf("Nao tens dinheiro suficiente para continuar a apostar.\nTens que refletir bem sobre as tuas decisoes de vida.\n\n");
            //Dar opcao de jogar novamente quando o jogador perde
            printf("Queres jogar novamente? (s/n) ");

            //Loop para restringir a resposta do jogador
            while(valido == 0)
            {
                fgets(line, MAX, stdin);
                sscanf(line, " %c ", &novamente);

                //Reinicia as variaveis se o jogador quiser jogar novamente
                if(novamente == 's')
                {
                    valido = 1;
                    reiniciar = 1;
                    carteira = 100;
                    tipoAposta = 0;
                    valorAposta = 0;
                    imprimirAposta = 0;
                }
                //Se o jogador nao quiser jogar novamente, define a variavel jogar como zero para sair do loop do jogar
                else if(novamente == 'n')
                {
                    valido = 1;
                    jogar = 0;
                    lucro = 100 - carteira;
                    printf("\nObrigado pelo donativo de %deur ao casino!\n\n", lucro);
                }
                //Quando o jogador nao digita um input valido
                else
                {
                    printf("\nInput invalido. Queres jogar novamente? (s/n) ");
                }
            }
            //Reinicia a validade para entrar no proximo loop
            valido = 0;
        }
    }
    //Quando o jogo acaba, imprime mensagem de despedida
    printf("Ate a proxima!\n");
    return 0;
}
