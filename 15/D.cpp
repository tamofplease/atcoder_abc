#include <iostream>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) rep(i,n+1)
int dp[51][51][10001] ={0};
int main(){
    int W,N,K;
    cin >> W>>N>>K;
    vector<int> w(N+1);
    vector<int> v(N+1);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }
    rep(i,N) Rep(j,N) Rep(k,W){
        if(k+w[i]<=W){
            dp[i+1][j+1][k+w[i]] = max(dp[i][j][k]+v[i],dp[i][j][k+w[i]]);
        }
        dp[i+1][j][k] = max(dp[i][j][k],dp[i+1][j][k]);

    }
    cout << dp[N][K][W];
    return 0;
}