// Name: Zhenming (Mark) Yang
// Section: 2
// Problem: Write a report from a file of information about suture
// Input: SUTURES.txt
// Output: suturesReport.txt
// Date: 10/11/2022

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string fb, batch;
    double t, p, dt, tper, pper, dtper;
    double total = 0, tcou = 0, pcou = 0, dtcou = 0, reject = 0;
    ifstream myfile("SUTURES.txt");
    ofstream report("suturesReport.txt");
    if (myfile.is_open()) {
        while (myfile >> batch >> t >> p >> dt) {
            if (t >= 170 || t <= 150) tcou++;
            if (p >= 70 || p <= 60) pcou++;
            if (dt >= 2.5 || dt <= 2) dtcou++;
            if (dt >= 2.5 || dt <= 2 || p >= 70 || p <= 60 || t >= 170 || t <= 150) reject++; fb = fb + batch + "\t";
            total++;
        }
    }
    else cout << "Unable to open file";
    tper = tcou / total;
    pper = pcou / total;
    dtper = dtcou / total;
    report << "Total number of product: " << total << endl;
    report << "Total number of reject: " << reject << endl;
    report << "Temperature rejected percentage: " << tper << "\nPressure rejected percentage: " << pper << "\nDwell time rejected percentage: " << dtper << endl;
    report << "Rejected due to temperature: " << tcou << "\nRejected due to pressure: " << pcou << "\nRejected due to dwell time: " << dtcou << endl;
    report << "All failed batches: " << fb;
    myfile.close();
    report.close();
    return 0;
}
