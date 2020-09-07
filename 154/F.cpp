
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string N;cin >> N;
    int K;cin >> K;
    //digitDP
    // keta, 1num, is smaller than N
    int dp[101][4][2];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int keta=1; keta<=N.length(); keta++){
        for(int num=0; num<K; num++){
            for(int is=0; is<2; is++){
                if(is == 0){ //no
                    int mx = N[keta-1]-'0';
                    for(int i=0; i<mx; i++){
                        if(i == 0){
                            dp[keta][num+1][1] += dp[keta-1][num][is];
                        }else{
                            dp[keta][num][1] += dp[keta-1][num][is];
                        }
                    }
                    if(mx == 0){
                        dp[keta][num+1][is] += dp[keta-1][num][is];
                    }else{
                        dp[keta][num][is] += dp[keta-1][num][is];
                    }
                }else if(is == 0){ //ok
                    for(int i=0; i<K; i++){
                        if(i == 0){
                            dp[keta][num+1][is] += dp[keta-1][num][is];
                        }else{
                            dp[keta][num][is] += dp[keta-1][num][is];
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i=1; i<=K; i++){
        for(int j=0; j<2; j++){
            res += i*dp[N.length()][i][j];
        }
    }
    cout << res << endl;
}