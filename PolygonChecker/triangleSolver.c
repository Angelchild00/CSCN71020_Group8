#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "triangleSolver.h"

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
