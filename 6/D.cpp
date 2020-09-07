#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int C[30002];
int dp[30001];
int main(){
    int N;cin >> N;
    rep(i,N){
        cin >> C[i];
    }
    dp[0] = 1;
    int ma = 0;
    for(int i=0;i<N;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(C[i]>=C[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        ma = max(ma,dp[i]);
    }
    int ans = 0;
    ans = N-ma;
    cout << ans << endl;
    
    
    return 0;

}