#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


int balance = 100;
unsigned short dificuldade = 0;
int number;
int rolar(void);
int apostar_num, valor_aposta;
char menu_opcoes;

unsigned short selecionar_dificulade();

int escolha_num();
int escolha_par();
int escolha_impar();
int opcoes();
int escolher_opcao();

unsigned short aposta_min;
unsigned short par(int number);
unsigned short impar(int number);
unsigned short fazer_aposta(int balance, int valor_aposta);


int main() 
{
    printf("Bem vindos a roleta!\n");
    dificuldade = selecionar_dificulade();
    opcoes();
   
    unsigned short quit = 0;
    //jogar enquanto o jogador tiver dinheiro
    while (quit == 0)
    {
        escolher_opcao();
        switch(menu_opcoes)
        {
            case 'n':               //apostar num número entre 1 a 36
                escolha_num();
                if (balance <= 0)
                    quit = 1;
                break;
                
            case 'p':               //apostar par 
                escolha_par();
                if (balance <= 0)
                    quit = 1;
                break;
                
            case 'i':               //apostar impar
                escolha_impar();
                if (balance <= 0)
                    quit = 1;
                break;
                
            case 'd':
                dificuldade = selecionar_dificulade();
                break;
                
            case 'o':               //mostrar o menu outra vez
                opcoes();
                break;
                
            case 's':               // mostrar o balance
                printf("\nBalance: %d€", balance);
                break;
                
            case 'q':               //sair do jogo
                printf("Adeus. Sais daqui com %d€.\n",balance);
                quit = 1;
                break;
                
            default:                // quando a opçao nao é valida  
                printf("\nNao é uma opçao.");
                
        }
    }
    
}


int escolher_opcao()          //selecionar uma opçao do menu
{
	printf("\nEscolhe uma opção: ");
	scanf(" %c", &menu_opcoes);
	return 0;
}


int opcoes()
{ 
	printf("Opções:\n");
	printf("\tn - apostar num número especifico entre 1 e 36\n");
	printf("\tp - apostar número par\n");
	printf("\ti - apostar número impar\n");
	printf("\to - opções\n");
	printf("\td - dificuldade\n");
	printf("\ts - show balance\n");
	printf("\tq - cashout and leave\n");
	printf("\n\tBalance: %d €\n", balance);
	return 0;
}

unsigned short selecionar_dificulade()
{
    char opcao = 0;
    
    while (1)
    {
        printf("\nSeleciona a dificuldade: ");
        printf("\nb - 1€  Beginner");
        printf("\nn - 10€ Normal");
        printf("\ne - 20€ Expert\n");
        scanf(" %c",&opcao);
        
        switch (opcao)
        {
            case 'b':
                return 1;
                break;
            case 'n':
                return 10;
                break;
            case 'e':
                return 20;
                break;
            default:
                printf("\nNão é uma dificuldade valida. ");
        }
    }
}

unsigned short fazer_aposta(int balance, int valor_aposta)
{
    if (valor_aposta > balance)
        printf("\nNão tens esse dinheiro todo!");
    else if (valor_aposta < dificuldade)
        printf("\nNão podes apostar menos que %d€.", dificuldade);
    else 
    {
        balance -= valor_aposta;
        return 1;
    }
    
    valor_aposta = 0;
    return 0;
}

void tensao()
{
    unsigned short count = 0;
    while(count++ < 4)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
}

unsigned short apostar_num_numero()
{
    printf("\nEscolhe um número de 1 a 36, o número 0 é da casa: ");
    scanf("%d",&apostar_num);
    if (apostar_num < 0 || apostar_num > 36)
        return 0;
        
    return 1;
}
int escolha_num() //o que fazer quando o jogador escolhe apostar numero
{
    if(apostar_num_numero())
    {
        printf("\nQuanto é que queres apostar? Recebes 35x o valor que apostaste: ");
        scanf("%d",&valor_aposta);
        if (fazer_aposta(balance,valor_aposta))
        {
            printf("\nApostaste %d€ no número %d", valor_aposta, apostar_num);
            printf("\nCarrega no ENTER para rolar! Boa sorte!");
            getchar();
            getchar();
            tensao();
            rolar();
            if (number == 0 || number != apostar_num)
            {
                balance -=valor_aposta;
                printf("\nUps, que azar! Perdeste %d€. O teu balance é de %d€\n",valor_aposta, balance);
            }
            else
            {
                balance += (valor_aposta*35);
                printf("\nParabéns! O teu balance é de %d€",balance);
            }
        }
    }
    else 
        printf("Não é valido.");
    return 0;
}


unsigned short par(int number)
{
    if ((number &1) == 0)
        return 1;
    return 0;
}

unsigned short impar(int number)
{
    if ((number &1) != 0)
        return 1;
    return 0;
}

int escolha_par()    //o que acontece quando o jogador escolhe par
{
    printf("\nQuanto é que queres apostar nos pares? Recebes 2x o valor que apostaste: ");
    scanf("%d", &valor_aposta);
    if (fazer_aposta(balance,valor_aposta))
    {
        printf("\nApostaste %d€ no par.",valor_aposta);
        printf("\nCarrega no ENTER para rolar! Boa sorte!");
        getchar();
        getchar();
        tensao();
        rolar();
        
        if (par(number))
        {
            balance += valor_aposta;
            printf("\nParabéns! O teu balance é de %d€",balance);
        }
        else
        {
            balance -= valor_aposta;
            printf("\nUps, que azar! Perdeste %d€. O teu balance é de %d€\n",valor_aposta, balance);
        }
    }   
    return 0;
}

int escolha_impar()      //o que acontece quando o jogador escolhe impar
{
    printf("\nQuanto é que queres apostar nos impares? Recebes 2x o valor que apostaste: ");
    scanf("%d", &valor_aposta);
    if (fazer_aposta(balance,valor_aposta))
    {
        printf("\nApostaste %d€ no impar.",valor_aposta);
        printf("\nCarrega no ENTER para rolar! Boa sorte!");
        getchar();
        getchar();
        tensao();
        rolar();
        if (impar(number))
        {
            balance += valor_aposta;
            printf("\nParabéns! O teu balance é de %d€",balance);
        }
        else
        {
            balance -= valor_aposta;
            printf("\nUps, que azar! Perdeste %d€. O teu balance é de %d€\n",valor_aposta, balance);
        }
    }
    return 0;
}

int rolar(void)
{
    srand(time(NULL));
    number=1+(rand()%36);
    printf("\nSaiu o número %d\n", number);
    return number;
    
}
