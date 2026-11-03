#include "pch.h" 
#include "CppUnitTest.h"

void Sort(int** R, const int rowCount, const int colCount);
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab71
{
    TEST_CLASS(UnitTestLab71)
    {
    public:

        TEST_METHOD(TestMethod_Calc)
        {
            const int rows = 2;
            const int cols = 2;

            int** R = new int* [rows];
            for (int i = 0; i < rows; i++)
                R[i] = new int[cols];

            R[0][0] = -10; R[0][1] = 5;
            R[1][0] = -3;  R[1][1] = 8;

            int S = 0, k = 0;
            Calc(R, rows, cols, S, k);

            Assert::AreEqual(10, S);
            Assert::AreEqual(3, k);
            Assert::AreEqual(-10, R[0][0]); // Елемент із парними індексами та <=0 НЕ модифікувався
            Assert::AreEqual(0, R[0][1]);   // Інші обнулися

            for (int i = 0; i < rows; i++) delete[] R[i];
            delete[] R;
        }

        TEST_METHOD(TestMethod_Sort)
        {
            const int rows = 2;
            const int cols = 3;

            int** R = new int* [rows];
            for (int i = 0; i < rows; i++)
                R[i] = new int[cols];

            R[0][0] = 5; R[0][1] = 2; R[0][2] = 10;
            R[1][0] = 9; R[1][1] = 2; R[1][2] = 10;

            Sort(R, rows, cols);

            Assert::AreEqual(9, R[0][0]);
            Assert::AreEqual(5, R[1][0]);

            for (int i = 0; i < rows; i++) delete[] R[i];
            delete[] R;
        }
    };
}