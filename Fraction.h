#ifndef SAVEME_FRACTION_H
#define SAVEME_FRACTION_H

#include <iostream>
#include <utility>
using namespace std;


class Fraction {
private:
    int numerator, denominator, ID = -1;
    double real;

    class MyException : public std::exception {
    private:
        std::string m_error;

    public:
        explicit MyException(std::string error) : m_error(std::move(error)) {}

        const char* what() const noexcept override {
            return m_error.c_str();
        }


    };

public:
    void standard_view();
    double get_real_form() const;
    int get_ID();
    Fraction();
    Fraction(const int&, const int&);
    Fraction(const Fraction&);

    int get_num() const;
    int get_denom() const;
    void set_num(const int&);
    void set_denom(const int&);

    void count_real();

    Fraction operator+(const Fraction&);
    Fraction& operator+=(const Fraction&);
    Fraction operator+(const int&);
    Fraction& operator+=(const int&);

    Fraction operator-(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction operator-(const int&);
    Fraction& operator-=(const int&);

    Fraction operator*(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction operator*(const int&);
    Fraction& operator*=(const int&);

    Fraction operator/(const Fraction&);
    Fraction& operator/=(const Fraction&);
    Fraction operator/(const int&);
    Fraction& operator/=(const int&);

    Fraction& operator=(const Fraction&);
    Fraction& operator-();
    bool operator==(const Fraction&);
    bool operator != (const Fraction&);
    bool operator > (const Fraction&);
    bool operator>=(const Fraction&);
    bool operator < (const Fraction&);
    bool operator<=(const Fraction&);
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator!() const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction&);
    friend std::istream& operator>>(std::istream& in, Fraction& fr);
};

int is_number(std::string& str);

#endif 