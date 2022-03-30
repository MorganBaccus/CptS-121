/**************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
***************************************************/

//Starting Code Authors: Deitel & Deitel - C How to Program
//Starting Code copied from https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA7.htm

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define HAND_SIZE 6
#define FACE_TYPES 13
#define SUIT_TYPES 4

typedef struct card {
	int faceIndex;
	int suitIndex;
} Card;

// Function prototypes
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], Card handTwo[]);
void printHand(const char *wFace[], const char *wSuit[], Card hand[]);
void calcNumTimes(Card hand[], int numTimes[13]);
int containsPair(Card hand[], int numTimes[13]);
int containsTwoPair(Card hand[], int numTimes[13]);
int containsThreeOfAKind(Card hand[], int numTimes[13]);
int containsFourOfAKind(Card hand[], int numTimes[13]);
void calcCountSuit(Card hand[], int suitCount[4]);
int containsFlush(Card hand[], int suitCount[4]);
int containsStraight(Card hand[], int numTimes[13]);
void printMenu(void);
char handleCharInput(void);
void clearScreen(void);
int evaluateHand(Card hand[]);
void pressKeyToContinue(void);
void reinitializeArrays(Card handOne[], Card handTwo[], int deck[4][13]);
int dealerAI(Card hand[], int playerOneScore, int playerTwoScore);
void drawNCards(Card hand[], Card handTwo[], int n);
void drawNCardsPlayer(Card hand[], Card handTwo[], int n);
int ifCardHasBeenDrawn(int desiredFace, int desiredSuit, Card handOne[], Card handTwo[]);
void generateCard(int *face, int *suit);

#endif