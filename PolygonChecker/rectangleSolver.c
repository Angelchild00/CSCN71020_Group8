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
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	//sortPoints(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);	

	int perimeter = PerimeterFrom4Points(x1, y1, x2, y2, x3, y3, x4, y4);

	if (CheckRightAngle(x1, y1, x2, y2, x3, y3, x4, y4) == true) {
		float area = AreaOfRectangle(x1,y1,x2,y2,x3,y3);
		char result = ("IsRectangle = True\nPerimeter = %d\nArea = %d", perimeter, area);
		return result;
	}
	char result = ("IsRectangle = False\nPerimeter of shape = %d", perimeter);
	return ;
}

// sorts points given by user to desired format
void sortPoints(CORNERS points[]) {
	//given: 3,3  4,5  5,3  2,5  
	//should recieve: 3,3  5,3  4,5  2,5
	
	int tx1 = points[0].x; int tx2 = points[1].x; int tx3 = points[2].x; int tx4 = points[3].x;
	int arrayX[] = { tx1, tx2, tx3, tx4 };
	int ty1 = points[0].y; int ty2 = points[1].y; int ty3 = points[2].y; int ty4 = points[3].y;
	int arrayY[] = { ty1, ty2, ty3, ty4 };
	// find center point for x's any y's by adding them together then dividing by 4
	float sumX = (tx1 + tx2 + tx3 + tx4);
	float centerX = (sumX / POINTS);
	float sumY = (ty1 + ty2 + ty3 + ty4);
	float centerY = (sumY / POINTS);
	// if x > centerX then it is in quadrant 2 or 3 (assign as outer value) 2
	// if x < centerX then it is in quadrant 1 or 4 (assign as inner value) 1
	for (int i = 0; i < POINTS; i++) {
		if (arrayX[i] > centerX) {
			arrayX[i] = UPPER;
		}
		else {
			arrayX[i] = LOWER;
		}
	}
	// if y > centerY then it is in quadrant 3 or 4 (assign as upper value) 2
	// if y < centerY then it is in quadrant 1 or 2 (assign as lower value) 1
	for (int i = 0; i < POINTS; i++) {
		if (arrayY[i] > centerY) {
			arrayY[i] = UPPER;
		}
		else {
			arrayY[i] = LOWER;
		}
	}
	//	sorting the points using the quadrants
	for (int i = 0; i < POINTS; i++) {
		// p1 = lower && lower
		if ((arrayX[i] = LOWER) && (arrayY[i] = LOWER)) {
			points[i].x = arrayX[i];
			points[i].y = arrayY[i];
		}
		// p2 = upperX && lowerY
		if ((arrayX[i] = UPPER) && (arrayY[i] = LOWER)) {
			points[i].x = arrayX[i];
			points[i].y = arrayY[i];
		}
		// p3 = upper && upper
		if ((arrayX[i] = UPPER) && (arrayY[i] = UPPER)) {
			points[i].x = arrayX[i];
			points[i].y = arrayY[i];
		}
		// p4 = lowerX && upperY
		if ((arrayX[i] = LOWER) && (arrayY[i] = UPPER)) {
			points[i].x = arrayX[i];
			points[i].y = arrayY[i];
		}
	}
}

//bool checkIsRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
//	//check anlges
//	{
//		// if all angles == 90deg
//		return true;
//	}
//
//	return false;
//}

//int PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
//	// find the 4 lengths
//	// perimeter = l1 + l2 + l3 + l4
//}

//float AreaOfRectangle(int length, int width) {
//	// area = length * width
//}

