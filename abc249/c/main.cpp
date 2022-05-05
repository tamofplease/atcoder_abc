#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    int n, k; cin >> n >> k;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    int ns = (1 << n);
    int ans = 0;
    for(int bit=0;bit<ns;bit++) {
        map<char, int> ma;
        for(int i=0;i<n;i++) {
            if(bit&(1<<i)) {
                for(char c : s[i])  {
                    ma[c]++;
                }
            }
        }
        int tmp = 0;
        for(auto it=ma.begin();it!=ma.end();it++) {
            if(it->second == k) tmp++;
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}