// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v;
    map<pair<string, int>, int> ma;
    rep(i, n) {
        string s;
        int p;
        cin >> s >> p;
        v.emplace_back(s, p);
        ma[{s, p}] = i + 1;
    }
    sort(ALL(v), comp);
    for (pair<string, int> c : v) {
        cout << ma[c] << endl;
    }

    return 0;
}
