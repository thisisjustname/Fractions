#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction fr(6,2);
    Fraction fr1(7, 2);
    cout << fr << endl;
    cout << fr1 << endl;
    ++fr1;
    cout << fr1 << endl;
    cin >> fr1;
    ++fr1;
    cout << fr1;
    return 0;
}
