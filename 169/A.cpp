#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}


int main(){

    ll N;
    
    cin >> N;
    ll n=N;
    ll i=2;
    map<ll,ll> map{};
    ll maxv = 0;
    while(true) {
        if(N%i==0) {
            ll tmp = i;
            while(N%i==0) {
                if(map[i]==0)map[i]=1;
                else map[i]++;
                N /= i;
            }
        }
        i++;
        if(i*i > N){
            if(N != 1 && N != 0)map[N]++;
            break;
        }
    }
    ll ans = 0;

    for(auto itr = map.begin(); itr!= map.end(); ++itr) {
        ll tmp = itr->second;
        ll j=0;
        while(true) {
            j++;
            if(tmp<j)break;
            tmp -= j;
            ans++;
        }
    }

    cout << ans << endl;
    
    
    return 0;
}