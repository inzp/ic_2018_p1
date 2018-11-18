#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "roleta_funcoes.h"

const int NumsRoletta = 36;
#define MIN_APOSTA minAposta;

int indice, n, balanco, currentBet, minAposta;
char bet;

int balanco = 100;
int currentBet = 0;

//Gerador de numeros aleatorios da roleta
void Gerar_Random(){ /*Este gerador mudifica a seed para o numero aleatorio, utilizando o tempo do computador, garantido que o numero gerado e de facto aleatorio de cada vez que se joga*/
	long ultime;
	time(&ultime);
	srand((unsigned) ultime);
}

int NumAleatorio() {
	indice = rand()%NumsRoletta;
	return indice;
}


//Menus de interface com o jogador
void Intro(){
	printf("Welcome to the Roulette!\n\n");
	printf("- Well, well, well... it's been a minute since I last saw such an handsome face around these parts. Y'know what darlin', I might as well put my money where my mouth is and give ya some to bet.\n\n");
	printf("You just earned %d €!\n", balanco);
}

void Menu(){
	switch (bet){
	case 'H': case 'h':
		Help();
		break;
	case 'B': case 'b':
		P_apostar();
		break;
	case 'C': case 'c':
		Balanco();
 		break;
	case 'N': case 'n':
		ApostaN(); /*recolhe o numero dado pelo jogador para facilitar a organizar o procedimentos dentro do menu*/
		if (currentBet!=0 && n==indice){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- Now that's what ya call being on a roll! Ya show 'em darlin'!\n");
			balanco = balanco + NumsRoletta*currentBet;
			currentBet = 0;
		} else if (currentBet!=0 && n!=indice){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- Oh! Better luck next time sugar.\n");
			currentBet = 0;
		}
		break;
	case 'E': case 'e': /*Para o caso par-impar nao e necessario fazer o mesmo que no caso N porque a verificacao das condicoes e mais direta*/
		if (currentBet!=0 && indice%2==0){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- Now that was a good one! Bloody knew ya had it in ya sugar.\n");
			balanco = balanco + 2*currentBet;
			currentBet = 0;
		} else if (currentBet!=0 && indice%2!=0){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- Y'know what they say, nothing gold can stay forever... yet bad luck still remains... *sigh*\n");
			currentBet = 0;
		}
			break;
	case 'O': case 'o':
		if (currentBet!=0 && indice%2!=0){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- I see you've met my friend Lady Luck! No loyalty among thieves nowadays, he he he...\n");
			balanco = balanco + 2*currentBet;
			currentBet = 0;
		} else if (currentBet!=0 && indice%2==0){
			printf("\n\n## And the number is...%d!\n", indice);
			printf("- Shame darlin', that's a loss... I know ya can do better than that!\n");
			currentBet = 0;
		}
			break;
	case 'L': case 'l':
		printf("\n\n- I see... Well, this was fun. See ya 'round, stranger.\n");
		exit(1); /*Force quit no programa para ter a certeza de que o jogador nao fica preso dentro do mesmo*/
		break;
	}
}

void SelectMenu(){ /*Interface "grafica" para as escolhas na funcao Menu*/
	printf("\n\n[B - Set Bet] [C - Check Balance] [H - Help] [L - Leave]\n[E - Bet Even] [O - Bet Odd] [N - Bet Number]\n\n");
	printf("- So, how's it gonna be? :");
	scanf(" %c", &bet);
}


//Menu de niveis e variaveis de condicao
void SwLevel(){
	char nivel;
	printf("\n\nI'm not feeling so lucky... (min = 10 €) - S\n");
	printf("I'm feeling lucky (min = 20 €) - M\n");
	printf("I'll give you a run for your money! (min = 30 €) - L\n");
	printf("\n - How lucky you reckon ya feelin' today? : ");
	scanf("%c", &nivel);
	getchar();
	switch (nivel){
		case 'S': case 's':
			minAposta = 10;
			break;
		case 'M': case 'm':
			minAposta = 20;
			break;
		case 'L': case 'l':
			minAposta = 30;
			break;
		}
}


//Quadro de Intrucoes
void Help(){
	printf("\n\nThe Roulette is a game that allows you to bet money on three different categories: on a specific number between 0-35 and on even or odd numbers, also within the 0-35 limit. If you manage to guess the right number while betting on the first category, you'll get 35 x the money you betted; whereas on the second, you'll only get 2 x the money.\nDon't forget, you must bet some money before choosing the category.\n- Easy, eh? Though ya should keep in mind if you run outta money, you run outta fun too. So bet wisely darlin'!\n");
}


//Quadro e controlo de Balanco
void Balanco(){
	printf("\n\nBalance: %d €\n", balanco);
	printf("Current bet: %d €\n\n", currentBet);
}


//Sistema de apostas
int P_apostar() {
	while(currentBet<minAposta){
		printf("\n\nLevel's smallest bet: %d \n", minAposta);
		printf("\n- How much do ya wanna bet, sugar? : ");
		scanf("%d", &currentBet);
		getchar();
		if(balanco <= 0){ /*Esta condicao garante que o jogo termina uma vez que o balanco for 0*/
			currentBet = 0;
			printf("\n\n\n- Hate to ruin the fun for ya but you're outta money darlin'! Time to call it a day, just wait till lady luck rubs off on ya some more and drop by some other time. See ya 'round!\n");
			exit(1); /*Para garantir que realmente termina - force quit*/
		}
	balanco = balanco - currentBet;
	}
	return balanco;
}


//Procedimentos unicos para a aposta N
int ApostaN(){
	do{
		printf("Which number would ya like, darlin'? : ");
		scanf("%d", &n);
	}
	while (n!=0 && n>NumsRoletta); /*Estas duas condicoes permitem ao programa insistir na pergunta ate ambas serem satisfeitas*/
	return n;
}
