#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <tgmath.h>
#define MOD 1000000007
using namespace std;
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll N;
ll K;
#define MAXN 200000
ll A[MAXN];
ll F[MAXN];
bool sor(int a,int b){
    if(a>b)return true;
    else return false;
}

bool ok(ll mid){
    ll kplace = K;
    for(int i=0;i<N;i++){
        if(A[i]*F[i]>mid){
            kplace -=A[i]-(mid/F[i]);
        }
        if(kplace<0){
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> N >> K;
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    rep(i,N){
        cin >> F[i];
    }
    if(sum<=K){
        cout << 0 << endl;
        return;
    }
    sort(A,A+N);
    sort(F,F+N,sor);
    ll front = LONG_MAX;
    ll back = -1;
    ll mid;
    while(abs(front-back)>1){
        mid = (front+back)/2;
        //cout << mid << endl;
        if(ok(mid))front = mid;
        else back = mid;
    }
    cout << front<< endl;
}
int main(){
    solve();
    return 0;
}