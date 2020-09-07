#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 100001
int a[MAXN],b[MAXN];
ll N,K;
typedef pair<ll,ll> P;
int main(){
    P par[MAXN];
    cin >> N >> K;
    rep(i,N){
        ll A,B;cin >> A >> B;
        par[i].first = A;
        par[i].second = B;
    }   
    sort(par,par+N);
    ll count = 0;
    rep(i,N){
        if(count+par[i].second<K)count += par[i].second;
        else {
            cout << par[i].first << endl;
            break;
        }
    }
    return 0;

}