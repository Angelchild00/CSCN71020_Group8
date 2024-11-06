#include <stdio.h>
#include <stdbool.h>

#include "rectangleSolver.h"

// Project 1 - Leanne Ryan Luis

// implementation of the rectangleSolver library


//main rectangle function
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	sortPoints(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

	int perimeter = ("test %d", PerimeterFrom4Points(x1, y1, x2, y2, x3, y3, x4, y4));


	if (checkIsRectangle(x1, y1, x2, y2, x3, y3, x4, y4) == true) {
		float area = AreaOfRectangle(length, width);
		// return perimeter, area
	}

	return perimeter;
}


void sortPoints(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, int* x4, int* y4) {

}

bool checkIsRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	//check anlges
	{
		// if all angles == 90deg
		return true;
	}

	return false;
}

int PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// find the 4 lengths
	// perimeter = l1 + l2 + l3 + l4
}

float AreaOfRectangle(int length, int width) {
	// area = length * width
}

