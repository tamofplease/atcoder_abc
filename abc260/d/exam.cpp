// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    map<int, vector<int>> ma1;
    map<int, vector<int>> ma2;
    vector<int> v1(100000000, 0);
    vector<int> v2(100000000, 0);
    const clock_t begin_time = clock();
    ma1[1] = v1;
    ma1[2] = ma1[1];
    ma1.erase(1);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    const clock_t begin_time_2 = clock();
    ma2[1] = v2;
    ma2.emplace(2, move(ma2[1]));

    std::cout << float(clock() - begin_time_2) / CLOCKS_PER_SEC << endl;
    return 0;
}
