#include <iostream>
#include <algorithm>
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

bool com(const int &a,const int &b){
    return a>b;
}

int N,K;
#define MAXN 200001
int H[MAXN];

int main(){
    cin >> N >> K;
    rep(i,N)cin >> H[i];
    sort(H,H+N,com);
    ll sum = 0;
    for(int i=K;i<N;i++){
        sum += H[i] ;
    }
    cout << sum << endl;
    return 0;
}