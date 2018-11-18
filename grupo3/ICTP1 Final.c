#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void delay(int milli_seconds) 
{  
  
    clock_t start_time = clock(); 				   // String start time  
  
   
    while (clock() < start_time + milli_seconds);  // looping till required time is not acheived 
} 
void printText(void) {  						   // function to print text in the help option
	printf("b - Start betting\n");
	printf("n <number> - the number you wish to bet on, from 1 to 35.\n");
	printf("e - Bet on an even number.\n");
	printf("o - Bet on an odd number.\n");
	printf("r - Roll the roullete.\n");
	printf("h - Help.\n");
	printf("s - Show your current balance.\n");
	printf("c - Cashout and finish the game.\n");
}

int main() {
	int bal = 100;	 							   // initial balance variable
	int bet = 0; 	 							   // initial bet variable
	int mbet; 		 							   // minimum about you can bet based on the difficuty chose
	int curbal; 	 							   // ballence after the player has placed a bet
	int defeat = 0; 							   // variable so you can exit the game
	int num;		 							   // number the player bets on
	int numcasino;	 							   // number the house rolls
	int flagcheck;   							   // check if player has picked option n, e or o

	char opc; 		 							   // variable for chosen option
	char*s;			 							   // string to clean the buffer
	char dif; 		 							   // the chosen dificulty setting
	
	

	printf("Welcome! Our game has 3 difficulty settings, which are: \n");
	printf("- Easy (minimu bet of 1 euro)\n- Normal (minimum bet of 10 euros)\n");
	printf("- Hard (minimum bet of 20 euros)\n");
	printf("Choose the difficulty by typing in the letter 'e', 'n' or 'h' for each diffuclty, respectively.");
  
  	dif = getchar();							  // get the char of the dificulty

    if (dif == 'e'){							  // easy mode
      printf("You have chosen the easy mode, with a minimum bet of 1 euro.");
      mbet = 1;
    }
    else if (dif == 'n'){						  // medium mode
      printf("You have chosen the normal mode, with a minimum bet of 10 euros.");
      mbet = 10;    
    }
    else if (dif == 'h') {						  // hard mode
      printf("You have chosen the hard mode, with a minimum bet of 20 euros.");
      mbet = 20;
    }

	srand((unsigned int) time(NULL));			   // start the random generator with seed = time NULL

	printf("Welcome to our roullete game!\n"); 	   // introduction
	printf("Balance: %d euros\n", bal);        	   // information on your current balance
	printf("Current bet: %d euros \n", bet);   	   // information on how much money you have put on the line
	/*list of possible moves in this game*/
	printf("\nChoose one of the following options:\n"); 
	printf("b - Start betting.\n");
	printf("n <number> - the number you wish to bet on, from 1 to 35.\n");
	printf("e - Bet on an even number.\n");
	printf("o - Bet on an odd number.\n");
	printf("r - Roll the roullete.\n");
	printf("h - Help.\n");
	printf("s - Show your current balance.\n");
	printf("c - Cashout and finish the game.\n");
	printf("!Start by betting your desired amount!\n");

	printf("\n Select an option:\n");
	

	while(defeat == 0) {

		opc = getchar(); 							// read the inserted option

		switch(opc) {

			case 'b':
				printf("How much money do you want to throw away? "); 
				scanf("%d", &bet); 					// to save the amount of money the player wants to bet
				sscanf("%s",s); 					// clear buffer
				if(bet < mbet) { 					// if the player tries to play without using money
					printf("You can't play the game like this, use the minimum next time, use b to try again.\n");
				} 
				else if(bet > bal) { 				// if the player bets more than what he has
					printf("Woah there buckaroo, stop playing around and bet something within your reach, try again with b.\n");

				} 
				else if(bet <= bal) { 				// If the payer puts a vaid bet
					printf("You have selected to bet %d euros on this round.\n", bet);
					curbal = bal - bet;				// remove bet from ballance 
					printf("Your current balance is %d euros.\n To continue select another option.\n", curbal);

				}

				opc = getchar();				    // changing cases
				sscanf("%s",s);						// clean the buffer
				break; 
			case 'n':
				flagcheck = 0;						// definig case n as case 0 of flagcheck
			

				if(bet <= mbet) { 					// in case the player starts with n before b
					printf("You thought we were going to let you play without betting? Go back with 'b' and bet something before security decides that enough is enough, if you get what im saying.\n"); //error message
				break;
				} 
				else {
					printf("Alright, feeling lucky I see, which number do you wish to bet? Pick between 1-35.\n");
					scanf("%d", &num);
					sscanf("%s",s);					// clear the buffer once more

				}


				if(bet <= mbet) { 					// in case the player starts with n before b
					printf("You thought we were going to let you play without betting? Go back with 'b' and bet something before security decides that enough is enough, if you get what im saying.\n"); //error message
				
				} 
				

				break;
			case 'e':
				flagcheck = 1;						// defining case e as case 1 of flagcheck
				printf("So you went for the 50/50 chance ey? Well good luck mate...\n");

				if (bet < mbet) {
					printf(" or so I would like to say, I suggest you bet the minimum. Press 'b' to go back to betting.\n");
				}
				
				break;
			case 'o':
				flagcheck = 2;					    // defining case o as case 2 of flagcheck
				printf("So you went for the 50/50 chance ey? Hope you win...");

				if (bet < mbet) {
					printf(" or so I would like to say, in order to win you must bet, you did not think we would allow you to play without betting the minimum did you? Press 'b' to go back to betting.\n");
				}
				
				break;
			case 'r':
				numcasino = rand()%36; 				// random number generator for all numbers between 0 and 35
				delay(4000000);

				if(flagcheck == 0){
					if(num == numcasino) { 			// if you get the number right, i'm not even sure if this is possible at the moment
						curbal = curbal + bet * 35; // add necessary value to balance if the player wins the round
						printf("It landed on %d.\n", numcasino);
						printf("Congratulations, you won! Lucky you, you got 35 times the money you bet.\n");
						printf("To check your balance press 's'.\n");
						bet = 0;					// reset the bet

					}
					else if (num != numcasino) { 	// if you do not get the number
						printf("It landed on %d.\n", numcasino);
						printf("Sucks to be you, ye' didn't get it mate, and yer' %d euros poorer\n", bet);
						bal = curbal;				// reset the balance, removing the value bet
						bet = 0;					// reset the bet
					}

				}
				else if(flagcheck == 1) {

					if((numcasino%2) == 0){
						curbal = curbal + bet * 2; // add necessary value won by the player
						printf ("\nIt appears you were right, the ball landed on an even number, you just doubled the money you had bet!\n");
						printf("To check your balance press 's'.\n");
						bet = 0;				   // reset bet
					}
					else if ((numcasino%2) == 1) {
						printf("\n\nOuch, it would seem your idea backfired, it landed on an odd number.\n");
						printf("\nTough luck buddy, you just lost %d euros on that one.\n", bet);
	         			bal = curbal;			  // reset balance and remove bet value
	         			bet = 0;				  // reset bet
					}
				}
				else if(flagcheck == 2) {

					if((numcasino%2) == 1){
						curbal = curbal + bet * 2;// add necesssary value one by the player
						printf ("\nLady Luck is smiling, the ball landed on an odd number, you just doubled the bet!\n");
						printf("To check your balance press 's'.\n");
						bet = 0;
					}
					else if ((numcasino%2) == 0) {
						printf("\n\nOuch, it would seem your idea backfired, it landed on an even number.");
						printf("\nTough luck buddy, you just lost %d euros on that one.\n", bet);
	          			bal = curbal;			  // reset balance and remove bet value
	          			bet = 0;;				  // reset bet
					}


				}


				break;
			case 'h':
			
				printText();					  // print the text in the void variable printtext

				break;
			case 's':							 // to see you current balance
				printf("Your current balance is %d euros.\n", curbal);

				break;
			case 'c':
				printf("It was a pleasure having you here, do come again!\n");
        		printf("You leave with %d euros.", curbal);
        		return 0;						//	exit game				

				break;
			default: 
        		break;	
		
		}
	} 

	return 0;
}
