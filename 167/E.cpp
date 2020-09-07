#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;
#define MOD 998244353

vector<ll> fac(300001); 
vector<ll> ifac(300001); 

ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

ll N,m,K;

int main(){
    
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<200000; i++){
        fac[i+1] = fac[i]*(i+1) % M; 
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    cin >> N >> m >> K;

    ll tmp = 1;
    ll s;
    ll fa = 0;
    for(int k=0;k<=K;k++) {
        tmp = mpow(m-1,N-1-k) % M;
        tmp *= m;
        tmp %= M;
        ll ans = comb(N-1,k) % M;
        fa += (tmp*ans) %M;
        fa %= M;
    }
    
    if(fa<0) fa += M;
    cout << fa << endl;;

    
    return 0;
}