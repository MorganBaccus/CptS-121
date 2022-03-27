/*******************************************************************************************
* Programmer: Morgan Baccus                                                                       *
* Class: CptS 121, Spring 2019; Lab Section 16                                            *
* Programming Assignment: PA4                                                     *
* Date: February 23, 2019                                                                         *
* Description:       *
*******************************************************************************************/

#include "craps.h"

int main(void)
{
	int option = 0;
	
	srand(time(NULL));

	printf("Welcome to craps!\n");

	do {
		printf("Please enter 1 to view the rules, 2 to play, or 3 to exit:\n");
		scanf("%d", &option);

		if (option == 1)
		{
			printGameRules();
		}
		else if (option == 2)
		{
			system("cls"); // Clear screen
			printf("Let's play!");

			int rollCount = 0;
			crapsTest(rollCount); // call function that calls all the other functions that will play the game
		}
		else if (option == 3)
		{
			printf("You chose to exit. Goodbye!\n");
		}
	} while (option != 3);


	system("pause");
	return 0;
}