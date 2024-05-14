#pragma once
#include <iostream>


template<int p>
class Fp {
public:
    Fp(int x = 0) : value(x% p) { // �����������
        if (x < 0)
            value += p;
    };

    int val() const {  // ���������� �������� �������� ����
        return value;
    }; 

    Fp<p>& operator=(int x) {  // �������� ������������ �� ������ �����
        value = x % p;
        if (x < 0)
            value += p;
        return *this;
    }; 

    Fp<p> operator+(const Fp<p>& other) const {  // �������� ��������
        return (value + other.value) % p;
    }; 

    Fp<p> operator-(const Fp<p>& other) const {  // �������� ���������
        if (value - other.value < 0)
            return (value - other.value) % p + p;
        else
            return (value - other.value) % p;
    }; 
    Fp<p> operator*(const Fp<p>& other) const {  // �������� ���������
        return (value * other.value) % p;
    }; 

    Fp<p> operator/(const Fp<p>& other) const {  // �������� �������
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

    Fp<p> operator-() const {  // �������� ����� �����
        return p - value;
    };

    Fp<p>& operator+=(const Fp<p>& other) {  // �������� += (�������� � �������������)
        *this = *this + other;
        return *this;
    }; 

    Fp<p>& operator-=(const Fp<p>& other) {  // �������� -= (��������� � �������������)
        *this = *this - other;
        return *this;
    }; 

    Fp<p>& operator*=(const Fp<p>& other) {  // �������� *= (��������� � �������������)
        *this = *this * other;
        return *this;
    }; 

    Fp<p>& operator/=(const Fp<p>& other) {  // �������� /= (������� � �������������)
        *this = *this / other;
        return *this;
    }; 

    bool operator==(const Fp<p>& other) const {  // �������� ��������� �� ���������
        return value == other.value;
    }; 
    bool operator!=(const Fp<p>& other) const {  // �������� ��������� �� �����������
        return !(value == other.value);
    }; 

    // ����� ��������
    template <int Tstream>
    friend std::ostream& operator<<(std::ostream& out, const Fp<Tstream>& el);
private:
    int value; // �������� �������� ����
};

// ����� ��������
template <int Tstream>
std::ostream& operator<<(std::ostream& out, const Fp<Tstream>& el) {
    out << el.val();
    return out;
}