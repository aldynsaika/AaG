#include <iostream>
#include <iomanip>
#include <vector>
#include "Matrix.hpp"


int main() {
    // Создание матрицы 3x3 с заданными значениями
    std::vector<std::vector<int>> data1 = { {1, 2, 3},
                                           {4, 5, 6},
                                           {7, 8, 9} };
    Matrix<int> matrix1(data1);

    // Создание матрицы 3x3 с заданными значениями
    std::vector<std::vector<int>> data2 = { {1, 2, 3},
                                           {4, 5, 6},
                                           {7, 8, 9} };
    Matrix<int> matrix2(data2);

    // Вывод матриц на экран
    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1;

    std::cout << "\nMatrix 2:" << std::endl;
    std::cout << matrix2;

    // Число строк
    std::cout << "\nMatrix1 rows:";
    std::cout << matrix1.get_rows();

    // Число столбцов
    std::cout << "\nMatrix1 cols:";
    std::cout << matrix1.get_cols();

    // Сравнение матриц
    if (matrix1 == matrix2) std::cout << "\nMatrix 1 = Matrix 2" << std::endl;
    else std::cout << "\nMatrix 1 != Matrix 2" << std::endl;

    // Сложение матриц
    Matrix<int> sum = matrix1 + matrix2;
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    std::cout << sum;

    // Вычитание матриц
    Matrix<int> sub = matrix1 - matrix2;
    std::cout << "\nMatrix 1 - Matrix 2:" << std::endl;
    std::cout << sub;

    // Умножение матриц
    Matrix<int> mul = matrix1 * matrix2;
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    std::cout << mul;

    // Отрицание матриц
    std::cout << "\n-Matrix 1:" << std::endl;
    std::cout << -matrix1;

    // Транспонирование матрицы
    Matrix<int> tr = matrix1.transpose();
    std::cout << "\nTransposition Matrix 1:" << std::endl;
    std::cout << tr;

    // Конкатенация матриц по горизонтали
    Matrix<int> hor = matrix1.horizontal_concatenate(matrix2);
    std::cout << "\nConcatenate Matrix 1 and Matrix 2 horizontally:" << std::endl;
    std::cout << hor;

    // Конкатенация матриц по вертикали
    Matrix<int> ver = matrix1.vertical_concatenate(matrix2);
    std::cout << "\nConcatenate Matrix 1 and Matrix 2 vertically:" << std::endl;
    std::cout << ver;    

    return 0;
}