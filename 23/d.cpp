#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MOD 1000000007
using namespace std;

#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll N;
#define MAXN 1000001
ll H[MAXN],S[MAXN];
ll data[MAXN];
bool ok(ll hight){
    for(int i=0;i<N;i++){
        if(hight<H[i])return false;
        data[i] = (hight-H[i])/S[i];
    }
    sort(data,data+N);
    for(int i=0;i<N;i++){
        if(data[i]<i)return false;
    }
    return true;
}
int main(){
    cin >> N;
    rep(i,N)cin >> H[i] >> S[i];
    int hi[MAXN];
    ll mint = 0,maxt = INT_MAX;
    while(maxt-mint>1){
        ll hight = (mint+maxt)/2;
        if(ok(hight))maxt = hight;
        else mint = hight;
    }
    cout << maxt << endl;
    
    return 0;
}