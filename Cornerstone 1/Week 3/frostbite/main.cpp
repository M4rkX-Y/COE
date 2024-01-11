// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Calculate the frostbit time
// Input: Ta, V
// Output: Frostbite time
// Date: 9/29/2022

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double Twc, Ta, V;
    cout << "Input the air temperature" << endl; // input the air temperature and wind speed
    cin >> Ta;
    cout << "Input the wind speed" << endl;
    cin >> V;
    Twc = 35.74 + 0.6215 * Ta - 35.75 * pow(V, 0.16) + 0.4275 * Ta * pow(V, 0.16);
    cout << "The wind chill index is " << Twc << endl;
    if (Twc < -48.0) cout << "Frostbite time of 5 minutes or less" << endl; // check the Twc and see what frostbite condition we have
    else if (Twc < -19.0 && Twc >= -48.0) cout << "Frostbite time of 30 minutes or less" << endl;
    else if (Twc >= -19.0) cout << "Frostbite not a concern for 30 minutes or less exposure" << endl;
    else cout << "Invalid Inputs" << endl;
    return 0;
}
