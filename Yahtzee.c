#include "Yahtzee.h"
int play_menu(void)
{
	int option = 1, play_game = 0;
	printf("lets play Yahtzee!\n");
	do
	{
		printf("1. Display Rules.\n");
		printf("2. Play Game.\n");
		printf("3. Exit.\n");
		scanf("%d", &option);
	} while (!(option >= 1 && option <= 3));

	switch (option)
	{
	case 1: printf("Displaying the rules!\n");
		print_game_rules();
		play_menu();
		break;
	case 2: printf("Playing the game!\n");
		play_game = 1;
		break;
	case 3: printf("Exiting!\n");
		play_game = 0;
		break;
	default: printf("Error with input!\n"); // not really needed for this example because of 
		break;                              // input-validation loop
	}
}
void print_game_rules(void)
{
	printf("The Rules of Yahtzee:\n\n");
	printf("The scorecard used for Yahtzee is composed of two sections.\n");
	printf("A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. \n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n");
	printf("The lower section contains a number of poker like combinations. See the table provided below:\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("Three-of-a-kind = Three dice with the same face = Sum of all face values on the 5 dice\n");
	printf("Four-of-a-kind = Four dice with the same face =|Score| Sum of all face values on the 5 dice\n");
	printf("Full house = One pairand a three - of - a - kind =|Score| 25\n");
	printf("Small straight = A sequence of four dice = |Score| 30\n");
	printf("Large straight = A sequence of five dice = |Score| 40\n");
	printf("Yahtzee (think five-of-a-kind) = Five dice with the same face = |Score| 50\n");
	printf("Chance = May be used for any sequence of dice; this is the catch all combination = |Score| Sum of all face values on the 5 dice\n");
	printf("--------------------------------------------------------------------------------------\n");
}

void print_score_chart(void)
{
	printf("--------------------------------------------------------------------------------------\n");
	printf("Three-of-a-kind = Three dice with the same face = Sum of all face values on the 5 dice\n");
	printf("Four-of-a-kind = Four dice with the same face =|Score| Sum of all face values on the 5 dice\n");
	printf("Full house = One pairand a three - of - a - kind =|Score| 25\n");
	printf("Small straight = A sequence of four dice = |Score| 30\n");
	printf("Large straight = A sequence of five dice = |Score| 40\n");
	printf("Yahtzee (think five-of-a-kind) = Five dice with the same face = |Score| 50\n");
	printf("Chance = May be used for any sequence of dice; this is the catch all combination = |Score| Sum of all face values on the 5 dice\n");
	printf("--------------------------------------------------------------------------------------\n");
}




void roll_dice(int dice[], int size)
{
	char cont = 0;
	int index = 0;

	printf("Roll dice = \n");

	for (index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;

	}
	printf("\n");
}


void choose_combo(int die[5], int size, int combination[13], int scores[13], int player, int round)
{
	int selection = 0, index = 0, is_combo_valid = 0;

	printf(" PLAYER %d\n", player);
	printf(" ROUND %d\n\n", round);
	print_die(die, 5, combination);


	do
	{
		printf("Enter the combination you would like to use: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			is_combo_valid = ones(die, combination, scores);
			break;
		case 2:
			is_combo_valid = twos(die, combination, scores);
			break;
		case 3:
			is_combo_valid = threes(die, combination, scores);
			break;
		case 4:
			is_combo_valid = fours(die, combination, scores);
			break;
		case 5:
			is_combo_valid = fives(die, combination, scores);
			break;
		case 6:
			is_combo_valid = sixes(die, combination, scores);
			break;
		case 7:
			is_combo_valid = three_of_a_kind(die, combination, scores);
			break;
		case 8:
			is_combo_valid = four_of_a_kind(die, combination, scores);
			break;
		case 9:
			is_combo_valid = full_house(die, combination, scores);
			break;
		case 10:
			is_combo_valid = small_straight(die, combination, scores);
			break;
		case 11:
			is_combo_valid = large_straight(die, combination, scores);
			break;
		case 12:
			is_combo_valid = yahtzee(die, combination, scores);
			break;
		case 13:
			is_combo_valid = chance(die, combination, scores);
			break;
		default:
			printf("Please enter a valid selection.\n\n");
			break;
		}

	} while (!is_combo_valid);



}
//done! Aka
void print_die(int die[])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d", die[i]);
	}
}

