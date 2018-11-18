#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//Variables
int Balance = 100;
int B_amount = 0;
int B_number;
int E_O = 3;
int S_options;
int R_value;
int Level;
int Answer;
int Check;

//Declared Functions
void Select_Options();
void Bet_Amount();
void Bet_Number();
void Bet_EO();
void R_Value();
void C_Out();
void help();
void S_Level();

//Game Start
int main(void) {
  printf("Welcome to Ruddy Roulette!\n\tYou have: %i€ to try your best, good luck!\n",Balance);
  printf("\nSelect your gambling Level: \n\t<1> Begginer 1€  bets\n\t<10> Normal   10€ bets\n\t<20> Expert   20€ bets\n\t I'm a");
  S_Level();
}

//Shows actual balance&bet
void S_Balance(){
  printf("\tBalance:     %i€", Balance);
  printf("\n\tCurrent bet: %i€\n", B_amount);
  Select_Options();
}

//Verifies if player have alredy made a bet and if he wants to change the value of it
void Bet_Amount(){
  if(B_amount != 0){
      printf("Slow down mate, you have alredy made your bet, wanna change the amount? \n\t<0> YES \n\t<1> NO\n\t");
      scanf("%i",&Answer);
      if(Answer == 0){
        Balance += B_amount;
        B_amount = 0;
        Bet_Amount();
      }else{
        Select_Options();
      }
      }
    printf("\n\tSelect your bet amount:");
    scanf("%i",&B_amount);

    //Checks if the bet is higher than the current balance or lower then the level
    if (B_amount > Balance){
      printf("That's more than you can afford pal, try a smaller amount \n");
      B_amount = 0;
      Bet_Amount();
      } else if (B_amount < Level){
      printf("Sorry man, you are going to deal with your choices\n");
      B_amount = 0;
      Bet_Amount();
      }else {
        Balance -= B_amount;
        Select_Options();
      }
}

//Select the betting number. Checks: if it is the house number, if it is between 1-36
void Bet_Number() {
  printf("\n\tSelect your betting number:");
  scanf("%d",&B_number);

  if (B_number == 0){
    printf("That's the house number mate, chose another\n");
    Bet_Number();
  } else if(B_number < 0) {
    printf("That's not a valid number, try one between 1 and 36\n");
    Bet_Number();
  } else if(B_number > 36) {
    printf("That's not a valid number, try one between 1 and 36\n");
    Bet_Number();
  } else {
    Select_Options();
  }
}

//Select even or odd numbers for the betting
void Bet_EO(){
  printf("\n\tSelect 0 for even and 1 for odd numbers:");
  scanf("%i",&E_O);
  if(E_O < 0) {
    printf("That's not a valid number, try 0 or 1\n");
    Bet_EO();
  } else if(E_O > 1) {
    printf("That's not a valid number, try 0 or 1\n");
    Bet_EO();
    } else {
    Select_Options();
  }
}

//Choose a random number between 0-36, inform this number, aplies conditions for winning\losing and aplies delay
void R_Value(){
  //Generates random number between 0 - 36
  srand(time(NULL));
  R_value = rand();
  R_value = R_value % 36; 
  
  //Aplies delay
  printf("Spinning the Roulette: \n");
  sleep (1);
  printf(".\n");
  sleep (1);
  printf(".\n");
  sleep (1);
  printf(".\n");
  sleep (1);
  printf("The ball landed on %i\n",R_value);

 Check = B_amount;
 if (B_amount == 0){
    printf("Please, you have to gamble");
    Select_Options();
  }
  if(R_value == 0){
    B_amount = 0;
    Check = B_amount;
  }
  if (R_value == B_number){
    B_amount *= 35;
  }
  if (E_O == 0){
    if(R_value % 2 == 0){
      B_amount *= 2;
    }
  }else if (E_O == 1){
    if(R_value % 2 != 0){
          B_amount *= 2;
    }
  }

  if (B_amount == Check){
    printf("\nSorry, Ruddy won this time, better luck next roll\n");
    B_amount = 0;
  }else if(B_amount != Check){
    printf("\nCongrats, you won, but not for long...\n");
  }
  
  if(Balance ==0){
    if(B_amount == 0){
          C_Out();
    }
  }

  Balance += B_amount;
  B_amount = 0;
  S_Balance();
  Select_Options();
}

//End the program
void C_Out(){
  printf("You got %i€ from all this gambling stuff \n", Balance);
  printf("Game Over");
  exit(0);
}

//Show commands
void help() {
  printf("\nCheck out our commands:");
  printf("\n\t<1> for the amount of money you want to bet");
  printf("\n\t<2> to bet on a specific number - Pays 35 to 1");
  printf("\n\t<3> to bet on even or odd numbers - Pays 2 to 1");
  printf("\n\t<4> to roll!");
  printf("\n\t<5> to show your current balance");
  printf("\n\t<6> to cashout your current balance");
  printf("\n\t<7> FOR HELP!\n");
  Select_Options();
}

//Call functions after choosing a command
void Select_Options(){
  printf("\nSelect Option:");
  scanf("%i",&S_options);
  
  if(S_options < 0){
    printf("Thats not a command, try again\n");
    Select_Options();
  }else if (S_options > 7){
    printf("Thats not a command, try again\n");
    Select_Options();
    }else if (S_options == 1){
    Bet_Amount();
  } else if (S_options == 2){
    Bet_Number();
  }else if (S_options == 3){
    Bet_EO();
  }else if (S_options == 4){
    R_Value();
  }else if (S_options == 5){
    S_Balance();
  }else if (S_options == 6){
    C_Out();
  }else if (S_options == 7){
    help();
  }
}

//Defines player level
void S_Level(){
  scanf("%i",&Level);
  if(Level == 1){
    help();
  }else if(Level == 10){
    help();
  }else if(Level == 20){
    help();
  }else{
    printf("That is not in our list...\n\t Give it another try:");
    S_Level();
  }
}