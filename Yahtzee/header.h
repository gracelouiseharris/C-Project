#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void run_yahtzee(void);
void print_player_turn(int player_turn);
int roll_die(void);
int want_roll(void);
void print_hold_die(int array_int);
int get_hold_die(void);
void print_die_value(int die_value);
void print_die_int(int die_int);
void print_score_card(int *score);
void print_score_card2(int *score);
void print_menu(void);
int is_valid_menu_option(int option);
int get_menu_option(void);
void print_game_rules(void);
void exit_game(void);
int get_score_option_valid(void);
int is_valid_selection(int score_select);