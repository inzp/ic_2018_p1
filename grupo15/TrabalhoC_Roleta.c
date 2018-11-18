#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int roda_roleta();

int main(void) {
  char dificuldades[3];
  char Nivel_Jogo[30];
  int creditos;
  char modo_jogo[3];
  int valor_aposta;
  int numero_calhado;
  int especifico;
  char paridade[3];
  int valor_premio;
  float resto;
  char resposta[3];

  printf("BEM-VINDO AO JOGO DA ROLETA!\n");
  printf("\nCréditos: 100€\n");

  creditos = 100;

  strcpy(dificuldades, "");
  while(strcmp(dificuldades, "b") != 0 && strcmp(dificuldades, "n") != 0 && strcmp(dificuldades, "e") != 0){
    printf("\nQual é a dificuldade?\nBeginner[b] (mínimo de aposta é 1 euro)\nNormal[n] (mínimo de aposta é 10 euros)\nExpert[e] (mínimo de aposta é 20 euros)\n Opção: ");
    scanf("%s", dificuldades);
  }

  if (strcmp(dificuldades,"b") == 0) {
    strcpy(Nivel_Jogo,"Beginner(min: 1 euro)");
  } else if (strcmp(dificuldades,"n") == 0) {
    strcpy(Nivel_Jogo,"Normal(min: 10 euros)");
  } else {
    strcpy(Nivel_Jogo, "Expert(min: 20 euros)");
  }

  while(creditos > 0){

    strcpy(modo_jogo, "");
    while(strcmp(modo_jogo, "1") != 0 && strcmp(modo_jogo, "2") != 0){
      printf("\nSelecione o Modo de Jogo: \n[1] para o modo 'números específicos'; \n[2] para o modo 'par ou ímpar'; \n Opção: ");
      scanf("%s", modo_jogo);
    }

    valor_aposta = 0;
    while(1 == 1){
      printf("\nQuanto quer apostar?\n Valor: ");
      scanf("%d", &valor_aposta);
      if ((strcmp(dificuldades, "b")== 0 && valor_aposta < 1) || (strcmp(dificuldades, "n") == 0 && valor_aposta < 10) || (strcmp(dificuldades, "e") == 0 && valor_aposta < 20)) {
        printf("\nValor inválido. Seu nivel de jogo é %s. Faça nova aposta dentro dos limites.\n\n",Nivel_Jogo);
      } else {
        break;
      }
    }

    if(valor_aposta > creditos){
      printf("\nO valor excede os créditos disponíveis.\n\n");
    }else{
      creditos -= valor_aposta;
      if(strcmp(modo_jogo, "1") == 0){
          printf("\nQual é o numero a apostar? Entre 1 e 36.\n Aposta:  ");
          scanf("%d", &especifico);
        for(int i = 4; i > -1; i--){
          sleep(1);
          printf("%d\n", i);
        }
        numero_calhado = roda_roleta();
        printf("\nO número que calhou foi: %d\n", numero_calhado);
        if(especifico == numero_calhado){
          valor_premio = valor_aposta * 35;
          printf("Parabéns!! Você ganhou %d euros.\n", valor_premio);
          creditos += valor_premio;
        }else{
          printf("Lamento imenso, mas você perdeu.\n");
        }
      }else{
	strcpy(paridade, "");
        while(strcmp(paridade, "p") != 0 && strcmp(paridade, "i") != 0){
          printf("\nDigite [p] para números pares ou [i] para números ímpares.\n Aposta:  ");
          scanf("%s", paridade);
        }
        for(int i = 4; i > -1; i--){
          sleep(1);
          printf("%d\n", i);
        }
        numero_calhado = roda_roleta();
        printf("O número que calhou foi: %d\n", numero_calhado);
        resto = numero_calhado % 2;
        if((resto == 0 && strcmp(paridade, "p") == 0) || (resto == 1 && strcmp(paridade, "i") == 0)){
          valor_premio = valor_aposta * 2;
          printf("Parabéns!! Você ganhou %d euros.\n", valor_premio);
          creditos += valor_premio;
        }else{
          printf("Lamento imenso, mas você perdeu.\n");
        }
      }
      printf("\nOs seus créditos agora são: %d\n", creditos);
      strcpy(resposta, "");
      //O strcmp permite comparar as duas strings e devolver um numero
      //Como, neste caso, o numero é diferente de 0, foi preciso verificar para dar o loop
      if (creditos > 0 ) {
        while(strcmp(resposta, "s") != 0 && strcmp(resposta, "n") != 0){
          printf("\nDeseja jogar novamente?\nSim[s]\nNão[n]\n Opção: ");
          scanf("%s", resposta);
        }
        if(strcmp(resposta, "n")== 0){
          break;
        }

        printf("\n===================================================================================\n");
        printf("                             O   J O G O   C O N T I N U A\n");
        printf("===================================================================================\n\n");

      }
    }
  }
  printf("\nAcabou por ficar com %d euros.\n", creditos);
  printf("Obrigado por jogar!\n");
  return 0;
}

int roda_roleta() {
  srand(time(NULL));
  rand();
  int random_number = rand() % 36 + 1;
  return random_number;
}


