#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

int main(){
    ll w, h, n; cin >> w >> h >> n;
    vector<pair<ll, ll>> z(n);
    rep(i, n) {
        cin >> z[i].first >> z[i].second;
    }
    vector<pair<ll, ll>> table = z;
    map<ll, ll> lrank;// keyがvalue版め
    map<ll, ll> trank;
    sort(table.begin(), table.end(), sortbysec);
    ll number = 1;
    rep(i, n) {
        if(lrank[table[i].second] == 0) {
            lrank[table[i].second] = number;
            number++;
        }
    }
    number = 1;
    sort(table.begin(), table.end());
    rep(i, n) {
        if(trank[table[i].first] == 0) {
            trank[table[i].first] = number;
            number++;
        }
    }

    rep(i, n) {
        cout << trank[z[i].first] << " " << lrank[z[i].second] << endl;
    }


    return 0;
}