void print_combos(int combination[13])
{
	// Prints all the combinations, or an X if it's been used
	if (combination[0] == 0)
	{
		printf("1. Sum of 1s\n");
	}
	else { printf("0. Sum of 1s\n"); }

	if (combination[1] == 0)
	{
		printf("2. Sum of 2s\n");
	}
	else { printf("0. Sum of 2s\n"); }

	if (combination[2] == 0)
	{
		printf("3. Sum of 3s\n");
	}
	else { printf("0. Sum of 3s\n"); }

	if (combination[3] == 0)
	{
		printf("4. Sum of 4s\n");
	}
	else { printf("0. Sum of 4s\n"); }

	if (combination[4] == 0)
	{
		printf("5. Sum of 5s\n");
	}
	else { printf("0. Sum of 5s\n"); }

	if (combination[5] == 0)
	{
		printf("6. Sum of 6s\n");
	}
	else { printf("0. Sum of 6s\n"); }

	if (combination[6] == 0)
	{
		printf("7. Three of a kind\n");
	}
	else { printf("0. Three of a kind\n"); }

	if (combination[7] == 0)
	{
		printf("8. Four of a kind\n");
	}
	else { printf("0. Four of a kind\n"); }

	if (combination[8] == 0)
	{
		printf("9. Full house\n");
	}
	else { printf("0. Full house\n"); }

	if (combination[9] == 0)
	{
		printf("10. Small Straight\n");
	}
	else { printf("0. Small Straight\n"); }

	if (combination[10] == 0)
	{
		printf("11. Large Straight\n");
	}
	else { printf("0. Large Straight\n"); }

	// Can be used an unlimited amount of times
	printf("12. YAHTZEE\n");

	if (combination[12] == 0)
	{
		printf("13. Chance\n\n");
	}
	else { printf("0. Chance\n\n"); }
}


void reroll(int die[5], int size, int c_combo[13], int player, int round)
{
	int number = 0;
	int index = 0;
	int reroll_index = 0;
	int die_reroll = 0;

	for (index = 0; index < 2; index++)
	{
		do
		{
			printf("--------How many rerolls? Enter 0 to use this roll. \n");
			scanf("%d", &number);

		} while ((number != 1) && (number != 2) && (number != 3) && (number != 4) && (number != 5) && (number != 0));



		if (number != 0)
		{
			for (reroll_index = 0; reroll_index < number; reroll_index++)
			{

				do
				{
					printf("Enter a single die you would like to reroll: \n");
					scanf("%d", &die_reroll);
					die[die_reroll - 1] = rand() % 6 + 1;
				} while ((die_reroll != 5) && (die_reroll != 1) && (die_reroll != 2) && (die_reroll != 3) && (die_reroll != 4));

			}
		}
		else
		{
			break;
		}
	
		printf(" PLAYER %d \n", player);
		printf(" ROUND %d \n\n", round);

		print_die(die);
	}
}

void print_score(int scores[13], int player)
{
	int sum = 0, index = 0;
	for (index = 0; index < 13; index++)
	{
		sum = scores[index] + sum;
	}
	printf("Player %d's score is now %d.\n", player, sum);
}


int ones(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[0] == 0)
	{
		combination[0] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 1)
			{
				sum = sum + 1;
			}
		}
		points[0] = sum;
	}
	return value;
}


int twos(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[1] == 0)
	{
		combination[1] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 2)
			{
				sum = sum + 1;
			}
		}
		points[1] = sum * 2;
	}
	return value;
}

int threes(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[2] == 0)
	{
		combination[2] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 3)
			{
				sum = sum + 1;
			}
		}
		points[2] = sum * 3;
	}
	return value;
}


int fours(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[3] == 0)
	{
		combination[3] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 4)
			{
				sum = sum + 1;
			}
		}
		points[3] = sum * 4;
	}
	return value;
}

