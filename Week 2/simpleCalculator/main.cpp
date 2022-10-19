// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Calculator
// Input: num1, num2, op
// Output: output
// Date: 9/29/2022

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    bool check = true;
    char op;
    double num1, num2, output;
    cout << "Input the first number" << endl;
    cin >> num1;
    cout << "Input the second number" << endl;
    cin >> num2;
    cout << "Input the operator (+,-,*,/)" << endl;
    cin >> op;
    switch (op) {
        case '+':
            output = num1 + num2;
            break;
        case '-':
            output = num1 - num2;
            break;
        case '*':
            output = num1 * num2;
            break;
        case '/':
            output = num1 / num2;
            break;
        default:
            cout << "Invalid Operator" << endl;
            check = false;
    }

    if (check == true) cout << num1 << " " << op << " " << num2 << " = " << output << endl;
}
