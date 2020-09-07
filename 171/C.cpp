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

string tmp="";
void maker(ll N) {
    char a = ((N-1)%26) + 97;
    tmp = a + tmp;
    N--;
    if((N/26)>0)maker(N/26);
    else return;
}

int main(){
    ll N;cin >>N;
    tmp = ((N-1)%26) + 97;
    N--;
    N /= 26;
    if(N>0)maker(N);
    cout << tmp << endl;
    return 0;
}