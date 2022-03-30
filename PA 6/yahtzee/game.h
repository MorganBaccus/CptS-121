/**************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
***************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>

// Function prototypes
int gameMenu(int input);
int *holdDice(int dice[], int numberHolds);
void printScoreboardOptions(void);
int scoreboard1(int dice[], int choice);
int scoreboard2(int dice[], int choice);