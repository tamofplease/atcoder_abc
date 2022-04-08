#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

vector<ll> divisor(ll n) {
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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<bool> primes(55556, true);
    primes[0] = false, primes[1] = false;
    Rep(i, 55555) {
        int j = i;
        if(primes[i]) {
            while(j + i < 55556) {
                j += i;
                primes[j] = false;
            }
        }
    }
    queue<int> res;
    Rep(i, 55555) {
        if(primes[i]) {
            if(i%5==3) res.push(i);
        }    
    }
    rep(i, n) {
        int front = res.front(); res.pop();
        cout << front << endl;
    }

    return 0;
}
