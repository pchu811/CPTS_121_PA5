#ifndef PA5_old_H
#define PA5_old_H

/******************************************************************************
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

#define _CRT_SECURE_NO_WARNINGS

/******************************************************************************
* Globals											  *
******************************************************************************/
#define NUM_DICE 5


#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()

/************************************************************************
* Function: print_game_option()											*
* Date Created:10/24/2021												*
* Date Last Modified:													*
* Description: Print a game menu for Yahtzee						    *
* Input parameters: 													*
* Returns:																*
* Preconditions:														*
* Postconditions:														*
************************************************************************/
void print_game_option(void);

/***********************************************************************
* Function: display_rule()												*
* Date Created:10/24/2021												*
* Date Last Modified:													*
* Description: display game rule									    *
* Input parameters: 													*
* Returns:																*
* Preconditions:														*
* Postconditions:														*
***********************************************************************/
void display_rule(void);

//Get a menu option from the user; clear the screen
int get_option(void);

//option print and validate
int print_and_validate(void);

//If option 1 is entered, then print the game rules stated above and repeat step (1)
//otherwise if option 2 is entered, then continue on to step(4); player 1 starts the game
//otherwise if option 3 is entered, then print a goodbye messageand quit the program
//otherwise repeat step(1)
int check_game_rule(void);

//Ask the player to hit any key to continue on to roll the five dice
int continue_game(void);

//Roll the five dice and display the face values of each die
//int roll_die(void);
void display_dice(int* dice);

//roud game
void yahtzee_game(int* s, int* c);

//calculates the sum of an array
int sum_array(int array[], int size);

//get score 玩家通過每一步選擇得到分數
//choose dice combination
//choice用戶的選擇, dice 骰子值儲存,  size 骰子1-5
void score_get(int choice, int* dice, int size, int* s, int* c);

//display score
void prompt_score(int* score);

//swap array 
void bubble_sort(int arr[], int size);

#endif // DEBUG




