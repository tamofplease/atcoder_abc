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
ll N,x;
#define MAXN 100001
ll a[MAXN];
int main(){
    cin >> N >> x;
    //N = 100000,x = 0;
    rep(i,N){
        //a[i] = 1000000000;
        cin >> a[i];
    }
    ll ans = 0;
    if(a[0]>x){
        ans += (a[0]-x);
        a[0] -= ans;
    }
    rep(i,N-1){
        if(a[i]+a[i+1]>x){
            ll tmp;
            tmp = (a[i]+a[i+1])-x;
            ans += tmp;
            if(a[i+1]>=tmp)a[i+1] -= tmp;
            else{
                a[i+1] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}