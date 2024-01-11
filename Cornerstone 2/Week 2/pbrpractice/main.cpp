#include <iostream>

using namespace std;
void pbr(int &a, int &b);


int main() {
    int a, b;
    cout << "input a and b separated with space" << endl;
    cin >> a >> b;
    while (b >= 0) {
        pbr(a, b);
        cout << "a = " << a << ", b = " << b << endl;
    }
    return 0;
}

void pbr(int &a, int &b) {
    int temp_a = a;
    int temp_b = b;
    a = a - temp_b;
    b = b - temp_a;
}