int fives(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[4] == 0)
	{
		combination[4] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 5)
			{
				sum = sum + 1;
			}
		}
		points[4] = sum * 5;
	}
	return value;
}


int sixes(int die[5], int combination[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combination[5] == 0)
	{
		combination[5] = 1;
		value = 1;
		for (index = 0; index < 5; index++)
		{
			if (die[index] == 6)
			{
				sum = sum + 1;
			}
		}
		points[5] = sum * 6;
	}
	return value;
}


int three_of_a_kind(int die[5], int combination[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	// Checks if combo has been used before
	if (combination[6] == 0)
	{
		result = 1;
		combination[6] = 1;
		for (number = 1; number < 7; number++)
		{
			sum = 0;

			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}

			if (sum >= 3)
			{
				points[6] = die[0] + die[1] + die[2] + die[3] + die[4];
				break;
			}
		}

	}
	return result;
}


int four_of_a_kind(int die[5], int combination[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	// Check if combo has been used before
	if (combination[7] == 0)
	{
		combination[7] = 1; // Sets combo to used
		// Checks if a die matches a number, if it does then adds to a variable "sum". If sum = 3, then it breaks. Otherwise repeat with number+1. 
		for (number = 1; number > 5; number++)
		{
			sum = 0;

			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}

			if (sum >= 4)
			{
				points[7] = die[0] + die[1] + die[2] + die[3] + die[4];
				break;
			}
		}
		result = 1;
	}

	return result;
}


int full_house(int die[5], int combination[13], int points[13])
{
	int number = 0, result = 0, sum1 = 0, sum2 = 0, three = 0, two = 0, number2 = 0;

	if (combination[8] == 0)
	{
		combination[8] = 1;

		result = 1;

		for (number = 1; number < 7; number++)
		{
			sum1 = 0;

			if (die[0] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[1] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[2] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[3] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[4] == number)
			{
				sum1 = sum1 + 1;
			}

			if (sum1 == 3)
			{
				break;
			}
		}

		for (number2 = 1; number2 < 7; number2++)
		{
			sum2 = 0;

			if (die[0] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[1] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[2] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[3] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[4] == number2)
			{
				sum2 = sum2 + 1;
			}

			if (number2 == number)
			{
				sum2 = 0;
			}

			if (sum2 == 2)
			{
				if (sum2 + sum1 == 5)
				{
					points[8] = 25;
				}
				break;
			}
		}
	}
	return result;

}

int small_straight(int die[5], int combination[13], int points[13])
{
	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	if (combination[9] == 0)
	{
		result = 1;

		combination[9] = 1;

		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (die[index] > die[index + 1])
				{
					temp = die[index];
					die[index] = die[index + 1];
					die[index + 1] = temp;
				}
			}
		}

		for (index = 4; index > 0; index--)
		{
			if (die[index] == die[index - 1] + 1)
			{
				sum++;
			}

		}

		if (sum >= 3)
		{
			points[9] = 30;
		}
	}

	return result;
}

int large_straight(int die[5], int combination[13], int points[13])
{
	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	if (combination[10] == 0)
	{
		result = 1;
		combination[10] = 1;
		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (die[index] > die[index + 1])
				{
					temp = die[index];
					die[index] = die[index + 1];
					die[index + 1] = temp;
				}
			}
		}

		for (index = 4; index > 0; index--)
		{
			if (die[index] == die[index - 1] + 1)
			{
				sum++;
			}

		}

		if (sum >= 4)
		{
			points[10] = 30;
		}
	}

	return result;
}


int yahtzee(int die[5], int combination[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	if (combination[11] == 0)
	{
		combination[11] = 1;

		for (number = 0; number < 5; number++)
		{
			sum = 0;

			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}

			if (sum == 5)
			{
				points[11] = 50;
			}
		}
		result = 1;
	}

	return result;
}

int chance(int die[5], int combination[13], int points[13])
{
	int result = 0, sum = 0;

	if (combination[12] == 0)
	{
		combination[12] = 1;
		result = 1;
		sum = die[0] + die[1] + die[2] + die[3] + die[4];

		points[12] = sum;
	}



	return result;
}
