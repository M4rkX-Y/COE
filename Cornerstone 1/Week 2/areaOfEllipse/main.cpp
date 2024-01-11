// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Calculate the area of an ellipse
// Input: a, b
// Output: A
// Date: 9/23/2022

#include <iostream>
#include <iomanip>
#define Pi 3.1415926

using namespace std;

int main() {
    double a, b, A; // define the variables
    cout << "Input the first semiaxes of the ellipse: " << endl;  // take input from user for both semiaxes
    cin >> a;
    cout << "Input the second semiaxes of the ellipse: " << endl;
    cin >> b;
    A = Pi * a * b;  // calculate the area
    cout << fixed << setprecision(2) << "The area of the ellipse is: " << A << endl; // output the area
    return 0;
}
