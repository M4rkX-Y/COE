#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double foot, inch;
    cout << "Enter length in feet: " << endl;
    cin >> foot;
    inch = 12.0 * foot;
    cout << fixed << setprecision(2);
    cout << "The length is " << inch << " inch(es)" << endl;
    return 0;
}
