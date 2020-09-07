#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
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

const int MAXN = 100000;
int a[MAXN];
ll N,K;
int main(){
    int front=0,back=0;
    cin >> N >> K;
    rep(i,N)cin >> a[i];
    ll tmp = 0;
    ll ans = 0;
    while(1) {
        if(tmp >= K) {
            ans += N - front + 1;
            back++;
            front = back;
            tmp = 0;
        }
        if(front==N && tmp < K)break;
        tmp += a[front];
        front++;
    }

    cout << ans << endl;


    return 0;
}