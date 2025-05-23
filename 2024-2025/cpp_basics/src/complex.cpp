#include <complex>
#include <iostream>

using Complex = std::complex<double>;  // Определяем псевдоним

int main() {
    Complex z1 = 3.0 + 4.0j;  // Complex вместо std::complex<double>
    Complex z2(2.5, -1.5); // конструктор

    std::cout << "z1 = " << z1 << "\n";
    std::cout << "z2 = " << z2 << "\n";
    std::cout << "z1 + z2 = " << z1 + z2 << "\n";

    return 0;
}