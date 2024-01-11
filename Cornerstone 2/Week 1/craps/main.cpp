#include <iostream>
#include <cstdlib>

using namespace std;
int dice_roll();
void intro();

int main() {
    int bank = 1000;
    int wager, r1, r2, r_sum;
    srand(time(0));
    intro();
    while (true) {
        while (true) {
            cout << "Input your wager. You have " << bank << " dollars" << endl;
            cin >> wager;
            if (wager <= bank) {
                break;
            }
            else {
                cout << "Insufficient input. Please renter your wager" << endl;
            }
        }
        while (true) {
            r1 = dice_roll();
            r2 = dice_roll();
            r_sum = r1 + r2;
            cout << "You rolled " << r1 << " + " << r2 << " = " << r_sum << endl;
            if (r_sum == 7 || r_sum == 11) {
                bank = bank + wager;
                cout << "You win! Now you have " << bank << " dollars." << endl;
                break;
            }
            if (r_sum == 2 || r_sum == 3 || r_sum == 12) {
                bank = bank - wager;
                cout << "You lost. Now you have " << bank << " dollars." << endl;
                break;
            }
            else {
                while (true) {
                    cout << "You have to roll a(n) " << r_sum << endl;
                    r1 = dice_roll();
                    r2 = dice_roll();
                    cout << "You rolled " << r1 << " + " << r2 << " = " << r1 + r2 << endl;
                    if (r1 + r2 == r_sum) {
                        bank = bank + wager;
                        cout << "You win! Now you have " << bank << " dollars." << endl;
                        break;
                    }
                    if (r1 + r2 == 7) {
                        bank = bank - wager;
                        cout << "You lost. Now you have " << bank << " dollars." << endl;
                        break;
                    }
                }
                break;
            }
        }
        if (bank == 0) {
            cout << "Game Over. You lost all your money." << endl;
            break;
        }
    }
    return 0;
}

int dice_roll() {
    int random = rand() % 6 + 1;
    return random;
}

void intro() {
    cout << "Welcome to Craps" << endl;
}