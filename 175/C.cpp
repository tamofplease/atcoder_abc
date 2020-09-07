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

    ll X,K,D;
    cin >> X >> K >> D;
    ll tmp;
    ll tmp_place;
    ll tmp_other;
    if(X>0){
        tmp = (X/D) + 1;
        tmp_place = X - tmp*D;
        tmp_other = X - (tmp-1)*D;
    }else {
        tmp = -(X/D) + 1;
        tmp_place = (-1*X) - tmp*D;
        tmp_other = (-1*X) - (tmp-1)*D;
    }
    if(tmp > K){
        if(X>0){
            cout << abs(X - K*D) << endl;
            return 0;
        }else{
            cout << abs(-1*(X)- K*D) << endl;
            return 0;
        }
    }
    if((K-tmp)%2==0){
        cout << abs(tmp_place) << endl;
    }else {
        cout<< abs(tmp_other) << endl;
    }
    return 0;
}