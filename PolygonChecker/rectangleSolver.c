#include <stdio.h>
#include <stdbool.h>

#include "rectangleSolver.h"

// Project 1 - Leanne Ryan Luis

// implementation of the rectangleSolver library

#define POINTS	4
#define UPPER	2
#define LOWER	1

void GetInput(CORNERS* points) {
	for (int i = 0; i < POINTS; i++) {
		int valid = 0;
		while (!valid) {
			printf("Enter x and y for point %d:\n", i + 1);
			if (scanf_s("%d %d", &points[i].x, &points[i].y) == 2) {
				if (ValidateInput(points[i])) {
					valid = 1;
				}
				else {
					printf("Invalid Input.Please enter Positive integers:\n");
				}
			}
			else {
				printf("Invalid Input. Please enter positive integers:\n");
				while (getchar() != '\n');
			}
		}

	}
}
int ValidateInput(CORNERS points) {
	if (points.x > 0 && points.y > 0) {
		return 1;
	}
	else
		return 0;
}

bool CheckRightAngle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	//Get length and width of 4 lines.
	int line1x = x2 - x1; int line1y = y2 - y1;
	int line2x = x3 - x2; int line2y = y3 - y2;
	int line3x = x4 - x3; int line3y = y4 - y3;
	int line4x = x1 - x4; int line4y = y1 - y4;
	//Calculate every dot product of two cross lines.
	int DotProduct1 = line1x * line2x + line1y * line2y;
	int DotProduct2 = line2x * line3x + line2y * line3y;
	int DotProduct3 = line3x * line4x + line3y * line4y;
	int DotProduct4 = line4x * line1x + line4y * line1y;
	//Check if four dot products are all 0, all 0 means it's a rectangle.
	return DotProduct1 == 0 && DotProduct2 == 0 && DotProduct3 == 0 && DotProduct4 == 0;
}

// This func should work for whatever points of two.
double LengthOfTwoPoints(int x1, int x2, int y1, int y2) {
	//int x1 = CORNERS.x;
	//int x2 = CORNERS.x;
	//int y1 = CORNERS.y;
	//int y2 = CORNERS.y;
	double lengthoftwo = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return lengthoftwo;
}

// This func should work whatever the shape is rectangle or not. 
double PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// find the 4 lengths
	// perimeter = l1 + l2 + l3 + l4
	double line1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	double line2 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	double line3 = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
	double line4 = sqrt(pow((x4 - x1), 2) + pow((y4 - y1), 2));
	return line1 + line2 + line3 + line4;
}

// This func should work only if the shape is rectangle.
double AreaOfRectangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	// area = length * width
	double line1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));	//length
	double line2 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));	//width
	double area = line1 * line2;
	return area;
}


//main rectangle function
bool analyzeRectangle(CORNERS* points) {

	CORNERS newPoints[POINTS] = { 0 };
	for (int i = 0; i < POINTS; i++) {
		newPoints[i] = sortPoints(points, i);
	}

	int perimeter = PerimeterFrom4Points(newPoints[0].x, newPoints[0].y, newPoints[1].x, newPoints[1].y, newPoints[2].x, newPoints[2].y, newPoints[3].x, newPoints[3].y);
	
	//char result = ("IsRectangle = False\nPerimeter of shape = %d", perimeter);

	if (CheckRightAngle(newPoints[0].x, newPoints[0].y, newPoints[1].x, newPoints[1].y, newPoints[2].x, newPoints[2].y, newPoints[3].x, newPoints[3].y)) {
		float area = AreaOfRectangle(newPoints[0].x, newPoints[0].y, newPoints[1].x, newPoints[1].y, newPoints[2].x, newPoints[2].y);

		printf("IsRectangle = True\nPerimeter = %d\nRectangle Area = %f", perimeter, area);
		return true;
	}

	printf("IsRectangle = False\nPerimeter = %d\n", perimeter);
	return false;
}

// sorts points given by user to desired format
CORNERS sortPoints(CORNERS* points, int p) {
	//given: 3,3  4,5  5,3  2,5  
	//should recieve: 3,3  5,3  4,5  2,5

	int tx1 = points[0].x; int tx2 = points[1].x; int tx3 = points[2].x; int tx4 = points[3].x;
	int arrayX[] = { tx1, tx2, tx3, tx4 };
	int ty1 = points[0].y; int ty2 = points[1].y; int ty3 = points[2].y; int ty4 = points[3].y;
	int arrayY[] = { ty1, ty2, ty3, ty4 };

	// Find the center point for sorting.
	float sumX = (tx1 + tx2 + tx3 + tx4);
	float centerX = (sumX / POINTS);
	float sumY = (ty1 + ty2 + ty3 + ty4);
	float centerY = (sumY / POINTS);

	// Determine the quadrant of each point based on the center point.
	int quadX[POINTS] = { 0 };
	int quadY[POINTS] = { 0 };
	for (int i = 0; i < POINTS; i++) {
		quadX[i] = (arrayX[i] > centerX) ? UPPER : LOWER;
		quadY[i] = (arrayY[i] > centerY) ? UPPER : LOWER;
	}

	// Sort the points into a new array based on their quadrant values.
	static CORNERS newPoints[POINTS];
	for (int i = 0; i < POINTS; i++) {
		if (quadX[i] == LOWER && quadY[i] == LOWER) {
			newPoints[0] = points[i];
		}
		else if (quadX[i] == UPPER && quadY[i] == LOWER) {
			newPoints[1] = points[i];
		}
		else if (quadX[i] == UPPER && quadY[i] == UPPER) {
			newPoints[2] = points[i];
		}
		else if (quadX[i] == LOWER && quadY[i] == UPPER) {
			newPoints[3] = points[i];
		}
	}

	return newPoints[p];
}
