#include <iostream>
#include <iomanip>

using namespace std;

float diam(float p);

int main() {
    float d, r;
    cout << "Enter the radius: " << endl;
    cin >> r;
    d = diam(r);
    cout <<  "The diameter is " << setprecision(3) << fixed << showpoint << d << endl;
    return 0;
}

float diam(float radius) {
    float diameter;
    diameter = 2 * radius;
    return diameter;
}