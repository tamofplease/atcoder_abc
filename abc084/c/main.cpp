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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> c(n), s(n), f(n);
    rep(i, n-1) {
        cin >> c[i] >> s[i] >> f[i];
    }
    int cur_time = 0;
    vector<int> ans;
    rep(begin, n)  {
        cur_time = 0;
        for(int i=begin;i<n-1;i++) {
            ans.push_back(cur_time);
            if(cur_time < s[i]) {
                cur_time = s[i];
            } else {
                if((cur_time - s[i]) % f[i] != 0) {
                    cur_time += f[i] - ((cur_time - s[i]) % f[i]);
                }
            }
            cur_time += c[i];
        }
        cout << cur_time << endl;
    }
    return 0;
}
