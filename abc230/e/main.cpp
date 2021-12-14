#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll N;
vector<ll> divisor(ll n){
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
void input() {
   cin >> N; 
}

void solve() {
    vector<ll> primes = divisor(N);
    ll ans = N;
    sort(primes.begin(), primes.end(), greater<ll>());
    rep(i, primes.size() - 1) {
        ll nums = primes[i] - primes[i+1];
        ll add = nums * (N / primes[i]);
        ans += add;
        cout << primes[i] << " " << primes[i+1] << " " << nums << " " << add << endl;
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
