#pragma once
#include <iostream>


template<int p>
class Fp {
public:
    Fp(int x = 0) : value(x% p) { // Конструктор
        if (x < 0)
            value += p;
    };

    int val() const {  // Возвращает значение элемента поля
        return value;
    }; 

    Fp<p>& operator=(int x) {  // Операция присваивания от целого числа
        value = x % p;
        if (x < 0)
            value += p;
        return *this;
    }; 

    Fp<p> operator+(const Fp<p>& other) const {  // Операция сложения
        return (value + other.value) % p;
    }; 

    Fp<p> operator-(const Fp<p>& other) const {  // Операция вычитания
        if (value - other.value < 0)
            return (value - other.value) % p + p;
        else
            return (value - other.value) % p;
    }; 
    Fp<p> operator*(const Fp<p>& other) const {  // Операция умножения
        return (value * other.value) % p;
    }; 

    Fp<p> operator/(const Fp<p>& other) const {  // Операция деления
        Fp<p> reverse = 0;
        int n = other.value;
        for (int i = 0; i < p; i++) {
            if ((n * i)%p == 1) {
                reverse = i;
                break;
            }
        }
        return *this * reverse;
    }; 

    Fp<p> operator-() const {  // Операция смены знака
        return p - value;
    };

    Fp<p>& operator+=(const Fp<p>& other) {  // Операция += (сложение с присваиванием)
        *this = *this + other;
        return *this;
    }; 

    Fp<p>& operator-=(const Fp<p>& other) {  // Операция -= (вычитание с присваиванием)
        *this = *this - other;
        return *this;
    }; 

    Fp<p>& operator*=(const Fp<p>& other) {  // Операция *= (умножение с присваиванием)
        *this = *this * other;
        return *this;
    }; 

    Fp<p>& operator/=(const Fp<p>& other) {  // Операция /= (деление с присваиванием)
        *this = *this / other;
        return *this;
    }; 

    bool operator==(const Fp<p>& other) const {  // Операция сравнения на равенство
        return value == other.value;
    }; 
    bool operator!=(const Fp<p>& other) const {  // Операция сравнения на неравенство
        return !(value == other.value);
    }; 

    // Вывод элемента
    template <int Tstream>
    friend std::ostream& operator<<(std::ostream& out, const Fp<Tstream>& el);
private:
    int value; // Значение элемента поля
};

// Вывод элемента
template <int Tstream>
std::ostream& operator<<(std::ostream& out, const Fp<Tstream>& el) {
    out << el.val();
    return out;
}