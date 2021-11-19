//
// Created by stuar on 19.11.2021.
//

#ifndef SAVEME_FRACTION_H
#define SAVEME_FRACTION_H

#include <iostream>


class Fraction {
private:
    int numerator, denominator;
    double real;
public:
    void standart_wiew();
    void real_form();
    Fraction(int num, int denum);

    Fraction operator+(Fraction fr);
    Fraction operator-(Fraction fr);
    Fraction operator*(Fraction fr);
    Fraction operator/(Fraction fr);
    Fraction operator-();
    bool operator==(Fraction fr);
    bool operator != (Fraction fr);
    bool operator > (Fraction fr);
    bool operator < (Fraction fr);
    void operator++();
    void operator--();
    Fraction& operator=(Fraction fr);
    Fraction& operator+=(Fraction fr);
    Fraction& operator-=(Fraction fr);
    Fraction& operator*=(Fraction fr);
    Fraction& operator/=(Fraction fr);
    Fraction operator!();
    friend std::ostream& operator<<(std::ostream &out, Fraction fr);
    friend std::istream& operator>>(std::istream &in, Fraction fr);
};


#endif //SAVEME_FRACTION_H
