#include <iostream>
#include <vector>

using namespace std;
vector<int> V;
typedef long long ll;
const int MOD = 1000000007 ;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
ll M;
int a[1000000000] ={0};//iがa[i]乗
int j = 2;
int dp[100001][101];
void Prime(int i = 2){
    while(true){
        
        if(M%i!=0)break;
        M/=i;
        a[j]++;
    }
    j++;
    if(M==1 )return;
    if(M<i*i){
        a[M]= 1;
        return ;
    }
    Prime(i+1);
}

int main(){
    cin >> N >> M;
    Prime();
    int count=0;
    rep(i,j){
        rep(k,N+1)dp[k][0] = 1;
        if(a[i]!=0){
            for(int k=0;k<N;k++){
                for(int l=1;l<=a[i];l++){
                    if(l-1-a[i]>=0)dp[k+1][l] = (dp[k][l] + dp[k][l-1]-dp[k+1][l-1-a[i]]+MOD)%MOD;
                    else{
                        dp[k+1][l] = (dp[k][l] + dp[k+1][l-1])%MOD;
                    }
                }
            }
            V.push_back(dp[N][a[i]]);
        }
    }
    ll ans = 1;
    
    while(!V.empty()){
        ans *= V.back();
        ans %= MOD;
        V.pop_back();
    }
    cout << ans << endl;
    return 0;

}