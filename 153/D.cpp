#include <iostream>
#include <map>
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

ll H;
#define MAXN 10000000000
ll num = 0;
/*map<ll,ll> Ma;
ll count(ll a){//この数を返す
    if(Ma.find(a) != Ma.end())return Ma[a];
    Ma[a] = count(a/2)*2+1;
    return Ma[a];
}*/

int main(){
    cin >> H;
    int num = 0;
    ll counter = 0;
    ll co = 1;
    while(true){
        if(co > H)break;
        num++;
        counter += co;
        co *= 2;
    }

    cout << counter << endl;


    return 0;
}