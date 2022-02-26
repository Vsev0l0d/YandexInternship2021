#include <iostream>
#include <set>
#include <algorithm>
#include <list>
using namespace std;

list<int> get_median_indices(int32_t a, int32_t b, int32_t c){
    list<int> median_indices;
    if (a >= b && a <= c || a <= b && a >= c) median_indices.push_back(0);
    if (b >= a && b <= c || b <= a && b >= c) median_indices.push_back(1);
    if (c >= b && c <= a || c <= b && c >= a) median_indices.push_back(2);
    return median_indices;
}

int main() {
    int32_t arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];

    set<int> median_indices;
    for (int x : get_median_indices(arr[0], arr[1], arr[2]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0] - arr[1], arr[1], arr[2]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0] - arr[2], arr[1], arr[2]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0], arr[1] - arr[0], arr[2]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0], arr[1] - arr[2], arr[2]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0], arr[1], arr[2] - arr[0]))
        median_indices.insert(x);
    for (int x : get_median_indices(arr[0], arr[1], arr[2] - arr[1]))
        median_indices.insert(x);

    for (int i = 0; i < 3; i++)
        cout << (median_indices.find(i) != median_indices.end() ? "YES" : "NO") << endl;
    return 0;
}