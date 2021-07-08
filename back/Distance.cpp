#include <iostream>
#include <algorithm>
using namespace std;

int main() { // time limit exceeded in 15 test
    int32_t n, k;
    cin >> n >> k;
    int32_t a[n], sort_a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    copy(a, a + n, sort_a);
    sort(sort_a, sort_a + n);

    for (int32_t x : a) {
        int32_t left = 0, right = n;
        while(left < right){
            int32_t middle = (left + right) >> 1;
            if (sort_a[middle] < x) left = middle + 1;
            else right = middle;
        }
        int32_t index = left, l_step = 1, r_step = 1;
        int64_t sum = 0;
        while (l_step + r_step - 2 < k){
            if (index - l_step >= 0){
                if (index + r_step < n){
                    if (abs(x - sort_a[index - l_step]) < abs(x - sort_a[index + r_step])){
                        sum += abs(x - sort_a[index - l_step]);
                        l_step++;
                    } else {
                        sum += abs(x - sort_a[index + r_step]);
                        r_step++;
                    }
                } else {
                    sum += abs(x - sort_a[index - l_step]);
                    l_step++;
                }
            } else {
                sum += abs(x - sort_a[index + r_step]);
                r_step++;
            }
        }
        cout << sum << " ";
    }
    return 0;
}