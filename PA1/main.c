/*******************************************************************************************
* Programmer: Morgan Baccus                                                                       *
* Class: CptS 121, Spring 2019; Lab Section X                                            *
* Programming Assignment: PA1                                                     *
* Date: January 18, 2019                                                                          *
* Description: Prompt user for input for several equations and use to solve for various equations.      *
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include <stdio.h>
#include <math.h>


int main(void)
{
	// declare floating-point variables
	double force = 0, mass = 0, acceleration = 0,
		volumeCylinder = 0, radius = 0, height = 0,
		distance = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0,
		tanTheta = 0, theta = 0,
		totalResistance = 0,
		y = 0, z = 0, x = 0, ySolution = 0;
	// declare integers
	int a = 0, shift = 0, R1 = 0, R2 = 0, R3 = 0;
	// declare characters
	char plaintextCharacter = '\0', encodedCharacter = '\0';

	// Newton's Second Law of Motion: force = mass * acceleration
	printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	scanf("%lf %lf", &mass, &acceleration);
	force = mass * acceleration;
	printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n\n", mass, acceleration, force);

	// Volume of a cylinder: volumeCylinder = PI * radius^2 * height
	printf("Please enter the radius and height (both floating-point values) for use in the volume of a cylinder equation: ");
	scanf("%lf %lf", &radius, &height);
	volumeCylinder = PI * (radius * radius) * height;
	printf("Volume of a cylinder: volumeCylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n\n", PI, radius, height, volumeCylinder);

	// Character encoding: encodedCharacter = (plaintextCharacter - 'A') + 'a' - shift
	printf("Please enter a plaintext character (a character) and a shift value (an integer value) for use in the character encoding equation: ");
	scanf(" %c %d", &plaintextCharacter, &shift);
	encodedCharacter = (plaintextCharacter - 'A') + 'a' - shift;
	printf("Character encoding: encodedCharacter = (plaintextCharacter - 'A') + 'a' - shift = ( %c - 'A') + 'a' - %d = %c \n\n", plaintextCharacter, shift, encodedCharacter);

	// Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2)
	printf("Please enter x1, x2, y1 and y2 (all floating-point values) for use in the distance between two points equations: ");
	scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
	distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	printf("Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of (%lf - %lf)^2 + (%lf - %lf)^2 = %lf\n\n", x1, x2, y1, y2, distance);

	// Tangent: tanTheta = sin (theta) / cos (theta)
	printf("Please enter theta (a floating-point value) for use in the tangent equation: ");
	scanf("%lf", &theta);
	tanTheta = sin(theta) / cos(theta);
	printf("Tangent: tanTheta = sin (theta) / cos (theta) = sin(%lf) / cos(%lf) = %lf\n\n", theta, theta, tanTheta);

	// Total resistance of resistors in paralell: totalResistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors
	printf("Please enter R1, R2, and R3 (all integers) for 3 resistors for use in the total resistance of resistors in paralell equation: ");
	scanf("%d %d %d", &R1, &R2, &R3);
	totalResistance = 1.0 / ((1.0 / R1) + (1.0 / R2) + (1.0 / R3));
	printf("Total resistance of resistors in paralell: totalResistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %lf\n\n", R1, R2, R3, totalResistance);

	// General equation: y = (2 / 3) - y + z * x / (a % 2) + PI
	printf("Please enter y, z, x, (all floating-point values) and a (an integer value) for use in the general equation: ");
	scanf("%lf %lf %lf %d", &y, &z, &x, &a);
	ySolution = (2.0 / 3.0) - y + z * x / (a % 2) + PI;
	printf("General equation: y = (2 / 3) - y + z * x / (a %% 2) + PI = (2 / 3) - %lf + %lf * %lf / (%d %% 2) + 3.141592 = ", y, z, x, a);
	printf("%lf\n\n", ySolution);

	system("pause");
}