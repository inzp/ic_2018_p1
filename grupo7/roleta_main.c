#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "roleta_funcoes.h"


//Funcao Main AKA Jogo da Roleta
int main(){
	Intro();
	Balanco();
 	SwLevel();
	while (1){
		Gerar_Random();
		NumAleatorio();
		SelectMenu();
		Menu();
	}
}
