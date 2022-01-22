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
    string s; cin >> s;
    int left = 0, right = s.length();
    while(right - left > 0) {
        int mid = (right - left) / 2;
        int cur = 0;
        vector<int> toggle((int)s.length()*2+1, 0);
        rep(i, s.length()) {
            if(s[i] % 2 == 0) {
                toggle[i+k] -= 1;
            }
            if(isToggled) {
                if(s[i] == '1') {
                    isToggled = !isToggled;
                }
            } else {
                if(s[i] == '0') {
                    isToggled = !isToggled;                    
                }
            }
        }
    }
    return 0;
}
