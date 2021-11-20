#include <iostream>
#include "Fraction.h"
#include <string>

using namespace std;

int main() {
    Fraction fr;
    Fraction fr1(7, 2);
    string str = "125";

    cout << is_number(str) << endl;
    cout << fr << endl;
    cout << fr1 << endl;
    ++fr1;
    cout << fr1 << endl;
    cin >> fr1;
    ++fr1;
    cout << fr1 << endl;
    cout << fr / fr1 << endl;

    cout << fr1.real_form();
    return 0;
}
