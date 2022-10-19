// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: See if the rope can withstand the tension of a rotating object
// Input: v
// Output: true or false
// Date: 9/29/2022

#include <iostream>
#include <cmath>
#define R 3.0
#define M 2.0

using namespace std;

int main() {
    double V, T;
    cout << "Input the rotation speed of the object (in meters/second)" << endl; // intake the speed of the rotating object
    cin >> V;
    T = (M * V * V) / R;
    if (T <= 60) cout <<"The rope can withstand the tension of the rotating object" << endl; // check if the tension is under the maximum tension of the rope
    else cout <<"The rope can not withstand the tension of the rotating object" << endl;
    return 0;
}
