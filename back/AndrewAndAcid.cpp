#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    int32_t reservoirs[n];
    for (int i = 0; i < n; i++) {
        cin >> reservoirs[i];
        if (i && reservoirs[i - 1] > reservoirs[i]){
            cout << -1;
            return 0;
        }
    }
    cout << reservoirs[n - 1] - reservoirs[0];
    return 0;
}

