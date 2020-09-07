#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <tgmath.h>
#define MOD 1000000007
using namespace std;
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll N,W;
#define MAXN 200
const ll INF = 10000000000000;
ll v[MAXN],w[MAXN];

void solve1(){
    int mid = N/2;
    pair<ll,ll> P[1<<mid];
    for(int i=0;i<1<<mid;i++){
        ll vin = 0,win = 0;
        for(int j=0;j<mid;j++){
            if(i>>j&1){
                vin += v[j];
                win += w[j];
            }
        }
        P[i] = make_pair(win,vin);
    }
    sort(P,P+(1<<mid));
    int m = 1;
    for(int i=1;i<(1<<mid);i++){
        if(P[m-1].second<P[i].second){
            P[m++] = P[i];
        }
    }
    ll ans = 0;
    for(int i=0;i<1<<(N-mid);i++){
        ll vin = 0,win = 0;
        for(int j=0;j<(N-mid);j++){
            if(i>>j&1){
                vin += v[mid+j];
                win += w[mid+j];
            }
        }
        if(win <= W){
            ll par = (lower_bound(P,P+mid,make_pair(W-win,INF))-1)->second;
            ans = max(par+vin,ans);
        }
    }
    cout << ans << endl;
    return ;
}
ll dp[MAXN][MAXN*1000+1];

void solve2(){
    //個数、v
    for(int i=0;i<N;i++){
        for(int j=0;j<=N*1000;j++){
            dp[i][j] = INF;
            if(j==w[i]){
                dp[i][j] = v[i];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=N*1000;j++){
            dp[i+1][j]  = min(dp[i+1][j],dp[i][j]);
            if(j-v[i]>=0)dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    ll ans = INF;
    for(int i=0;i<N*1000;i++){
        if(dp[N][i]<=W)ans = min(ans,(ll)i);
    }
    cout << ans << endl;
}

void solve3(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=N*1000;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=1000*N;j++){
            dp[i+1][j] = dp[i][j];
            if(j-w[i]>=0)dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    ll ans = 0;
    rep(i,W+1){
        ans = max(ans,dp[N][i]);
    }
    cout << ans << endl;
}

int main(){
    cin >> N >> W;
    bool k1 = true,k2 = true;
    rep(i,N){
        cin >> v[i] >> w[i];
        if(v[i]>1000)k1 = false;
        if(w[i]>1000)k2 = false;
    }
    /*if(N<=30){
        solve1();
    }else if(k2){
        solve2();
    }else{
        solve3();
    }*/
    solve2();
    return 0;
}