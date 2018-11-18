//trabalho feito por inacio, vitor e joao


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
}

int main(void) 
{
  //variaveis
  char input = 'z'; // default input
  int creditos = 100;
  int aposta = 0;
  int numEscolha=0;
  int number;
  int tryAgain = false;
  int evenOdd;
  int i;
  int apostaMin;
  int perguntar = false;
  int dificuldade;

while(perguntar==false)
{
  printf("Choose yor level of difficulty:\n");
  printf("1 for (1€) Begginer\n");
  printf("2 for (10€) Normal\n");
  printf("3 for (20€) Expert\n");
  printf("Choose an option!");
  scanf("%d", &dificuldade);

  if(dificuldade='1')
  {
    apostaMin=1;
    perguntar=true;
  }
  else if(dificuldade='2')
  {
    apostaMin=10;
    perguntar=true;
  }
  else if(dificuldade='3')
  {
    apostaMin=20;
    perguntar=true;
  }

}

//introducao
printf("Welcome to the Roulette Game!\n");
printf("\n");
printf("Available options:\n");
printf("To roll or bet, use 'b' beforehand to specify how much money you want to use.\n");
printf("\n");
printf("\t n - Roll on a specified number.            (Pays 1 to 35.)\n");
printf("\t r - Roll on an even or odd number.         (Pays 1 to 2.)\n");
printf("\t h - Help.\n");
printf("\t c - Cash out and go home!\n");
printf("\n");

while (creditos>=0)//loop para continuar a jogar
{
  while (input=='z')
  {
    tryAgain = false;
    printf("\tBalance   -       %d€\n", creditos);
    printf("\tBet       -       %d€\n", aposta);
    printf("\n");
    printf("Choose an option!");
    scanf("\t %c", &input);
  }

  //opções
  // apostar dinheiro
  while (input=='b' && tryAgain==false) 
  {
    printf("How much money do you want to bet?");
    scanf("%d",&aposta);

    if(aposta>creditos)
    {
      printf("You bet more than what you have!\n");
    }
    else if(aposta<apostaMin)
    {
      printf("Bet the minimum first!!\n");
    }
    else
    {
      tryAgain=true;
      input='z';  
    }    
  }


  // apostar num numero especifico
  while (input=='n')
  {
    if(aposta<=0)
    {
    printf("Bet your money first!\n");
    input='z';
    break;
    }
    while(tryAgain==false)
    {
      printf("Feeling lucky, eh? What number do you want to bet on?\n");
      printf("(1 to 36.)");
      scanf("%d", &numEscolha);

      if(numEscolha<1)
      {
        printf("Invalid number.\n");
      }
      else if(numEscolha>36)
      {
        printf("Invalid number.\n");
      }
      else
      {
        //temporizador
        for (i = 4; i > 0; i--) { 
        delay(4); 
        printf("-\n");
        }
        //temporizador

        srand(time(NULL));                              //funcao rolar
        number=rand()%37;                               //funcao rolar
        printf("---------------------------\n");        //funcao rolar
        printf("The ball has landed on %d!\n", number); //funcao rolar
        printf("---------------------------\n");        //funcao rolar
        if (number==numEscolha && number!=0)
        {
          creditos += (aposta*35);
          printf("Winner! You now have %d€ in your pocket!\n", creditos);
          printf("\n");
          tryAgain=true;
          input='z';
          break;
        }
        else
        {
          creditos -= aposta;
          printf("Sorry. You've lost $%d.\n\n", aposta);
          tryAgain=true;
          input='z';
          break;
        }
      }
    }
  }
  while(input=='r')
  {
    if(aposta<=0)
    {
    printf("Bet your money first!\n");
    input='z';
    break;
    }
    
    printf("Even or odd?\n(1 for Even.)\n(2 for Odd.)\n");
    scanf("%d", &evenOdd);

    if(evenOdd!= 1 && evenOdd!= 2)
    {
      printf("Invalid choice!\n");
    }

    if(evenOdd==1)
    {
      //temporizador
      for (i = 4; i > 0; i--) { 
      delay(4); 
      printf("-\n");
      }
      //temporizador
      
      srand(time(NULL));
      number=rand()%37;
      printf("---------------------------\n");
      printf("The ball has landed on %d!\n", number);
      printf("---------------------------\n");
      if (number%2==0 && number!=0)
      {
        creditos += (aposta*2);
        printf("Winner! You now have %d€ in your pocket!\n", creditos);
      }
      else
      {
        creditos -= aposta;
        printf("Sorry. You lost %d€. Your new balance is %d€\n", aposta, creditos);
      }
      input='z';
    }
    else if(evenOdd==2)
    {
      //temporizador
      for (i = 4; i > 0; i--) { 
      delay(4); 
      printf("-\n");
      }
      //temporizador

      srand(time(NULL));
      number=rand()%37;
      printf("---------------------------\n");
      printf("The ball has landed on %d!\n", number);
      printf("---------------------------\n");
      if (number%2==1 && number!=0)
      {
        creditos += (aposta*2);
        printf("Winner! You now have %d€ in your pocket!\n", creditos);
      }
      else
      {
        creditos -= aposta;
        printf("Sorry. You lost %d€. Your new balance is %d€\n", aposta, creditos);
      }
      input='z';
    }
  }

  // help
  if(input=='h')
  {
    printf("\n");
    printf("Available options:\n");
    printf("To roll or bet, use 'b' beforehand to specify how much money you want to use.\n");
    printf("\n");
    printf("\t n - Roll on a specified number.     (Pays 1 to 35.)\n");
    printf("\t r - Roll on a even or odd number.   (Pays 1 to 2.)\n");
    printf("\t h - Help.\n");
    printf("\t c - Cash out and go home!\n");
    printf("\n");
    input='z';
  }
  // cash out and go home
  if(input=='c')
  {
    printf("You're done? Alright. Here's what you leave with:\n");
    printf(" %d€ in your pocket!\n", creditos);
    printf("\n");
    printf("You leave feeling...\n");
    
    if(creditos < 5)
      {
          printf("0-4");
      }
      else if(creditos >=5 && creditos < 10)
      {
          printf(" Regret. At least you can pay a cab home.");
      }
      else if(creditos >=10 && creditos < 100)
      {
          printf(" Okay, at least you didn't spend all of it...");
      }
      else if(creditos >=100 && creditos < 500)
      {
          printf(" Alright. You left before you got greedy.");
      }
      else if(creditos >=500 && creditos < 1000)
      {
          printf(" Nice! Pretty good pay off!");
      }
      else if(creditos >=1000 && creditos < 2500)
      {
          printf(" Smart! Leaving with the most that you could get!");
      }
      else if(2500 <= creditos)
      {
          printf(" AMAZING! You're rich!");
      }
    return 0;
  }

}//program while ends here DO NOT GO OVER

}
