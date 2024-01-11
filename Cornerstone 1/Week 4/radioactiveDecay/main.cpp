// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Output a table that shows the radioactive decay of Technetium-99
// Input: n/a
// Output: table with time and A/A0
// Date: 10/4/2022

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double A0, A, t = 0, h = 6;
    cout << "Time\tA/A0" << endl;
    while (t <= 24) {
        A = A0 * pow(exp(1), -t * (log(2) / h));
        cout << t << "\t";
        cout << setprecision(3) << A/A0 << endl;
        t++;
    }
    return 0;
}
