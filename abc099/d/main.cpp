#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++)
        indexes[i] = i;
    do
    {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

void foreach_permutation(int n, int k, std::function<void(int *)> f) {
    foreach_comb(n, k, [&](int *c_indexes)
                 { foreach_permutation(k, [&](int *p_indexes)
                                       {
      int indexes[k];
      for (int i = 0; i < k; i++) {
        indexes[i] = c_indexes[p_indexes[i]];
      }
      f(indexes); }); });
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, c; cin >> n >> c;
    vector<int> zero(1001, 0), one(1001, 0), two(1001, 0);
    vector<vector<int>> uConfort(c+1, vector<int>(c+1)), grid(n+1, vector<int>(n+1));
    rep(i, c) rep(j, c) cin >> uConfort[i][j];
    rep(i, n) rep(j, n) {
        cin >> grid[i][j];
        grid[i][j]--;
    }
    rep(i, n) rep(j, n) {
        if((i+j) % 3 == 0) {
            zero[grid[i][j]]++;
        } else if((i+j)%3==1) {
            one[grid[i][j]]++;
        } else {
            two[grid[i][j]]++;
        }
    }
    ll ans = LLONG_MAX;
    foreach_permutation(c, 3, [&zero, &one, &two, &uConfort, &ans, &c](int *colors) {
        ll tmp = 0;
        int zColor = colors[0], oColor = colors[1], tColor = colors[2];
        rep(i, c) {
            tmp += zero[i] * uConfort[i][zColor];
            tmp += one[i] * uConfort[i][oColor];
            tmp += two[i] * uConfort[i][tColor];
        }
        ans = min(tmp, ans);
    });
    cout << ans << endl;
    return 0;
}
