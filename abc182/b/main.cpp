#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
int A[110];
void input() {
    cin >> N;
    rep(i, N) cin >> A[i];
}

void solve() {
    int tmp =0 , ans = 0;
    for(int i = 2; i <= 1000 ; i++ ) {
        int cur = 0;
        rep(j, N) {
            if(A[j] % i == 0) {
                cur += 1;
            }
        }
        if(cur > tmp) {
            tmp = cur;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
