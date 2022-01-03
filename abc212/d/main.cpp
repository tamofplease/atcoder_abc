#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int q; cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll tm = 0;
    ll x;
    rep(i, q) {
        int query; cin >> query;
        if(query == 1) {
            cin >> x;
            pq.push(x-tm);
        }
        if(query == 2) {
            cin >> x;
            tm += x;
        }
        if(query == 3) {
            x = pq.top(); pq.pop();
            cout << x + tm << endl;
        }
    }
    return 0;
}
