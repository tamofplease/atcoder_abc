#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
string S;
ll dp[100001][14];
int main(){
    cin >> S;
    dp[0][0] = 1;
    ll len = S.length();
    for(int i=0;i<len;i++){
            for(int k=0;k<13;k++){
                if(S[i]=='?'){
                    for(int j=0;j<10;j++){
                        dp[i+1][(k*10+j)%13] += dp[i][k];
                        dp[i+1][(k*10+j)%13] %= MOD;
                    }
                }else{
                    int t = S[i] - '0';
                    dp[i+1][(k*10+t)%13] += dp[i][k];
                    dp[i+1][(k*10+t)%13] %= MOD;
                }
        }
    }
    cout << dp[len][5]%MOD << endl;
    return 0;

}