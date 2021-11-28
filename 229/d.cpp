#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string S;
int K;

void input() {
   cin >> S >> K; 
}
void solve() {
    int ans = 0;
    int remain = K;
    int tmp = 0;
    int tail = 0;
    int sl = S.length();
    rep(i, sl) {
        if(S[i] == 'X') {
            ans = max(ans, ++tmp);
            continue;
        }
        if(remain > 0) {
            remain--;
            ans = max(ans, ++tmp);
            continue;
        }
        if(remain == 0) {
            while(S[tail] == 'X') {
                tail++;tmp--;
            }
            tail++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
