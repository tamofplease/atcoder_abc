#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int N,K;
#define MAXN 2002
ll C[MAXN][MAXN];
void solve(int i){
    if(K-1<0||N-K+1<0){
        cout << 0<< endl;
        return;
    }
    ll ans = (C[K-1][i-1]*C[N-K+1][i]);
    cout << ans%MOD << endl;
}

int main(){
    cin >> N >> K;
    for(int j=0;j<=2001;j++){
        C[0][j] = 0;
    }
    for(int i=0;i<=2001;i++){
        C[i][0] = 1;
    }
    

    for(int i=1;i<=2001;i++)for(int j=1;j<=2001;j++){
        if(i==j)C[i][j] = 1;
        else if(i<j)C[i][j] = 0;
        else C[i][j] = C[i-1][j]+C[i-1][j-1];
        C[i][j]%=MOD;
    }
    int i=1;
    
    for(i=1;i<=K;i++){
        solve(i);
    }

    return 0;
}