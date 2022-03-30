/**************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
***************************************************/

#include "game.h"

int gameMenu(int input) {
	if (input == 1) {
		printf("The scorecard used for Yahtzee has two sections, an upper and lower section.");
		printf("There are thirteen scoring combinations are divided amongst the two sections.");
		printf("The upper section consists of scoring combos that are scored by summing the value of the dice matching the faces of the box.");
		printf("If a player rolls 3 3's, then the score placed in the 3's box is the sum of the dice which is 9.");
		printf("Once a player has chosen to fill a box, it cannot be overwritten.");
		printf("If the sum of the scores in the upper section is greater than or equal to 63,");
		printf("then 35 bonus points are added to the player's overall at the end of the game.");
		printf("The lower section contains combinations such as Yahtzee.\n");
	}
	else if (input == 2)
		return 1;
	else if (input == 3)
		return 0;
}
int *holdDice(int dice[], int numberHolds) {
	int temp1, temp2, temp3, temp4, temp5, pos1, pos2, pos3, pos4, pos5;

	if (numberHolds == 0) {
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
			printf("Die %d: %d\n", i + 1, dice[i]);
		}
	}

	if (numberHolds == 1) {
		printf("What one dice would you like to hold? 1-5\n");
		scanf("%d", &pos1);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
		}

		// Randomizes all dice
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		// Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	// When the player holds two dice
	if (numberHolds == 2) {
		printf("What TWO dice would you like to hold? 1-5\n");
		scanf("%d%d", &pos1, &pos2);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
		}

		// Randomizes all die
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		// Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	// When the player holds three dice
	if (numberHolds == 3) {
		printf("What THREE dice would you like to hold? 1-5\n");
		scanf("%d%d%d", &pos1, &pos2, &pos3);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
			if (j + 1 == pos3) {
				temp3 = dice[pos3 - 1];
			}
		}

		// Randomizes all dice
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		dice[pos3 - 1] = temp3;
		// Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	// When the player holds four dice
	if (numberHolds == 4) {
		printf("What four dice would you like to hold? 1-5\n");
		scanf("%d%d%d%d", &pos1, &pos2, &pos3, &pos4);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
			if (j + 1 == pos3) {
				temp3 = dice[pos3 - 1];
			}
			if (j + 1 == pos4) {
				temp4 = dice[pos4 - 1];
			}
		}

		// Randomizes all dice
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		dice[pos3 - 1] = temp3;
		dice[pos4 - 1] = temp4;

		// Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}

	return dice;
}

void printScoreboardOptions(void) {
	printf("Enter 1 For Sum Of Ones\n");
	printf("Enter 2 For Sum Of Twos\n");
	printf("Enter 3 For Sum Of Threes\n");
	printf("Enter 4 For Sum Of Fours\n");
	printf("Enter 5 For Sum Of Fives\n");
	printf("Enter 6 For Sum Of Sixes\n");
	printf("Enter 7 For Three Of A Kind\n");
	printf("Enter 8 For Four Of A Kind\n");
	printf("Enter 9 For A Full House\n");
	printf("Enter 10 For A Small Straight\n");
	printf("Enter 11 For A Large Straight\n");
	printf("Enter 12 For A Yahtzee\n");
	printf("Enter 13 For Chance\n");
}

int scoreboard1(int dice[], int choice) {
	int score = 0, temp = 0;

	if (choice <= 6) {
		for (int i = 1; i < 6; i++) {
			if (dice[i - 1] == choice) {
				temp = temp + 1;
			}
		}
		if (temp == 0) {
			score = 0;
		}
		else if (temp != 0) {
			
			score = temp * choice;
		}
	}

	if (choice == 7) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		if (temp > 2) {
			score = sumArray;
		}
		else if (temp != 3) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	// Four Of A Kind Option 8 Works
	if (choice == 8) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		if (temp == 4) {
			score = sumArray;
		}
		else if (temp != 4) {
			score = 0;
		}
	}

	// Full House Option 9
	if (choice == 9) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 3) {
			score = 25;
		}
		else if (temp != 3) {
			score = 0;
		}
	}

	// Small Straight Option 10 Works
	if (choice == 10) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 2) {
			score = 0;
		}
		else if (temp == 2) {
			score = 30;
		}
	}

	// Large Straight Option 11 Works
	if (choice == 11) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 4) {
			score = 0;
		}
		else if (temp == 4) {
			score = 40;
		}
	}

	// Yahtzee Option 12 Works
	if (choice == 12) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 4) {
			score = 50;
		}
		else if (temp != 4) {
			score = 0;
		}
	}

	// Chance Option 13 Works
	if (choice == 13) {
		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		score = sumArray;
	}

	return score;
}

int scoreboard2(int dice[], int choice) {
	int score = 0, temp = 0;
	if (choice <= 6) {
		for (int i = 1; i < 6; i++) {
			if (dice[i - 1] == choice) {
				temp = temp + 1;
			}
		}
		if (temp == 0) {
			score = 0;
		}
		else if (temp != 0) {
			score = temp * choice;
		}
	}

	// Three Of A Kind Option 7
	if (choice == 7) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		if (temp > 2) {
			score = sumArray;
		}
		else if (temp != 3) {
			score = 0;
		}
	}

	// Four Of A Kind Option 8 Works
	if (choice == 8) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		if (temp == 4) {
			score = sumArray;
		}
		else if (temp != 4) {
			score = 0;
		}
	}

	// Full House Option 9
	if (choice == 9) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 3) {
			score = 25;
		}
		else if (temp != 3) {
			score = 0;
		}
	}

	// Small Straight Option 10 Works
	if (choice == 10) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 2) {
			score = 0;
		}
		else if (temp == 2) {
			score = 30;
		}
	}

	// Large Straight Option 11 Works
	if (choice == 11) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 4) {
			score = 0;
		}
		else if (temp == 4) {
			score = 40;
		}
	}

	// Yahtzee Option 12 Works
	if (choice == 12) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 4) {
			score = 50;
		}
		else if (temp != 4) {
			score = 0;
		}
	}

	if (choice == 13) {
		int sumArray = 0;
		for (int i = 0; i < 5; i++) {
			sumArray += dice[i];
		}
		score = sumArray;
	}

	return score;
}