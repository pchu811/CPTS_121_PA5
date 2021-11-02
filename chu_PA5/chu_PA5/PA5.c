/*******************************************************************************
* Programmer: Pei-Chi Chu													  *
* Class: CptS 121; Lab Section 19                                             *
* Programming Assignment: Programming Project 5                               *
* Date: 10/24/2021                                                            *
*                                                                             *
* Description: This program reports the the Game of Yahtzee					  *
*                                                                             *
*                                                                             *
* Relevant Formulas: None                                                     *
*                                                                             *
* Format of input file (input.dat):											  *
* Format of output file (output.dat):							              *
******************************************************************************/

#include "PA5.h"

//print game menu for the user
void print_game_option(void)
{
	printf("********************  Welcome Yahtzee  ********************\n\n");
	printf("1. Print game rule\n");
	printf("2. Start a game of Yahtzee\n");
	printf("3. Exit\n\n");

	printf("Please choose a number: ");
}

//display the emenu
void display_rule(void)
{
	printf("1. The scorecard used for Yahtzee is composed of two sections.A upper section and a lower section.\n");
	printf("2. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("3. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. \n");
	printf("4. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.  \n");
	printf("5. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. \n");
	printf("6. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. \n");
	printf("7. The lower section contains a number of poker like combinations.\n\n");
	printf("----------------Upper Section---------------\n\n");
	printf("#1. the dice of 1: score sum of 1's\n");
	printf("#2. the dice of 2: score sum of 2's\n");
	printf("#3. the dice of 3: score sum of 3's\n");
	printf("#4. the dice of 4: score sum of 4's\n");
	printf("#5. the dice of 5: score sum of 5's\n");
	printf("#6. the dice of 6: score sum of 6's\n\n");
	printf("----------------Lower Section----------------\n\n");
	printf("#7. Three-of-a-kind (three dice with the same face): score sum of all face values on the 5 dice\n");
	printf("#8. Four-of a kind (Four dice with the same face): score sum of all face values on the 5 dice\n");
	printf("#9. Full house (One pair and a three-of-a-kind): score plus 25\n");
	printf("#10. Small straight (A sequence of four dice): score plus 30\n");
	printf("#11. Large straight (A sequence of five dice): score plus 40\n");
	printf("#12. Yahtzee (think five-of-a-kind) (Five dice with the same face): score plus 50\n\n");
	printf("#13. Chance(May be used for any sequence of dice; this is the catch all combination): \nscore Sum of all face values on the 5 dice\n\n\n");

	check_game_rule();
}

//Get a menu option from the user; clear the screen
int get_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

int print_and_validate(void)
{
	int option = 0;

	do
	{
		print_game_option();
		option = get_option();
	} while (option < 1 || option > 3); // input validation loop

	return option;
}

//get option and choose option from user
int check_game_rule(void)
{
	int option = 0;

	option = print_and_validate();

	switch (option) // option has to be 1 - 3
	{
	case 1: // print the menu
		display_rule();
		break;
	case 2: // get the initial bank balance
		while (1) {
			int s_one[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//score--- to store score in array(13 elements)
			int s_two[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			int c_one[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };// check two player's choice, cant repeat choosing
			int c_two[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			//switch player1 and player2, round 13 times
			for (int i = 0; i < 13; i++) {
				yahtzee_game(s_one, c_one, 1); //player 1
				yahtzee_game(s_two, c_two, 2); //player 2
			}
			//determine player1 and player 2 who is winner
			//if player1 win
			if (sum_array(s_one, 14) > sum_array(s_two, 14)) {
				printf("Congratulations! Player 1 win!");
			}
			//if player2 win
			else if (sum_array(s_two, 14) > sum_array(s_one, 14)) {
				printf("Congratulations! Player 2 win!");
			}
			//if draw
			else {
				printf("Draw!");
			}
		
			break;
		}
		break;
	case 3: // Exit
		printf("Thank you!");
		break;
	}

}

//Ask the player to hit any key to continue on to roll the five dice
int continue_game(void)
{
	getch(); //按任何建進入
	//printf("Please hit any key to continue to roll the five dice: ");
	system("cls");
	system("pause");
}

//Roll the five dice and display the face values of each die
void roll_dice(int* dice)
{
	for (int i = 0; i < 5; i++)
	{
		dice[i] = rand() % 6 + 1;
	}
	printf("%d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
}

//round game
//round three chance
void yahtzee_game(int* s, int* c, int p) //s--score, c -- user choice, p-- player
{
	int reroll = 0, choose_dice = 0;

	continue_game();
	if (p == 1) {
		printf("PLAYER 1\n");
	}
	else if (p == 2) {
		printf("PLAYER 2\n");
	}
	prompt_score(s);

	int dice[5]; //array dice 1-5
	int user_selection = 0; //value of yes or no from users
	char ans = '\0'; //for if the user choose to continue the game
	//three time for user if the user want to roll the dice
	for (int i = 0; i < 3 && user_selection == 0; i++)
	{	
		int win = 0, size = 0;
		//char user_selection_one[3], user_selection_two[3];//ask the user if he/she wants to choose
		//char guest_one[13]; char guest_two[13];//the condition of users's choose, check if they already choose 1-13

		
		if (i == 0)
		{
			roll_dice(dice);
			bubble_sort(dice, size);
		}
		//round three-- no chance to reroll the dice
		//the third round to ask the user which combinatioin she/he wants to choose
		if (i == 2)
		{
			printf("It's the final round! Which combination do you want to choose?");
			scanf(" %d", &user_selection);

			while (1)
			{
				if (user_selection >= 1 && user_selection <= 13)
				{
					score_get(user_selection, dice, NUM_DICE, s, c);
					break;
				}
				else
				{
					printf("OOPS! Which combination do you want to choose? (1 - 13)");
					scanf(" %d", &user_selection);
				}
			}

		}
		//when round one and round two 穦タ盽笲︽┏ 
		//ask the player (Y/N) if he/she wants to reroll the dice //use the roll for one of the game combinations		
		else
		{
			//ask the user if he/she wants to continue the game y or n
			printf("Do you want to continue to reroll dice[Y(for yes)/N(for no)]:\n");
			scanf(" %c", &ans);

			do 
			{
				//if yes -- how many numbers do you want to reroll
				//array for which one do you want to reroll(1-5)
				if (ans == 'y' || ans == 'Y')
				{
					printf("How many dice do you want to reroll(press 1 - 5)? \n");
					scanf(" %d", &reroll);

					for (int i = 0; i < reroll; i++)
					{
						printf("Which dice do you want to reroll? (press 1 - 5 according to the position) \n");
						scanf(" %d", &choose_dice);
						
						//reroll dice //choose_dice-1 -- 玩家選擇地當時位置 -1 玩家選擇3 -- 位置[2]
						dice[choose_dice - 1] = rand() % 6 + 1; //隨機數
					}
					printf("%d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
					bubble_sort(dice, size);
					break;
				}
				//if no
				//ask the user which combination she/he wants to choose
				else if (ans == 'n' || ans == 'N')
				{
					printf("Which combination would you want to choose? ");
					scanf(" %d", &user_selection);
					//select dice combination
					score_get(user_selection, dice, NUM_DICE, s, c);
					break;
				}
				else
				{
					printf("Please enter Y/N: ");
					scanf(" %c", &ans);
				}
			} while (i < 3);

		}
		
	}
	prompt_score(s);

	printf("Press any key to switch player: ");
	getch();

}


//get score 產硄筁–˙匡拒眔だ计
//choose dice combination
//choiceノめ匡拒, dice 浑纗,  size 浑1-5
//select dice combination
void score_get(int choice, int* dice, int size, int* s, int* c) 
{
	int score = 0; //store score in array(13 combination)

	//if the comnation have been choosen, ask the user rechoose one
	while (c[choice - 1] == 1) { //choice-1 --- size start at 0, so -1 //==1 required condition
		printf("this combination is already choosen, please choose another one:\n");
		scanf("%d", &choice);
	}
	bubble_sort(dice, size);


	//when choose combination 1 through 6
	if (choice >= 1 && choice <= 6)
	{
		score = sum_dice_with_specified_face_value(dice, size, choice);
	}

	/// <summary>
	/// lower section for user to choose
	/// </summary>
	/// <param name="choice"></param>
	/// <param name="dice"></param>
	/// <param name="size"></param>
	if (choice == 7) //Three-of-a-kind 
	{
		for (int i = 0; i < size - 2; i++) 
		{
			if (dice[i] == dice[i + 1] && dice[i] == dice[i + 2]) //Three dice with the same face
			{
				score += sum_array(dice, size); //Sum of all face values on the 5 dice
			}
		}
	}
	if (choice == 8) //Four-of-a-kind 
	{
		for (int i = 0; i < size - 3; i++)
		{
			if (dice[i] == dice[i + 1] && dice[i] == dice[i + 2] && dice[i] == dice[i + 3]) //Four dice with the same face
			{
				score = sum_array(dice, size); //Sum of all face values on the 5 dice
			}
		}
	}
	if (choice == 9) //Full house
	{
		bubble_sort(dice, size);
		//One pair and a three-of-a-kind
		if (((dice[0] == dice[1]) && (dice[2] == dice[3] && dice[2] == dice[4])) || ((dice[0] == dice[1] && dice[0] == dice[2]) && (dice[3] == dice[4])))
		{
			score = 25; //score + 25
		}
	}
	if (choice == 10) //Small straight -- A sequence of four dice
	{
		int in_sequence = 0;

		for (int i = 0; i < size - 1; i++)
		{
			if (dice[i] == dice[i + 1] - 1)
			{
				in_sequence++;
			}
			else if (dice[i] != dice[i + 1] && in_sequence != 3)
			{
				in_sequence = 0;
			}
		}
		if (in_sequence >= 3)
		{
			score = 30;
		}
		else {
			score = 0;
		}
	}
	if (choice == 11) //Large straight --A sequence of five dice
	{
		if (dice[0] == dice[1] - 1 && dice[0] == dice[2] - 2 && dice[0] == dice[3] - 3 && dice[0] == dice[4] - 4) 
		{
			score = 40;
		}
	}
	if (choice == 12) //Yahtzee (think five-of-a-kind)
	{
		if (dice[0] == dice[1] && dice[0] == dice[2] && dice[0] == dice[3] && dice[0] == dice[4]) {
			score = 50; //score + 50
		}
	}
	if (choice == 13)  //Chance -- May be used for any sequence of dice; this is the catch all combination
	{
		score = sum_array(dice, size); //Sum of all face values on the 5 dice
	}
	c[choice - 1] = 1;
	s[choice - 1] = score;
}
  
//calculates the sum of an array
int sum_array(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

//display score
void prompt_score(int* score) { //*score save score 
	printf("-------------  Score  -------------\n");
	printf("1: Sum of ones       %d   2: Sum of twos        %d\n", score[0], score[1]);
	printf("3: Sum of threes     %d   4: Sum of fours       %d\n", score[2], score[3]);
	printf("5: Sum of fives      %d   6: Sum of sixes       %d\n", score[4], score[5]);
	printf("7: Three of a kind   %d   8: Four of a kind     %d\n", score[6], score[7]);
	printf("9: Full house        %d   10: Small straight    %d\n", score[8], score[9]);
	printf("11: Big straight     %d   12: Yahtzee           %d\n", score[10], score[11]);
	printf("13: Chance			 %d   \n\n", score[12]);
	//sum_array, total score
	//前6個數組加起來(upper section) >= 63
	if (sum_array(score, 6) >= 63) {
		score[13] = 35;
	}
	printf("total score: [%d]  bonus: [%d] \n\n\n",  sum_array(score, 14), score[13]); //14-- +bonus

}


void bubble_sort(int arr[], int size) {
	int tempt = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tempt = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tempt;
			}
		}
	}
}

/// <summary>
/// Finds the sum of all dice with the specified face value.
/// </summary>
/// <param name="dice_arr"></param>
/// /// <param name="size"></param>
/// <param name="target_face_value"></param>
/// <returns>the sum of all dice with the specified face value</returns>
int sum_dice_with_specified_face_value(int* dice_arr, int size, int target_face_value)
{
	int final_score = 0;
	for (int i = 0; i < size; i++) {
		if (dice_arr[i] == target_face_value)
		{
			final_score += target_face_value;
		}
	}
	return final_score;
}