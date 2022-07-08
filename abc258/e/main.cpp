// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n, q, x;
    cin >> n >> q >> x;
    vector<int> w(n);
    ll allW = 0;
    rep(i, n) {
        cin >> w[i];
        allW += w[i];
    }
    vector<ll> k(q);
    rep(i, q) cin >> k[i];

    vector<ll> nums(n, 0);
    ll front = 0;
    ll cur = 0;
    for (int back = 0; back < n; back++) {
        if (x - cur > allW) {
            front += ((x - cur) / allW) * n;
            cur += ((x - cur) / allW) * allW;
        }
        while (cur < x) {
            cur += w[front % n];
            front++;
        }
        nums[back] = front - back;
        cur -= w[back];
    }
    int oneLoop = 0;
    vector<int> next(n);
    vector<int> been(n, -1);
    vector<int> ma;
    int iter = 0;
    while (been[iter] == -1) {
        been[iter] = oneLoop;
        ma.push_back(iter);
        next[iter] = (iter + nums[iter]) % n;
        iter += nums[iter] % n;
        iter %= n;
        oneLoop++;
    }
    oneLoop -= been[iter];

    for (ll tgt : k) {
        tgt--;
        if (been[iter] >= tgt) {
            cout << nums[ma[tgt]] << endl;
            continue;
        }
        tgt -= been[iter];
        tgt %= oneLoop;
        tgt += been[iter];
        cout << nums[ma[tgt]] << endl;
    }
    return 0;
}
