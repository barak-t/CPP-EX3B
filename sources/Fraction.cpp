#include <iostream>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

#include "Fraction.hpp"

namespace ariel {

    Fraction::Fraction(int num, int divider) : a(num), b(divider) {
        if(b == 0) {
            throw std::invalid_argument("Value incorrect, denominator can't be zero.");
        }
        this->minimized();
    }
    Fraction::Fraction(): a(0), b(1){}

    Fraction::Fraction(float frac) {
        this->b = 1000;
        this->a = static_cast<int>(round(frac * 1000.0));
        this->minimized();
    }

    void Fraction::minimized() {
        int gcd = __gcd(this->a, this->b);
        this->a = this->a / gcd;
        this->b = this->b / gcd;
    }

    void Fraction::checkOverflow(long num) const {
        if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min()) {
            throw overflow_error("Int Overflow");
        }
    }
    void Fraction::checkOverflow(long num1, long num2) const {
        checkOverflow(num1);
        checkOverflow(num2);
    }

    int Fraction::getNumerator() {
        return this->a;
    }
    int Fraction::getDenominator() {
        return this->b;
    }

    float Fraction::value() const {
        return (float)this->a / this->b;
    }
    // +
    Fraction Fraction::operator+(const Fraction& other) const {
        long long a = ((long)this->a * other.b) + (this->b * other.a);
        double b = (long)this->b * other.b;
        this->checkOverflow(a,b);
        return Fraction(a, b);
    }
    Fraction operator+(const Fraction& fraction, float num) {
        return fraction + Fraction(num);
    }
    Fraction operator+(float num, const Fraction& fraction) {
        return fraction + Fraction(num);
    }
    // ++
    Fraction& Fraction::operator++() { //prefix
        checkOverflow((long)this->a + this->b);
        this->a += this->b;
        return *this;
    }
    Fraction Fraction::operator++(int num) { //postfix
        Fraction tmp(this->a, this->b);
        ++(*this);
        return tmp;
    }

    // -
    Fraction Fraction::operator-(const Fraction& other) const {
        long a = (long)(this->a * other.b) - (this->b * other.a);
        long b = (long)this->b * other.b;
        this->checkOverflow(a,b);
        return Fraction(a, b);
    }
    Fraction operator-(const Fraction& fraction, float num) {
        return fraction - Fraction(num);
    }
    Fraction operator-(float num, const Fraction& fraction) {
        return Fraction(num) - fraction;
    }

    // --
    Fraction& Fraction::operator--() { //prefix
        checkOverflow((long)this->a - this->b);
        this->a -= this->b;
        return *this;
    }
    Fraction Fraction::operator--(int num) { //postfix
        Fraction tmp(this->a, this->b);
        --(*this);
        return tmp;
    }

    // *
    Fraction Fraction::operator*(const Fraction& other) const {
        long a = (long)this->a * other.a;
        long b = (long)this->b * other.b;
        checkOverflow(a, b);
        return Fraction(a, b);
    }
    Fraction operator*(const Fraction& fraction, float num) {
        return fraction * Fraction(num);
    }
    Fraction operator*(float num, const Fraction& fraction) {
        return fraction * num;
    }

    // /
    Fraction Fraction::operator/(const Fraction& other) const {
        if(other.a == 0) {
            throw std::runtime_error("Can't divide with zero");
        }
        long a = (long)this->a * other.b;
        long b = (long)this->b * other.a;
        checkOverflow(a, b);
        return Fraction(a, b);
    }
    Fraction operator/(const Fraction& fraction, float num) {
        return fraction / Fraction(num);
    }
    Fraction operator/(float num, const Fraction& fraction) {
        return Fraction(num) / fraction;
    }


    // >
    bool Fraction::operator>(Fraction const other) const {
        return this->value() > other.value();
    }
    bool operator>(Fraction const &fraction, float num) {
        return fraction.value() > num;
    }
    bool operator>(float num, const Fraction other) {
        return num > other.value();
    }

    // >=
    bool Fraction::operator>=(Fraction other) const {
        return this->value() >= other.value();;
    }
    bool Fraction::operator>=(float num) const {
        return this->value() >= num;
    }
    bool operator>=(float num, Fraction const &other) {
        return num >= other.value();
    }

    // <
    bool Fraction::operator<(Fraction const other) const {
        return this->value() < other.value();;
    }
    bool operator<(Fraction const &fraction, float num) {
        return fraction.value() < num;
    }
    bool operator<(float num, Fraction const other) {
        return num < other.value();
    }

    // <=
    bool Fraction::operator<=(Fraction const other) const {
        return this->value() <= other.value();;
    }
    bool Fraction::operator<=(float num) const {
        return this->value() <= num;
    }
    bool operator<=(float num, Fraction const &other) {
        return num <= other.value();
    }

    // ==
    bool Fraction::operator==(Fraction const &fraction) const {
        return fraction.value() == this->value();
    }
    bool Fraction::operator==(float num) const {
        return this->value() == num;
    }
    bool operator==(float num, Fraction const &fraction) {
        return fraction == num;
    }


    // COUT
    std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
        if(fraction.b < 0) {
            return output << fraction.a * -1 << "/" << fraction.b * -1;
        }
        return output << fraction.a << "/" << fraction.b;
    }

    // CIN
    std::istream& operator>> (std::istream& input , Fraction& fraction) {

        int a, b;

        input >> a;
        input >> b;

        if (input.fail() || b == 0) {
            throw std::runtime_error("Bad input.");
        }

        fraction = Fraction(a, b);
        return input;
    }
}