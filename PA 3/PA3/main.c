/*******************************************************************************************
* Programmer: Morgan Baccus                                                                      *
* Class: CptS 121, Spring 2019; Lab Section 10                                            *
* Programming Assignment: PA3                                                    *
* Date: 2/2/19                                                                        *
* Description:    ----  *
*******************************************************************************************/

#include "student.h"

int main(void)
{
	/* Declare file pointers for input and output .dat files*/
	FILE *infile;
	FILE *outfile;
				   
	/* Declare variables*/
	double GPA1 = 0, GPA2 = 0, GPA3 = 0, GPA4 = 0, GPA5 = 0,
		age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0,
		GPASum = 0, CSSum = 0, ageSum = 0,
		GPAMean = 0, CSMean = 0, ageMean = 0,
		dev1 = 0, dev2 = 0, dev3 = 0, dev4 = 0, dev5 = 0, var = 0,
		GPAStdDev = 0, GPAMax = 0, GPAMin = 0;
	
	int ID1 = 0, ID2 = 0, ID3 = 0, ID4 = 0, ID5 = 0,
		classStand1 = 0, classStand2 = 0, classStand3 = 0, classStand4 = 0, classStand5 = 0,
		numStudents = 5;


	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");

	/* Read in information on student 1*/
	ID1 = readInt(infile); // needs to get 8 ints
	GPA1 = readDouble(infile);
	classStand1 = readInt(infile);
	age1 = readDouble(infile);

	/* Read in information on student 2*/
	ID2 = readInt(infile);
	GPA2 = readDouble(infile);
	classStand2 = readInt(infile);
	age2 = readDouble(infile);

	/* Read in information on student 3*/
	ID3 = readInt(infile);
	GPA3 = readDouble(infile);
	classStand3 = readInt(infile);
	age3 = readDouble(infile);

	/* Read in information on student 4*/
	ID4 = readInt(infile);
	GPA4 = readDouble(infile);
	classStand4 = readInt(infile);
	age4 = readDouble(infile);

	/* Read in information on student 5*/
	ID5 = readInt(infile);
	GPA5 = readDouble(infile);
	classStand5 = readInt(infile);
	age5 = readDouble(infile);

	/* Calculate Sums*/
	GPASum = calculateSum(GPA1, GPA2, GPA3, GPA4, GPA5);
	CSSum = calculateSum(classStand1, classStand2, classStand3, classStand4, classStand5);
	ageSum = calculateSum(age1, age2, age3, age4, age5);

	/* Calculate Means and output to file*/
	GPAMean = calculateMean(GPASum, numStudents);
	printDouble(outfile, GPAMean);

	CSMean = calculateMean(CSSum, numStudents);
	printDouble(outfile, CSMean);

	ageMean = calculateMean(ageSum, numStudents);
	printDouble(outfile, ageMean);

	/* Calculate deviation of each GPA*/
	dev1 = calculateDeviation(GPA1, GPAMean);
	dev2 = calculateDeviation(GPA2, GPAMean);
	dev3 = calculateDeviation(GPA3, GPAMean);
	dev4 = calculateDeviation(GPA4, GPAMean);
	dev5 = calculateDeviation(GPA5, GPAMean);

	/* Calculate the Variance of GPAs*/
	var = calculateVariance(dev1, dev2, dev3, dev4, dev5, numStudents, GPAMean);

	/* Calculate the Standard Deviation of GPAs and output to file*/
	GPAStdDev = calculateStandardDeviation(var);
	printDouble(outfile, GPAStdDev);

	/* Find GPA Min and output to file*/
	GPAMin = findMin(GPA1, GPA2, GPA3, GPA4, GPA5);
	printDouble(outfile, GPAMin);

	/* Find GPA Max and output to file*/
	GPAMax = (GPA1, GPA2, GPA3, GPA4, GPA5);
	printDouble(outfile, GPAMax);

	/* Close the files*/
	fclose(infile);
	fclose(outfile);

	return 0;
}