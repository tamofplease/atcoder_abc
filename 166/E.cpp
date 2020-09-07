#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

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



const int MAXN = 200001;
int A[MAXN];
int main(){
    int N;cin >> N;
    Rep(i,N)cin >> A[i];
    map<ll,ll> lmap;
    map<ll,ll> smap;
    Rep(i,N){
        ll large = i + A[i];
        ll small = i - A[i];
        if(lmap[large]>0)lmap[large]++;
        else lmap[large] = 1;
        if(smap[small]>0)smap[small]++;
        else smap[small] = 1;
    }
    ll ans = 0;
    Rep(i,N){
        ll large = i + A[i];
        ll small = i - A[i];
        smap[small]--;
        ans += smap[large];
        lmap[large]--;
    }

    cout << ans << endl;
    


    return 0;
}