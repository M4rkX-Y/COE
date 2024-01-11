#include <iostream>
#include <fstream>
using namespace std;


void getNewData(double (&B2A)[20][20], double (&pHA)[20][20]);                //define all void function and use pass by reference to manipulate the data for more efficiency
void getLowHighData(double (&low_pHA)[20][20], double (&high_pHA)[20][20]);
void compareData(double (&pHA)[20][20], double (&low_pHA)[20][20], double (&high_pHA)[20][20]);

int main() {
    double B2A[20][20], pHA[20][20], low_pHA[20][20], high_pHA[20][20];   //define and initialize 2D arrays
    getNewData(B2A, pHA);            //get the new data and separate them into two arrays B2A and pHA, create two new files based on these arrays
    getLowHighData(low_pHA, high_pHA);          //get the low and high pHA data low_pHA and high_pHA
    compareData(pHA, low_pHA, high_pHA);         //compare pHA data with low_pHA and high_pHA, update and report the number of new minimum and maximum, update the low_pHA and high_pHA files
    return 0;
}

void getNewData(double (&B2A)[20][20], double (&pHA)[20][20]) {         //pass by reference the two arrays
    ifstream new_data("NewdataA.txt");       //open data file
    for(int row = 0; row < 20; row++) {            //loop through the rows and columns of the data file
        int B2A_column = 0, pHA_column = 0;         //define column counter for 2D arrays, refresh it every row is finished
        for (int column = 0; column < 40; column++) {
            if (column % 2 == 1){                  //separate the two data by using odd and even columns
                new_data >> B2A[row][B2A_column];           //put the data from the data files into the B2A arrays
                B2A_column++;                       //add one to B2A column counter so the next data add to the correct place
            }
            else {
                new_data >> pHA[row][pHA_column];           //put the data from the data files into the pHA arrays
                pHA_column++;                       //add one to pHA column counter so the next data add to the correct place
            }
        }
    }
    ofstream new_B2A_data("B2A.txt");       //open data file
    ofstream new_pHA_data("pHA.txt");
    for(int row = 0; row < 20; row++) {                 //loop through the rows and columns of the 2D arrays
        for (int column = 0; column < 20; column++) {
            new_pHA_data << pHA[row][column] << "\t";       //put the array into the file
            new_B2A_data << B2A[row][column] << "\t";
        }
        new_pHA_data << endl;
        new_B2A_data << endl;
    }

}

void getLowHighData(double (&low_pHA)[20][20], double (&high_pHA)[20][20]){
    ifstream high_pHA_data("HighpHA-1.txt");        //open data file
    ifstream low_pHA_data("LowpHA.txt");
    for(int row = 0; row < 20; row++) {                 //loop through the rows and columns of the data file
        for (int column = 0; column < 20; column++) {
            low_pHA_data >> low_pHA[row][column];           //put the data from the data files into the 2D arrays
            high_pHA_data >> high_pHA[row][column];
        }
    }
}


void compareData(double (&pHA)[20][20], double (&low_pHA)[20][20], double (&high_pHA)[20][20]){
    int new_low = 0, new_high = 0;              //define the count variables
    for(int row = 0; row < 20; row++) {                 //loop through the rows and columns of the 2D arrays
        for (int column = 0; column < 20; column++) {
            if (low_pHA[row][column] > pHA[row][column]) {          //compare the low_pHA with pHA
                //cout << low_pHA[row][column] << "\t" << pHA[row][column] << endl;
                new_low++;                                    //add one to count variable
                low_pHA[row][column] = pHA[row][column];        //replace data in low_pHA with pHA
            }
            if (high_pHA[row][column] < pHA[row][column]) {         //compare the high_pHA with pHA
                new_high++;                                   //add one to count variable
                high_pHA[row][column] = pHA[row][column];       //replace data in high_pHA with pHA
            }
        }
    }
    cout << "There are " << new_low << " new low values and " << new_high << " new high values found in the new data." << endl;    //report the count
    ofstream new_high_pHA_data("HighpHA-1.txt");        //open data file
    ofstream new_low_pHA_data("LowpHA.txt");
    for(int row = 0; row < 20; row++) {                 //loop through the rows and columns of the 2D arrays
        for (int column = 0; column < 20; column++) {
            new_low_pHA_data << low_pHA[row][column] << "\t";       //update the files
            new_high_pHA_data << high_pHA[row][column] << "\t";
        }
        new_low_pHA_data << endl;
        new_high_pHA_data << endl;
    }
}