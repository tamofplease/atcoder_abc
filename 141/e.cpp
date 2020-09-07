#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
string S;
#define MAXN 5020
ll dp[MAXN+1][MAXN+1];
int main(){
    int N;cin >> N;
    rep(i,N+1)rep(j,N+1)dp[i][j] = 0;
    cin >> S;
    
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            if(S[i]==S[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = 0;
            }
        }
    }
    ll ma = 0;
    rep(i,N){
        for(int j=i+1;j<N+1;j++){
            if(dp[i][j]+i<=j)ma = max(ma,dp[i][j]);
        }
    }

    cout << ma << endl;
    return 0;

}