// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;
using mint = modint1000000007;
// using mint = modint998244353;

const int MOD = 1000000007;

template <typename T, int FAC_MAX>
struct Comb {
   private:
    vector<T> fac, ifac;

   public:
    Comb() {
        fac.resize(FAC_MAX, 1);
        ifac.resize(FAC_MAX, 1);
        Rep(i, FAC_MAX - 1) fac[i] = fac[i - 1] * i;
        ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
        rRep(i, FAC_MAX - 2) ifac[i] = ifac[i + 1] * T(i + 1);
    }
    T aPb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1);
        if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
    T pairCombination(int n) {
        if (n % 2 == 1) return T(0);
        return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2));
    }
};
// xagcx
// xacgx
// xgacx
// axgc
// agxc

int main() {
    int n;
    cin >> n;
    const string base = "AGCT";
    vector<string> init = {"AGC", "ACG", "GAC"};
    set<string> invalid = {
        "AGC",
        "ACG",
        "GAC",
    };
    for (const char c : base) {
        for (string i : init) {
            invalid.insert(i + c);
            invalid.insert(c + i);
        }
        string a = "A";
        a.push_back(c);
        a += "GC";
        invalid.insert(a);
        swap(a[1], a[2]);
        invalid.insert(a);
    }
    map<pair<int, string>, mint> memo;
    Rep(i, n) for (const string& in : invalid) memo[{i, in}] = 0;
    auto dfs = [&](auto f, const int idx, const string prev) -> mint {
        if (memo.count({idx, prev})) {
            return memo[{idx, prev}];
        }
        if (idx == n) {
            return memo[{idx, prev}] = 1;
        }
        string cur = prev;
        if (cur.length() == 4) cur.erase(0, 1);
        mint res = 0;
        for (char b : base) {
            cur += b;
            res += f(f, idx + 1, cur);
            cur.pop_back();
        }
        return memo[{idx, prev}] = res;
    };
    mint ans = 0;
    for (char c : base) {
        string s(1, c);
        ans += dfs(dfs, 1, s);
    }
    cout << ans.val() << endl;
    return 0;
}
