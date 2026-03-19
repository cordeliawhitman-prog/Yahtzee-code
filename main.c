#include "Yahtzee.h"
int main(void)
{
	int dice_p1[5] = { 0 }, scores_p1[13] = { 0 }, scores_p2[13] = { 0 }, dice_p2[5] = { 0 }, player1_combos[13] = { 0 }, playeer2_combos[13] = { 0 }, turn = 0;
	play_menu();
	//print_die(dice_p1);
	//while (play_menu())
	//{

		//while (turn < 14)
		//{
		//{
		//// PLAYER 1
		//	printf(" PLAYER 1 \n");
		//	printf(" ROUND %d \n\n", turn);
		//	roll_dice(dice_p1, 5);
		//	print_die(dice_p1);
		//	print_die(dice_p1, 5, player1_combos);
		//	reroll(dice_p1, 5, player1_combos, 1, turn);
		//	choose_combo(dice_p1, 5, player1_combos, scores_p1, 1, turn);
		//	system("cls");
		//	printf(" PLAYER 1 \n");
		//	printf(" ROUND %d \n\n", turn);
		//	print_score(scores_p1, 1);
		//	printf("\n\nPress any key to switch to player 2.");
		//	system("pause > nul");
		//	system("cls");
		//	// PLAYER 2
		//	printf(" PLAYER 2 \n");
		//	printf(" ROUND %d\n\n", turn);
		//	roll_dice(dice_p2, 5);
		//	print_die(dice_p2, 5, playeer2_combos);
		//	reroll(dice_p2, 5, playeer2_combos, 2, turn);
		//	choose_combo(dice_p2, 5, playeer2_combos, scores_p2, 2, turn);
		//	printf(" PLAYER 2 \n");
		//	printf(" ROUND %d\n\n", turn);
		//	print_score(scores_p2, 2);
			//player 1
	printf("---------------------------------------------------\n");
	printf("					 Player 1                      \n");
	printf("					 Round 1                       \n");
	printf("---------------------------------------------------\n");
	roll_dice(dice_p1, 5);
	print_die(dice_p1);
	reroll(dice_p1, 5, 13, 1, 1);
	print_score_chart();
	choose_combo(dice_p1, 5, player1_combos, scores_p1, 1, 1);
	//turn++;

//	}

//}

}
