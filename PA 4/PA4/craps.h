/*******************************************************************************************
* Programmer: Morgan Baccus                                                                       *
* Class: CptS 121, Spring 2019; Lab Section 16                                            *
* Programming Assignment: PA4                                                     *
* Date: February 23, 2019                                                                          *
* Description:       *
*******************************************************************************************/

// define and include
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function declarations
void printGameRules(void);

double getBankBalance(void);

double getWagerAmount(void);

int checkWagerAmount(double wager, double bankBalance);

int rollDie(void);

int calculateDiceSum(int die1, int die2);

int isWinLossOrPoint(int diceSum);

int isPointLossOrNeither(int diceSum, int pointValue);

double adjustBankBalance(double bankBalance, double wagerAmount, int addOrSubtract);

void chatterMessages(int numberRolls, int winLossNeither, double initialBankBalance, double currentBankBalance);

void playCraps(double bankBalance, double wager, int rollCount, int playersPoint);

void crapsTest(int rollCount);