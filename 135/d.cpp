#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
#define MOD 1000000007
string S;
ll dp[101001][13];//dp[i桁まで見たとき][そこまでの数の１３で割ったあまり]

int main(){
    cin >> S;
    dp[0][0] = 1;
    for(int i=0;i<S.length();i++){
        for(int k=0;k<13;k++){
            int t;
            if(S[i]!='?'){
                t = S[i]-'0';
                dp[i+1][(k*10+t)%13] += dp[i][k]%=MOD;
            }else{
                for(int j=0;j<10;j++){
                    dp[i+1][(k*10+j)%13] += dp[i][k]%=MOD;
                }
            }
        }
    }
    cout << dp[S.length()][5]%MOD << endl;
    return 0;
}