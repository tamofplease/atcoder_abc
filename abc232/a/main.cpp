#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string s;
int main(){
    cin >> s;
    cout << (s[0] - '0') * (s[2] - '0') << endl;
    return 0;
}
