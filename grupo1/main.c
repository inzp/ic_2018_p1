#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// Set initial random
	srand( time(0) );
	
	// Initial money
	int cur_money = 100;
	
	// Loop while he has money
	while ( cur_money > 0 )
	{
		printf("Tens %d$.\n", cur_money);
		
		int bet_amount;
		printf("Quanto queres apostar? ");
		scanf("%d", &bet_amount);
		
		if ( bet_amount > cur_money || bet_amount < 1 )
		{
			printf("Não podes não apostar. Tenta outro valor\n");
			continue;
		}
		
		cur_money -= bet_amount;
		
		printf("Em que queres apostar?\n");
		printf("1. Num número\n");
		printf("2. Num par\n");
		printf("3. Num ímpar\n");
		
		int option_answer;
		scanf("%d", &option_answer);
		
		// Set random 
		int roulette_number = 1 + 34*(rand() / (float)RAND_MAX); 
		
		// Number
		if ( option_answer == 1 )
		{
			printf("Em que número queres apostar? ");
			int number_answer;
			scanf("%d", &number_answer);
			
			printf("Saíu o número %d\n", roulette_number);
			if ( number_answer == roulette_number )
			{
				printf("Parabéns, ganhas-te %d$\n", bet_amount*35);
				cur_money += bet_amount*35;
			}
			else
			{
				printf("OOF, perdes-te %d$\n",  bet_amount);
			}
		}
		
		// Even
		if ( option_answer == 2 )
		{
			printf("Saíu o número %d\n", roulette_number);
			if ( roulette_number % 2 == 0 )
			{
				printf("Parabéns, ganhas-te %d$\n", 2*bet_amount);
				cur_money += 2*bet_amount;
			}
			else
			{
				printf("OOF, perdes-te %d$\n",  bet_amount);
			}
		}
		
		// Odd
		if ( option_answer == 3 )
		{
			printf("Saíu o número %d\n", roulette_number);
			if ( roulette_number % 2 == 1 )
			{
				printf("Parabéns, ganhas-te %d$\n", 2*bet_amount);
				cur_money += 2*bet_amount;
			}
			else
			{
				printf("OOF, perdes-te %d$\n",  bet_amount);
			}
		}
		
		// Tell the user how much money they have
		printf("Tens %d$.\n", cur_money);
		
		// Check if the user wants to exist
		printf("Queres parar de jogar? (y/n) ");
		char leave_answer;
		scanf(" %c", &leave_answer);
		
		if ( leave_answer == 'y' || leave_answer == 'Y' )
		{
			break;
		}
	}
	
	// Check if user is out of money 
	if ( cur_money == 0 )
	{
		printf("Ficas-te sem dinheiro por isso foste obrigado a sair\n");
	}
	
}
