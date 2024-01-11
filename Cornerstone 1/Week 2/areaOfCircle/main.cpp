//name: Zhenming (Mark) Yang
//section: 2
//purpose: Find area and circumference of a circle
//Output: Area and circumference
//Input: Radius
//Constant: Pi = 3.1415926

#include <iostream>
#include <iomanip>
#include <cmath>
#define Pi 3.1415926

using namespace std;

int main() {
    double r, area, circumference;
    cout << "Input the radius of the circle: ";
    cin >> r;
    area = Pi * pow(r,2.0);
    circumference = 2.0 * Pi * r;
    cout << fixed << setprecision(2) << endl;
    cout << setw(40) << "The area of the circle is:" << setw(10) << area << endl;
    cout << setw(40) << "The circumference of the circle is:" << setw(10) << circumference << endl;

    return 0;
}
