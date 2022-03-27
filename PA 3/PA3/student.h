/*******************************************************************************************
* Programmer: Morgan Baccus                                                                      *
* Class: CptS 121, Spring 2019; Lab Section 10                                            *
* Programming Assignment: PA3                                                    *
* Date: 2/2/19                                                                        *
* Description:      *
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

/* Precondition: file must already be opened successfully*/
double readDouble(FILE *infile);

int readInt(FILE *infile);

double calculateSum(double num1, double num2, double num3, double num4, double num5);

double calculateMean(double sum, int number);

double calculateDeviation(double number, double mean);

double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number, double GPAMean);

double calculateStandardDeviation(double variance);

double findMax(double num1, double num2, double num3, double num4, double num5);

double findMin(double num1, double num2, double num3, double num4, double num5);

void printDouble(FILE *outfile, double number);