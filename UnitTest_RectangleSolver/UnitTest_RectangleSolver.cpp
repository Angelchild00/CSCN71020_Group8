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
	};
}
