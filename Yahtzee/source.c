#include "headerPA5.h"


void run_yahtzee(void)
{
	srand((unsigned int)time(NULL));

	int player_turn = 1, dice[5] = { 0 }, rolls_count = 0, keep[5] = { 0 }, count[7] = { 0 }, score1[17] = { 0 }, score2[17] = { 0 }, score_select = 0, sum_dice = 0, total_turns = 0, option = 0, valid = 0, used1[14], used2[14], is_valid = 0;

	while (option == 0 || option == 1 || option == 2 || option == 3)
	{
		while (option == 0)
		{
			print_menu();
			option = get_menu_option();
			valid = is_valid_menu_option(option);
		}

		while (valid == 0)
		{
			printf("Please enter a valid selection.\n");
			option = get_menu_option();
			valid = is_valid_menu_option(option);
		}

		while (option == 1)
		{
			print_game_rules();
			printf("Got it? Press 2 to play!\n");
			option = get_menu_option();
		}

		while (option == 3)
		{
			exit_game();
			option = 4;
		}

		
		while (option == 2)
		{
			system("cls");
			while (total_turns < 27)
			{
				while (player_turn == 1)
				{
					while (rolls_count < 4)
					{
						score_select = 0;
						// print whose turn it is
						print_player_turn(player_turn);
						system("pause");
						// inital dice roll
						for (int i = 0; i < 5; i++)
						{
							dice[i] = roll_die();
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}

						//do you want to roll again?
						rolls_count = want_roll();

						if (rolls_count == 0)
							break;

						// which dice do you want to keep?
						for (int i = 0; i < 5; i++)
						{
							print_hold_die(i + 1);
							keep[i] = get_hold_die();
						}

						// roll dice not kept
						for (int i = 0; i < 5; i++)
						{
							if (keep[i] == 0)
							{
								dice[i] = roll_die();
							}
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}

						//do you want to roll again?
						rolls_count = want_roll();

						if (rolls_count == 0)
							break;

						// which dice do you want to keep?
						for (int i = 0; i < 5; i++)
						{
							print_hold_die(i + 1);
							keep[i] = get_hold_die();
						}

						// roll dice not kept
						for (int i = 0; i < 5; i++)
						{
							if (keep[i] == 0)
							{
								dice[i] = roll_die();
							}
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}
						system("pause");

						break;

					} //rolling process
					//print score card
					print_score_card(score1);
					print_score_card2(score1);
					//how do you want to score?
					score_select = get_score_option();
					is_valid = is_valid_selection(score_select);

					while (is_valid == 0 || used1[score_select] == 1)
					{
						
						if (is_valid == 0)
						{
							printf("Please select a valid score option, 1-13\n");
						}

						if (used1[score_select] == 1)
						{
							printf("You have already used this combination, please select another way to score this turn.\n");
						}

						score_select = get_score_option_valid();
						is_valid = is_valid_selection(score_select);

					}

					used1[score_select] = 1;

					// SUM DICE
					sum_dice = dice[1] + dice[2] + dice[3] + dice[4] + dice[0];
					// GET VALUES PER NUMBER
					int count[7] = { 0 };
					for (int i = 0; i < 5; i++)
					{
						if (dice[i] == 1)
							count[1] += 1;
						else if (dice[i] == 2)
							count[2] += 1;
						else if (dice[i] == 3)
							count[3] += 1;
						else if (dice[i] == 4)
							count[4] += 1;
						else if (dice[i] == 5)
							count[5] += 1;
						else if (dice[i] == 6)
							count[6] += 1;
					}

					// ONES
					if (score_select == 1)
					{
						score1[1] = count[1];
					}
					// TWOS
					else if (score_select == 2)
					{
						score1[2] = 2 * count[2];
					}
					// THREES
					else if (score_select == 3)
					{
						score1[3] = 3 * count[3];
					}
					// FOURS
					else if (score_select == 4)
					{
						score1[4] = 4 * count[4];
					}
					// FIVES
					else if (score_select == 5)
					{
						score1[5] = 5 * count[5];
					}
					// SIXES
					else if (score_select == 6)
					{
						score1[6] = 6 * count[6];
					}
					// THREE OF A KIND
					else if (score_select == 7)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] >= 3)
								score1[7] = sum_dice;
						}
					}
					// FOUR OF A KIND
					else if (score_select == 8)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] >= 4)
								score1[8] = sum_dice;
						}
					}
					// FULL HOUSE
					else if (score_select == 9)
					{
						for (int i = 0; i < 7; i++)
						{
							for (int j = 0; j < 7; j++)
							{
								if (count[i] == 3)
								{
									if (count[j] == 2)
										score1[9] = 25;
								}
							}
						}
					}
					// SMALL STRAIGHT
					else if (score_select == 10)
					{
						if ((count[1] >= 1 && count[2] >= 1 && count[3] >= 1 && count[4] >= 1) || (count[2] >= 1 && count[3] >= 1 && count[4] >= 1 && count[5] >= 1) || (count[3] >= 1 && count[4] >= 1 && count[5] >= 1 && count[6] >= 1))
							score1[10] = 30;
					}
					// LARGE STRAIGHT
					else if (score_select == 11)
					{
						if ((count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1 && count[6] == 1) || (count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1))
							score1[11] = 40;
					}
					// YAHTZEE
					else if (score_select == 12)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] == 5)
								score1[12] = 50;
						}
					}
					// CHANCE
					else if (score_select == 13)
					{
						score1[13] = sum_dice;
					}


					// TOTAL TOP
					score1[14] = score1[1] + score1[2] + score1[3] + score1[4] + score1[5] + score1[6];
					// BONUS
					if (score1[14] >= 63)
						score1[15] = 35;
					// TOTAL
					score1[16] = score1[14] + score1[15] + score1[7] + score1[8] + score1[9] + score1[10] + score1[11] + score1[12] + score1[13];

					system("cls");

					print_score_card(score1);
					print_score_card2(score1);
					system("pause");
					system("cls");
					player_turn = 2;
				} //while it's player 1's turn

				while (player_turn == 2)
				{

					while (rolls_count < 4)
					{
						score_select = 0;
						// print whose turn it is
						print_player_turn(player_turn);
						system("pause");
						// inital dice roll
						for (int i = 0; i < 5; i++)
						{
							dice[i] = roll_die();
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}

						//do you want to roll again?
						rolls_count = want_roll();

						if (rolls_count == 0)
							break;

						// which dice do you want to keep?
						for (int i = 0; i < 5; i++)
						{
							print_hold_die(i + 1);
							keep[i] = get_hold_die();
						}

						// roll dice not kept
						for (int i = 0; i < 5; i++)
						{
							if (keep[i] == 0)
							{
								dice[i] = roll_die();
							}
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}

						//do you want to roll again?
						rolls_count = want_roll();

						if (rolls_count == 0)
							break;

						// which dice do you want to keep?
						for (int i = 0; i < 5; i++)
						{
							print_hold_die(i + 1);
							keep[i] = get_hold_die();
						}

						// roll dice not kept
						for (int i = 0; i < 5; i++)
						{
							if (keep[i] == 0)
							{
								dice[i] = roll_die();
							}
						}
						// print dice
						for (int i = 0; i < 5; i++)
						{
							print_die_int(i + 1);
							print_die_value(dice[i]);
						}
						system("pause");

						break;

					} //rolling process
					  //print score card
					print_score_card(score2);
					print_score_card2(score2);
					//how do you want to score?
					score_select = get_score_option();
					is_valid = is_valid_selection(score_select);

					while (is_valid == 0)
					{
						printf("Please select a valid score option.\n");
						score_select = get_score_option_valid();
						is_valid = is_valid_selection(score_select);
					}


					while (used2[score_select] == 1)
					{
						printf("You have already used this combination, please select another way to score this turn.\n");
						score_select = get_score_option_valid();
					}

					used2[score_select] = 1;
					// SUM DICE
					sum_dice = dice[1] + dice[2] + dice[3] + dice[4] + dice[0];
					// GET VALUES PER NUMBER
					int count[7] = { 0 };
					for (int i = 0; i < 5; i++)
					{
						if (dice[i] == 1)
							count[1] += 1;
						else if (dice[i] == 2)
							count[2] += 1;
						else if (dice[i] == 3)
							count[3] += 1;
						else if (dice[i] == 4)
							count[4] += 1;
						else if (dice[i] == 5)
							count[5] += 1;
						else if (dice[i] == 6)
							count[6] += 1;
					}

					// ONES
					if (score_select == 1)
					{
						score2[1] = count[1];
					}
					// TWOS
					else if (score_select == 2)
					{
						score2[2] = 2 * count[2];
					}
					// THREES
					else if (score_select == 3)
					{
						score2[3] = 3 * count[3];
					}
					// FOURS
					else if (score_select == 4)
					{
						score2[4] = 4 * count[4];
					}
					// FIVES
					else if (score_select == 5)
					{
						score2[5] = 5 * count[5];
					}
					// SIXES
					else if (score_select == 6)
					{
						score2[6] = 6 * count[6];
					}
					// THREE OF A KIND
					else if (score_select == 7)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] >= 3)
								score2[7] = sum_dice;
						}
					}
					// FOUR OF A KIND
					else if (score_select == 8)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] >= 4)
								score2[8] = sum_dice;
						}
					}
					// FULL HOUSE
					else if (score_select == 9)
					{
						for (int i = 0; i < 7; i++)
						{
							for (int j = 0; j < 7; j++)
							{
								if (count[i] == 3)
								{
									if (count[j] == 2)
										score2[9] = 25;
								}
							}
						}
					}
					// SMALL STRAIGHT
					else if (score_select == 10)
					{
						if ((count[1] >= 1 && count[2] >= 1 && count[3] >= 1 && count[4] >= 1) || (count[2] >= 1 && count[3] >= 1 && count[4] >= 1 && count[5] >= 1) || (count[3] >= 1 && count[4] >= 1 && count[5] >= 1 && count[6] >= 1))
							score2[10] = 30;
					}
					// LARGE STRAIGHT
					else if (score_select == 11)
					{
						if ((count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1 && count[6] == 1) || (count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1))
							score2[11] = 40;
					}
					// YAHTZEE
					else if (score_select == 12)
					{
						for (int i = 0; i < 7; i++)
						{
							if (count[i] == 5)
								score2[12] = 50;
						}
					}
					// CHANCE
					else if (score_select == 13)
					{
						score2[13] = sum_dice;
					}


					// TOTAL TOP
					score2[14] = score2[1] + score2[2] + score2[3] + score2[4] + score2[5] + score2[6];
					// BONUS
					if (score1[14] >= 63)
						score1[15] = 35;
					// TOTAL
					score2[16] = score2[14] + score2[15] + score2[7] + score2[8] + score2[9] + score2[10] + score2[11] + score2[12] + score2[13];

					system("cls");

					print_score_card(score2);
					print_score_card2(score2);
					system("pause");
					system("cls");
					player_turn = 1;
				} //while it's player 2's turn
				total_turns += 1;
			} //while total turns is less than 27
			if (score2[16] > score1[16])
				printf("Congratulations Player 2, you win\n!");
			if (score1[16] > score2[16])
				printf("Congratulations Player 1, you win!\n");
			if (score1[16] == score2[16])
				printf("You tied!");
		} //while option = 2
	} //run function
}

