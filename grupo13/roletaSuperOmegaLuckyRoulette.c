#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int betting (int money, int bet)          /*Através desta função é verificado se o utilizador tem créditos suficientes para fazer a aposta que pretende, e, caso os tenha, subtrai o valor ao número de créditos e guarda o valor da aposta*/
{           
  if (bet <= money) {
    money = money - bet;
    printf("Balance : %d $ \n", money);
    printf("Current bet : %d $ \n", bet);
    return money;
  } else {
      printf("You don't have enough money to bet that much!\n");
      return money;
  }
}


int menu (int money, int bet)          /*Esta função apresenta ao utilizador uma lista de comandos que pode executar*/
{
  printf("Welcome to lucky roulette!\n");
  printf("Balance: %d $ \n", money);
  printf("Current bet: %d $ \n", bet);
  printf("Which option do you choose?\n");
  printf("n - Bet on a specific number - pays 35 to 1\n");
  printf("o - Bet on an odd number - pays 2 to 1\n");
  printf("e - Bet on an even number - pays 2 to 1\n");
  printf("b - Show balance\n");
  printf("h - Help\n");
  printf("c - Cashout and go home!\n");
  return 0;
}

int delay(int random)         /*Com esta função, o valor gerado aleatoriamente da roleta é revelado após uma curta contagem decrescente*/
{
    sleep(1);

    printf("4\n");

    sleep(1);

    printf("3\n");

    sleep(1);

    printf("2\n");

    sleep(1);

    printf("1\n");
    
    sleep(1);

    printf("The number is... %d!\n", random);

    return 0;
}

