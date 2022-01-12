#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    ll n; cin >> n;
    if(n==0) {
        cout << 0 << endl;
        return 0;
    }
    string ans;
    vector<ll>posi;
    vector<ll> nega;
    ll po = 0, ne = 0;
    ll tmp = 1;
    rep(i, 50) {
        ((tmp>0)?po:ne) += tmp;
        posi.push_back(po);
        nega.push_back(ne);
        tmp *= -2;
    }
    tmp = 1;
    int i = 0;
    if(n>0) {
        while(tmp < n) {
            tmp *= -2;
            i++;
        }
    } else {
        while(tmp > n) {
            tmp *= -2;
            i++;
        }
    }
    for(int j=i; j>=0;j--) {
        if(tmp > 0) {
            if(n-tmp>=nega[j]){
                n-=tmp;
                ans+="1";
            } else {
                ans+= "0";
            }
        } else {
            if(n-tmp<=posi[j]) {
                n -= tmp;
                ans+="1";
            } else {
                ans+= "0";
            }
        }
        tmp /= -2;
    }
    int cur_i = 0;
    rep(i, ans.length()) {
        if(ans[i] != '0') {
            break;
        }
        cur_i++;
    }
    cout << ans.substr(cur_i, (int)ans.length()) << endl;

    return 0;
}
