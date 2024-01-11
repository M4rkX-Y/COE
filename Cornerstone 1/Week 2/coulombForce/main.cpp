// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Calculate the coulomb's force between two objects
// Input: Q1, Q2, r
// Output: F
// Date: 9/23/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#define Pi 3.1415926
#define EPSILON 8.8854 * pow(10, -12)

using namespace std;

int main() {
    double Q1, Q2, r, F;  // define variables
    cout << "Input the charge (in Coulombs) of the first object: " << endl;  // get user input on the two charges and there distance
    cin >> Q1;
    cout << "Input the charge (in Coulombs) of the second object: " << endl;
    cin >> Q2;
    cout << "Input distance (in Meters) between two objects: " << endl;
    cin >> r;
    F = (Q1 * Q2) / (4 * EPSILON * Pi * pow(r, 2));  // calculate the force based on coulomb's law
    cout << fixed << setprecision(5) << "The Force between these two charged objects is " << F << " N" << endl;  // output the force between two objects
    return 0;
}
