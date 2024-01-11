
#include <iostream>
#include <cstdlib>

using namespace std;
void encourager();    // randomly select a encourage message for the end of the game
void board(int Dim, int mark_1[3][3], int mark_2[3][3]);       // function that print the board to the players
bool check_win(int Dim, int mark[3][3]);       //check if the player win or not

int main() {
    bool check = true;    //define variables
    int Dim = 3, co, ro, counter;
    string cont;
    srand(time(0));    //seed random using time
    while (check) {    //loop for if you want to end the game
        counter = 0;             //counter to see if the board is full and the game is tied
        int mark_1[3][3], mark_2[3][3];        //initiate the 2D arrays with false for each player to check where their marks are
        for (int i = 0; i < Dim; i++) {
            for (int j = 0; j < Dim; j++) {
                mark_1[i][j] = false;
                mark_2[i][j] = false;
            }
        }
        cout << "Welcome to Tic-Tac-Toe" << endl;             //start game
        cout << "A game in which two players alternately put Xs and Os in compartments of a figure formed by two vertical lines crossing two horizontal lines and each tries to get a row of three Xs or three Os before the opponent does." << endl << endl;
        while (true) {     //first game starts
            board(Dim, mark_1, mark_2);      //print the board for player 1
            cout << "Player 1 turn:" << endl;
            while (true){     //take player 1 input and check if it is valid or not
                cout << "Input the row where you want to put the mark: (1-3)" << endl;
                cin >> ro;
                cout << "Input the column where you want to put the mark: (1-3)" << endl;
                cin >> co;
                if (mark_1[ro - 1][co - 1] == true || mark_2[ro - 1][co - 1] == true) {
                    cout << "The square is occupied. Please re-enter: " << endl;
                }
                else if (ro > Dim || co > Dim) {
                    cout << "The number input is invalid. Please re-enter: " << endl;
                }
                else {
                    break;
                }
            }
            mark_1[ro - 1][co - 1] = true;   //make the player 1 board true on the block
            if (check_win(Dim, mark_1)) {        //check if player 1 win or not
                cout << endl << "Player 1 win!!!" << endl;
                break;
            }
            counter++;      //plus one block is occupied
            if (counter == Dim * Dim) {     //check if the board is filled. if it is the game is tied
                cout << endl << "Tie!!!" << endl;
                break;
            }
            cout << "\n\n";
            board(Dim, mark_1, mark_2);         //print the board for player 2
            cout << "Player 2 turn:" << endl;
            while (true){      //take player 2 input and check if it is valid or not
                cout << "Input the row where you want to put the mark: (1-3)" << endl;
                cin >> ro;
                cout << "Input the column where you want to put the mark: (1-3)" << endl;
                cin >> co;
                if (mark_1[ro - 1][co - 1] == true || mark_2[ro - 1][co - 1] == true) {
                    cout << "The square is occupied. Please re-enter: " << endl;
                }
                else if (ro > Dim || co > Dim) {
                    cout << "The number input is invalid. Please re-enter: " << endl;
                }
                else {
                    break;
                }
            }
            mark_2[ro - 1][co - 1] = true;    //make the player 2 board true on the block
            if (check_win(Dim, mark_2)) {         //check if player 2 win or not
                cout << endl << "Player 2 win!!!" << endl;
                break;
            }
            counter++;         //plus one block is occupied
            if (counter == Dim * Dim) {    //check if the board is filled. if it is the game is tied
                cout << endl << "Tie!!!" << endl;
                break;
            }
        }
        encourager();   //print encourage message
        while (true) {        //ask if you want to play another game
            cout << "continue? (y/n) " << endl;
            cin >> cont;
            if (cont == "y") {
                break;
            }
            else if ( cont == "n") {
                check = false;
                break;
            }
            else cout << "Invalid Input. Please retry" << endl;
        }
    }
    return 0;
}


bool check_win(int Dim, int mark[3][3]) {
    for (int i = 0; i < Dim; i++) {         //check the columns for win
        int count_x = 0;
        for (int j = 0; j < Dim; j++) {
            if (mark[i][j]) count_x++;
        }
        if (count_x == Dim) return true;
    }

    for (int i = 0; i < Dim; i++) {        //check the rows for win
        int count_y = 0;
        for (int j = 0; j < Dim; j++) {
            if (mark[j][i]) count_y++;
        }
        if (count_y == Dim) return true;
    }

    int count_c = 0;               //check the cross for win
    for (int i = 0; i < Dim; i++) {
        if (mark[i][i]) count_c++;
    }
    if (count_c == Dim) return true;

    if (mark[2][0] && mark[1][1] && mark[0][2]) return true;

    return false;
}

void board(int Dim, int mark_1[3][3], int mark_2[3][3]) {
    cout << "-------------------" << endl;       //print the board. this is the top boarder
    for (int i = 0; i < Dim; i++) {          // fill the board for each row with either empty blocks or filled with x and o
        for (int j = 0; j < Dim; j++) {
            if (mark_1[i][j] == true){
                cout << "|  x  ";
            }
            else if (mark_2[i][j] == true){
                cout << "|  o  ";
            }
            else{
                cout << "|     ";
            }
        }
        cout << "|" << endl << "-------------------" << endl;
    }
}

void encourager() {
    string msg;
    int random = rand() % 6 + 1;         //random number between 1 and 6
    if (random == 1) {
        msg = "You are a lot of fun to know.";
    }
    if (random == 2) {
        msg = "You got this.";
    }
    if (random == 3) {
        msg = "Good luck today! I know you’ll do great.";
    }
    if (random == 4) {
        msg = "Sending major good vibes your way.";
    }
    if (random == 5) {
        msg = "Hope you’re doing awesome!";
    }
    if (random == 6) {
        msg = "Keep on keeping on!";
    }
    cout << "Encouraging words: " << msg << endl;        //print the message
}