#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

char name[MAX];
int numero[MAX];
int valor;
int paridade[MAX];
int rndom;
int saldo;
int aposta[MAX];
int repeticao[MAX];

//Prototipos de funções

int calcSaldo(int s, int a, int r)
{
        int result;
        if(r == 1)
                result = s + a;
        else
                result = s - a;

	return result;
}

int randomNumber(int min, int max)		//Gerador de numero aleatorio e função de roleta a seguir
{
	if(min>max)
	{
		int aux = min;
		min = max;
		max = aux;
	}
	return min + rand() % ((max-min)+1);
}

int spinRoulette()
{
	srand((unsigned int) time(NULL));
	rndom = randomNumber(0,36);
		printf("A bola calhou no nº %d\n\n", rndom);
	return rndom;
}

//Opcoes de jogo (valor e tipo de aposta)

int valorAposta()
{
	printf("Quanto queres apostar, %s?\n1. 1€\n2. 10€\n3. 20€\n" ,name);
	scanf("%d", &aposta[0]);
		if(aposta[0] == 1)
		{
			printf("Vais apostar 1€. \n");
			valor = 1;
		}
		else if(aposta[0] == 2)
		{
			printf("Vais apostar 10€. \n");
			valor = 10;
		}
		else if(aposta[0] == 3)
		{
			printf("Vais apostar 20€. \n");
			valor = 20;
		}
		else
			printf("Não apostaste dinheiro...\n");
		printf("\n");
	return 0;
}

//Modos de jogo

int betMode()
{
	int mode[MAX];
	printf("Que modo queres jogar? Especifico ou par/impar?\n");
	scanf("%d", &mode[0]);
		if(mode[0] == 1)     //Apostas num unico numero
		{
			printf("Sentes-te com sorte, %s? Então vamos lá! Escolhe um número de 1 a 36.\n" ,name);
			scanf("%d", &numero[0]);
			printf("ROOOOOOOOODA A ROLETAAA!!!\n");
			rndom = spinRoulette();
			if(rndom == 0)
			{
				saldo = calcSaldo(saldo, valor, 0);
				printf("Calhou no zero, %s! Perdeste o teu dinheiro da aposta... Já vi macacos com mais sorte...\n" ,name);
				printf("Tens %d euros\n\n", saldo);
			}
			else if(rndom != numero[0])
			{
				saldo = calcSaldo(saldo, valor, 0);
				printf("Ah... fica para a próxima...\n");
				printf("Tens %d euros\n\n", saldo);
			}
			else if(rndom == numero[0])
        	        {
				saldo = calcSaldo(saldo, 35*valor, 1);
				printf("CAMPEÃO!! Arriscaste e tiveste sorte! Vá vamos lá jogar mais um bocadinho.\n");
				printf("Tens %d euros\n\n", saldo);
			}
			else
			{
				printf("erro\n\n");
			}
		}

		else if(mode[0] == 2)  //Par ou impar
		{
			printf("Escolhe então,%s \n 1 ----> Par \n OU \n 2 ----> Impar\n" ,name);
			scanf("%d", &paridade[0]);
			if(paridade[0] == 1)
			{
				printf("ROOOOOOOOODA A ROLETAAA!!!\n\n");
				rndom = spinRoulette();
				if(rndom == 0)
				{
					saldo = calcSaldo(saldo, valor, 0);
					printf("Calhou zero! Perdeste o dinheiro da aposta... estás com azar pah.\n");
					printf("Tens %d euros\n\n", saldo);
				}
				else if(rndom % 2 == 0)
				{
					saldo = calcSaldo(saldo, valor, 1);
					printf("Calhou par!\n");
					printf("Jogaste seguro e recompensou, mas podia ter sido melhor, %s.\n",name);
					printf("Tens %d euros\n\n", saldo);
				}
				else
				{
					saldo = calcSaldo(saldo, valor, 0);
					printf("Calhou impar!\n");
					printf("Jogaste seguro, mas não compensou, agora tens tu de compensar o que perdeste se fores inteligente.\n");
					printf("Tens %d euros\n\n", saldo);
				}
			}
			else if(paridade[0] == 2)
			{
				printf("ROOOOOOOOODA A ROLETAAA!!!\n");
				rndom = spinRoulette();
				if(rndom == 0)
				{
					saldo = calcSaldo(saldo, valor, 0);
					printf("Calhou zero! Perdeste o dinheiro da aposta!\n");
					printf("Tens %d euros\n\n", saldo);
				}
				else if(rndom % 2 != 0)
				{
					saldo = calcSaldo(saldo, valor, 1);
					printf("Jogaste seguro e recompensou, mas podias ter sido melhor servido... Joga mais vá!\n");
					printf("Tens %d euros\n\n", saldo);
				}
				else
				{
					saldo = calcSaldo(saldo, valor, 0);
					printf("Jogaste seguro e não compensou, agora tens tu de compensar o que perdeste, %s...\n",name);
					printf("Tens %d euros\n\n", saldo);
				}
			}
			else
				printf("erro\n\n");
		}
		else
        	{
			printf("error\n\n");
		}
	return 0;
}


int main()
{

	saldo = 100;

	printf(" _________    _______        ______     __________  _        _  \n");
	printf("|=========|  |       *      /======*    =======//    *      /   \n");
	printf("| |          |        |    / /    * *         //      *    /    \n");
	printf("| |          |========    / /______* *       //        *  /     \n");
	printf("| |          |       *   |  ========  |     //          ||      \n");
	printf("| |          |        *  |  |      |  |    //           ||      \n");
	printf("|=========|  |         * |__|      |__|   =========     ||      \n");


	printf(" ______       ______      _           ________  _________      ______     \n");
	printf("|      *     /======*     |          |========  =========     /======*    \n");
	printf("|       |   /        *    |          |              |        / /    * *   \n");
	printf("|=======   |          |   |          |======        |       / /______* *  \n");
	printf("|      *    *        /    |          |              |      |  ========  | \n");
	printf("|       *    *      /     |          |              |      |  |      |  | \n");
	printf("|        *    ======      =========  |=========     |      |__|      |__| \n");


	printf("Como se chama?\n");
	scanf("%s", name);
	printf("Boa noite caro/a %s. Bem vindo ao Casino do Obunga, és novo/a aqui certo?... Bem, não interessa, o que importa é o dinheiro, estás pronto/a para um jogo da CRAZY ROLETA?!""\n", name);
	printf("O teu saldo é: %d\n\n", saldo);
        printf("Modo de jogo 1: Apostas num número específico? De 1 a 36. Arriscado, mas ganhas MAIS dinheiro!!\n");
        printf("OU \nModo de jogo 2: Apostas em números pares ou ímpares? É mais seguro, mas assim nao ganhas tanto dinheiro, novato/a.\n");
        printf("Cuidado! se calhar 0 perdes automaticamente o dinheiro que apostares...\n\n");
	printf("\n");
        while(saldo > 0)
        {
		printf("%d", valorAposta());
		printf("\n");
		printf("%d", betMode());
		printf("E então o que achas? É para continuar?\n");
		printf("1 ----> Sim \nOU \n2 ----> Não\n");
		scanf("%d", &repeticao[0]);
		if(repeticao[0] == 2)
		{
			printf("Foi bom enquanto durou %s, até à proxima\n", name);
			printf("Levas %d euros\n\n", saldo);
			return 0;
		}
	}
	printf("Ficaste sem dinheiro!! Pode ser que tenhas mais sorte para a próxima vez!!\n");
	return 0;
}
