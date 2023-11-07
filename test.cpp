#include <iostream>

struct Complex 
{
    double re, im;
    double abs() const 
    { return sqrt(re * re + im * im); }
};

void f(const Complex& z)
{
    cout << z.abs();
}// OK!

// ����������� �����
// 1) �� �������� ������ ���� �������
// 2) �������� ����� const � ����� ���������

struct Complex {
    double re, im;
    double abs() const {
        re = re;
        return sqrt(re * re + im * im);
    }
};

struct Complex {
    double re, im;
    double abs() const {
        if (0 == 1) re = 0;
        return sqrt(re * re + im * im);
    }
};

int main() { 
  return 0;
}
