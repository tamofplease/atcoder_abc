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
    string s;
    cin >> s;
    map<char, int> ma;
    for (char c : s) {
        ma[c]++;
    }
    for (auto it : ma) {
        if (it.second == 1) {
            cout << it.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
