#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "triangleSolver.h"

#define PI 3.14159265

bool doLengthsFormTriangle(int side1, int side2, int side3) {
	return ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1));
}

const char* analyzeTriangle(int side1, int side2, int side3) {
	if (!doLengthsFormTriangle(side1, side2, side3)) {
		return "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		return "Equilateral triangle";
	}
	else if (side1 == side2 || side1 == side3 || side2 == side3) {
		return "Isosceles triangle";
	}
	else {
		return "Scalene triangle";
	}
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



const char* getAngleFromSides(int a, int b, int c) {
	static char result[100];
	float angles[3] = { 0 };

	angles[0] = (float)(acos((double)(b * b + c * c - a * a) / (2 * b * c)) * (180 / PI));
	angles[1] = (float)(acos((double)(a * a + c * c - b * b) / (2 * a * c)) * (180 / PI));
	angles[2] = (float)(acos((double)(a * a + b * b - c * c) / (2 * a * b)) * (180 / PI));

	snprintf(result, sizeof(result), "%.2f, %.2f, and %.2f", angles[0], angles[1], angles[2]);
	return result;
}