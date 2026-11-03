// Lab_7_1.cpp
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 29 (Ітераційний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** R, const int rowCount, const int colCount);
void Sort(int** R, const int rowCount, const int colCount);
void Change(int** R, const int row1, const int row2, const int colCount);
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -8;
    int High = 42;
    int rowCount = 8;
    int colCount = 7;

    // Виправлено: виділення пам'яті під масив вказівників int*
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    // 1. Формування та виведення початкової матриці
    Create(R, rowCount, colCount, Low, High);
    cout << "Initial matrix R:";
    Print(R, rowCount, colCount);

    // 2. Впорядкування рядків матриці та виведення
    Sort(R, rowCount, colCount);
    cout << "Sorted matrix R:";
    Print(R, rowCount, colCount);

    // 3. Обчислення S, k та заміна елементів нулями
    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);

    // Виведення результатів
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // 4. Виведення модифікованої матриці
    cout << "Modified matrix R:";
    Print(R, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            R[i][j] = Low + rand() % (High - Low + 1); // Виправлено формулу
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << R[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** R, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = R[row1][j];
        R[row1][j] = R[row2][j];
        R[row2][j] = tmp;
    }
}

void Sort(int** R, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++) // Виправлено умови циклів
    {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
        {
            if ((R[i1][0] < R[i1 + 1][0])
                ||
                (R[i1][0] == R[i1 + 1][0] && R[i1][1] < R[i1 + 1][1])
                ||
                (R[i1][0] == R[i1 + 1][0] && R[i1][1] == R[i1 + 1][1] && R[i1][2] > R[i1 + 1][2]))
            {
                Change(R, i1, i1 + 1, colCount);
            }
        }
    }
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (R[i][j] > 0 || !(i % 2 == 0 && j % 2 == 0))
            {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
        }
    }
}