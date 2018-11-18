#include <stdio.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

int random_number();
int main (void) {

  int escolha;
  int aposta;
  int creditos;
  int calhou;
  int numero_escolhido;
  int premio;
  char jogar_denovo[3];
  int impar_par;
  

  creditos = 100 ;

  printf("Hey, bem-vindo à ROLETA.\n");
  printf("Os seus créditos: 100$\n");

  while(creditos > 0) {
    escolha = 0;
    while (escolha != 1 && escolha != 2) {

      printf("Escolha o modo de jogo: \n");
      printf("1-Impar/Par\n");
      printf("ou\n");
      printf("2-Número específico\n");
      scanf("%d", &escolha);

    }
      printf("Quanto quer apostar?\n");
      scanf("%d", &aposta);
      if(aposta > creditos) {
        printf("Não tem créditos suficientes, faça uma aposta válida.\nOs seus créditos são: %d€\n",creditos);
        scanf("%d", &aposta);
      }
     //Quando o jogador faz uma aposta essa mesma quantidade é retirada é retirada. 
      creditos -= aposta;

      
    if (escolha == 1) {
      printf("Aposta nos 1-Impares ou 2-Pares?\n");
      scanf("%d", &impar_par);
      if (impar_par == 1){
        printf("Você escolheu: Impares\n");
        calhou = random_number(); 
        for(int i = 5; i > -1; i--){
          sleep(1);
          printf("%d...\n",i);
        } 
        printf("Calhou: %d\n", calhou);   
        if (calhou %2 != 0){ 
          printf("Parabéns, acertou!\n");      
          premio = aposta *2;
          printf ("Ganhou:""%d€\n",premio);
          creditos += premio;
          printf ("Quer jogar novamente? Sim(s) ou Não(n)\n ");
          scanf("%s", jogar_denovo);
          if (strcmp(jogar_denovo,"n") == 0) {
          break;
          }
          while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
        }
        }
        else {
          printf("Perdeu.\n"); 
          printf("Os seus créditos: %d€\n",creditos);
          if (creditos == 0) {
            printf("Ficou sem créditos.\n");
          break;
          }
          printf ("Quer jogar novamente? Sim(s) ou Não(n)\n ");
          scanf("%s", jogar_denovo);
          if (strcmp(jogar_denovo,"n") == 0) {
          break;
          }
          while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
        }
        }
      }
      else {
        printf("Você escolheu: Par\n");
        calhou = random_number();  
//Faz uma contagem decrescente antes de mostrar ao jogador o número sorteado pelo computador.
        for(int i = 5; i > -1; i--){
          sleep(1);
          printf("%d...\n",i);
        }

        printf("Calhou: %d\n", calhou);
        if (calhou %2 == 0){
          printf("Parabéns! Você acertou!\n");
          premio = aposta *2;
          printf ("Ganhou:""%d€\n",premio); 
          creditos += premio; 
          printf ("Quer jogar novamente? Sim(s) ou Não(n)\n ");
          scanf("%s", jogar_denovo);
          if (strcmp(jogar_denovo,"n") == 0) {
          break;
          }
          while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
        }  
        }
        else {
          printf("Perdeu.\n"); 
          printf("Os seus créditos: %d€\n",creditos);
          if (creditos == 0) {
            printf("Ficou sem créditos.\n");
          break;
          }
          printf ("Quer jogar novamente? Sim(s) ou Não(n)\n ");
          scanf("%s", jogar_denovo);
          if (strcmp(jogar_denovo,"n") == 0) {
          break;
          }
          while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
        }
        }
      }     
    }  
    if (escolha == 2) {
      printf("Entre 1 e 35, em que número aposta?\n");
      scanf("%d",&numero_escolhido);
      calhou = random_number();
      for(int i = 5; i > -1; i--){
          sleep(1);
          printf("%d...\n",i);
        }
      printf("Calhou: %d\n", calhou);

      if (numero_escolhido == calhou) {
        premio = aposta *35;
        printf ("Ganhou:""%d€\n",premio);
        creditos += premio;
        printf("Os seus créditos: %d€\n",creditos);
        printf ("Quer jogar novamente? Sim(s) ou Não(n)\n ");
        if (strcmp(jogar_denovo,"n") == 0) {
        break;
        }
        while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
        }
      }
      else {
        printf("Perdeu.\n");
        printf("Os seus créditos: %d€\n",creditos);
        if (creditos == 0) {
            printf("Ficou sem créditos.\n");
          break;
          }
        if (creditos > 0) {
        printf("Quer jogar novamente? Sim(s) ou Não(n)\n");
        scanf("%s", jogar_denovo);
        if (strcmp(jogar_denovo,"n") == 0) {
          break;
        }
        while (strcmp(jogar_denovo,"s") != 0) {
          printf("Por favor responda apropriadamente à pergunta.\n");
          printf("Os seus créditos: %d€\n",creditos);
          scanf("%s", jogar_denovo);
          break;
        }
        }
      }
    }
  }
//Esta mensagem aparece quando o jogador fica sem créditos ou decide não jogar mais.
  printf("GAME OVER\n");
  return 0;
}
//Gera o número aleatório para ambos os modos de jogo.
int random_number() {
  srand(time(NULL));
  rand();
  int numero_aleatorio = rand() % 36 + 1;
  return numero_aleatorio ;
}
