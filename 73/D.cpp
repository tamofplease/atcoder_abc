#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int r[10];
#define MAXN 201
#define INF 1000000000
int D[MAXN][MAXN];
int main(){
    int N,M,R;
    cin >> N>> M >> R;
    rep(i,min(8,R)){
        cin >> r[i];
        r[i]--;
    }
    rep(i,N)rep(j,N){
        D[i][j] = INF;
        if(i==j)D[i][j] = 0;
    }
    rep(i,M){
        int a,b,c;cin >> a >> b >> c;
        a--,b--;
        D[a][b] = c;
        D[b][a] = c;
    }
    rep(k,N)rep(i,N)rep(j,N){
        D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
    }
    ll ans = 0;
    for(int i=0;i<min(8,R)-1;i++){
        ans += D[r[i]][r[i+1]];
    }
    
    cout << D[1][2] << D[2][3] <<  endl;
    cout << ans << endl;
    return 0;

}