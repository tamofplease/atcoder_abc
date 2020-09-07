#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
#define MAXN 2000
int main(){
    cin >> N;
    vector<int> L(N);
    rep(i,N)cin >> L[i];
    sort(L.begin(),L.end());

    ll ans = 0;
    for(int i=1;i<N;i++){
        int a = L[i];
        for(int j=0;j<i;j++){
            vector<int> V(i-j-1);
            for(int k=j+1;k<i;k++){
                V[k-j-1] = L[k];
            }
            int b = L[j];
            int tmp = lower_bound(V.begin(),V.end(),a+b)-upper_bound(V.begin(),V.end(),a-b);
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}