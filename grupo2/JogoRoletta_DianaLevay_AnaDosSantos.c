/*--------------------JOGO DE ROLETA--------------------*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int pcRandom (){ 
    srand((int) time (NULL));
    int pc = (rand()%37);
    return pc;
}

int pcEven () {
    int a = pcRandom() %2;
    return a;
}

int main()
{
  //Variables
	int amountBet = 0, balance = 100;
	int number, opAnumb;
  int specificNrBet = 0;
  int evenNrBet = 0; 
  int oddNrBet = 0;
  int newBet = 0;
  char option;
  char player = 'y';
  int welcome = 0;

 
do{   
  // Outputs and Inputs	
  if (welcome == 0){
  sleep(1);
  printf("*** Welcome to crazy Roulette! Do you feel lucky today? ***\n\n");
  welcome ++;
  }
 
  if (balance <= 0) {
  printf("your balance is 0! You lose! \n\n");
  break; 
  player = 'n';
  } 
  
  printf("  Balance: %d €\n", balance);
  printf("  Current Bet: %d €\n\n", amountBet);

  sleep(2);
  printf("  Choose an option:\n"
    "A <amount> - amount of money you want to bet\n"
    "B <number> - Bet on a specific number - Pays 35 to 1 -\n"
    "C Bet on even number - Pays 2 to 1 -\n"
    "D Bet on odd number - Pays 2 to 1 -\n"
    "E Roll\n"
    "F Help\n"
    "G Show Balance\n"
    "H Cashout and go home\n\n");
  sleep(3);
  printf("Please select option:\n");
  option = getchar();
 
  //Loops
 
 // Option A-------------------------------------------------------------------------
  if (option == 'A'|| option == 'a'){
    opAnumb = scanf(" %d", &number);
    if (opAnumb <= 0)
        printf("Invalid amount");
    else if (number > balance)
    	printf("Invalid amount");
    else if (number != 0) {
        amountBet = amountBet+number;
        //printf("\nBalance: %d €\n", balance);
        //printf("Current Bet: %d €\n\n", amountBet);
    }
   getchar(); 
   continue;
   }  

// Option B-------------------------------------------------------------------------  
else if (option == 'B' || option == 'b'){
   specificNrBet = scanf(" %d", &number);
    if (opAnumb <= 0)
        printf("please bet first \n");
    else if (specificNrBet == 0)
        printf("You can't choose 0! \n");
    else if (0 < number && number <=36) 
        printf("You chose %d \n",number);
    else
        printf("die\n");
  getchar();       
  continue;
   }  

// Option C--------------------------------------------------------------------------
else if (option == 'C' || option == 'c'){
    evenNrBet = 1;
    if (opAnumb <= 0)
        printf("please bet first \n");
    else 
    printf("You bet even \n");    
   getchar();  
   continue;
   }

// Option D-------------------------------------------------------------------------
else if (option == 'D' || option == 'd'){
  oddNrBet = 1;
  if (opAnumb <= 0)
    printf("please bet first \n");
  else 
    printf("You bet odd \n");   
   getchar();  
   continue;
   } 

// Option E--------------------------------------------------------------------------
else if (option == 'E' || option == 'e'){
    pcRandom();
    if (opAnumb <= 0)
        printf("please bet first \n");

    else if (specificNrBet != 0) {
      printf("\nYou bet %d€ on %d\n", amountBet, specificNrBet);
      sleep(1);
      printf("*******LETS ROLL!*******\n\n");
      sleep(4);
      printf("The pc rolled %d\n", pcRandom());
        if (pcRandom() == specificNrBet ){
        printf("You win!\n");
        newBet = (35*amountBet);
        balance = balance + newBet;
        printf("Amount = %d€\n", newBet);
        }
        else{
        printf("You lose!\n");
        balance = balance - amountBet;
        printf("Amount = %d€\n", amountBet);
        }
    
    }
    else if (evenNrBet == 1){
      if (pcEven () == 0) {
    printf("\nYou bet even \n");
    sleep(1);
    printf("*******LETS ROLL!*******\n\n"); sleep(4);
    printf("The pc rolled %d\n", pcRandom());
    printf("You win!\n");
    newBet = (2*amountBet);
    balance = balance + newBet;
    printf("Amount = %d€\n", newBet);
      }
    

      else if ( pcEven() !=0 ) {
    printf("\nYou bet even \n");
    sleep(1);
    printf("*******LETS ROLL!*******\n\n");
    sleep(4);
    printf("The pc rolled %d\n", pcRandom());
    printf("You lose!\n");
    balance = balance - amountBet;
    printf("Amount = %d€\n", amountBet);
    }
    evenNrBet = 0;
    }
   else if (oddNrBet == 1){
      if (pcEven () != 0){
    printf("\nYou bet odd \n");
    sleep(1);
    printf("*******LETS ROLL!*******\n\n");
    sleep(4);
    printf("The pc rolled %d\n", pcRandom());
    printf("You win!\n");
    newBet = (2*amountBet);
    balance = balance + newBet;
    printf("Amount = %d€\n", newBet);
   }
      else if ( pcEven() ==0 ){
    printf("\nYou bet odd \n");
    sleep(1);
    printf("*******LETS ROLL!*******\n\n");
    sleep(4);
    printf("The pc rolled %d\n", pcRandom());
    printf("You lose!\n");
    balance = balance - amountBet;
    printf("Amount = %d€\n", amountBet);
    }
    oddNrBet = 0;
    }
 
  getchar(); 
  amountBet=0;
  continue;
   } 

// Option F-------------------------------------------------------------------------  
else if (option == 'F' || option == 'f'){
  sleep(1);
  printf("\n*****************\n"
  "This is a game of luck \n"
  "in order to bet, select [A] and choose an amount \n"
  "bet on a specific number with [B]\n"
  "you may also choose to bet on even [C] or odd [D]\n"
  "after you've bet, roll and let fate do the rest \n"
  "chech your balance with [G], you lose if it reaches 0!\n"
  "cashout anytime by pressing [H], use it wisely! \n"
  "have fun! \n"
  "*****************\n\n");
  getchar(); 
   continue;
   } 

// Option G--------------------------------------------------------------------------
else if (option == 'G' || option == 'g'){
  printf("Your current Balance is %d €\n", balance);
  getchar(); 
  continue;
  } 

// Option H------------------------------------------------------------------------- 
else if (option == 'H' || option == 'h'){
  printf("game over!\n" "Your final Balance: %d €\n""See you soon! \n", balance);

   }


else {
  printf("invalid answer! Try again \n");
   getchar();   
  continue;
   } 

  
player = 'n';
welcome = 0;
printf("Would you like to play again? 'y'");
getchar();
player = getchar();
getchar();
printf("\n");


  }
 
while (player == 'y');
  
 return 0; 
}
