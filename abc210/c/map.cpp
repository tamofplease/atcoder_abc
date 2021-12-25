#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    map<int, int> ma;
    cout << ma.size() << endl;
    ma[0] = 1;
    cout << ma.size() << endl;
    ma[0] = 0;
    cout << ma.size() << endl;
    ma.erase(0);
    cout << ma.size() << endl;
    return 0;
}
