#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

ll calc(ll a, ll b);

int main() {
    ll n; cin >> n;
    ll ans = INT64_MAX;
    int j = 1000000;
    rep(i, 1000001) {
        while(calc(i,j) >= n && j >= 0) {
            ans = min(ans, calc(i,j));
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}

ll calc(ll a, ll b) {
    return (a*a*a)+(a*a*b)+(a*b*b)+(b*b*b);
}