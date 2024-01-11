#include <iostream>
#include <cmath>

using namespace std;
void rand_float(double mean, double variance, double &a, double &b);
double rand(double a, double b);
double calc_mean(double array[], int size);
double calc_variance(double array[], int size, double c_mean);

int main() {
    srand(time(0));
    double mean, variance, c_mean, c_variance, a, b;
    int size;
    cout << "Input the mean: " << endl;
    cin >> mean;
    cout << "Input the variance: " << endl;
    cin >> variance;
    cout << "Input the size of the random array: " << endl;
    cin >> size;
    double array[size];
    rand_float(mean, variance, a, b);
    for (int i = 0; i < size; i++) {
        array[i] = rand(a, b);
    }
    c_mean = calc_mean(array, size);
    c_variance = calc_variance(array, size, c_mean);
    cout << "Calculated mean: " << c_mean << endl;
    cout << "Calculated variance: " << c_variance << endl;
    cout << "Difference between calculated and given mean: " << abs(c_mean-mean) << " (" << (abs(c_mean-mean)/mean)*100 << "%)" << endl;
    cout << "Difference between calculated and given variance: " << abs(c_variance-variance) << " (" << (abs(c_variance-variance)/variance)*100 << "%)" << endl;
    return 0;
}

void rand_float(double mean, double variance, double &a, double &b) {
    a = mean - (pow(12*variance, 0.5))/2;
    b = 2*mean - a;
}

double rand(double a, double b) {
    double random = a + ((double)rand() / RAND_MAX) * (b - a);
    return random;
}

double calc_mean(double array[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + array[i];
    }
    return sum/size;
}

double calc_variance(double array[], int size, double c_mean){
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + pow(array[i] - c_mean, 2);
    }
    return sum/size;
}