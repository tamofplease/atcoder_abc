#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int base_k(int N) {
    string s; cin >> s;
    int res = 0;
    for(char c : s) {
        res = res * N + (c-'0');
    }
    return res;
}

int main(){
    int N;cin >> N;
    int a = base_k(N);
    int b = base_k(N);
    cout << (ll) a * b << endl;
    return 0;
}
