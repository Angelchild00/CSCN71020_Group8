#include <stdio.h>
#include <stdbool.h>

#include "rectangleSolver.h"

// Project 1 - Leanne Ryan Luis

// implementation of the rectangleSolver library

#define POINTS	4

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

// working on this
void sortPoints(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, int* x4, int* y4) {
	//given
	// 3,3  4,5  5,3  2,5  
	//should recieve
	// 3,3  5,3  4,5  2,5

	int tx1 = &x1; int tx2 = &x2; int tx3 = &x3; int tx4 = &x4;
	int ty1 = &y1; int ty2 = &y2; int ty3 = &y3; int ty4 = &y4;

	// find center point for x's any y's by adding them together then dividing by 4
	float sumX = (tx1 + tx2 + tx3 + tx4);
	float centerX = (sumX / POINTS);

	float sumY = (ty1 + ty2 + ty3 + ty4);
	float centerY = (sumY / POINTS);

	
	// if x > centerX then it is in quadrant 2 or 3 (assign as outer value) 2
	// if x < centerX then it is in quadrant 1 or 4 (assign as inner value) 1
		if 

	// if y > centerY then it is in quadrant 3 or 4 (assign as upper value) 2
	// if y < centerY then it is in quadrant 1 or 2 (assign as lower value) 1

	//	p4 = upper && inner,			p3 = upper && outer
	//
	//  p1 = lower && inner,			p2 = lower && outer

	

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

