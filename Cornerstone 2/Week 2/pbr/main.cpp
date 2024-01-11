#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calc_DnV (double &D, double &V, double W, double L, double E, double b, double h);

int main() {
    double D, V, W, L, E, b, h;
    cout << "Input \n"
            "W = Weight of load in lbs\n"
            "L = Length of beam in ft\n"
            "E = Modulus of Elasticity in (lb/ft^2)\n"
            "b = Beam's base dimension in ft\n"
            "h = Beam's height dimension in ft\n"
            "Separate with spaces:" << endl;
    cin >> W >> L >> E >> b >> h;
    calc_DnV(D, V, W, L, E, b, h);
    cout << fixed << setprecision(4) << "Beam Deflection = " << D << "\nShear Stress = " << V << endl;
    return 0;
}


double calc_DnV (double &D, double &V, double W, double L, double E, double b, double h) {
    D = (4*W*pow(W,3))/(E*b*pow(h, 3));
    V = W/(b*h);
}