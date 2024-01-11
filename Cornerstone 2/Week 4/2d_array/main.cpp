#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Peak {
public:
    int row;
    int col;
    double content;
};

int main() {
    int i = 0, size = 7, pc = 0, g = 0, m_index;
    Peak peak_list[10];
    double data[size + 1][size + 1];
    double max = 0;
    string fname;
    cout << "Input the name for the report file: " << endl;
    cin >> fname;
    ifstream fin("elevations.txt");
    ofstream fout(fname+".txt");
    while (fin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3] >> data[i][4] >> data[i][5] >> data[i][6] >> data[i][7]) {
        i++;
    }
    fout << "The " << fname << " matrix is: " << endl;
    for (int j = 1; j < size + 1; j++) {
        for (int k = 1; k < size + 1; k++) {
            fout << fixed << setprecision(1) << data[j][k] << " ";
            if (data[j][k] > data[j-1][k] && data[j][k] > data[j+1][k] && data[j][k] > data[j][k-1] && data[j][k] > data[j][k+1]) {
                peak_list[g].row = j;
                peak_list[g].col = k;
                peak_list[g].content = data[j][k];
                g++;
                pc++;
            }
        }
        fout << "\n";
    }
    fout << "The grid size is " << size << " by " << size << endl;
    fout << "The " << pc << " peaks in the dataset are: " << endl;
    for (int f = 0; f < pc; f++) {
        Peak peak = peak_list[f];
        fout << "Elevation " << peak.content << " at point " << peak.row << ", " << peak.col << endl;
        if (peak.content > max) {
            max = peak.content;
            m_index = f;
        }
    }
    fout << "The highest peak is at an elevation of " << peak_list[m_index].content << " at " << peak_list[m_index].row << ", " << peak_list[m_index].col << " in the " << fname << " matrix." << endl;
    fout.close();
    return 0;
}
