// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Output the best optimal turn ratio for the circuit
// Input: n/a
// Output: a lot of Ps, best n
// Date: 10/4/2022

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double ps, rs = 8, n, vs = 40, r0 = 20, gps = 0, gn = 0;
    for (n = 0.01; n <= 2; n = n + 0.01) {
        ps = rs * pow((n * vs) / (pow(n, 2) * r0 + rs), 2);
        cout << ps << endl;
        if (ps > gps) gn = n; gps = ps;
    }
    cout << "Turn ratio that maximizes the power delivered to the speakers is " << gn << endl;
    return 0;
}
