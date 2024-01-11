#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    int day_l[31], hi_20_l[31], lo_20_l[31], hi_21_l[31], lo_21_l[31];
    double avg_20[31], avg_21[31];
    int i = 0, high = 0, low = 0, avg = 0;
    ifstream myfile("Jan_temp_hi_lo.txt");
    ofstream fout("result.txt");
    while (myfile >> day_l[i] >> hi_20_l[i] >> lo_20_l[i] >> hi_21_l[i] >> lo_21_l[i]) {
        i++;
    }

    cout << "Dataframe:" << endl;
    cout << "Day   High 2020   Low 2020   Avg 2020   High 2021   Low 2021   Avg 2021"
         << endl;
    fout << "Dataframe:" << endl;
    fout << "Day   High 2020   Low 2020   Avg 2020   High 2021   Low 2021   Avg 2021"
         << endl;
    for (int j = 0; j < 31; j++) {
        avg_20[j] = (hi_20_l[j] + lo_20_l[j]) / 2;
        avg_21[j] = (hi_21_l[j] + lo_21_l[j]) / 2;
        if (hi_21_l[j] > hi_20_l[j]) {
            high++;
        }
        if (lo_21_l[j] > lo_20_l[j]) {
            low++;
        }
        if (avg_21[j] > avg_20[j]) {
            avg++;
        }
        cout << fixed << setprecision(2) << setw(2) << day_l[j] << "       " << hi_20_l[j] << "          " << lo_20_l[j] << "       " << avg_20[j] << "         " <<  hi_21_l[j] << "         "
             << lo_21_l[j] << "       " << avg_21[j] <<endl;
        fout << fixed << setprecision(2) << setw(2) << day_l[j] << "       " << hi_20_l[j] << "          " << lo_20_l[j] << "       " << avg_20[j] << "         " <<  hi_21_l[j] << "         "
             << lo_21_l[j] << "       " << avg_21[j] <<endl;
    }
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Days 2021 high hotter than 2020 high: " << high << " (" << high*100/31 << "%)" << endl;
    cout << "Days 2021 low hotter than 2020 low: " << low << " (" << low*100/31 << "%)" << endl;
    cout << "Days 2021 average hotter than 2020 average: " << avg << " (" << avg*100/31 << "%)" << endl;
    fout << "-----------------------------------------------------------------------" << endl;
    fout << "Days 2021 high hotter than 2020 high: " << high << " (" << high*100/31 << "%)" << endl;
    fout << "Days 2021 low hotter than 2020 low: " << low << " (" << low*100/31 << "%)" << endl;
    fout << "Days 2021 average hotter than 2020 average: " << avg << " (" << avg*100/31 << "%)" << endl;
    return 0;
}
