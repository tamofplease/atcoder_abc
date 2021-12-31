#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    string x; cin >> x;
    int len =  x.length();
    ll summation = 0;
    rep(i, len) {
        summation += x[i] - '0';
    }
    vector<int> ans; /// 答えをしもけたから順に詰めていく。
    ll carrer = 0;
    rep(i, len) {
        int j = len - i - 1;
        ll tm = (summation % 10 + carrer % 10) % 10;
        ans.push_back(tm);
        carrer = (carrer + summation) / 10;
        summation -= x[j] - '0';
    }
    while(carrer > 0) {
        ans.push_back(carrer%10);
        carrer /= 10;
    }
    ll l_a = ans.size();
    rep(i, l_a) {
        ll j = l_a - i - 1;
        cout << ans[j];
    }
    cout << endl;

    return 0;
}
