#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void print_game_rules(void);
void print_score_chart(void);
//int roll_die(int dice[], int size);
int three_of_a_kind();
void roll_dice(int die[], int size);
int ones(int die[5], int c_combo[13], int points[13]);
int twos(int die[5], int c_combo[13], int points[13]);
int threes(int die[5], int c_combo[13], int points[13]);
int fours(int die[5], int c_combo[13], int points[13]);
int fives(int die[5], int c_combo[13], int points[13]);
int sixes(int die[5], int c_combo[13], int points[13]);
int three_of_a_kind(int die[5], int c_combo[13], int points[13]);
int four_of_a_kind(int die[5], int c_combo[13], int points[13]);
int full_house(int die[5], int c_combo[13], int points[13]);
int small_straight(int die[5], int c_combo[13], int points[13]);
int large_straight(int die[5], int c_combo[13], int points[13]);
int yahtzee(int die[5], int c_combo[13], int points[13]);
int chance(int die[5], int c_combo[13], int points[13]);
int play_menu(void);
void choose_combo(int die[5], int size, int c_combo[13], int scores[13], int player, int round);
void print_die(int die[]);
void reroll(int die[5], int size, int c_combo[13], int player, int round);
void print_score(int scores[13], int player);

#endif
