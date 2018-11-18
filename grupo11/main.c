#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Menu.h"
#include "Globals.h"

//App Entry point.
int main()
{
	//Create a (random) seed for the generation of random numbers.
	srand((unsigned int)time(NULL));

	//Call main loop with the approppriate mininum bet value (Given by MinBetSelection()).
	MainLoop(MinBetSelection());

	return 0;
}