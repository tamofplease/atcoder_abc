#include <iostream>
#include <string>
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
int N,K;
typedef pair<ll,ll> P;

bool sor(double &a,double &b){
    return a>b;
}

bool ok(double mid,const vector<P> &WP){
    double S[N];
    rep(i,N){
        S[i] = WP[i].second*WP[i].first-WP[i].first*mid;
    }
    sort(S,S+N,sor);
    double ans = 0;
    for(int i=0;i<K;i++){
        ans += S[i];
    }
    return ans>=0;
}

int main(){
    cin >> N >> K;
    vector<P> WP(N);
    rep(i,N){
        cin >> WP[i].first >> WP[i].second;
    }
    double mi = 0;
    double ma = __DBL_MAX__;
    while(ma-mi>0.0000000000001){
        double mid = (mi+ma)/2;
        if(ok(mid,WP)){
            mi = mid;
        }else{
            ma = mid;
        }
    }
    cout <<setprecision(15) << mi << endl;
    return 0;
}