#include <stdio.h>  // biblioteca padrão do C “standard input-output”.//
#include <stdlib.h> //  biblioteca padrão de funções envolvendo alocação de memória, controle de processos, conversões, etc…//
#include <time.h>   // biblioteca padrão  para manipulação de datas e horários.//

void delay (int seconds)  // suspende a execução por um determinado tempo em segundos//
{
    int milliSeconds = 1000*seconds;          // converte a variável milissegundos de segundos em milissegundos//
    clock_t start = clock ();                 //Tempo de partida, começo, t start = hora do momento//
    while (clock () < start + milliSeconds);  //Condição : relógio < que um determinado tempo, partida + variável milissegundos//
}


void printstats( int quantia, int aposta)     //inicia e carrega as variáveis quantia e aposta.//
{
    printf("\n\tquantia : %d", quantia);      //imprime a variável quantia.//
    printf("\n\taposta : %d", aposta);        //imprime a variável aposta.//
}

void printMenu( int quantia, int aposta)
{
    printstats(quantia, aposta);
    printf("\nPode apostar numa das segintes opções:\n\n");  //Imprime e muda de linha.//
    printf("1) Pode escolher um número de 1 a 35 (Aposta de alto risco!)\n\n"); //Imprime e muda de linha.//
    printf("2) Pode escolher par ou ímpar"); //Imprime.//
}

void apostarnumero(int *quantia)
{
    int nespecifico;  // inicia variável.//
    printf("\nEntão vai apostar em grande?\n Escolha um número entre 1 e 35 para apostar> "); //Imprime.//
    scanf("%d", &nespecifico); //Carrega variável &nespecifico//
    
    if (nespecifico < 0 || nespecifico >36) //Condição: vê se variável nespecifico está fora do intervalo entre 1 e 35.//
    {
       printf ("\nValor não válido!");      // se sim, Imprime Valor não válido!//
    }
    else                                    //Caso contrário.//
    {
        int aposta;                         //inicia variável.//
        printf("Quer apostar quanto dinheiro nesta rodada?");   //imprime pergunta.//
        scanf("%d", &aposta);                 //Carrega variável com a resposta anterior.//
        if (aposta <= 0 || aposta > *quantia) //Condição: vê se variável aposta está fora do intervalo entre 1 e variavel quantia.//
        {
            printf ("A quantia que quer apostar não é válida!");   // se sim, Imprime Valor não válido!//
        }
        
        else   //Caso contrário//
        {
            printf("\nApostou %d€ no número %d", aposta, nespecifico);   //imprime as variáveis aposta e nespecifico.//
            printf("\nCarregue Enter para girar a roleta. BOA SORTE!");  //imprime instrução ao jogador.//
            getchar();    //acha número inteiro aliatório//
            getchar();    //acha número inteiro//
            int numero = girar_roleta();
            if (numero==nespecifico)      //Condição: se o número é igual ao número escolhido.//
            {
                *quantia += (aposta*35);  // variavel *quantia = a variavel aposta * 35.//
                printf("Ganhou!!! \n Agora tem %d€ para apostar\n", *quantia);  //Imprime Ganhou.//
            }
            else               //Caso contrário.//
            {
                *quantia -= aposta; // subtrai a aposta à variavel *quantia.//
                printf("Este não é o seu dia de sorte. \n Perdeu %d€, agora tem %d€ para apostar.\n ", aposta, *quantia); 
            }                                                              //Imprime: pouca sorte; valores das variáveis aposta e *quantia.//
        }
    }
}

void tempo ()
{
    for (int x = 0; x < 4; x++)   // compaço de espera.//
    {
        printf (".");            // imprime "."//
        fflush (stdout);
        delay(1);               //atrasa//
    }
}

void apostapar (int *quantia) 
{
    int parimpar, // inicia variável//
        aposta;
    printf("Precione 1 para ímpar e 2 para par. Escolha com cuidado!> ");// imprime//
    scanf("%d", &parimpar); // carrega variável//
    if (parimpar < 1 || parimpar > 2) //condição opção entre 1 e 2//
    {
        printf("Opção não válida! :)");// imprime opção não válida em valores fora do intervalo de 1 e 2//
    }
    else //caso contrário//
    {
        printf("\n Quanto dinheiro que apostar nesta ronda? \n");// imprime//
        scanf("%d", &aposta);//carrega variável do valor da aposta//
        if (aposta <= 0 || aposta > *quantia)// condição 
        {
            printf ("A quantia que quer apostar não é válida!");//imprime//
        }
        else // caso contrário//
        {
            if (parimpar==1) // condição no caso opção 1
                printf("\n Apostou %d€ num número ímpar.", aposta); // imprime//
            else // caso contrário//
                printf("\n Apostou %d€ num número par.", aposta); // imprime//
            printf("\n Carregue Enter para girar a roleta. BOA SORTE!"); // imprime//
            getchar();
            getchar();
            int numero = girar_roleta(); //gira roleta//
            if (parimpar==1) // condição se opção for 1//
            {
                if (numero%2==1)
                {
                    *quantia += aposta; // quantia soma o total da aposta//
                    printf("Hoje é o seu dia! \n  Agora tem %d€ para apostar\n", *quantia);// imprime//
                    
                }
                else // caso contrário//
                {
                    *quantia -= aposta; // quantia subtrai o total da aposta//
                    printf("Quanto mais perder mais nós gostamos de o ter cá. \n Perdeu %d€, agora tem %d€ para apostar\n", aposta, *quantia); // imprime//
                }
            }
            else if (numero%2==0) // condição se opção for 2//
            {
                    *quantia += aposta; // quantia soma o total da aposta//
                    printf("Viva ganhou! Assim pode pagar uma rodada a todos ou não? \n Agora tem %d€ para aposta\nr", *quantia); // imprime//
                
            }
            else // caso contário//
            {
                *quantia -= aposta; // quantia subtrai o total da aposta//
                printf("É melhor pedir um emprestimo se continuar assim :) \n Perdeu %d€, agora tem %d€ para apostar\n ", aposta, *quantia); // imprime//
            }
        }
    }
}

int main(void)

{
int opcao ;
int nespecifico;
int parimpar;
int numero;
int aposta;
int quantia;
    
char nome[100]; // variavel nome//
printf("Digite seu nome:\n");// imprime//
scanf("%s", nome);// le nome inserido//
printf("BEM VINDO AO JOGO DA ROLETA!\n");// imprime//
printf("%s",nome);// imprime nome//
printf(",no inicio do jogo tem 100€ para apostar.\n");// imprime//


quantia=100; // mostra quantia//

while (quantia>0)
{
    printMenu(quantia, aposta);
    printf("\nEscolha a opção em que quer apostar 1 ou 2> ");
    scanf("%d", &opcao);
    
    switch (opcao)
    {
        case 1 :
        apostarnumero(&quantia);
        
        break;
        
        case 2 :
        apostapar (&quantia);
        break;
        
    }
}

getchar();
getchar();
return 0;
}

int girar_roleta (void)
{
    int numero;
    srand(time(NULL));
    numero=1+(rand()%36);
    printf("A bola calhou no");
    delay(1000);
    printf("%d\n", numero);
    return numero;
}
