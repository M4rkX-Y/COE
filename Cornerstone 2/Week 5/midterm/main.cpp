#include <iostream>
#include <fstream>

using namespace std;
int main() {
    double raw_data[20], fixed_data[20];    // declare arrays
    int count = 0, change = 0;
    ifstream fin("sensor_data.txt");     // declare input file
    while (fin >> raw_data[count]) {       // input data from file to 1d array
        count++;
    }
    for (int i = 0; i < count; i++) {
        double n;
        if (raw_data[i] < 0) {        // correct the data and count how many changes
            n = 0;
            change++;
        }
        else if (raw_data[i] > 600) {
            n = 600;
            change++;
        }
        else {
            n = raw_data[i];
        }
        fixed_data[i] = n;
    }
    for (int i = 0; i < count; i++) {        // output the fixed array and the number of elements that was changed
        cout << fixed_data[i] << endl;
    }
    cout << "The number of signal values that were corrected is " << change<< endl;
    return 0;
}
