/*******************************************************************************************
* Programmer: Morgan Baccus                                                                    *
* Class: CptS 121, Spring 2019; Lab Section 16                                            *
* Programming Assignment: PA 5                                                  *
* Date: March 6, 2019                                                                          *
* Description: This program is a game of a yahtzee and this .c brings together the other two files.      *
*******************************************************************************************/

#include "yahtzee.h"


//Main

int main(void)
{
	int option = 0;

	printf("Welcome to yahtzee!\n");

	do
	{
		printf("Please enter 1 to view the game rules, 2 to play, or 3 to exit:\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printGameRules();
		}
		else if (option == 2)
		{
			system("cls"); // Clear screen
			printf("Let's play!\n");

			// call function that calls all the other functions that will play the game
		}
		else if (option == 3)
		{
			system("cls"); // Clear screen
			printf("You chose to exit. Goodbye!\n");
		}
	} while (option != 3);

	system("pause");
	return 0;
}