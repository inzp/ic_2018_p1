//Bibliotecas em uso
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

//Função Principal
int main() {
    //Variaveis e constantes do programa
    int carteira = 100;
    char dificuldade;
    char modalidade;
    char repetir;
    int game=false;
    int numAposta=0;
    int creditosApostados=0;
    int numRandom=0;
    int rep1=false;
    int rep2=false;
    int rep3=false;
    int rep4 = false;
    int endgame = false;
    srand(time(NULL));

    //Boas vindas ao jogador
    printf("Bem vindo ao Jogo da Roleta!!! Tente a sua sorte!\n");

    //ciclo de repetição do jogo
    while(game==false){
         rep2=false;
         rep3=false;
         rep4 = false;
         endgame = false;

        //ciclo da dificuldade escolhida
        while(rep1==false){
            //Modo de dificuldade do jogo
            printf("\tCarteira: %d creditos \n", carteira);
            printf("\nEscolha a dificuldade das apostas:\n");
            printf("\ti - Iniciante (credito minimo: 1)\n");
            printf("\tn - Normal (credito minimo: 10)\n");
            printf("\td - Dificil (credito minimo: 20)\n");
            //Escolha da dificuldade
            scanf("\n%c", &dificuldade);

            //Se o jogador selecionar a difucldade iniciante o cilco acaba e o jogo continua
            if(dificuldade == 'i'){
                rep1 = true;
                break;
            }

            //Se escolher a difucldade normal o ciclo acaba e o jogo continua
            else if(dificuldade == 'n'){
                rep1 = true;
                break;
            }

            //Se escolher a dificuldade dificil o ciclo acaba e o jogo continua
            else if(dificuldade == 'd'){
                rep1 = true;
                break;
            }

            //Se o jogador digitar um comando que nao seja i/n/d vai lhe pedir por um comando valido
            else{
                printf("\nDigite um comando correto\n");
                rep1 = false;
            }
        }

        //ciclo do tipo de aposta escolhido
        while(rep2==false){
            //Modalidades disponiveis
            printf("\nDigite a modalidade da aposta\n");
            printf("\tp - Pares (2x) \n");
            printf("\ti - Impares (2x) \n");
            printf("\te - Numero Especifico (35x) \n");
            printf("\t\t AVISO: 0 E DA CASA\n");
            //Escolha da modalidade
            scanf("\n%c", &modalidade);

            //Se o jogador escolher a modalidade 'p' o ciclo termina e o jogo prossegue
            if(modalidade == 'p'){
                rep2=true;
                break;
            }

            //Se o jogadior escolher a modalidade 'i' o ciclo termina e o jogo prossegue
            else if(modalidade == 'i'){
                rep2=true;
                break;
            }

            //Se o jogador escolher a modalidade 'e', apos ele escolher o numero em que quer apostar o cilco acaba e o jogo proessegue
            else if(modalidade == 'e'){

            //Ciclo de indicar o numero especifico
                while(rep4==false){
                    printf("\nIndique o numero em que quer apostar (1 a 36):");
                    //Escolha do numero de aposta
                    scanf("%d", &numAposta);
                    printf("\n");
                    //Se o numero for menor que 1, o programa vai pedir novamente o numero
                    if(numAposta <1){
                        printf("NUMERO NAO PERMITIDO");
                        rep4=false;
                    }
                    //Se o numero for maior que 36, o programa vai pedir novamente o numero
                    else if (numAposta > 36){
                        printf("NUMERO NAO PERMITIDO");
                        rep4=false;
                    }
                    //Caso o jogador escolha um numero entre 1 e 36 inclusive o ciclo acaba e o jogo prossegue
                    else{
                        rep4=true;
                        rep2 = true;
                        break;
                    }
                }
            }
            //Se o jogador nao introduzir uma modalidade valida o programa pede-lhe uma correta
            else{
                printf("\nIntroduza uma modalidade válida (p/i/e): ");
                rep2 = false;
            }
        }


        //ciclo do valor da aposta
        while(rep3==false){
            printf("Quanto quer apostar: ");
            //Numeros de creditos apostados
            scanf("%d", &creditosApostados);

            //Caso o jogodaor escolha a dificuldade iniciante
            if(dificuldade == 'i'){
                //Se o jogador apostar um valor menor que 1 ou acima dos creditos que tem na sua carteira é lhe pedido que introduza um valor possivel a apostar
                if(creditosApostados<1||creditosApostados>carteira){
                    printf("\nNUMERO NAO PERMITIDO\nINICIANTE - APOSTAS DE 1 A %d\n", carteira);
                    rep3=false;
            }
                //Se introduzir um numero correto, o ciclo acaba e o jogo prossegue
                else{
                    rep3=true;
                }
            }

            //Caso o jogador escolha a dificuldade normal
            else if(dificuldade == 'n'){
                //Se o jogador apostar um valor menor que 10 ou acima dos creditos que tem na sua carteira é lhe pedido que introduza um valor possivel a apostar
                if(creditosApostados<10||creditosApostados>carteira){
                    printf("\nNUMERO NAO PERMITIDO\nMODO NORMAL - APOSTAS DE 10 A %d\n", carteira);
                    rep3=false;
                }
                //Se introduzir um numero correto, o ciclo acaba e o jogo prossegue
                else{
                    rep3=true;
                }
            }

            //Caso o jogador escolha a dificuldade dificl
            else{
                //Se o jogador apostar um valor menor que 20 ou acima dos creditos que tem na sua carteira é lhe pedido que introduza um valor possivel a apostar
                if(creditosApostados<20||creditosApostados>carteira){
                    printf("\nNUMERO NAO PERMITIDO\nMODO DIFICIL - APOSTAS DE 20 A %d\n",carteira);
                    rep3=false;
                }
                //Se introduzir um numero correto, o ciclo acaba e o jogo prossegue
                else{
                    rep3=true;
                }
            }
        }

        //delay de 4segundos, para sempre que o jogador apostar
        sleep(1); 

        printf("4...\n"); 

        sleep(1); 

        printf("3...\n"); 

        sleep(1); 

        printf("2...\n"); 

        sleep(1); 

        printf("1...\n"); 

        sleep(1);

        //escolha do numero aleatorio pelo computador
        numRandom=rand()%37;
        printf("Calhou o %d \n", numRandom);
        //O valor de creditos na carteira apos a aposta feita
        carteira=carteira - creditosApostados;

        /*Se o numero escolhido pelo o computador der resto 0 quando divisivel por 2 e a
        modalidade escolhida for par, ou se o numero escolhido pelo computador não der resto 0
        quando divisivel por 2 e a modalidade escolhida for impar, o jogador ganha a aposta
        e recebe o dobro dos creditos que apostou */
        if((numRandom%2==0 && modalidade=='p') || (numRandom%2!=0 && modalidade=='i')){
            carteira=carteira+ creditosApostados*2;
            printf("Ganhou a aposta!\n");
        }
        /*Se o numero escolhido pelo computador for igual ao numero escolhido pelo jogador e
        a modalidade for 'e' o jogador ganha a aposta e recebe 35x o valor dos creditos apostados*/
        else if(numRandom==numAposta && modalidade=='e'){
            carteira=carteira+ creditosApostados*35;
            printf("Ganhou a aposta!\n");
        }
        //Se nenhuma das condiçoes anteriores for satisfeita o jogador perde a aposta
        else {
            printf("Perdeu a aposta!\n");
        }

        printf("\nTem de momento %d creditos",carteira);

        //Se o valor de creditos do jogador for igual a 0, o jogo acaba
        if(carteira==0){
            printf("\nObrigado por jogar!");
            break;
        }

        //Se o valor de creditos do jogador for menor a 10, o jogo acaba
        else if(carteira < 10 && dificuldade == 'n'){
            printf("\nCreditos minimos nao disponiveis!\nObrigado por jogar!");
            break;
        }

        //Se o valor de creditos do jogador for menor a 20, o jogo acaba
        else if(carteira < 20 && dificuldade == 'd'){
            printf("\nCreditos minimos nao disponiveis!\nObrigado por jogar!");
            break;
        }


        //Ciclo de repetiçao do jogo
        while(endgame==false) {
            printf("\nQuer jogar novamente? (s/n)\n ");
            //Escolha do jogador relativamente a se este deseja ou nao contiuar a jogar
            scanf("\n%c", &repetir);

            //Se o jogador escolher sim, o jogo volta ao inicio e este ciclo termina
            if(repetir=='s'){
                game=false;
                endgame=true;
            }

            //Se o jogador escolher nao o jogo acaba
            else if(repetir=='n'){
                printf("Obrigado por jogar !");
                game=true;
                endgame=true;
            }
            //Se o jogador introduzir outro comando sem ser 's' ou 'n', é lhe pedidio novamente se este que jogador ou não
            else{
                endgame=false;
            }



        }
    }

    return 0;
}
