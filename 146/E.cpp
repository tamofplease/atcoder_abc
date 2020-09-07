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
#define MAXN 500000

int main(){
    int N,K;
    cin >> N >> K;
    int A[MAXN];
    rep(i,N)cin >> A[i];
    rep(i,N)A[i]%=K;
    int back = 0;
    ll tmp = 0;
    ll count = 0;
    ll ans = 0;
    int front = 0;
    while(true){
        if(count+=1>K || tmp+A[front]>=K){
            tmp -= A[back];
            count--;
            back++;
        }else{
            tmp += A[front];
            front++;
            count++;
        }
        if(tmp%K==count)ans++;
        if(front==N){
            while(back<N-1){
                tmp-=A[back];
                back++;
                count--;
                if(tmp%K==count)ans++;
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}