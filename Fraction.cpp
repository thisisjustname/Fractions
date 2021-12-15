#include "Fraction.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

int identifier(1);

int is_number(std::string& str) {
    int num = 0, iterator = 1;
    for (char i : str)
        if (!isdigit(i))
            return 0;
        else {
            num += (i - '0') * pow(10, str.length() - iterator);
            iterator++;
        }

    return num;
}

int gcd(int a,int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void Fraction::standard_view() {
    int min = std::min(abs(numerator), abs(denominator));
    for (int i = 2; i <= min; ++i)
        while (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
        }
}

int Fraction::get_ID() {
    return ID;
}

Fraction::Fraction(int num, int denom) {
    try {
        if (denom == 0)
            //throw "Denominator can't be equal to zero";
            throw MyException("Denominator can't be equal to zero");
        if (num == 0) {
            num = 0;
            denom = 0;
        }
        if (denom < 0) {
            num *= -1;
            denom *= -1;
        }
        numerator = num;
        denominator = denom;

        real = (double)numerator / denominator;
        standard_view();

    }
    catch (MyException& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }

    if (this->ID == -1) {
        ID = identifier;
        identifier += 1;
    }
}

Fraction Fraction::operator-() {
    numerator *= -1;
    return *this;
}

Fraction& Fraction::operator=(const Fraction& fr) {
    numerator = fr.numerator;
    denominator = fr.denominator;

    return *this;
}

Fraction Fraction::operator+(const Fraction& fr) {
    int nod = lcm(denominator, fr.denominator);

    return { numerator * (nod / denominator) + fr.numerator * (nod / fr.denominator), nod };
}

Fraction& Fraction::operator+=(const Fraction& fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator * (nod / denominator) + fr.numerator * (nod / fr.denominator);
    denominator = nod;
    count_real();
    return *this;
}

Fraction Fraction::operator+(const int& num) {
    Fraction fr(num, 1);
    int nod = lcm(denominator, fr.denominator);

    return { numerator * (nod / denominator) + fr.numerator * (nod / fr.denominator), nod };
}

Fraction& Fraction::operator+=(const int& num) {
    Fraction fr(num, 1);

    int nod = lcm(denominator, fr.denominator);
    numerator = numerator * (nod / denominator) + fr.numerator * (nod / fr.denominator);
    denominator = nod;
    count_real();
    return *this;
}

Fraction Fraction::operator-(const Fraction& fr) {
    int nod = lcm(denominator, fr.denominator);

    return { numerator * (nod / denominator) - fr.numerator * (nod / fr.denominator), nod };
}

Fraction& Fraction::operator-=(const Fraction& fr) {
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator * (nod / denominator) - fr.numerator * (nod / fr.denominator);
    denominator = nod;
    count_real();
    return *this;
}

Fraction Fraction::operator-(const int& num) {
    Fraction fr(num, 1);
    int nod = lcm(denominator, fr.denominator);

    return { numerator * (nod / denominator) - fr.numerator * (nod / fr.denominator), nod };
}

Fraction& Fraction::operator-=(const int& num) {
    Fraction fr(num, 1);
    int nod = lcm(denominator, fr.denominator);
    numerator = numerator * (nod / denominator) - fr.numerator * (nod / fr.denominator);
    denominator = nod;
    count_real();
    return *this;
}

Fraction Fraction::operator*(const Fraction& fr) {
    if (fr.numerator == 0 || numerator == 0)
        return { 0, 1 };
    else
        return { numerator * fr.numerator, fr.denominator * denominator };
}

Fraction& Fraction::operator*=(const Fraction& fr) {
    if (fr.numerator == 0 || numerator == 0)
        numerator = 0;
    else {
        numerator *= fr.numerator;
        denominator *= fr.denominator;
    }
    count_real();
    return *this;
}

Fraction Fraction::operator*(const int& num) {
    Fraction fr(num, 1);
    if (fr.numerator == 0 || numerator == 0)
        return { 0, 1 };
    else
        return { numerator * fr.numerator, fr.denominator * denominator };
}

Fraction& Fraction::operator*=(const int& num) {
    Fraction fr(num, 1);
    if (fr.numerator == 0 || numerator == 0) {
        numerator = 0;
        fr.numerator = 0;
    }
    else {
        numerator *= fr.numerator;
        denominator *= fr.denominator;
    }
    count_real();
    return *this;
}

Fraction Fraction::operator/(const Fraction& fr) {
    try {
        if (fr.numerator == 0)
            throw MyException("Division by zero");
        else
            return this->operator*(fr.operator!());
    }

    catch (MyException& exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

Fraction& Fraction::operator/=(const Fraction& fr) {
    try {
        if (fr.numerator == 0)
            throw MyException("Division by zero");
        else
            return this->operator*=(fr.operator!());
    }

    catch (MyException& exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

Fraction Fraction::operator/(const int& num) {
    Fraction fr(num, 1);
    try {
        if (fr.numerator == 0)
            throw MyException("Division by zero");
        else
            return this->operator*(fr.operator!());
    }

    catch (MyException& exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

Fraction& Fraction::operator/=(const int& num) {
    Fraction fr(num, 1);
    try {
        if (fr.numerator == 0)
            throw MyException("Division by zero");
        else
            return this->operator*=(fr.operator!());
    }

    catch (MyException& exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

bool Fraction::operator==(const Fraction& fr) {
    if (denominator == fr.denominator && numerator == fr.numerator)
        return true;
    else
        return false;
}

bool Fraction::operator!=(const Fraction& fr) {
    return !this->operator==(fr);
}

bool Fraction::operator>(const Fraction& fr) {
    int inc = lcm(denominator, fr.denominator);

    if (numerator * inc / denominator > fr.numerator * inc / fr.denominator)
        return true;
    else
        return false;
}

bool Fraction::operator>=(const Fraction& fr) {
    if (this->operator==(fr) || this->operator>(fr))
        return true;
    else
        return false;
}

bool Fraction::operator<(const Fraction& fr) {
    return !this->operator>(fr);
}

bool Fraction::operator<=(const Fraction& fr) {
    if (this->operator==(fr) || this->operator<(fr))
        return true;
    else
        return false;
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    standard_view();
    count_real();
    return *this;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    standard_view();
    count_real();
    return *this;
}

Fraction Fraction::operator!() const {
    try {
        if (numerator == 0)
            throw MyException("Division by zero");

        return { denominator, numerator };
    }

    catch (MyException& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
    }
    return { numerator, denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& fr) {
    if (fr.denominator == 1)
        out << fr.numerator;
    else
        out << fr.numerator << "/" << fr.denominator;

    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fr) {
    std::string str;
    in >> str;
    int index = str.find("/"), num, denom;
    try {
        if (index == -1) {
            if (is_number(str) == -1)
                throw Fraction::MyException("Invalid_argument");
            else
                num = is_number(str);
            denom = 1;
        }
        else {
            std::string temp1 = str.substr(0, index),
                    temp2 = str.substr(index + 1, str.length() - index - 1);

            if (is_number(temp1) == -1 || is_number(temp2) == -1)
                throw "invalid_argument";
            else {
                num = stoi(str.substr(0, index));
                denom = stoi(str.substr(index + 1, str.length() - index - 1));
            }
        }
    }

    catch (Fraction::MyException& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        exit(EXIT_FAILURE);
    }

    fr = Fraction(num, denom);
    return in;
}

double Fraction::get_real_form() const {
    return real;
}

Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
    real = 1;
}

int Fraction::get_num() const {
    return numerator;
}

int Fraction::get_denom() const {
    return denominator;
}

void Fraction::count_real() {
    real = static_cast<double>(numerator) / denominator;
}

void Fraction::set_num(const int &num) {
    numerator = num;
}

void Fraction::set_denom(const int &num) {
    denominator = num;
}