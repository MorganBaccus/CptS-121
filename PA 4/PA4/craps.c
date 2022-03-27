/*******************************************************************************************
* Programmer: Morgan Baccus                                                                  *
* Class: CptS 121, Spring 2019; Lab Section 16                                            *
* Programming Assignment: PA4                                                     *
* Date: February 23, 2019                                                                          *
* Description:       *
*******************************************************************************************/

#include "craps.h"

// Prints the rules of craps
void printGameRules(void)
{
	printf("Here are the rules:\n");
	printf("A player rolls two dice. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. \nIf the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (the house wins).If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. \nTo win, you must continue rolling the dice until you make your point. \nThe player loses by rolling a 7 before making the point.\n");
}

// Prompts the user to enter their bank balance which is then saved as a double and returned
double getBankBalance(void)
{ 
	double balance = 0;

	printf("\nPlease enter your bank balance in dollars: ");
	scanf("%lf", &balance);
	
	return balance;
}

// PRompts the user to enter the amount that they want to wager on the roll
double getWagerAmount(void)
{
	double wagerAmount = 0;

	printf("\nPlease enter the amount of your wager in dollars: ");
	scanf("%lf", &wagerAmount);
	
	return wagerAmount;
}

// Checks that the wager is within the user's bank balance
int checkWagerAmount(double wager, double bankBalance)
{
	if (wager <= bankBalance)
	{
		return 1; // Within bank balance
	}
	else {
		return 0; // Exceeds bank balance
	}
	
}

// Will randomly generate a number 1-6 to simulate rolling a die
int rollDie(void)
{
	int dieValue = 0;

	dieValue = rand() % 6 + 1; // Generates a random number 1 - 6

	return dieValue;
}

// Calculates the sum of the dice rolled
int calculateDiceSum(int die1, int die2)
{
	int sum = 0;

	sum = die1 + die2;
	
	return sum;
}

// Return 0 if player losses, 1 if player wins, -1 if player gets point
int isWinLossOrPoint(int diceSum)
{

	if (diceSum == 2 || diceSum == 3 || diceSum == 12)
	{
		return 0; // loss
	}
	if (diceSum == 7 || diceSum == 11)
	{
		return 1; // win
	}
	else {
		return -1; // sum = player's point // needs to return score //
	}
	
}

// If the sum of the roll is the point value return 1, if the sum of the roll is a 7 return 0, else return -1
int isPointLossOrNeither(int diceSum, int pointValue)
{
	if (diceSum == pointValue)
	{
		return 1;
	}
	if (diceSum == 7)
	{ 
		return 0;
	}
	else {
		return -1;
	}
}

// Adjust bank balance based on the number returned from addOrSubtract
double adjustBankBalance(double bankBalance, double wagerAmount, int addOrSubtract)
{
	if (addOrSubtract == 1)
	{
		bankBalance = bankBalance + wagerAmount;
	}

	else if (addOrSubtract == 0)
	{
		bankBalance = bankBalance - wagerAmount;
	}
	
	return bankBalance;
}

void chatterMessages(int numberRolls, int winLossNeither, double initialBankBalance, double currentBankBalance)
{

}

// Function to call all the other functions so that the user can play the game
void playCraps(double bankBalance, double wager, int rollCount, int playersPoint)
{

	int die1 = 0, die2 = 0, sumDice = 0;

	printf("Ready to roll?\n");

	die1 = rollDie();
	die2 = rollDie();
	sumDice = calculateDiceSum(die1, die2);
	printf("Die 1 is: %d, Die 2 is: %d, The sum is: %d\n", die1, die2, sumDice);

	//sum becomes players point on first roll
	if (isWinLossOrPoint(sumDice) == -1)
	{
		if (rollCount == 0)
		{
			playersPoint = sumDice;
			printf("Your point is: %d\n", playersPoint);

		}

		// continue to play
		while (rollCount == 0 || sumDice != playersPoint)
		{
			rollCount++;
			playCraps(bankBalance, wager, rollCount, playersPoint);
		}

		if (sumDice == playersPoint)
		{
			printf("Congratulations! You won! The game is over\n"); //add wager to bank account
			bankBalance = adjustBankBalance(bankBalance, wager, 1);
			printf("Your updated bank balance is: %.2lf\n", bankBalance);
		}

	}

	else if (isWinLossOrPoint(sumDice) == 0)
	{
		printf("Sorry! You lost! The game is over \n");

		bankBalance = adjustBankBalance(bankBalance, wager, 0); //subtract wager from bank balance
		printf("Your updated bank balance is: %.2lf\n", bankBalance);
	}

	else if (isWinLossOrPoint(sumDice) == 1)
	{
		printf("Congratulation! You won! The game is over\n"); // palyer wins and game ends

		bankBalance = adjustBankBalance(bankBalance, wager, 1); //add wager to bank account
		printf("Your updated bank balance is: %.2lf\n", bankBalance);
	}
}

// Calls all other functions so that only this function must be called in main
void crapsTest(int rollCount)
{
	int checkWager = 0, playersPoint = 0;
	double bankBalance = 0, wager = 0;

	bankBalance = getBankBalance();

	do {
		wager = getWagerAmount();

		checkWager = checkWagerAmount(wager, bankBalance);

		if (checkWager != 1)
		{
			printf("Your wager is too high! Please enter a new wager.\n");
		}

	} while (checkWager != 1);

	playCraps(bankBalance, wager, rollCount, playersPoint);
}


