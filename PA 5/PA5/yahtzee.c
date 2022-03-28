/*******************************************************************************************
* Programmer: Morgan Baccus                                                                    *
* Class: CptS 121, Spring 2019; Lab Section 16                                            *
* Programming Assignment: PA 5                                                  *
* Date: March 6, 2019                                                                          *
* Description: This program is a game of a yahtzee and this .c file holds the function necessary to run the program.      *
*******************************************************************************************/

#include "yahtzee.h"

// Functions

void printGameRules(void)
{
	printf("Here are the rules for yahtzee:\n");
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.");
}