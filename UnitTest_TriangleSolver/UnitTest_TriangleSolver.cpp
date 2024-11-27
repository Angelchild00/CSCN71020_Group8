#include "pch.h"
#include "CppUnitTest.h"

extern "C" const char* analyzeTriangle(int side1, int side2, int side3); 
extern "C" bool doLengthsFormTriangle(int side1, int side2, int side3);
extern "C" const char* getAngleFromSides(int a, int b, int c);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangleSolver
{
	TEST_CLASS(UnitTestTriangleSolver)
	{
	public:
		
		TEST_METHOD(Test_Equilateral)
		{
			const char* result = analyzeTriangle(3, 3, 3);
			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(Test_Isosceles)
		{
			const char* result = analyzeTriangle(3, 3, 2);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(Test_Scalene)
		{
			const char* result = analyzeTriangle(3, 4, 5);
			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Test_NotATriangle)
		{
			const char* result = analyzeTriangle(1, 2, 3);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(Test_AnglesOfRightTriangle)
        {
            const char* angles = getAngleFromSides(3, 4, 5);
            Assert::AreEqual("36.87, 53.13, and 90.00", angles);
        }
		TEST_METHOD(Test_AnglesOfEquilateralTriangle)
		{
			const char* angles = getAngleFromSides(3, 3, 3);
			Assert::AreEqual("60.00, 60.00, and 60.00", angles);
		}

	};
}
