/**************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
***************************************************/

#include "game.h"

int main(void) {
	int rerollDecider, numberHolds, diceKeepDecision, oneDice, twoDice, threeDice, fourDice, fiveDice, target, continueReroll;
	srand(time(NULL));
	//printGameBoard(printGameRules);
	int dice[5] = { 0 };
	int pos1, pos2, pos3, pos4, pos5, temp, temp1, temp2, player1, player2, choice, input, rollIt, score1 = 0, score2 = 0;
	do {
		printf("Press 1 For Game Rules\nPress 2 To Start Game\nPress 3 To Exit\n");
		scanf("%d", &input);
		gameMenu(input);
		if (input == 3) {
			printf("\nGoodbye\n\n");
			return 0;
		}
	} while (input != 2);
	system("cls");
	// Play the game 28 times for 14 rounds
	for (int i = 1; i < 46; i++) {

		// If the iterations is odd Player 1 goes
		if (i % 2 != 0) {
			player1 = 1;
			player2 = 0;
			printf("Player One Turn\n");
		}
		// If the iterations is even Player 2 goes
		else if (i % 2 == 0) {
			player1 = 0;
			player2 = 1;
			printf("Player Two Turn\n");
		}

		// Array assigns 5 dice values
		system("pause");
		for (int i = 0; i < 5;) {
			dice[i] = rand() % 6 + 1;
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
		// See if player wants to change dice or not
		printf("Would you like to reroll any dice? Press 1 to reroll, 0 to keep all\n");
		scanf("%d", &diceKeepDecision);

		if (diceKeepDecision == 1) {
			printf("How many die would you like to hold? 0-4\n");
			scanf("%d", &numberHolds);
			printf("This is your first reroll\n");
			holdDice(dice, numberHolds);
			for (int n = 0; n < 2; n++) {
				printf("Would you like to reroll again? Press 1 to Reroll, 0 To Keep\n");
				scanf("%d", &continueReroll);
				if (continueReroll == 1) {
					printf("How many die would you like to hold? 0-4\n");
					scanf("%d", &numberHolds);
					printf("This is your %d/3 rerolls\n", n + 2);
					holdDice(dice, numberHolds);
				}
			}
		}
		printScoreboardOptions();
		// If Player 1, use Player 1 scoreboard
		if (player1 == 1) {
			printf("Hey Player 1! What combination would you like to choose? 1-12\n");
			scanf("%d", &choice);
			score1 = score1 + scoreboard1(dice, choice);
			printf("PLAYER ONE: Score %d\n", score1);
		}
		// If Player 2, use Player 2 scoreboard
		else if (player2 == 1) {
			printf("Hey Player 2! What combination would you like to choose? 1-12\n");
			scanf("%d", &choice);
			score2 = score2 + scoreboard2(dice, choice);
			printf("PLAYER TWO: Score %d\n", score2);
		}
		if (i >= 28) {
			if (score1 >= 63) {
				for (int w = 0; w < 10; w++) {
					printf("Player One wins!");
				}

			}
			else if (score2 >= 63) {
				for (int w = 0; w < 10; w++) {
					printf("Player Two wins!");
				}
			}
		}
	}

	return 0;
}