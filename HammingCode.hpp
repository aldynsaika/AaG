#pragma once
#include "Matrix.hpp"
#include "Fp.hpp"
#include "string"
#include "math.h"

template<int p>
class HammingCode {
public:
    HammingCode(size_t m) : m(m){  // Конструктор
        generate_matrices();
    }; 

    Matrix<Fp<p>> get_H() const {  // Получение матрицы H
        return H;
    }; 

    Matrix<Fp<p>> get_G() const {  // Получение матрицы G
        return G;
    }; 

private:
    // Атрибуты
    size_t n;    // Количество символов в кодовом слове
    size_t k;    // Количество информационных символов
    size_t m;    // Количество проверочных символов
    Matrix<Fp<p>> H; // Проверочная матрица
    Matrix<Fp<p>> G; // Порождающая матрица

    // Дополнительные переменные
    int max_col = (pow(p, m) - 1) / (p - 1) - m;  // Максимальное число столбцов в матрице Н
    

    // Вспомогательные методы
    void generate_matrices() {
        Matrix<Fp<p>> B = fill_A();
        Matrix<Fp<p>> Curr1 = B.horizontal_concatenate(Matrix<Fp<p>>::eye(m));
        H = Curr1;
        Matrix<Fp<p>> Curr2 = Matrix<Fp<p>>::eye(max_col).horizontal_concatenate(-(B.transpose()));
        G = Curr2;
    };

    int check_ed(int* num, int len) {  // Проверка на линейную зависимость с одним из столбцов единичной матрицы
        int count = 0;
        for (int i = 0; i < len; i++) 
            if (num[i] != 0)
                count++;
        if (count == 1 )
            return 0;
        return 1;
    };

    int check_lin(int* num, int len) {
        int count = 0;
        int flag = 1;
        int list_num[p + 1] = { 0 }; 
        for (int i = 0; i < len; i++)
            list_num[num[i]] = 1;
        for (int i = 0; i < p; i++) {
            if (list_num[i] == 1)
                count++;
        }
        for (int i = 2; i < p; i++) {
            if (list_num[i]) {
                flag = 0;
                break;
            }                
        }
        if (count > 1 || flag)
            return 1;
        return 0;
    }

    int* decimalToBaseP(int number, int baseP) {  // Перевод числа из десятичной системы счисления в систему счисления с основанием p
        int* curr = new int[m + 2];
        for (int i = 0; i < m + 2; i++) {
            curr[i] = -1;
        }
        int index = 0;
        while (number > 0) {
            curr[index] = number % baseP;;
            number /= baseP;
            index++;
        }
        int* result = new int[index];
        for (int i = 0; i <= index; i++) {
            result[i] = curr[i];
        }
        return result;
    }

    int super_check(Matrix<Fp<p>> A, int* curr, int column, int len) {
        int count = 0;
        for (int i = column-1; i >= 0; i--) {
            count = 0;
            for (int j = 0; j < len-1; j++) {
                Fp<p> n11 = A(j, i);
                Fp<p> n21 = curr[j];
                Fp<p> n12 = A(j+1, i);
                Fp<p> n22 = curr[j+1];
                if (n11 / n21 == n12 / n22) {
                    count++;
                }                    
            }
            if (count == len - 1)
                return 0;
        }
        return 1;
    }

    Matrix<Fp<p>> fill_A() {  // Заполнение вспомогательной матрицы
        Matrix<Fp<p>> A = Matrix<Fp<p>>::zeros(m, max_col);  // Вспомогательная матрица размера m*max_col
        int colum = 0;
        int max_n = pow(p, m);
        for (int i = 1; i < max_n; i++) {
            if (colum < max_col) {
                int* curr = decimalToBaseP(i, p);
                int len = 0;
                for (int k = 0; k < m + 2; k++) {
                    if (curr[k] != -1)
                        len++;
                    else
                        break;
                }
                if (check_ed(curr, len) & check_lin(curr, len) & super_check(A, curr, colum, len)) {
                    int reminder = i;
                    int index = 0;
                    while (reminder != 0) {
                        Fp<p> number = reminder;
                        A(index, colum) = number;
                        reminder = reminder / p;
                        index++;
                    }
                    colum++;
                }
            }
            else if (colum >= max_col) {
                break;
            }            
        }
        return A;        
    };
};