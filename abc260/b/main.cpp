// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}
void show(const set<int>& a) {
    for (int aa : a) {
        cout << aa << endl;
    }
}
void showv(const vector<pair<int, int>>& a) {
    for (auto aa : a) {
        cout << aa.first << " " << aa.second << "  ";
    }
    cout << endl;
}

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> ma, en, both;
    vector<int> a(n);
    Rep(i, n) {
        cin >> a[i - 1];
        ma.emplace_back(a[i - 1], i);
    }
    Rep(i, n) {
        int b;
        cin >> b;
        en.emplace_back(b, i);
        both.emplace_back(a[i - 1] + b, i);

    }

    sort(ALL(ma), comp);
    sort(ALL(en), comp);
    sort(ALL(both), comp);
    set<int> ans;
    rep(i, x) {
        ans.insert(ma[i].second);
    }
    int i = 0;
    while (ans.size() < x + y) {
        int id = en[i].second;
        i++;
        ans.insert(id);
    }
    i = 0;
    while (ans.size() < x + y + z) {
        int id = both[i].second;
        i++;
        ans.insert(id);
    }
    show(ans);

    return 0;
}
