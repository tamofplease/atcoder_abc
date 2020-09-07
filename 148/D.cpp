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
ll N;
ll ans = 0;

void calc(){
    ans += N/10;
    N = N/10;
    while(1){
        ans += N/5;
        N = N/5;
        if(N<5)break;
    }
}


void solve(){
    if(N<2){
        cout << 0 << endl;
        return ;
    }
    else if(N%2==1){
        cout << 0 << endl;
        return ;
    }else{
    while(N%5!=0){
        N-=2;
    }
    calc();
    }
    cout << ans << endl;
}

int main(){
    cin >> N;
    
    //cout << N << endl;
    solve();
    
    return 0;
}