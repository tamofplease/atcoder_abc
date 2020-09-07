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
int main(){
    int N;cin >> N;
    deque<ll> qu;
    Rep(i,9)qu.push_back(i);
    int counter = 0;
    while(1){
        ll q = qu.front();
        counter++;
        if(counter==N){
            cout << q << endl;
            return 0;
        }
        qu.pop_front();
        if((q%10)!=0)qu.push_back(q*10+(q-1)%10);
        qu.push_back(q*10+(q%10));
        if(q%10!=9)qu.push_back(q*10+(q+1)%10);
    }
    return 0;
}