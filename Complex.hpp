#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // Overload the << operator to print complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overload the == operator for comparison
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload the != operator for comparison
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
};

#endif // COMPLEX_HPP