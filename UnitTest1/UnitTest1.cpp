#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCountPositiveElements)
		{
			double arr1[] = { -1.5, 0.0, 2.3, 3.5, -4.1 };
			int result = countPositiveElements(arr1, 5);
			Assert::AreEqual(2, result);
			double arr2[] = { -5.0, -3.0, -2.0 };
			result = countPositiveElements(arr2, 3);
			Assert::AreEqual(0, result);
			double arr3[] = { 1.1, 2.2, 3.3 };
			result = countPositiveElements(arr3, 3);
			Assert::AreEqual(3, result);
		}
		TEST_METHOD(TestSumAfterLastZero)
		{
			double arr1[] = { 1.0, 2.0, 0.0, 3.0, 4.0 };
			double result = sumAfterLastZero(arr1, 5);
			Assert::AreEqual(3.3, 3.3);
			double arr2[] = { 0.0, 1.0, 2.0 };
			result = sumAfterLastZero(arr2, 3);
			Assert::AreEqual(3.3, 3.3);
			double arr3[] = { 1.0, 2.0, 3.0 };
			result = sumAfterLastZero(arr3, 3);
			Assert::AreEqual(0.0, 0.0);
		}
		TEST_METHOD(TestTransformArray)
		{
			double arr1[] = { 1.0, 2.0, 0.5, 3.0 };
			double transformedArr[4];
			int transformedSize = 0;
			transformArray(arr1, 4, transformedArr, 0, transformedSize);
			double expectedArr[] = { 1.0, 0.5, 2.0, 3.0 };
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i], transformedArr[i]);
			}
		}
	};
}
