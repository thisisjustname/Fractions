#include "Fraction.h"
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

int lcm (int a, int b)  {
    if(std::min(a, b) == 1)
        return std::max(a, b);

    return b == 0 ? a : lcm (b, a % b);
}

void Fraction::standart_wiew() {
    for (int i = 2; i <= std::min(numerator, denominator); ++i)
        if(numerator % i == 0 && denominator % i == 0){
            numerator /= i;
            denominator /= i;
        }
}

Fraction::Fraction(int num, int denum) {
    try{
        if (denum == 0)
            throw "Denominator can't be equal to zero";

        numerator = num;
        denominator = denum;

        real = (double)numerator / denominator;
        standart_wiew();
    }
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}

Fraction Fraction::operator+(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);

    return {numerator*(nod / denominator) + fr.numerator*(nod / fr.denominator), nod};
}

Fraction Fraction::operator-(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);

    return {numerator*(nod / denominator) - fr.numerator*(nod / fr.denominator), nod};
}

bool Fraction::operator==(Fraction fr) {
    if(denominator == fr.denominator && numerator == fr.numerator)
        return true;
    else
        return false;
}

bool Fraction::operator!=(Fraction fr) {
    return !this->operator==(fr);
}

bool Fraction::operator>(Fraction fr) {
    int inc = lcm(denominator, fr.denominator) / denominator;

    if(numerator*inc > fr.numerator*inc)
        return true;
    else
        return false;
}

bool Fraction::operator<(Fraction fr) {
    return !this->operator>(fr);
}

void Fraction::operator++() {
    numerator += denominator;
    standart_wiew();
}

void Fraction::operator--() {
    numerator -= denominator;
    standart_wiew();
}

Fraction Fraction::operator-() {
    numerator *= -1;
}

Fraction Fraction::operator!() {
    return {denominator, numerator};
}

std::ostream& operator<<(std::ostream &out, Fraction fr) {
    out << fr.numerator << "/" << fr.denominator;
    return out;
}

Fraction& Fraction::operator=(Fraction fr) {
    numerator = fr.numerator;
    denominator = fr.denominator;

    return *this;
}

Fraction &Fraction::operator+=(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator*(nod / denominator) + fr.numerator*(nod / fr.denominator);
    denominator = nod;
    return *this;
}

Fraction &Fraction::operator-=(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator*(nod / denominator) - fr.numerator*(nod / fr.denominator);
    denominator = nod;
    return *this;
}

Fraction Fraction::operator*(Fraction fr) {
    return {numerator*fr.numerator, fr.denominator*denominator};
}

Fraction Fraction::operator/(Fraction fr) {
    return this->operator*(fr.operator!());
}

Fraction &Fraction::operator*=(Fraction fr) {
    numerator *= fr.numerator;
    denominator *= fr.denominator;
    return *this;
}

Fraction &Fraction::operator/=(Fraction fr) {
    return this->operator*=(fr.operator!());
}

std::istream &operator>>(std::istream &in, Fraction fr) {
    std::string str;
    in >> str;
    int index = str.find("/");

    fr = Fraction(stoi(str.substr(0, index)),
                  stoi(str.substr(index + 1, str.length() - index - 1)));
    return in;
}
// 12/35