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
// two players roll the dice
// points are obtain by rolling five dice across thirteen tounds.
// During each round, each player may roll the dice up to three times to make one of the possible scoring combinations. 
// Each scoring combination has different point totals. 
// The scorecard used for Yahtzee is composed of two sections.
// supper section and lower section
// A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. 
// upper setion  consists of boxes that are scored by summing the value of the dice matching the faces of the box.
// If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.
// Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.
// If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.
// The lower section contains a number of poker like combinations. See the table provided below:


#include "PA5.h"

int main(void)
{
	

	srand((unsigned int)time(NULL)); // call only once PERIOD

	//print game menu for the user
	print_game_option();
	//system("pause");
	system("cls");
	
	check_game_rule();




	return 0;
}