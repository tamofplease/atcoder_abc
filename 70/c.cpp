#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 101
int N;
ll T[MAXN];
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    cin >> N;
    rep(i,N)cin >> T[i];
    ll ans = T[0];
    for(int i=1;i<N;i++){
        ans *= T[i]/gcd(ans,T[i]);
    }
    cout << ans << endl;
    return 0;

}