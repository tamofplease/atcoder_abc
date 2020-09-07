#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
#define MAXN 100001
ll A[MAXN];
int dp[MAXN];
int main(){
    //cin >> N ;
    N = 10000;
    rep(i,N){
        //cin >> A[i];
        A[i] = 0;
    }
    rep(i,N+1)dp[i] = -1;

    dp[0] = A[0];
    for(int i=1;i<N;i++){
        int j=0;
        if(dp[j]<A[i])dp[j] = A[i];
        else if(dp[j]>=A[i]){
            while(dp[j]>=A[i]){
                j++;
            }
            dp[j] = A[i];
        }
    }
    int ans = 0;
    while(dp[ans]!=-1){
        ans++;
    }
    cout << ans << endl;
    return 0;

}