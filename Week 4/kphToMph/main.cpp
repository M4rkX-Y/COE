// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Output a table that convert kph to mph
// Input: start, stop, increment
// Output: a lot of Ps, best n
// Date: 10/4/2022

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double start, stop, increment, kph, mph;
    cout << "What do you want to start at in kph?" << endl;
    cin >> start;
    cout << "What do you want to stop at in kph?" << endl;
    cin >> stop;
    cout << "What do you want the increment to be?" << endl;
    cin >> increment;
    kph = start;
    while (kph <= stop) {
        mph = kph * 0.6214;
        cout << "kph: " << kph << "\t" << "mph: " << mph << endl;
        kph += increment;
    }
    return 0;
}
