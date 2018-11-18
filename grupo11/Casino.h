
#include "Globals.h"

void Delay(int number_of_seconds);

int RandomRange(int min, int max);

unsigned short IsEven(int number);

void CreateTension();

unsigned short BetOnNumber(int *numberBet);

unsigned short MakeBet(int *balance, int *currentBet, int auxBet, unsigned short minBet);

unsigned short Roll(int *balance, int *currentBet, int *numberBet, unsigned short betType);