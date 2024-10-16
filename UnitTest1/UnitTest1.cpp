#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_2_it/lab_7_2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestFindMaxOfMins)
        {
            const int rows = 3;
            const int cols = 4;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++)
                matrix[i] = new int[cols];

            // Ініціалізація тестового випадку
            matrix[0][0] = 3; matrix[0][1] = 7; matrix[0][2] = 1; matrix[0][3] = 5; // Min = 1
            matrix[1][0] = 6; matrix[1][1] = 2; matrix[1][2] = 9; matrix[1][3] = 4; // Min = 2
            matrix[2][0] = 8; matrix[2][1] = 10; matrix[2][2] = 3; matrix[2][3] = 11; // Min = 3

            // Виклик функції безпосередньо
            int maxOfMins = MaxMin(matrix, rows, cols); // Використовуйте існуючу функцію MaxMin

            // Перевірка, що результат правильний
            Assert::AreEqual(3, maxOfMins); // Найбільше з мінімальних значень - 3

            // Звільнення пам'яті
            for (int i = 0; i < rows; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

	};
}
