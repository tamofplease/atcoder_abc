#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
int N,M;

ll re(int a){
    ll an = 1;
    while(1){
        an *= a;
        a--;
        if(a==0)break;
        an %=MOD;
    }
    return an;
}
void solve(){
    if(abs(N-M)>1){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    if(N==M){
        ans = (re(N)*re(M)*2)%MOD;
        cout << ans << endl;
        return;
    }
    ans = (re(N)*re(M))%MOD;
    cout << ans << endl;
}
int main(){
    cin >> N >>M;
    solve();
    return 0;

}