#pragma once
//Maybe we can use .h in the header files so when we include our .h files in the .c file, we don't need to include these again.
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef struct corners {
	int x;
	int y;
} CORNERS, PTCORNERS; //called this corners because "points" was taken in the define. 

void GetInput(CORNERS* points);
int ValidateInput(CORNERS points);

//Structure of function,return true or false for a rectangle.
//No need of this function.
//bool CheckAngleOfRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

//Googled and found formula of Dot Product to check if two lines are  
bool CheckRightAngle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

// Functions to calculate perimeter of the shape of 4 points(x1,y1) (x2,y2),(x3,y3) (x4,y4) whether it's rectangle or not.
double PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
// Functions to calculate area of the shape if it's rectangle, cause there will check if it's rectangle first,so just need 3 pionts.
double AreaOfRectangle(int x1, int y1, int x2, int y2, int x3, int y3);

// Functions to calculate length of two point of (x1,y1) (x2,y2)
double LengthOfTwoPoints(int x1, int x2, int y1, int y2);
//// utils library for rectangle functions
//
bool analyzeRectangle(CORNERS* points);

CORNERS sortPoints(CORNERS* points);
//
//bool checkIsRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
//
//int PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
//
//float AreaOfRectangle(int length, int width);
//
