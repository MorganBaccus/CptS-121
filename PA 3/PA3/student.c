/*******************************************************************************************
* Programmer: Morgan Baccus                                                                      *
* Class: CptS 121, Spring 2019; Lab Section 10                                            *
* Programming Assignment: PA3                                                    *
* Date: 2/2/19                                                                        *
* Description:      *
*******************************************************************************************/

#include "student.h"

/* Read Double Function*/
double readDouble(FILE *infile)
{
	double doubleVal = 0;
	fscanf(infile, "%lf", &doubleVal);
	
	return doubleVal;
}

/* Read Integer Function*/
int readInt(FILE *infile)
{
	int intVal = 0;
	fscanf(infile, "%d", &intVal);
	
	return intVal;
}

/* Calculate Sum Function*/
double calculateSum(double num1, double num2, double num3, double num4, double num5)
{
	double sum = 0;
	sum = num1 + num2 + num3 + num4 + num5;

	return sum;
}

/* Calculate Mean Function*/
double calculateMean(double sum, int number)
{
	double mean = 0;
	mean = sum / number;

	return mean;
}

/* Calculate Deviation Function*/
double calculateDeviation(double number, double mean)
{
	double deviation = 0;
	deviation = number - mean;

	return deviation;
}

/* Calculate Variance Function*/
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number, double GPAMean)
{
	double variance = 0;
	variance = (pow(deviation1 - GPAMean, 2) + pow(deviation2 - GPAMean, 2) + pow(deviation3 - GPAMean, 2) + pow(deviation4 - GPAMean , 2) + pow(deviation5 - GPAMean, 2)) / (number - 1);

	return variance;
}

/* Calculate Standard Deviation Function*/
double calculateStandardDeviation(double variance)
{
	double standardDeviation = 0;
	standardDeviation = sqrt(variance);

	return standardDeviation;
}

/* Find Max Function*/
double findMax(double num1, double num2, double num3, double num4, double num5)
{
	double max = num1;
	if (num2 > max)
	{
		max = num2;
	}
	if (num3 > max)
	{
		max = num3;
	}
	if (num4 > max)
	{
		max = num4;
	}
	if (num5 > max)
	{
		max = num5;
	}

	return max;
}

/* Find Min Function*/
double findMin(double num1, double num2, double num3, double num4, double num5)
{
	double min = num1;
	if (num2 < min)
	{
		min = num2;
	}
	if (num3 < min)
	{
		min = num3;
	}
	if (num4 < min)
	{
		min = num4;
	}
	if (num5 < min)
	{
		min = num5;
	}

	return min;
}

/* Print Double to Hundreth Function*/
void printDouble(FILE *outfile, double number)
{
	printf(outfile, "%.2lf", number);
}