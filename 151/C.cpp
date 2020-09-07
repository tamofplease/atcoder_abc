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

int N,M;
#define MAXN 100002
string S[MAXN];
ll p[MAXN];

int main(){
    cin >> N >> M;

    rep(i,M){
       cin >> p[i] >> S[i];
    }
    ll data[MAXN];
    ll allwa = 0;
    ll allac = 0;
    rep(i,N+1)data[i] = 0;
    for(int i=0;i<M;i++){
        if(data[p[i]]!=-1 && S[i]=="WA"){
            data[p[i]]++;
        }
        if(data[p[i]]!=-1 && S[i]=="AC"){
            allac++;
            allwa += data[p[i]];
            data[p[i]] = -1;
        }
    }
    cout << allac << " " << allwa << endl;
    return 0;
}