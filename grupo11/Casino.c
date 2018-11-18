#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Casino.h"
 
void Delay(int milliSeconds)
{
	clock_t startTime = clock();

	//loop while clock hasn't reached time
	while (clock() < startTime + milliSeconds);
}
 
//This Method generates a integer number between min and max
int RandomRange(int min, int max)
{
	//Switch minimum value with max, if min is bigger than max.
	if (min > max)
	{
		int aux = min;
		min = max;
		max = aux;
	}

	//Return random generated integer.
	return min + rand() % (max - min + 1);
}

//This method return 1 (true) if the number is even and 0 (false) if otherwise.
unsigned short IsEven(int number)
{
	/*This is a bit operation...
	if the last bit is 1 then the number should be odd.
	if the last bit is 0 then the number should be even.
	Returns 1 (true) if the binary number ends with 0.*/
	if ((number & 1) == 0)
		return 1;

	//Returns 0 (false) if otherwise
	return 0;
}

/*This method outputs '.' 4 times in 4 seconds
It is intended take 4 seconds so that it creates tension before the roll number is given.*/
void CreateTension()
{
	for (int i = 0; i < 4; i++)
	{
		printf(".");
		fflush(stdout);
		Delay(1000);
	}
}

/*This method assigns a number for betting.
It has to be between 0 and 36. If it is this method will return 1 otherwise 0.*/
unsigned short BetOnNumber(int *numberBet)
{
	//Check if number to bet on, is between 0 and 36
	if (*numberBet < 0 || *numberBet > 36)
		printf("You have to bet on a number between 0 and 36.");
	else
	{
		//Number to be bet on is correct. Return 1 (true).
		printf("\nyou are betting on number %d", *numberBet);
		return 1;
	}
	
	//No bet has been properly set. Return 0 (false)
	return 0;
}

/*This method Creates a bet.
First it checks if the player has the money. Then it checks if the current bet is under the minimum bet value.
If the ammout of money to bet on is correct then this method will return 1 (true) and 0 (false) otherwise.*/
unsigned short MakeBet(int *balance, int *currentBet, int auxBet, unsigned short minBet)
{
	//Check if the player has the money.
	if (*currentBet > *balance)
		printf("\nWhat's wrong with you... You don't have that much money!");
	//Check if money amount to bet is under the minimum bet amount.
	else if (*currentBet < minBet)
		printf("\nYou can't bet under %d €", minBet);
	//This code is executed if all the necessary requirements have been met.
	//And a bet has been placed. Return 1 (true).
	else
	{
		printf("\nYou are betting %d €", *currentBet);
		*balance -= auxBet;
		return 1;
	}

	//The bet couldn't be done. Reset current bet and return 0 (false).
	*currentBet = 0;
	return 0;
}

/*This method checks if the player wins or loses the current bet he made.
First, the method checks if a bet has been properly made.
Then, the method checks if the player has bet any money.
Then, accordingly to the bet type the player has bet on, this method checks if player has won.
If the player has won then change balance and current bet.
This method sould return 0 (false) if the roll could be done and 1 (true) if the roll was successfuly.*/
unsigned short Roll(int *balance, int *currentBet, int *numberBet, unsigned short betType)
{
	/*If the bet was made on a specific number and that number hasn't been set then return 0 (false).
	If the no bet has been made. return 0 (false)*/
	if (betType == Number && *numberBet == -1 || betType == None)
	{
		printf("\nHey dude...Bet on a number first!");
		return 0;
	}

	//If the no money has been placed on the bet return 0 (false).
	if (*currentBet <= 0)
	{
		printf("\nHey dude...Put your money on the table first!");
		return 0;
	}

	printf("\nOk, lets (rock) and roll");
	printf("\nAnd the number is");
	
	//Wait for the number to be given out.
	CreateTension();

	//Generate a random number between 0 and 36.
	int rollNumber = RandomRange(0, 36);

	printf("%d", rollNumber);

	//Check if the player won or lost accordingly to he's bet type.
	switch (betType)
	{
		case Number: //Player has bet on a specific number
			if (rollNumber == 0 || rollNumber == 36 || *numberBet != rollNumber)
				printf("\nYou lost... sory about that mate");
			else
			{
				printf("\nYou win... Congratulations.");
				*balance += 35 * (*currentBet);
			}
			break;
		case Odd: //PLayer has made a bet on an odd number.
			if (!IsEven(rollNumber))
			{
				printf("\nYou win... Congratulations.");
				*balance += 2 * (*currentBet);
			}
			else
				printf("\nYou lost... sory about that mate");
			break;
		case Even: //Player has made a bet on a even number.
			if (IsEven(rollNumber))
			{
				printf("\nYou win... Congratulations.");
				*balance += 2 * (*currentBet);
			}
			else
				printf("\nYou lost... sory about that mate");
			break;
	}

	//Reset Current bet
	*numberBet	= -1;
	*currentBet = 0;

	//Return 1 (true). Indicating a successful roll.
	return 1;
}