#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

ll H[100001];
ll dp[100001];//i番目まで見たときの右にいける回数
int main(){
    int N;
    cin >> N ;
    rep(i,N)cin >> H[i];
    ll maxt = 0;
    dp[N-1] = 0;
    for(int i=N-1;i>0;i--){
        if(H[i]<=H[i-1]){
            dp[i-1] = dp[i]+1;
        }else dp[i-1] = 0;
        maxt = max(maxt,dp[i-1]);
    }
    //rep(i,N)cout << dp[i] << endl;
    cout << maxt << endl;
    
    return 0;

}