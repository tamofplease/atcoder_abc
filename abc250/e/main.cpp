// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> a_n, b_n;
    unordered_set<int> a_s, b_s;
    for (int& ref : a) {
        cin >> ref;
        a_s.insert(ref);
        a_n.push_back(a_s.size());
    }
    for (int& ref : b) {
        cin >> ref;
        b_s.insert(ref);
        b_n.push_back(b_s.size());
    }
    vector<bool> isValid(n + 1, false);
    a_s = {}, b_s = {};
    unordered_set<int> common;
    int a_iter = 0, b_iter = 0;
    while (a_iter < n && b_iter < n) {
        if (a_n[a_iter] != b_n[b_iter]) {
            a_n[a_iter] < b_n[b_iter] ? a_iter++ : b_iter++;
            continue;
        }
        int a_val = a[a_iter], b_val = b[b_iter];
        int tgt_num = a_n[a_iter];
        if (a_val == b_val) {
            common.insert(a_val);
            isValid[tgt_num] = common.size() == tgt_num;
            a_iter++, b_iter++;
            continue;
        }
        if (a_s.count(b_val)) {
            a_s.erase(b_val);
            common.insert(b_val);
        } else if (!common.count(b_val)) {
            b_s.insert(b_val);
        }
        if (b_s.count(a_val)) {
            b_s.erase(a_val);
            common.insert(a_val);
        } else if (!common.count(a_val)) {
            a_s.insert(a_val);
        }
        isValid[tgt_num] = common.size() == tgt_num;
        a_iter++, b_iter++;
    }
    /// count and memo the number of unique element in a and b;
    // e.g: a: [1,2,3,4,5] => a_c: {1,2,3,4,5}
    //      b: [1,2,2,4,3] => b_c: {1,2,2,3,4}
    // check each match and is element is true or not:
    // e.g.: {1,1}=> ture, {2,2} => true, {3,3} => false, {4,4} => false
    /// 1. check a_c[x_i] and b_c[x_i]
    /// false=> No;
    /// true =>

    int q;
    cin >> q;
    vector<string> ans;
    rep(i, q) {
        int x, y;
        cin >> x >> y, x--, y--;
        if (a_n[x] != b_n[y]) {
            ans.push_back("No");
            continue;
        }
        ans.push_back(isValid[a_n[x]] ? "Yes" : "No");
    }

    // rep(i, n) { cout << i << " " << isValid[i] << endl; }
    // rep(i, n) { cout << a_n[i] << " " << b_n[i] << endl; }

    for (const string& an : ans) cout << an << endl;
    return 0;
}
