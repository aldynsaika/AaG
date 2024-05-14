#include "HammingCode.hpp" 
#include "time.h"

int main() {
    // Генерация матрицы А случайными значениями
    srand(time(0));
    Matrix <Fp<3>> A(4, 4); 
    for (size_t i = 0; i < A.get_rows(); ++i) {
        for (size_t j = 0; j < A.get_cols(); ++j) {
            A(i, j) = rand();
        }
    }
    // Выводим матрицу А
    std::cout << A << std::endl;
    
    // Создаем объект класса Fp
    Fp<3> a = 8;
    Fp<3> b = 1;

    // Вывод а
    std::cout << "a = ";
    std::cout << a << std::endl;

    // Вывод b
    std::cout << "b = ";
    std::cout << b << std::endl;

    // Вывод деления а и b
    std::cout << "a / b = ";
    std::cout << a / b << std::endl;

    // Вывод суммы а и b
    std::cout << "a + b = ";
    std::cout << a + b << std::endl;

    // Вывод разности а и b
    std::cout << "a - b = ";
    std::cout << a - b << std::endl;

    // Вывод отрицания а
    std::cout << "-a = ";
    std::cout << -a << std::endl;

    std::cout << '\n';

    // Создаем объект класса HammingCode
    HammingCode<5> hammingCode(3); // p=5, m=3

    // Получаем матрицу H
    Matrix<Fp<5>> matrixH = hammingCode.get_H();

    // Выводим матрицу H
    std::cout << "Matrix H:" << std::endl;
    std::cout << matrixH;

    // Получаем матрицу G
    Matrix<Fp<5>> matrixG = hammingCode.get_G();

    // Выводим матрицу G
    std::cout << "Matrix G:" << std::endl;
    std::cout << matrixG;

    return 0;
}
