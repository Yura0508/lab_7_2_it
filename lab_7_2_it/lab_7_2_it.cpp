// lab_7_2_it.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rows, const int cols, const int Low, const int High);
void Print(int** a, const int rows, const int cols);
int MaxMin(int** a, const int rowCount, const int colCount);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int Low = 1;
    int High = 100;
    int rows, cols;

    cout << "Enter number of rows (k): ";
    cin >> rows;
    cout << "Enter number of columns (n): ";
    cin >> cols;


    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];


    Create(a, rows, cols, Low, High);
    Print(a, rows, cols);



    int maxMin = MaxMin(a, rows, cols);

    cout << "Largest of the minimum elements from each row = " << maxMin << endl;


    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;
    cin.get();
    return 0;
}

// Function to create the matrix with random integers
void Create(int** a, const int rows, const int cols, const int Low, const int High) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Function to print the matrix
void Print(int** a, const int rows, const int cols) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}


int MaxMin(int** a, const int rowCount, const int colCount)
{
    int min, max;
    for (int i = 0; i < rowCount; i++)
    {
        min = a[i][0];
        for (int j = 1; j < colCount; j++)
            if (a[i][j] < min)
                min = a[i][j];
        if (i == 0)
            max = min;
        if (min > max)
            max = min;
    }
    return max;
}
