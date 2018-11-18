#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

/*Variaveis de banco, numero escolhido pelo jogador, numero gerado, valor da aposta, tipo de aposta, paridade, dificuldade e resposta de jogar novamente.*/
int banco = 100;
int numero_apostado, numero, valor;
char tipo, par_impar, resposta_dif;
char resposta = 's';

/*Funcoes de funcionamente e limitacoes.*/
int dificuldade()
{
  printf("\ndificuldade de jogo:\n\n f - facil (aposta min. 1e)\n m - media (aposta min. 10e)\n d - dificil (aposta min. 20e)\n\nqual queres?\n");
  scanf("%s", &resposta_dif);
  while (resposta_dif != 'f' && resposta_dif != 'm' && resposta_dif != 'd')
  {
    printf("\ndificuldade inexistente\n\ndificuldade de jogo:\n\n f - facil (aposta min. 1e)\n m - media (aposta min. 10e)\n d - dificil (aposta min. 20e)\n\nqual queres?\n");
    scanf("%s", &resposta_dif);
  }
  return 0;  
}

int valor_aposta()
{
  printf("\nfaz a tua aposta.(euros)\n");
  scanf("%d", &valor);

  if (resposta_dif == 'f')
  {
    while (valor <= 0 || valor > banco) 
    {
      printf("\nvalor invalido\n\ninsere outra vez a tua aposta.(euros)\n");
      scanf("%d", &valor);
    }
  }
  else if (resposta_dif == 'm')
  {
    while (valor < 10 || valor > banco) 
    {
      printf("\nvalor invalido\n\ninsere outra vez a tua aposta.(euros)\n");
      scanf("%d", &valor);
    }
  }
  else 
  {
    while (valor < 20 || valor > banco) 
    {
      printf("\nvalor invalido\n\ninsere outra vez a tua aposta.(euros)\n");
      scanf("%d", &valor);
    }
  }

  banco = (banco - valor);  
  printf("\naposta: %de \n\n", valor);
  return 0;  
}

int tipo_aposta()
{
  printf("\n\nopcoes de aposta:\n\n p - par\n i - impar\n n - numero\n\nqual queres?\n");
  scanf("%s", &tipo);
  while (tipo != 'p' && tipo != 'i' && tipo != 'n')
  {
    printf("\nopcao invalida\n\nopcoes de aposta:\n p - par\n i - impar\n n - numero\n\nqual queres?\n");
    scanf("%s", &tipo);
  }
  return 0;  
}

int jogarnovamente()
{
  if (banco == 0 )
  {
    printf("\n\ngame over, ate a proxima.");  
  }
  else //if (resposta != 'n')
  {
    printf("\n\nqueres rodar outra vez?(s/n)\n");
    scanf("%s", &resposta);
    while (resposta != 'n' && resposta != 's')
    {
      printf("s ou n!\n");
      scanf("%s", &resposta);
    }
  }
  /*else
  {
    printf("\nate a proxima");
  }*/
  return 0;
}

int main()
{
  printf("JOGO DA ROLETA\n\nneste jogo gira-se uma roleta com numeros de 0 a 36 e com os 100e que te damos e alguma sorte a mistura podes tentar adivinha-lo ou se e par ou impar! nao te esquecas que o 0 e o nosso numero da sorte :D\n________________________________________________________");

  printf("\n\nbanco: %de\n", banco);

  dificuldade();

  while (banco > 0 && resposta == 's')
  { 
    tipo_aposta();
    
    valor_aposta();

    srand(time(NULL));  
    int numero = rand() % 36 + 0;
    if (numero % 2 == 0)
    {
      par_impar = 'p';
    }
    else
    {
      par_impar = 'i';
    }

    if (tipo == 'n')
    {
      printf("em que numero? \n");
      scanf("%d", &numero_apostado);
      while (numero_apostado < 1 || numero_apostado > 36)
      {
        printf("\nso podes apostar entre 1 e 36\n\nque numero deseja?\n");
        scanf("%d", &numero_apostado);
      }

      if (numero_apostado == numero)
      {
        printf("\no numero da bola e...........\n");
        sleep(3);
        printf("%d, ganhaste :)\n", numero);
        banco = banco + valor * 35;
      }
      else
      { 
        printf("\no numero da bola e...........\n");
        sleep(3);
        printf("%d, perdeste :(\n", numero);
      }
    }
    else if (tipo == par_impar && numero == 0)
    {
      printf("\no numero da bola e...........\n");
      sleep(3);
      printf("%d, perdeste, 0 e o numero da casa :( \n", numero);
    }
    else if (tipo == par_impar) 
    {
      printf("\no numero da bola e...........\n");
      sleep(3);
      printf("%d, ganhaste :)\n", numero);
      banco = banco + valor * 2;
    }
    else
    { 
      printf("\no numero da bola e...........\n");
      sleep(3);
      printf("%d, perdeste :(\n", numero);
    }

    sleep(1);

    printf("__________________________________________\n\nbanco: %de", banco);

    sleep(2);

    jogarnovamente();

    if (resposta == 'n')
    {
      printf("\nate a proxima");
    }
  }
  return 0;
}
