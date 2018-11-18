#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "func_roleta.h"
FILE *file;

int main(){
  //variaveis----------------------------------------------------------------------
  int Creditos = 100;
  int cashBet, numberBet, n, minBet;
  char choice[5];
  char load;
  /*
  choice[0] = travel in menu
  choice[1] = bet option
  choice[2] = if player bet
  choice[3] = if player chose on what to bet
  choice[4] = color, r-RED and b-Black
  */

  //welcome titles
  minBet=0;
  choice[2] = 0;
  choice[3] = 0;
  Start();
  //incio--------------------------------------------------------------------------
  printf("\nHello outsider. Before we begin do you want to load your last balance? (y/n).\n");
  scanf("%c", &load);
  if (load == 'y'){//player wants to load save file____________________________________
    Creditos = load_game(Creditos,cashBet, minBet);
    printf("Rice successfully imported.");
  }
  printf("\nAlright, one more thing, the difficulty. Would you like to play on:\n1 -------------------- The Cotton-Tail Room for free betting\n2 -------------------- The Rice-Paddy Hall for a minimum of 10 rice when betting\n3 -------------------- The Rice Hall-of-Fame for a minimum of 20 rice when betting?\n");
  scanf("%d", &minBet);
  comand_list(Creditos);
  printf("Make your choice: ");
  while (Creditos > 0){
    scanf("%c",choice);
    switch(choice[0]){
      case 'b': //player chooses how much to bet___________________________________
        printf("Rice to bet: ");
        scanf("%d", &cashBet);
        //player chose difficulty level 1
        if (minBet == 1){
          while ((cashBet >= Creditos) | (cashBet <= 0)){
            printf("\nGoddamn it outsider, if you bet it all you won't have rice for dinner!(you must stick to 1 rice)\nRice to Bet: ");
            scanf("%d", &cashBet);
          }

          //player chose difficulty level 2
        }else if(minBet == 2){
          while (cashBet < 10){
            printf("\nOutsider, That isn't allowed on the Rice-Paddy Hall. You'll have to bet more than %d rice.\nRice to Bet: ", cashBet);
            scanf("%d", &cashBet);
            }

          //player chose difficulty level 3
        }else if(minBet == 3){
          while (cashBet < 20){
            printf("\nOutsider, The Rice Hall-of-Fame is no playground. %d rice is not enough.\nRice to Bet: ", cashBet);
            scanf("%d", &cashBet);
            }
          }
        Creditos -= cashBet;
        show_Balance(Creditos, cashBet);
        choice[2] = 1;
        break;

      case 'n': // player chooses to bet on a number________________________________
        scanf("%d", &numberBet);
        while ((numberBet > 36) | (numberBet == 0)){
        printf("C'mon then, pick one between 1 and 36\n");
        scanf("%d", &numberBet);
        }
        printf("You just bet on the number %d.\n", numberBet);
        choice[1] = 'n';
        choice[3] = 1;
        break;
      case 'h': // player wants to see control list_________________________________
        help();
        break;
      case 'r': // roll the numbers_________________________________________________
        if ((choice[2] == 1) & (choice[3] == 1)){
          printf("lets roll.\n");
          n =rollr();
          //Faz corresponder creditos ao return das funcoes para atualizar a quantia.
          if (choice[1] == 'e'){
            Creditos = odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'o'){
            Creditos = odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'c'){
            Creditos = color_check(n, choice[4], Creditos, cashBet);
          }else if(choice[1] == 'n'){
            Creditos = number_compare(n, numberBet, Creditos, cashBet);
          }
        }else if(choice[2] == 0){
          printf("You need to bet first!\n");
        }else if(choice[3] == 0){
          printf("Choose on what to bet first!\n");
        }
        break;
      case 's': // player wants to see balance______________________________________
        show_Balance(Creditos, cashBet);
        choice[1] = 's';
        break;
      case 'e': // player bets on an even number. Pays 2 to 1_______________________
        printf("Even hm? Alright champ, roll when you are ready.\n");
        choice[1] = 'e';
        choice[3] = 1;
        break;
      case 'o': // player bets on an odd number. Pays 2 to 1________________________
        printf("Odd it is, roll when you wish.\n");
        choice[1] = 'o';
        choice[3] = 1;
        break;
      case 'c': // player picks the color red to bet________________________________
        printf("Acknowledged, Red it is. Whenever you are ready, roll.\n");
        choice[1] = 'c';
        choice[3] = 1;
        choice[4] = 'r';
        break;
      case 'v': // player picks the color black to bet________________________________
        printf("You little punk, Black it is. Whenever you are ready, roll.\n");
        choice[1] = 'c';
        choice[3] = 1;
        choice[4] = 'b';
        break;
      case 'g': // player wants to save progress____________________________________
        save_game(Creditos,cashBet, minBet);
        break;
      case 'm': // rolar a roleta sem efeito nos creditos, apreciar o delay?__________
        rollr();
        break;
      case 'l': //sair do loop com uma label.______________________________________
        goto finish;
    }
  }
  finish:
  printf("\nLooks like you are done for today. Comeback sometime!");
  delay(2);
  return 0;
}
