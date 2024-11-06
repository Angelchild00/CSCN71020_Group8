#pragma once

// utils library for rectangle functions

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

void sortPoints(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, int* x4, int* y4);

bool checkIsRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

int PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

float AreaOfRectangle(int length, int width);
