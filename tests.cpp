#include "HammingCode.hpp" 
#include "time.h"

int main() {
    // ��������� ������� � ���������� ����������
    srand(time(0));
    Matrix <Fp<3>> A(4, 4); 
    for (size_t i = 0; i < A.get_rows(); ++i) {
        for (size_t j = 0; j < A.get_cols(); ++j) {
            A(i, j) = rand();
        }
    }
    // ������� ������� �
    std::cout << A << std::endl;
    
    // ������� ������ ������ Fp
    Fp<3> a = 8;
    Fp<3> b = 1;

    // ����� �
    std::cout << "a = ";
    std::cout << a << std::endl;

    // ����� b
    std::cout << "b = ";
    std::cout << b << std::endl;

    // ����� ������� � � b
    std::cout << "a / b = ";
    std::cout << a / b << std::endl;

    // ����� ����� � � b
    std::cout << "a + b = ";
    std::cout << a + b << std::endl;

    // ����� �������� � � b
    std::cout << "a - b = ";
    std::cout << a - b << std::endl;

    // ����� ��������� �
    std::cout << "-a = ";
    std::cout << -a << std::endl;

    std::cout << '\n';

    // ������� ������ ������ HammingCode
    HammingCode<5> hammingCode(3); // p=5, m=3

    // �������� ������� H
    Matrix<Fp<5>> matrixH = hammingCode.get_H();

    // ������� ������� H
    std::cout << "Matrix H:" << std::endl;
    std::cout << matrixH;

    // �������� ������� G
    Matrix<Fp<5>> matrixG = hammingCode.get_G();

    // ������� ������� G
    std::cout << "Matrix G:" << std::endl;
    std::cout << matrixG;

    return 0;
}