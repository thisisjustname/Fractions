#include "Fraction.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

int is_number(std::string &str){
    int num = 0, iterator = 1;
    for (char i : str)
        if(!isdigit(i))
            return 0;
        else{
            num += (i - '0') * pow(10, str.length() - iterator);
            iterator++;
        }

    return num;
}


int lcm (int a, int b)  {
    if(std::min(a, b) == 1)
        return std::max(a, b);

    return b == 0 ? a : lcm (b, a % b);
}

void Fraction::standard_wiew() {
    for (int i = 2; i <= std::min(numerator, denominator); ++i)
        if(numerator % i == 0 && denominator % i == 0){
            numerator /= i;
            denominator /= i;
        }
}

Fraction::Fraction(int num, int denom) {
    try{
        if (denom == 0)
            throw "Denominator can't be equal to zero";
        else if (numerator == 0){
            numerator = 0;
            denominator = 0;
        } else {
            numerator = num;
            denominator = denom;

            real = (double) numerator / denominator;
            standard_wiew();
        }
    }
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
        exit(EXIT_FAILURE);
    }
}

Fraction Fraction::operator-() {
    numerator *= -1;
}

Fraction& Fraction::operator=(Fraction fr) {
    numerator = fr.numerator;
    denominator = fr.denominator;

    return *this;
}

Fraction Fraction::operator+(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);

    return {numerator*(nod / denominator) + fr.numerator*(nod / fr.denominator), nod};
}

Fraction &Fraction::operator+=(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator*(nod / denominator) + fr.numerator*(nod / fr.denominator);
    denominator = nod;
    return *this;
}

Fraction Fraction::operator-(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);

    return {numerator*(nod / denominator) - fr.numerator*(nod / fr.denominator), nod};
}

Fraction &Fraction::operator-=(Fraction fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator*(nod / denominator) - fr.numerator*(nod / fr.denominator);
    denominator = nod;
    return *this;
}

Fraction Fraction::operator*(Fraction fr) {
    if(fr.numerator == 0 || numerator == 0)
        return {0, 1};
    else
        return {numerator*fr.numerator, fr.denominator*denominator};
}

Fraction &Fraction::operator*=(Fraction fr) {
    if(fr.numerator == 0 || numerator == 0){
        numerator = 0;
        fr.numerator = 0;
    }
    else {
        numerator *= fr.numerator;
        denominator *= fr.denominator;
    }
    return *this;
}

Fraction Fraction::operator/(Fraction fr) {
    try{
        if (fr.numerator == 0)
            throw "Division by zero";
        else
            return this->operator*(fr.operator!());
    }

    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
        exit(EXIT_FAILURE);
    }
}

Fraction &Fraction::operator/=(Fraction fr) {
    try{
        if (fr.numerator == 0)
            throw "Division by zero";
        else
            return this->operator*=(fr.operator!());
    }

    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
        exit(EXIT_FAILURE);
    }
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

bool Fraction::operator>=(Fraction fr) {
    if(this->operator==(fr) || this->operator>(fr))
        return true;
    else
        return false;
}

bool Fraction::operator<(Fraction fr) {
    return !this->operator>(fr);
}

bool Fraction::operator<=(Fraction fr) {
    if(this->operator==(fr) || this->operator<(fr))
        return true;
    else
        return false;
}

void Fraction::operator++() {
    numerator += denominator;
    standard_wiew();
}

void Fraction::operator--() {
    numerator -= denominator;
    standard_wiew();
}

Fraction Fraction::operator!() {
    try {
        if (numerator == 0)
            throw "Impossible operation";

        return {denominator, numerator};
    }

    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return {numerator, denominator};
}

std::ostream& operator<<(std::ostream &out, Fraction fr) {
    if(fr.denominator == 1)
        out << fr.numerator;
    else
        out << fr.numerator << "/" << fr.denominator;

    return out;
}

std::istream &operator>>(std::istream &in, Fraction &fr) {
    std::string str;
    in >> str;
    int index = str.find("/"), num, denom;
    try{
        if (index == -1){
            if(!is_number(str))
                throw "invalid_argument";
            else
                num = is_number(str);
            denom = 1;
        } else{
            std::string temp1 = str.substr(0, index), temp2 = str.substr(index + 1,
                                                                         str.length() - index - 1);
            if (!is_number(temp1) || !is_number(temp2))
                throw "invalid_argument";
            else {
                num = stoi(str.substr(0, index));
                denom = stoi(str.substr(index + 1, str.length() - index - 1));
            }
        }
    }

    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
        exit(EXIT_FAILURE);
    }

    fr = Fraction(num, denom);
    return in;
}

double Fraction::real_form() {
    return real;
}

