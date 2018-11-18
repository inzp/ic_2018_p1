#include <stdio.h>
#include <time.h>
#include <stdlib.h>
FILE *file;

void delay(int seconds){ //time delay___________________________________________
  int milli_seconds = 1000*seconds;
  clock_t start = clock();
  while(clock() < start + milli_seconds); //"ocupar" o pc com outra coisa enquanto corre.
}

int rollr(){ //roleta tirar novo nr_____________________________________________
  int n, i;
  printf("the number is...\n");
  srand(time(NULL));
  for (i = 0; i<4 || n==0 ; i++){
    n=(rand()%37);
    printf("...%d\n", n);
    delay(1);
  }
  printf("\n...%d!!\n",n);
  return n;
}

int comand_list(int Creditos){ //welcome message________________________________
    printf("\n  \tYour initial Balance is: %d Rice\n\n", Creditos);
    printf("\tb <amount> -- the amount of rice you want to bet \n\n");
    printf("\tn <number> -- bet on a specific number \n");
    printf("\te ----------- bet on an even number. Pays 2 to 1 \n");
    printf("\to ----------- bet on an odd number. Pays 2 to 1 \n");
    printf("\tc ----------- bet on color red \n");
    printf("\tv ----------- bet on color black \n\n");
    printf("\tr ----------- roll \n");
    printf("\tm ----------- roll for fun\n\n");
    printf("\th ----------- help \n");
    printf("\ts ----------- show current balance \n");
    printf("\tl ----------- cash out/leave \n\n");
    printf("\tg ----------- save game progress \n");
    printf("\tt ----------- load saved game \n\n");
    printf("\tRed or black: Choosing a color\n\t-Red numbers are --- 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n\t-Black numbers are - 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
    return 0;
}

int help (void){ //instrucoes___________________________________________________
    printf("\tWell... Here is the manual: \n");
    printf("\tb <amount> -- the amount of rice you want to bet \n\n");
    printf("\tn <number> -- bet on a specific number \n");
    printf("\te ----------- bet on an even number. Pays 2 to 1 \n");
    printf("\to ----------- bet on an odd number. Pays 2 to 1 \n");
    printf("\tc ----------- bet on color red \n");
    printf("\tv ----------- bet on color black \n\n");
    printf("\tr ----------- roll \n");
    printf("\tm ----------- roll for fun\n\n");
    printf("\th ----------- help \n");
    printf("\ts ----------- show current balance \n");
    printf("\tl ----------- cash out/leave \n\n");
    printf("\tg ----------- save game progress \n");
    printf("\tt ----------- load saved game \n\n");
    printf("\tRed or black: Choosing a color\n\t-Red numbers are --- 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n\t-Black numbers are - 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
    return 0;
}

int show_Balance(int Creditos, int bet){// mostrar a balance____________________
  printf("\t Balance:        %d\n", Creditos);
  printf("\t Current Bet:    %d\n", bet);
  return 0;
}

int odd_even(int number, int choice, int cashBet, int Creditos){//par e impar___
  if (choice == 'e') {
    if(number%2 == 0){
      Creditos += cashBet*2;
      printf("You Won.  Now with %d rice in the bag.\n", Creditos);
    }else{
      printf("Shoot, you lost. You now have %d rice\n", Creditos);
    }
  }else if(choice =='o'){
    if(number%2 == 1){
      Creditos += cashBet*2;
        printf("You Won.  Now with %d rice in the bag.\n", Creditos);
    }else{
      printf("Shoot, you lost. You now have %d rice\n", Creditos);
    }
  }
  return Creditos;
}

int color_check(int roll,int choice, int Creditos, int bet){//red and black check______________________
  int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
  int controller = 0;
  int x=0;
  printf("Feeling colorfull aye?\n");

  if (choice == 'r'){ // if player chooses red = 1---------------
    for (x = 1; x < 18; x++) {
      if(roll == red[x]){
        controller = 1;
      }
    }
  } else if (choice == 'b'){ // if player chooses black = 2------
    for (x = 1; x < 18; x++) {
      if(roll == black[x]){
        controller = 1;
      }
    }
  }
  if (controller == 1){
    Creditos += bet*2;
    printf("You Won this one. Yor balance now is of %d rice. \n", Creditos);
  }else if (controller == 0){
    printf("You Lost this one. Currently with %d rice. \n", Creditos);
  }

  return Creditos;
}

int Start(){// first messages___________________________________________________
  printf("\n");
  printf("Welcome to the rice fields Casino, where money isn't allowed! \nYou may be wondering why money isnt allowed. It's very simple, we do this for fun, not to ruin our lifes and live in misery.\nAnd that is the main reason for the why we use rice as currency.");
  printf(" Although, we've been having some technical issues lately and only the roulette is available...Rice got into the circuits of the other games...\n");
  return 0;
}

int number_compare(int n, int numberBet, int Creditos, int cashBet){//betting on a specific number_________
  if (n == numberBet){
    Creditos += cashBet*numberBet;
    printf("The rice gods gave you the blessing of the monocots. You are rewarded with %d rice fields top notch rice. You now have %d jolly rice.\n", cashBet*numberBet, Creditos);
  }else{
    printf("yea, dont get ahead of yourself. You lost %d rice. Currently with %d\n", cashBet, Creditos);
  }
  return Creditos;
}

//case g:
void save_game(int Creditos, int cashBet, int minBet){// saving the game_____________________________________________
  file =fopen("GameSave.sv", "w+");
  fprintf(file, "%d\n", Creditos);
  fprintf(file, "%d\n", cashBet);
  fprintf(file, "%d\n", minBet); //adicionar para a dificuldade opcional(ver github)
  fclose(file);
  printf("Game successfully saved.\n\n");
}

//case t:
int load_game(int Creditos, int cashBet, int minBet){// loading previously saved game_______________________________
  if ((file = fopen("GameSave.sv", "r+")) !=NULL){
    fscanf(file, "%d\n", &Creditos);
    fscanf(file, "%d\n", &cashBet);
    fscanf(file, "%d\n", &minBet); //adicionar para a dificuldade opcional(ver github)
    fclose(file);
    printf("\nYou have successfully loaded your game.\n");
    printf("\n\n");
    printf("\tYou are in the difficulty %d \n", minBet);
    show_Balance(Creditos, cashBet);
  }else{
    printf("\nThere is no saved game to load.\n");
  }
  return Creditos;
}
