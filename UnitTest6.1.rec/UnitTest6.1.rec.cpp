#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP6.1.rec/LabAP6.1.rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForArrayFunctions
{
    TEST_CLASS(UnitTestForArrayFunctions)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int n = 5;
            int arr[n];
            int Low = 4, High = 10;

            Create(arr, n, Low, High, 0);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(arr[i] >= Low && arr[i] <= High, L"Element out of bounds");
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            const int n = 5;
            int arr[n] = { 15, 21, 27, 45, 75 };
            int count = 0, sum = 0;

            ProcessArray(arr, n, count, sum, 0);

            Assert::AreEqual(5, count, L"Count of elements should match");
            Assert::AreEqual(183, sum, L"Sum of elements should match");

            for (int i = 0; i < n; i++) {
                Assert::AreEqual(0, arr[i], L"Element should be zeroed");
            }
        }

        TEST_METHOD(TestPrint)
        {
            const int n = 5;
            int arr[n] = { 1, 2, 3, 4, 5 };
            Print(arr, n, 0);
        }
    };
}
