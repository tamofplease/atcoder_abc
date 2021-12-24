#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll H, W, N, M;
int table[1500][1500];
void show() {
    // rep(i, H){
    //     rep(j, W) {
    //         cout << table[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main(){
    cin >> H >> W >> N >> M;
    vector<int> A(N), B(N), C(M), D(M);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    rep(i, M) {
        cin >> C[i] >> D[i];
    }
    rep(i, N) {
        table[A[i]-1][B[i]-1] = 1;
    }
    rep(i, M) {
        table[C[i]-1][D[i]-1] = -1;
    }
    rep(i, H) {
        rep(j, W-1) {
            if(table[i][j] >= 1 && table[i][j+1] >= 0) table[i][j + 1] = 1;
        }
        for (int j = W - 1; j > 0; j--) {
            if (table[i][j] > 0 && table[i][j - 1] >= 0) table[i][j - 1] = 1;
        }
    }
    rep(i, N) {
        table[A[i] - 1][B[i] - 1] = 2;
    }
    rep(i, W) {
        rep(j, H-1) {
            if(table[j][i] > 1 && table[j+1][i] >= 0) table[j+1][i] = 2;
        }
        for(int j = H-1 ; j>0;j--){
            if(table[j][i] > 1 && table[j-1][i] >= 0) table[j-1][i] = 2;
        }
    }
    ll ans = 0;
    rep(i,H) rep(j, W) {
        ans += table[i][j] > 0;
    }
    cout << ans << endl;
    return 0;
}
