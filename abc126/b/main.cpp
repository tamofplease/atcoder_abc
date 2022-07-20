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
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(2, 2));
    if (1 <= a && a <= 12) {
        if (1 <= b && b <= 12) {
            puts("AMBIGUOUS");
            return 0;
        }
        puts("MMYY");
        return 0;
    }
    if (1 <= b && b <= 12) {
        puts("YYMM");
        return 0;
    }
    puts("NA");


    return 0;
}