#include <iostream>

using namespace std;

bool compare(int a, int b) {
    if (a < b) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string a, b;
    int i, j;
    cout << "Hello World!" << endl;
    cout << "input number one: " << endl;
    getline(cin, a);
    cout << "input number two: " << endl;
    getline(cin, b);
    i = stoi(a);
    j = stoi(b);
    if (compare(i, j)) {
        cout << a << " less than " << b << endl;
    }
    else {
        cout << a << " greater than " << b << endl;
    }

    return 0;
}
