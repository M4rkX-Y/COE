// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Calculate the maximum deflection
// Input: Load weight, Beam length, Beam base, and Beam height, Modulus of Elasticity
// Output: Maximum deflection
// Date: 10/15/2022

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateMD (double lw, double bl, double bb, double bh);

int main(){
    double lw, bl, bb, bh, md; // define variables
    cout << "Input the Load Weight(lb): " << endl; // get user input in lw, bl, bb, and bh
    cin >> lw;
    cout << "Input the Beam Length(ft): " << endl;
    cin >> bl;
    cout << "Input the Beam Base(ft): " << endl;
    cin >> bb;
    cout << "Input the Beam Height(ft): " << endl;
    cin >> bh;
    if (lw < 0 || bl < 0 || bb < 0 || bh < 0) throw invalid_argument("Negative input is not allowed."); // throw error if user input negative numbers
    md = calculateMD(lw, bl, bb, bh); // call the function to calculate md
    cout << fixed << setprecision(3) << "The Maximum Deflection = " << md << endl; // output the result with set decimal places
    return 0;
}

double calculateMD (double lw, double bl, double bb, double bh) {
    double me, md; // define variables
    cout << "Input the Modulus of Elasticity(lb/ft^2): " << endl; // get input for me
    cin >> me;
    md = (4 * lw * pow(bl, 3)) / (me * bb * pow(bh, 3)); // calculate md
    return md;
}