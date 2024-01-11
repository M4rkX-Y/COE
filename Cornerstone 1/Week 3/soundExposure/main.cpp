// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Sound Level from pressure of sound
// Input: p
// Output: Sound Level
// Date: 9/29/2022

#include <iostream>
#include <cmath>
#define p0 20 * pow(10, 6)

using namespace std;

int main() {
    float p, L;
    struct {float value; const char *description;} list[] = {
            { 0, "Light leaf rustling" },
            { 30, "Calm library" },
            { 60, "Normal conversation" },
            { 90, "Traffic on a busy roadway at 10m" },
            { 100, "Jackhammer at 1m" },
            { 120, "Possible hearing damage" },
            { 130, "Threshold of pain" },
            { INFINITY, "Something is wrong, please re-enter the value" },
    };
    cout << "Input the pressure of sound (in Pascals)" << endl;
    cin >> p;
    if (p < 0) throw invalid_argument("Invalid input.");
    L = 20 * log10(p / p0);
    for (int i = 0; i < 8; i++) {
        if (L <= list[i].value) {
            cout << list[i - 1].description << endl;
            break;
        }
    }
    return 0;
}
