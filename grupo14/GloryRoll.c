#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int roulette[37] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
    int rouletteEven[18] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
    int rouletteOdd[18] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
    int randomIndex = rand() % 36;
    int randomValue = roulette[randomIndex];
    int balance = 100;
    int lastBet = 0;
    int sBet, option, i, flag;
    srand ( time(NULL) );

    do
    {
        printf("\n");
        printf("________________________________________________________________________\n");
        printf("\n");
        printf("Welcome to the Glory Roll..!\n");
        printf("\n");
        printf("Are you feeling lucky?\n");
        printf("\n");
        printf("    Balance:        $%d\n", balance);
        printf("    Last bet:    $%d\n", lastBet);
        printf("\n");
        printf("Choose an option:\n");
        printf("    1 - bet on a specific number - pays 35 to 1\n");
        printf("    2 - bet on an even number - pays 2 to 1\n");
        printf("    3 - bet on an odd number - pays 2 to 1\n");
        printf("    4 - help\n");
        printf("    5 - show balance\n");
        printf("    6 - cash out and go home\n");
        printf("\n");
        printf("Please type your option below:\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n");
                printf("You chose to bet on a specific number.\n");
                printf("\n");
                printf("Please type in how much money you want to bet (you currently have $%d):\n", balance);
                scanf("%d", &lastBet);
                balance = balance - lastBet;
                printf("\n");
                printf("You chose to bet $%d.\n", lastBet);
                printf("\n");
                printf("You have $%d left.\n", balance);
                printf("\n");
                printf("Please type in the specific number you want to bet on:\n");
                scanf("%d", &sBet);
                printf("\n");
                printf("You chose the number %d. Let's see if you're lucky.\n", sBet);
                printf("\n");
                printf("The roulette is waiting for you. Press ENTER to roll it.\n");
                getch();
                randomIndex = rand() % 36;
                randomValue = roulette[randomIndex];

                    if(randomValue == sBet)
                    {
                        lastBet = lastBet * 35;
                        balance = balance + lastBet;
                        printf("\n");
                        printf("The ball landed on: %d\n", randomValue);
                        printf("\n");
                        printf("Congratulations! You won $%d!!\n", lastBet);
                        printf("\n");
                        printf("Your balance is now $%d.\n", balance);
                    }

                    else if(randomValue == 0)
                    {
                        printf("\n");
                        printf("You betted on the number: %d\n", sBet);
                        printf("The ball landed on: %d\n", randomValue);
                        printf("\n");
                        printf("Sorry... You lost this time. You should totally try again!\n");
                        printf("\n");
                        printf("Your balance is now $%d.\n", balance);
                    }

                    else
                    {
                        printf("\n");
                        printf("You betted on the number: %d\n", sBet);
                        printf("The ball landed on: %d\n", randomValue);
                        printf("\n");
                        printf("Sorry... You lost this time. You should totally try again!\n");
                        printf("\n");
                        printf("Your balance is now $%d.\n", balance);
                    }

                break;

            case 2:
                printf("\n");
                printf("You chose to bet on an even number.\n");
                printf("\n");
                printf("Please type in how much money you want to bet (you currently have $%d):\n", balance);
                scanf("%d", &lastBet);
                balance = balance - lastBet;
                printf("\n");
                printf("You chose to bet $%d.\n", lastBet);
                printf("\n");
                printf("You have $%d left.\n", balance);
                printf("\n");
                printf("The roulette is waiting for you. Press ENTER to roll it.\n");
                getch();
                randomIndex = rand() % 36;
                randomValue = roulette[randomIndex];

                if(randomValue == 0)
                {
                    printf("\n");
                    printf("The ball landed on: %d\n", randomValue);
                    printf("\n");
                    printf("Sorry... You lost this time. You should totally try again!\n");
                    printf("\n");
                    printf("Your balance is now $%d.\n", balance);
                }
                else
                {
                    flag = 0;
                    for (i = 0; i < 18; i++)
                    {
                        if (randomValue == rouletteEven[i])
                        {
                            lastBet = lastBet * 2;
                            balance = balance + lastBet;
                            printf("\n");
                            printf("The ball landed on: %d\n", randomValue);
                            printf("\n");
                            printf("Congratulations! You won $%d!!\n", lastBet);
                            printf("\n");
                            printf("Your balance is now $%d.\n", balance);
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        printf("\n");
                        printf("The ball landed on: %d\n", randomValue);
                        printf("\n");
                        printf("Sorry... You lost this time. You should totally try again!\n");
                        printf("\n");
                        printf("Your balance is now $%d.\n", balance);
                    }
                }

                break;

            case 3:
                printf("\n");
                printf("You chose to bet on an odd number.\n");
                printf("\n");
                printf("Please type in how much money you want to bet (you currently have $%d):\n", balance);
                scanf("%d", &lastBet);
                balance = balance - lastBet;
                printf("\n");
                printf("You chose to bet $%d.\n", lastBet);
                printf("\n");
                printf("You have $%d left.\n", balance);
                printf("\n");
                printf("The roulette is waiting for you. Press ENTER to roll it.\n");
                getch();
                randomIndex = rand() % 36;
                randomValue = roulette[randomIndex];

                if(randomValue == 0)
                {
                    printf("\n");
                    printf("The ball landed on: %d\n", randomValue);
                    printf("\n");
                    printf("Sorry... You lost this time. You should totally try again!\n");
                    printf("\n");
                    printf("Your balance is now $%d.\n", balance);
                }
                else
                {
                    flag = 0;
                    for (i = 0; i < 18; i++)
                    {

                        if (randomValue == rouletteOdd[i])
                        {
                            lastBet = lastBet * 2;
                            balance = balance + lastBet;
                            printf("\n");
                            printf("The ball landed on: %d\n", randomValue);
                            printf("\n");
                            printf("Congratulations! You won $%d!!\n", lastBet);
                            printf("\n");
                            printf("Your balance is now $%d.\n", balance);
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        printf("\n");
                        printf("The ball landed on: %d\n", randomValue);
                        printf("\n");
                        printf("Sorry... You lost this time. You should totally try again!\n");
                        printf("\n");
                        printf("Your balance is now $%d.\n", balance);
                    }
                }

                break;

            case 4:
                printf("This is the help text. Here you find out how to play roulette in this program.\n");
                printf("\n");
                printf("First, select which type of bet you want to make (you can bet on a single number, on even numbers or on odd numbers).\n");
                printf("\n");
                printf("Please do remember that 0 is the houses' number. You never win if a 0 is rolled.\n");
                printf("\n");
                printf("When you've decided, go ahead and select that option.\n");
                printf("\n");
                printf("You will then be prompted to type in how much of your balance you want to bet.\n");
                printf("\n");
                printf("If you chose to bet on a single number, you will be asked to type in which number you want to bet on.\n");
                printf("\n");
                printf("Once all that is done, all that's left is for the roulette to spin!\n");
                printf("\n");
                printf("You will be asked to press enter to roll the roulette, and when you do, may luck shine on you.\n");
                printf("\n");
                printf("Have fun!\n");
                break;

            case 5:
                printf("Your balance is: $%d.", balance);
                printf("\n");
                break;

            case 6:
                printf("Sorry to see you go... We hope you've enjoyed your stay with us.\n");
                printf("\n");
                printf("Good luck out there!\n");
                exit(0);
                break;

            default:
                printf("Please choose a valid option.\n");
                break;
     }
    }
    while(balance > 0);

    printf("Oh dear! You ran out of cash. Go make some and come back for more fun!\n");
    printf("See you soon!");
    return 0;
}
