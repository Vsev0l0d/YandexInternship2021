#include <iostream>
#include <list>
#include <set>
using namespace std;

int main() {
    int N, M, count = 0;
    int64_t x;
    cin >> N >> M;
    list <int64_t> slabs;
    for (int i = 0; i < N; i++){
        cin >> x;
        while (!slabs.empty() && slabs.back() <= x) slabs.pop_back();
        slabs.push_back(x);
    }

    auto iter = slabs.begin();
    auto iter_next = slabs.begin();
    iter_next++;
    while(iter_next != slabs.end()){
        *iter = (*iter) - (*iter_next);
        iter++; iter_next++;
    }
    slabs.sort();

    multiset<int64_t> volunteers;
    for (int i = 0; i < M; i++){
        cin >> x;
        volunteers.insert(x);
    }

    iter = slabs.begin();
    while(iter != slabs.end()){
        auto volunteer = volunteers.upper_bound(*iter);
        if (volunteer != volunteers.begin() && !volunteers.empty()){
            volunteer--;
            volunteers.erase(volunteer);
            count++;
        }
        iter++;
    }

    cout << count;
    return 0;
}
