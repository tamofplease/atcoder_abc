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

int getcost(int a,int b){
    return abs(a-b)*abs(a-b);
}

int N;
#define MAXN 101
int X[MAXN];

int main() {
    cin >> N ;
    rep(i,N)cin >> X[i];
    int mini=10000000,ans= 0;
    for(int i=0;i<=1000;i++) {
        ll tmp = 0;
        rep(j,N){
            tmp += (X[j]-i) * (X[j]-i);
        }
        if(mini > tmp) {
            mini = tmp;
            ans = i;
        }
    }

    cout << mini << endl;
    
    return 0;
}
// int X[MAXN];
// int main(){
//     cin >> N;
//     rep(i,N)cin >> X[i];
//     int mini = 1000000000;
//     for(int i=1;i<=100;i++){
//         int cost = 0;
//         for(int j=0;j<N;j++){
//             cost += getcost(X[j],i);
//         }
//         if(cost < mini)mini = cost;
//     }
//     cout << mini << endl;
//     return 0;
// }