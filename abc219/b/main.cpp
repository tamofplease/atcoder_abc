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
    map<char, string> ma;
    cin >> ma['1'] >> ma['2'] >> ma['3'];
    string s; cin >> s;
    for(char c : s) cout << ma[c];
    cout << endl;
    return 0;
}
