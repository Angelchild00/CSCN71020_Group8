#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#define POINTS 4

int side = 0;

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();
		int shapeChoice = printShapeMenu();
		char* result;
		switch (shapeChoice)
		{
		case 1:
			printf("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			getTriangleSides(triangleSides);
			if (doLengthsFormTriangle(triangleSides[0], triangleSides[1], triangleSides[2])) {
				const char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
				const char* angles = getAngleFromSides(triangleSides[0], triangleSides[1], triangleSides[2]);
				printf("%s\n", result);
				printf("The angles are: %s\n", angles);
			}
			else {
				printf("The sides do not form a triangle.\n");
			}
			break;
		case 2:
			printf_s("Rectangle selected\n");
			CORNERS points[POINTS];
			GetInput(points);			//TODO: prevent user from inputting the same point twice
			analyzeRectangle(points);	// this does return a bool value if we ever need it
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
}
