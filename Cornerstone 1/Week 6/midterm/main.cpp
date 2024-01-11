//Name: Zhenming (Mark) Yang
//Date: 10/25/2022
//Project: Midterm (calculate the torque of a rotating disk)
//Input: mass, radius, angular acceleration
//Output: torque

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double moment(double r, double m);  //define the functions
double Torque(double r, double m, double ac);

int main() {
    double r, m, ac, I, T; //define the variables
    int time;
    cout << "How many calculations of Torque do you need: " << endl;
    cin >> time;
    for (int i = 0; i < time; i++) {  //a loop that allows the user to do the calculation multiple times
        string input;
        cout << "Input the Radius of the disk " << i + 1 << ": " << endl; //take the input of radius, mass, and acceleration
        cin >> r;
        if (0.093 >  r || r > 0.207) throw invalid_argument("Invalid radius, please input 0.093 <=  r <= 0.207");  //error check
        cout << "Input the Mass of the disk " << i + 1 << ": " << endl;
        cin >> m;
        if (0.088 >=  m || m > 11) throw invalid_argument("Invalid mass, please input 0.088 <   m <= 11");   //error check
        cout << "Input the Angular Acceleration of the disk (rad/s^2) " << i + 1 << ": " <<  endl;
        cin >> ac;
        T = Torque(r, m, ac); //calculate torque
        cout << fixed << setprecision(4) << "The Torque of disk " << i + 1 << " is: " << T << endl;  //output torque and set decimal points
    }
    return 0;
}

double moment(double r, double m) {  //function that calculate moment of inertia
    return 0.5 * m * pow(r, 2);
}

double Torque(double r, double m, double ac) {   //function that calculate Torque
    double I;
    I = moment(r, m);  //calculate the moment of inertia inside the Torque function
    return I * ac;
}