int main()
{
    char choose, difficulty[10];
    int money = 100, bet = 0, random;
    int Easy = false;
    int Normal = false;
    int Hard = false;
    int GameOn = true;

    begin:
    printf("NOTE: difficulty selection is case sensitive!\n");
    printf("Beginner - minimum bet 1 $\n");
    printf("Normal - minimum bet 10 $\n");
    printf("Expert - minimum bet 20 $\n");
    printf("Choose the difficulty: ");
    scanf("%s", difficulty);
    if (strstr (difficulty, "Beginner")){
        Easy = true;
        while (Easy == true){
            menu(money,bet);
            while (GameOn == true) {
                if (money <= 0) {    /*Verifica se o utilizador tem créditos suficientes para continuar a jogar*/
                    printf("You don't have enough money to keep playing!\n");
                    printf("Game Over\n");
                    return 0;
                }
                printf("What do you wanna do: ");
                scanf("%s", &choose);             /*Aqui é verificada a escolha do utilizador, das escolhas disponíveis na lista de comandos*/
                switch (choose) {
                    case 'n': {                   /*Opção para apostar num número específico*/    
                        int number;
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet > 0){
                            money = betting (money, bet);
                            printf("Which number will you choose?\n");
                            scanf("%d",&number);
                            if (number <= 36 && number >= 1) {
                                printf("It's time to roll!\n");
                                srand((unsigned int) time(NULL));{
                                    random = rand() % (36 - 0 + 1) + 0;
                                    delay(random);
                                    if (number == random) {       /*Vitória do utilizador*/
                                        printf("You won!\n");
                                        money = money + (35 * bet);
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else if (random == 0) {       /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else {
                                        printf("You lost!\n");    /*Número diferente do escolhido pelo utilizador = derrota*/
                                        printf("Balance: %d $ \n", money);
                                    }
                                }
                            }
                            else {
                                printf("That's not an option!\n");    /*Caso o utilizador escolha apostar num número fora do intervalo possível*/
                                money = money + bet;
                            }   
                        }
                        else if (bet <= 0) {     /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet without any money!\n");
                        }
                    }
                    break;

                    case 'o':{      /*Utilizador aposta nos números ímpar*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet > 0){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {    /*Número gerado é par, derrota do utilizador*/
                                    printf("The number is even!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                                else {       /*Número gerado é ímpar, vitória do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet <= 0) {    /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet without any money!\n");
                        }
                    }
                    break;

                    case 'e':{      /*Utilizador aposta nos números par*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet > 0){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {   /*Número gerado é par, vitória do utilizador*/
                                    printf("The number is even!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                                else if (random == 0) {    /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                }
                                else {   /*Número gerado é ímpar, derrota do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet <= 0) {     /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet without any money!\n");
                        }
                    }
                    break;

                    case 'h':  /*Apresenta a lista de comandos de novo*/
                        printf("n - Bet on a specific number - pays 35 to 1\n");
                        printf("o - Bet on an odd number - pays 2 to 1\n");
                        printf("e - Bet on an even number - pays 2 to 1\n");
                        printf("b - Show balance\n");
                        printf("c - Cashout and go home!\n");
                    break;

                    case 'c': /*Apresenta uma mensagem de parabéns que informa com quanto dinheiro o utilizador "sai da mesa" e termina o programa*/
                        printf("CONGRATULATIONS! You walked away with %d $\n", money);
                        printf("Game Over");
                        return 0;
                    break;

                    case 'b':  /*Apresenta os créditos disponíveis*/
                        printf("Balance: %d $ \n", money);
                    break;

                    default:   /*Caso o utilizador tente escolher uma opção que não exista*/
                        printf("That's not an option!\n");
                        printf("Try again\n");
                    break;
                }
            }
        }
    }

    else if (strstr (difficulty, "Normal")){
        Normal = true;
        while (Normal == true){
            menu(money,bet);
            while (GameOn == true) {
                if (money < 10) {   /*Verifica se o utilizador tem créditos suficientes para continuar a jogar*/
                    printf("You don't have enough money to keep playing!\n");
                    printf("Game Over\n");
                    return 0;
                }
                printf("What do you wanna do: ");
                scanf("%s",&choose);
                switch (choose) {
                    case 'n': {     /*Opção para apostar num número específico*/ 
                        int number;
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 10){
                            money = betting (money, bet);
                            printf("Which number will you choose?\n");
                            scanf("%d", &number);
                            if (number <= 36 && number >= 1) {
                                printf("It's time to roll!\n");
                                srand((unsigned int) time(NULL));{
                                    random = rand() % (36 - 0 + 1) + 0;
                                    delay(random);
                                    if (number == random) {     /*Vitória do utilizador*/
                                        printf("You won!\n");
                                        money = money + (35 * bet);
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else if (random == 0) {     /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else {          /*Número diferente do escolhido pelo utilizador = derrota*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                    }
                                }
                            }
                            else {
                                printf("That's not an option!\n");
                                money = money + bet;
                            }
                        }
                        else if (bet < 10){    /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'o':{    /*Utilizador aposta nos números ímpar*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 10){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {     /*Número gerado é par, derrota do utilizador*/     
                                    printf("The number is even!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                                else {    /*Número gerado é ímpar, vitória do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet < 10) {    /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'e':{    /*Utilizador aposta nos números par*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 10){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {   /*Número gerado é par, vitória do utilizador*/
                                    printf("The number is even!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                                else if (random == 0) {     /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                }
                                else {   /*Número gerado é ímpar, derrota do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet < 10) {    /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf(" You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'h':    /*Apresenta a lista de comandos de novo*/
                        printf("n - Bet on a specific number - pays 35 to 1\n");
                        printf("o - Bet on an odd number - pays 2 to 1\n");
                        printf("e - Bet on an even number - pays 2 to 1\n");
                        printf("b - Show balance\n");
                        printf("c - Cashout and go home!\n");
                    break;

                    case 'c':    /*Apresenta uma mensagem de parabéns que informa com quanto dinheiro o utilizador "sai da mesa" e termina o programa*/
                        printf("CONGRATULATIONS! You walked away with %d $\n", money);
                        printf("Game Over");
                        return 0;
                    break;

                    case 'b':    /*Apresenta os créditos disponíveis*/
                        printf("Balance: %d $ \n", money);
                    break;

                    default:    /*Caso o utilizador tente escolher uma opção que não exista*/
                        printf("That's not an option!\n");
                        printf("Try again\n");
                    break;
                }
            }
        }
    }

    else if (strstr (difficulty, "Expert")){
        Hard = true;
        while (Hard == true){
            menu(money, bet);
            while (GameOn == true) {
                if (money < 20) {    /*Verifica se o utilizador tem créditos suficientes para continuar a jogar*/
                    printf("You don't have enough money to keep playing!\n");
                    printf("Game Over\n");
                    return 0;
                }
                printf("What do you wanna do: ");
                scanf("%s", &choose);    /*Aqui é verificada a escolha do utilizador, das escolhas disponíveis na lista de comandos*/
                switch (choose) {
                    case 'n': {    /*Opção para apostar num número específico*/ 
                        int number;
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 20){
                            money = betting (money, bet);
                            printf("Which number will you choose?\n");
                            scanf("%d", &number);
                            if (number <= 36 && number >= 1) {
                                printf("It's time to roll!\n");
                                srand((unsigned int) time(NULL));{
                                    random = rand() % (36 - 0 + 1) + 0;
                                    delay(random);
                                    if (number == random) {      /*Vitória do utilizador*/
                                        printf("You won!\n");
                                        money = money + (35 * bet);
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else if (random == 0) {      /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                    }
                                    else {           /*Número diferente do escolhido pelo utilizador = derrota*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                    }
                                }
                            }
                            else {
                                printf("That's not an option!\n");
                                money = money + bet;
                            }
                        }
                        else if (bet < 20) {     /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'o':{    /*Utilizador aposta nos números ímpar*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 20){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {   /*Número gerado é par, derrota do utilizador*/
                                    printf("The number is even!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                                else {   /*Número gerado é ímpar, vitória do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet < 20) {      /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'e':{   /*Utilizador aposta nos números par*/
                        printf("Balance: %d $ \n", money);
                        printf("Place your bet: ");
                        scanf("%d", &bet);
                        if (bet >= 20){
                            money = betting (money, bet);
                            srand((unsigned int) time(NULL));{
                                random = rand() % (36 - 0 + 1) + 0;
                                delay(random);
                                if (random % 2 == 0) {    /*Número gerado é par, vitória do utilizador*/
                                    printf("The number is even!\n");
                                    printf("You won!\n");
                                    money = money + (bet * 2);
                                    printf("Balance: %d $\n", money);
                                }
                                else if (random == 0) {    /*Número da casa: a casa ganha automaticamente*/
                                        printf("You lost!\n");
                                        printf("Balance: %d $ \n", money);
                                }
                                else {   /*Número gerado é ímpar, derrota do utilizador*/
                                    printf("The number is odd!\n");
                                    printf("You lost!\n");
                                    printf("Balance: %d $\n", money);
                                }
                            }
                        }
                        else if (bet < 20) {    /*Caso o utilizador tente apostar um valor abaixo do definido pelo nível de dificuldade*/
                            printf("You can't bet less than the minimum amount for this difficulty level!\n");
                        }
                    }
                    break;

                    case 'h':   /*Apresenta a lista de comandos de novo*/
                        printf("n - Bet on a specific number - pays 35 to 1\n");
                        printf("o - Bet on an odd number - pays 2 to 1\n");
                        printf("e - Bet on an even number - pays 2 to 1\n");
                        printf("b - Show balance\n");
                        printf("c - Cashout and go home!\n");
                    break;

                    case 'c':     /*Apresenta uma mensagem de parabéns que informa com quanto dinheiro o utilizador "sai da mesa" e termina o programa*/
                        printf("CONGRATULATIONS! You walked away with %d $\n", money);
                        printf("Game Over");
                        return 0;
                    break;

                    case 'b':   /*Apresenta os créditos disponíveis*/
                        printf("Balance: %d $ \n", money);
                    break;

                    default:   /*Caso o utilizador tente escolher uma opção que não exista*/
                        printf("That's not an option!\n");
                        printf("Try again\n");
                    break;
                }
            }
        }
    }

    else {  /*Verifica se o utilizador escolheu um nível de dificuldade da lista*/
        printf("That's not an option!\n");
        goto begin;
    }

    return 0;
}