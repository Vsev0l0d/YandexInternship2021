#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K, level;
    cin >> N >> M;
    int size = N*M;
    level = N - 2;

    string grid[N];
    getline(cin, grid[0]);
    for (int i = 0; i < N; i++) getline(cin, grid[i]);

    cin >> K;
    for (int i = 0; i < K; i++) {
        string name;
        int count;
        char symbol;
        cin >> name >> count >> symbol;

        while (count--){
            replace(grid[level].begin(), grid[level].end(), ' ', symbol);
            level--;
        }
    }

    for (int i = 0; i < N; i++) cout << grid[i] << endl;
    return 0;
}