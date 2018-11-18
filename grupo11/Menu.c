#include <stdio.h>
#include "Casino.h"
#include "Menu.h"

#define STRING_LENGTH 256

//This method prints out the current player stats.
void PrintStats(int balance, int currentBet)
{
	printf("\n\tBalance : \t%d €", balance);
	printf("\n\tCurrent bet : \t%.2d €", currentBet);
}

//This method prints out the game menu.
void PrintMenu(int balance, int currentBet)
{
	printf("Welcome to crazy roleta! Do you feel lucky today?");
	PrintStats(balance, currentBet);
	printf("\n\tChoose option");
	printf("\n\tb <amount> - amount of money you want to bet");
	printf("\n\tn <number> - bet on a specific number - pays 35 to 1");
	printf("\n\te - bet on even number - pays 2 to 1");
	printf("\n\to - bet on odd number  - pays 2 to 1");
	printf("\n\tr - roll");
	printf("\n\th - help");
	printf("\n\ts - show balance");
	printf("\n\tp - save game");
	printf("\n\tl - load previous game");
	printf("\n\tc - cashout and go home");
}

/*This method repeats itself until the player has made a correct selection on the minimum value to bet.
Returns the minimum value to bet (1; 10; 20).*/
unsigned short MinBetSelection()
{
	char line[STRING_LENGTH];
	char option;

	//Repeat Forever...
	while (1)
	{
		printf("Select difficulty level : ");
		printf("\na - 1â‚¬ Beginner");
		printf("\nb - 10â‚¬ Normal");
		printf("\nc - 20â‚¬ Expert\n\nSelection : ");
		
		fgets(line, STRING_LENGTH, stdin);
		sscanf(line, "%c", &option);

		switch (option)
		{
			case 'a': // Exit loop returning 1.
				return 1;
			case 'b': // Exit loop returning 10.
				return 10;
			case 'c': // Exit loop returning 20
				return 20;
			default:
				printf("\nUnkonwn option. please try again.\n");
		}
	}
}

//This Method is the main game loop.
void MainLoop(unsigned short minBet)
{
	int             balance		= 100,
			currentBet	= 0,
			tempBet		= 0,
			numberBet	= -1;
	unsigned short	betType			= None;
	unsigned short  quit			= 0;
	char            line[STRING_LENGTH],
			option;
	int 		decimal 		= 0;
	FILE*		file;

	//Prtins out menu.
	PrintMenu(balance, currentBet);

	//Until quit variable is not 0 repeat.
	while (quit == 0)
	{
		printf("\nPlease select option\n");
		fgets(line, STRING_LENGTH, stdin);
		sscanf(line, "%c %d", &option, &decimal);
		switch (option)
		{
			case 's': //Prints the player stats.
				PrintStats(balance, currentBet);
				break;
			case 'e': //Make bet on a even number.
				betType = Even;
				printf("\nyou are betting on a even number.");
				break;
			case 'o': //Make bet on a odd number
				betType = Odd;
				printf("\nyou are betting on a odd number.");
				break;
			case 'r': //Roll numbers.
				if (Roll(&balance, &currentBet, &numberBet, betType))
				{
					if (balance <= 0)
						quit = 1;
					else
						PrintStats(balance, currentBet);
					betType = None;
				}
				break;
			case 'b': //Bet money.
				currentBet += decimal;
				if (MakeBet(&balance, &currentBet, decimal, minBet))
					PrintStats(balance, currentBet);
				break;
			case 'n': //Bet on a specific number
				numberBet = decimal;
				if (BetOnNumber(&numberBet) == 1)
					betType = Number;
				break;
			case 'c': //Cashout.
				printf("\nSort of hoping that you'd stay.");
				printf("\nSad to see you go...");
				quit = 1;
				break;
			case 'h': //Prints menu.
				PrintMenu(balance, currentBet);
				break;
			case 'p': //Save game
				file = fopen("Saved game.sv", "w+");
				fprintf(file, "%d\n", balance);
				fprintf(file, "%d\n", currentBet);
				fprintf(file, "%d\n", minBet);
				fclose(file);
				printf("\nYou have saved the game.");
				printf("\n\n");
				break;
			case 'l': //Load saved game.
				if ((file = fopen("Saved game.sv", "r+")) != NULL)
				{
					fscanf(file, "%d\n", &balance);
					fscanf(file, "%d\n", &currentBet);
					fscanf(file, "%d\n", &minBet);
					fclose(file);
					printf("\nYou have loaded a previously saved game.");
					printf("\n\n");
					PrintMenu(balance, currentBet);
				}
				else
					printf("\nThere is no saved game to load.");
				break;
			default: //Prints unkown command.
				printf("\nCan't understand you mate. Write h and press enter to show menu options");
				break;
		}
	}

	printf("\nYou walk away with %d €", balance + currentBet);
	printf("\nGame over");
	fgets(line, STRING_LENGTH, stdin);
}
