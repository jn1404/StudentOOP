#include <iostream>
#include <istream>
#include <iomanip> // for setprecision in test_complex
#include <cmath> // for the abs() function
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    return ((abs(c1.get_real() - c2.get_real()) < 0.0001) && 
        (abs(c1.get_imag() - c2.get_imag())) < 0.0001); 
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << c.real << c.imag;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

Complex::Complex(double real, double imag) : 
    real(real), imag(imag) {
}

Complex::operator bool() const {
    return ((real != 0) || (imag != 0));
}

Complex& Complex::operator++() {
    real++;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    real++;
    return temp;
}

Complex& Complex::operator--() {
    real--;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    real--;
    return temp;
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum = {c1.get_real() + c2.get_real(), c1.get_imag()
     + c2.get_imag()};
    return sum;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex sub = {c1.get_real() - c2.get_real(), c1.get_imag()
     - c2.get_imag()};
    return sub;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    Complex mul = {real * i, imag * i};
    return mul;
}
