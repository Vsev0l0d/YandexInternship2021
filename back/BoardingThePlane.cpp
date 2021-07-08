#include <iostream>
#include <list>
using namespace std;

char letter[7] = {'A', 'B', 'C', '_', 'D', 'E', 'F'};

int main() {
    int n, m;
    cin >> n;
    string seating[n];
    for (int i = 0; i < n; i++) cin >> seating[i];

    cin >> m;
    for (int i = 0; i < m; i++){
        int num, column = 1;
        string side, position;
        cin >> num >> side >> position;
        if (side[0] == 'l') column *= -1;
        if (position[0] == 'w') column *= 3;

        list<int> seats;
        for (int j = 0; j < n; j++){
            if (seating[j][3 + column] == '.'){
                if (num > 1){
                    switch(3 + column){
                        case 0:
                            if (seating[j][1] == '.'){
                                if (num == 2) seats = {j, 0, 1};
                                else if (seating[j][2] == '.') seats = {j, 0, 1, 2};
                            }
                            break;
                        case 2:
                            if (seating[j][1] == '.'){
                                if (num == 2) seats = {j, 1, 2};
                                else if (seating[j][0] == '.') seats = {j, 0, 1, 2};
                            }
                            break;
                        case 4:
                            if (seating[j][5] == '.'){
                                if (num == 2) seats = {j, 4, 5};
                                else if (seating[j][6] == '.') seats = {j, 4, 5, 6};
                            }
                            break;
                        case 6:
                            if (seating[j][5] == '.'){
                                if (num == 2) seats = {j, 5, 6};
                                else if (seating[j][4] == '.') seats = {j, 4, 5, 6};
                            }
                            break;
                    }
                } else {
                    seats = {j, 3 + column};
                }
            }
            if (seats.size() > 0) break;
        }
        if (seats.size() == 0) cout << "Cannot fulfill passengers requirements" << endl;
        else {
            int row = seats.front();
            seats.pop_front();
            cout << "Passengers can take seats:";
            for (int s : seats){
                cout << " " << row + 1 << letter[s];
                seating[row][s] = 'X';
            }
            cout << endl;
            for (int j = 0; j < n; j++) cout << seating[j] << endl;
            for (int s : seats) seating[row][s] = '#';
        }
    }
    return 0;
}