void print_player_turn(int player_turn)
{
	printf("It's player %d's turn!\n", player_turn);
}

int roll_die(void)
{
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}

int want_roll(void)
{
	int roll_again = 0;
	printf("Do you want to roll again? Press 1 for yes, 0 for no.\n");
	scanf("%d", &roll_again);

	return roll_again;
}

void print_hold_die(int array_int)
{
	printf("Do you want to hold die %d? Press 1 for yes or 0 for no.\n", array_int);
}

int get_hold_die(void)
{
	int hold_die = 0;
	scanf("%d", &hold_die);
	return hold_die;
}

void print_die_value(int die_value)
{

	if (die_value == 1) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|            |\n");
		printf("|      @     |\n");
		printf("|            |\n");
		printf("|____________|\n\n");

	}
	else if (die_value == 2) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|  @         |\n");
		printf("|            |\n");
		printf("|        @   |\n");
		printf("|____________|\n\n");

	}
	else if (die_value == 3) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|  @         |\n");
		printf("|     @      |\n");
		printf("|        @   |\n");
		printf("|____________|\n\n");

	}
	else if (die_value == 4) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|  @     @   |\n");
		printf("|            |\n");
		printf("|  @     @   |\n");
		printf("|____________|\n\n");

	}
	else if (die_value == 5) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|  @     @   |\n");
		printf("|     @      |\n");
		printf("|  @     @   |\n");
		printf("|____________|\n\n");

	}
	else if (die_value == 6) {
		printf(" ____________\n");
		printf("|            |\n");
		printf("|  @     @   |\n");
		printf("|  @     @   |\n");
		printf("|  @     @   |\n");
		printf("|____________|\n\n");
	}
}

