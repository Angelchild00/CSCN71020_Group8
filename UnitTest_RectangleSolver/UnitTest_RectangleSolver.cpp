#include "pch.h"
#include "CppUnitTest.h"


typedef struct{
	int x;
	int y;
} CORNERS; 

extern "C" char* analyzeRectangle(CORNERS points[]);
extern "C" double PerimeterFrom4Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
extern "C" int ValidateInput(CORNERS points);
extern "C" double AreaOfRectangle(int x1, int y1, int x2, int y2, int x3, int y3);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangleSolver
{
	TEST_CLASS(UnitTestRectangleSolver)
	{
	public:
		
		TEST_METHOD(Test_ValidateInput)
		{
			CORNERS p = {1, 2};
			Assert::AreEqual(1, ValidateInput(p)); p.x = -1;
			Assert::AreEqual(0, ValidateInput(p)); p.y = -2;
			Assert::AreEqual(0, ValidateInput(p));
		}
		TEST_METHOD(Test_Perimeter1) {
			//Test case 1: Square with side length 1 
		double result = PerimeterFrom4Points(0, 0, 0, 1, 1, 1, 1, 0); 
		Assert::AreEqual(4.0, result, 0.0001);
		}
		TEST_METHOD(Test_Perimeter2) {
			// Test case 2: Rectangle with length 2 and width 1 
		double result = PerimeterFrom4Points(0, 0, 0, 1, 2, 1, 2, 0); 
		Assert::AreEqual(6.0, result, 0.0001);
		}
		TEST_METHOD(Test_Perimeter3) {
			// Test case 3: Irregular quadrilateral 
		double result = PerimeterFrom4Points(0, 0, 3, 0, 3, 4, 0, 4); 
		Assert::AreEqual(14.0, result, 0.0001);
		}
	};
}
