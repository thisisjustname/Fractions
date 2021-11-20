#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction fr;
    Fraction fr1(7, 2);


    cout << fr << endl;
    cout << fr1 << endl;
    ++fr1;
    cout << fr1 << endl;
    cin >> fr1;
    cout << fr1 << endl;
    cout << fr / fr1 << endl;

    cout << fr1.real_form();
    return 0;
}
