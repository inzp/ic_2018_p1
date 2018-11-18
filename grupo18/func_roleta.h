#ifndef _FUNC_ROLETA_H_
#define _FUNC_ROLETA_H_
int Start();
int rollr();
int delay();
void comand_list(int Creditos);
void help();
int show_Balance(int Creditos, int bet);
int odd_even(int number, int choice, int cashBet, int Creditos);
int color_check(int roll, int choice, int Creditos, int bet);
int number_compare(int n, int numberBet, int Creditos, int cashBet);
int load_game(int Creditos, int cashBet, int minBet);
void save_game(int Creditos, int cashBet, int minBet);
#endif
