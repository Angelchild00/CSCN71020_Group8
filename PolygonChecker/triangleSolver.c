#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include "triangleSolver.h"

#define PI 3.14159265

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
		while (true) {
			if (scanf_s("%d", &triangleSides[i]) != 1 || triangleSides[i] <= 0) {
				while (getchar() != '\n');
				printf("Invalid Input. Please enter a positive integer:\n");
			}
			else {
				if (triangleSides[i] > 0 && triangleSides[i] <= INT_MAX) {
					break;
				}
				else {
					printf("Input is too large. Please enter a smaller integer:\n");
				}
			}
		}
	return triangleSides;
}

char* doLengthsFormTriangle(int side1, int side2, int side3) {		// TO DO: might have to make this return a bool
	// ex. inputs 5, 3, 4											// and, move lines 79-83 to main
	//max = 5
	//hypotenuse = sqrt((3 ^ 2) + (4 ^ 2))
	//does max == hypotenuse ?
	//5 == 5 therefore the lengths given, form a triangle

	int max = side1;
	int a = side2;
	int b = side3;
	if (side2 > max) {
		if (side2 > side3) {
			max = side2;
			a = side1;
			b = side3;
		}
		if (side3 > side2) {
			max = side3;
			a = side2;
			b = side3;
		}
	}
	
	int asquar = a * a;
	int bsquar = b * b;
	int hypotenuse = sqrt((asquar + bsquar));

	char* result = "";
	if (hypotenuse == max) {	//may be some buggs from this: it should work in theory, double check during testing
		bool istriangle = true;
		char* angles = (getAngleFromSides(a, b, max));
		char* result1 = "Given the lengths %d, %d, and %d:\nIsTriangle = TRUE\nAngles are %s", angles; 
		return result1;
	}
	char* result2 = "Given the lengths %d, %d, and %d:\nIsTriangle = FALSE";

	return result2; 
}

char* getAngleFromSides(int a, int b, int c) {
	float angles[3] = { 0 };
	//∠A = arccos((b2 + c2 - a2)/2bc)
	//∠B = arccos((a2 + c2 - b2)/2ac)	//arcos or acos() returns value in rad so must multiply by (180/PI) to get deg
	//∠C = arccos((a2 + b2 - c2)/2ab)
	char* result = "";
	float rad1 = acos(((b + c - a) / (2 * b * c)));
	float angle1 = (rad1 * (180 / PI));
	float rad2 = acos(((a + c - b) / (2 * a * c)));
	float angle2 = (rad2 * (180 / PI));
	float rad3 = acos(((a + b - c) / (2 * a * b)));
	float angle3 = (rad3 * (180 / PI));

	result = "%lf, %lf, and %lf", angle1, angle2, angle3;

	return  result; 	// this is not a good way of returning it
}