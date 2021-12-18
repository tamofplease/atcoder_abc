#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
int main(){
    cin >> N;
    map<string, int> ma;
    string ans;
    int m = 0;
    rep(i, N) {
        string s;cin >> s;
        ma[s]++;
        if(m < ma[s]) {
            ans = s;
            m = ma[s];
        }
    }
    cout << ans << endl;
    
    return 0;
}
