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

int K;
int main(){
    cin >> K;
    if(K%2==0){
        cout << -1 << endl;
        return 0;
    }
    int tmp = 0;
    int sur = 0;
    int counter = 1;

    while(1) {
        tmp += 7;
        sur = tmp%K;
        if(sur == 0)break;
        tmp = sur * 10;
        counter++;
        if(counter > 50000000){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << counter << endl;
    return 0;
}