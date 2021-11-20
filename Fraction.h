//
// Created by stuar on 19.11.2021.
//

#ifndef SAVEME_FRACTION_H
#define SAVEME_FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
    double real;

    class MyException: public std::exception {
    private:
        std::string m_error;


    public:
        MyException(std::string error) : m_error(error) {}

        const char *what() const noexcept {
            return m_error.c_str();
        }


    };

public:
    void standard_view();
    double real_form();
    Fraction(int num=1, int denom=1);

    Fraction operator+(Fraction fr);
    Fraction& operator+=(Fraction fr);

    Fraction operator-(Fraction fr);
    Fraction& operator-=(Fraction fr);

    Fraction operator*(Fraction fr);
    Fraction& operator*=(Fraction fr);

    Fraction operator/(Fraction fr);
    Fraction& operator/=(Fraction fr);

    Fraction& operator=(Fraction fr);
    Fraction operator-();
    bool operator==(Fraction fr);
    bool operator != (Fraction fr);
    bool operator > (Fraction fr);
    bool operator>=(Fraction fr);
    bool operator < (Fraction fr);
    bool operator<=(Fraction fr);
    void operator++();
    void operator--();
    Fraction operator!();

    friend std::ostream& operator<<(std::ostream &out, Fraction fr);
    friend std::istream& operator>>(std::istream &in, Fraction &fr);
};

int is_number(std::string &str);

#endif //SAVEME_FRACTION_H