void print_die_int(int die_int)
{
	printf("Die Number %d\n", die_int);
}

void print_score_card(int *score)
{
	printf("__________________________________________________________________________________________________________\n");
	printf("|   |        Name         |              Combination              |                  Score                |\n");
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 1 |        Ones         |     All dice with face value one      |                   %d                   |\n", score[1]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 2 |        Twos         |     All dice with face value two      |                   %d                   |\n", score[2]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 3 |       Threes        |    All dice with face value three     |                   %d                   |\n", score[3]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 4 |       Fours         |     All dice with face value four     |                   %d                   |\n", score[4]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 5 |       Fives         |     All dice with face value five     |                   %d                   |\n", score[5]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 6 |       Sixes         |     All dice with face value six      |                   %d                   |\n", score[6]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("|_________________________________________________________________________________________________________|\n");
	printf("|          TOTAL          |           Sum of top section          |                   %d                   |\n", score[14]);
	printf("|          BONUS          |    If sum of top is more than 63      |                   %d                   |\n", score[15]);
	printf("|_________________________|_______________________________________|_______________________________________|\n");
	printf("|_________________________________________________________________________________________________________|\n");
	printf("| 7 |   Three-of-a-kind   |    Three dice with the same value     |                   %d                   |\n", score[7]);

}


	void print_score_card2(int *score)
	{
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 8 |   Four-of-a-kind    |     Four dice with the same value     |                   %d                   |\n", score[8]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 9 |      Full House     |     One pair and a three-of-a-kind    |                   %d                   |\n", score[9]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 10|   Small Straight    |        A sequence of four dice        |                   %d                   |\n", score[10]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 11|   Large Straight    |        A sequence of five dice        |                   %d                   |\n", score[11]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 12|       Yahtzee       |     Five dice with the same value     |                   %d                   |\n", score[12]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("| 13|       Chance        |      Maybe be used for any sequence   |                   %d                   |\n", score[13]);
	printf("|___|_____________________|_______________________________________|_______________________________________|\n");
	printf("|_________________________________________________________________________________________________________|\n");
	printf("|          TOTAL          |          Sum of both sections         |                   %d                   |\n", score[16]);
	printf("|_________________________|_______________________________________|_______________________________________|\n\n\n");

}

