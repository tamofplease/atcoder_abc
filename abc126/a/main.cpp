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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s[k - 1] = tolower(s[k - 1]);
    cout << s << endl;
    return 0;
}
