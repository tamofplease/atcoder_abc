#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
ll G[1002];
void numb(int a){
    for(int i=2;i<=a;i++){
        if(a%i==0){
            G[i]++;
            a =a/i;
            break;
        }
    }
    if(a==1)return;
    numb(a);
}
int main(){
    int N;
    cin >>N;
    rep(i,N+1)G[i] = 0;
    for(int i=2;i<=N;i++){
        numb(i);
    }
    ll ans = 1;
    rep(i,N+1){
        if(G[i]!=0){
            ans *=(G[i]+1);
            ans %=MOD;
        }
        
    }
    cout << ans%MOD << endl;
    return 0;
}