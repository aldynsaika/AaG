#include <iostream>
#include <iomanip>
#include <vector>

template<typename T>
class Matrix {

public:
    Matrix() : rows(0), cols(0) { // ����������� ������ �������
    }

    Matrix(std::size_t rows, std::size_t cols) : cols(cols), rows(rows) { // ����������� ������� �������� ��������
        data.resize(rows);
        for (std::size_t i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }

    Matrix(const std::vector<std::vector<T>>& v) { // ����������� ������� �� ������� ��������
        data = v;
        rows = v.size();
        if (rows != 0) {
            cols = v[0].size();
        }
        else {
            cols = 0;
        }
    }

    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols), data(other.data) { // ����������� �����������
    }

    Matrix<T>& operator=(const Matrix<T>& other) { // �������� ������������
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        return *this;
    }

    T& operator()(size_t i, size_t j) { // ������ � �������� (i, j)
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const { // ������ � �������� (i, j) ��� ����������� �������
        return data[i][j];
    }

    size_t get_rows() const { // ��������� ���������� �����
        return rows;
    }

    size_t get_cols() const { // ��������� ���������� ��������
        return cols;
    }

    bool operator==(const Matrix<T>& other) const { // ��������� ������
        return (rows == other.rows && cols == other.cols && data == other.data);
    }

    bool operator!=(const Matrix<T>& other) const { // ��������� ������
        if (rows == other.rows && cols == other.cols && data == other.data) return false;
        else return true;
    }

    Matrix<T> operator*(const T& x) const { // ��������� ������� �� �������
        Matrix<T> result(rows, cols);;
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < rows; ++j) {
                result.data[i][j] = data[i][j] * x;
            }
        }
        return result;
    }

    Matrix<T> operator+(const Matrix<T>& other) const { // �������� ������
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Size error");
        }
        Matrix<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const { // ��������� ������
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Size error");
        }
        Matrix<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-() const { // ��������� �������
        Matrix<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * (-1);
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const { // ��������� ������
        if (cols != other.rows) {
            throw std::runtime_error("Size error");
        }
        Matrix<T> result(rows, other.cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < other.cols; ++j) {
                for (std::size_t k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> transpose() const { // ���������������� �������
        Matrix<T> result(cols, rows);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    Matrix<T> submatrix(size_t row, size_t col, size_t rows, size_t cols) const { // ��������� ����������, ������� � ������� (row, col) � ��������� (rows, cols)
        Matrix<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; i++) {
            for (std::size_t j = 0; j < cols; j++) {
                result.data[i][j] = data[i + row][j + col];
            }
        }

        return result;
    }

    static Matrix<T> eye(size_t n) { // �������� ��������� �������
        Matrix<T> ed(n, n);
        for (std::size_t i = 0; i < n; i++) {
            ed.data[i][i] = 1;
        }
        return ed;
    }

    static Matrix<T> zeros(size_t rows, size_t cols) { // �������� ������� �������
        return Matrix<T>(rows, cols);
    }

    Matrix<T> horizontal_concatenate(const Matrix<T>& other) const { // ������������ ������ �� �����������
        Matrix<T> result(rows, cols + other.cols);
        for (std::size_t i = 0; i < rows; i++) {
            for (std::size_t j = 0; j < cols + other.cols; j++) {
                if (j < cols) {
                    result.data[i][j] = data[i][j];
                }
                else {
                    result.data[i][j] = other.data[i][j - cols];
                }
            }
        }
        return result;
    }

    Matrix<T> vertical_concatenate(const Matrix<T>& other) const { // ������������ ������ �� ���������
        Matrix<T> result(rows + other.rows, cols);
        for (std::size_t i = 0; i < rows + other.rows; i++) {
            for (std::size_t j = 0; j < cols; j++) {
                if (i < rows) {
                    result.data[i][j] = data[i][j];
                }
                else {
                    result.data[i][j] = other.data[i - rows][j];
                }
            }
        }
        return result;
    }
    template <typename Tstream>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<Tstream>& m);

private:
    size_t rows;                      // ���������� �����
    size_t cols;                      // ���������� ��������
    std::vector<std::vector<T>> data; // ������ �������
};

template <typename Tstream>
std::ostream& operator<<(std::ostream& out, const Matrix<Tstream>& m) {
    const int MAX_NUM_DIGITS = 5;
    out << std::endl;
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            out << std::setw(MAX_NUM_DIGITS) << m(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}

 