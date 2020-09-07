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


int main() {
    int N,K;
    cin >> N >> K;
    int count = 0;
    int tmp = 1;
    while(1){
        count++;
        tmp *= K;
        if(tmp>N)break;
    }

    cout << count << endl;
    // int N,K;
    // cin >> N >> K;
    // ll tmp = 1;
    // int count = 0;
    // while(1){
    //     count++;
    //     if(tmp > N){
    //         count--;
    //         break;
    //     }else if(tmp == N) {

    //         break;
    //     }
    //     tmp *= K;
    // }
    // cout << count << endl;
    return 0;
}


