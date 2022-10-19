#include <iostream>

using namespace std;

int main() {
    int input;
    cout << "Input an integer" << endl; // get user input
    cin >> input;
    if (input % 2 == 0) cout << "The number is even" << endl; // use modulus to see if it is even or odd
    else cout << "The number is odd" << endl;
    return 0;
}
