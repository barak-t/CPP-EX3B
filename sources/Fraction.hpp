#include <iostream>

namespace ariel {

    class Fraction {

    private:
        int a, b;
        float value() const;
        void minimized();
        void checkOverflow(long) const;
        void checkOverflow(long, long) const;


    public:
        Fraction(int num, int divider);
        Fraction(float frac);
        Fraction();
        int getDenominator();
        int getNumerator();

        // +
        Fraction operator+(const Fraction& other) const;
        friend Fraction operator+(const Fraction& fraction, float num);
        friend Fraction operator+(float num, const Fraction& fraction);

        // -
        Fraction operator-(const Fraction& other) const;
        friend Fraction operator-(const Fraction& fraction, float num);
        friend Fraction operator-(float num, const Fraction& fraction);

        // *
        Fraction operator*(const Fraction& other) const;
        friend Fraction operator*(const Fraction& fraction, float num);
        friend Fraction operator*(float num, const Fraction& fraction);

        // /
        Fraction operator/(const Fraction& other) const;
        friend Fraction operator/(const Fraction& fraction, float num);
        friend Fraction operator/(float num, const Fraction& fraction);

        //++
        Fraction& operator++(); //prefix
        Fraction operator++(int num); //postfix

        //--
        Fraction& operator--(); //prefix
        Fraction operator--(int num); //postfix


        // >
        bool operator>(Fraction other) const;
        friend bool operator>(Fraction const &fraction, float num);
        friend bool operator>(float num, Fraction other);

        // >=
        bool operator>=(Fraction other) const;
        bool operator>=(float num) const;
        friend bool operator>=(float num, Fraction const &other);

        //<
        bool operator<(Fraction other) const;
        friend bool operator<(Fraction const &fraction, float num);
        friend bool operator<(float num, Fraction other);

        //<=
        bool operator<=(Fraction other) const;
        bool operator<=(float num) const;
        friend bool operator<=(float num, Fraction const &other);

        //==
        bool operator==(Fraction const &fraction) const;
        bool operator==(float num) const;
        friend bool operator==(float num, Fraction const &fraction);


        //cout
        friend std::ostream& operator<< (std::ostream& output, const Fraction& fraction);

        //cin
        friend std::istream& operator>> (std::istream& input , Fraction& fraction);
    };
}