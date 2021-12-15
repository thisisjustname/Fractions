#include <iostream>
#include <ctime>
#include "Fraction.h"

using namespace std;

int random_number() {
    int number = rand() % 30 - 10;
    if (number == 0) {
        number = 1;
    }
    return number;
}
void BubbleSort(Fraction* arr){
    bool itstimetostop = false;
    while (!itstimetostop) {
        itstimetostop = true;
        for (int i = 0; i < 9; ++i)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                itstimetostop = false;
            }
    }
}


int main() {
    srand(time(nullptr));
    const int length = 10;
    Fraction arr[length];


    for (auto & i : arr)
        i = Fraction(random_number(), random_number());

    for (const auto & i : arr)
        cout << i << "   ";

    cout << endl;
    BubbleSort(arr);
    for(auto & itt: arr){
        cout << itt << "   ";
    }
    cout << endl;

    return 0;
}