int get_score_option(void)
{
	int score_option = 0;
	printf("How would you like to score your dice? Select by typing the number in the left hand column.\n");
	scanf("%d", &score_option);

	return score_option;
}

int get_score_option_valid(void)
{
	int score_option = 0;
	scanf("%d", &score_option);

	return score_option;
}

void print_menu(void)
{
	printf("********************************************************\n");
	printf("                   WELCOME TO YAHTZEE                    \n");
	printf("                       MAIN MENU                        \n\n");
	printf("                 1) View Game Rules\n");
	printf("                   2) Play Game\n");
	printf("                     3) Exit\n\n");
	printf("*********************************************************\n\n");
}

int is_valid_menu_option(int option)
{
	int valid = 0;

	if (option == 1 || option == 2 || option == 3)
	{
		valid = 1;
	}

	return valid;
}

int get_menu_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

void print_game_rules(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations. See the table provided below:\n");
	printf("_______________________________________________________________________________________________________\n");
	printf("|        Name         |              Combination              |                  Score                |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|   Three-of-a-kind   |    Three dice with the same value     |  Sum of all face values on the 5 dice |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|   Four-of-a-kind    |     Four dice with the same value     |  Sum of all face values on the 5 dice |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|      Full House     |     One pair and a three-of-a-kind    |                   25                  |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|    Small Straight   |        A sequence of four dice        |                   30                  |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|    Large Straight   |        A sequence of five dice        |                   40                  |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|       Yahtzee       |     Five dice with the same value     |                   50                  |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
	printf("|       Chance        |      Maybe be used for any sequence   |  Sum of all face values on the 5 dice |\n");
	printf("|_____________________|_______________________________________|_______________________________________|\n");
}

void exit_game(void)
{
	printf("Thank you for playing!\n");
}


int is_valid_selection(int score_select)
{
	int is_valid = 0;

	if (score_select == 1 || score_select == 2 || score_select == 3 || score_select == 4 || score_select == 5 || score_select == 6 || score_select == 7 || score_select == 8 || score_select == 9 || score_select == 10 || score_select == 11 || score_select == 12 || score_select == 13)
	{
		is_valid = 1;
	}

	return is_valid;
}