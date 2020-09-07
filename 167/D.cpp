#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)

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

#define MAXN 200001

#define MAXK 1000000000000000000

int gone[MAXN];

int main(){

    ll N, K;
    int A[MAXN];
    cin >> N >> K;
    rep(i,N)cin >> A[i];
    int cur_place = 1;
    int count = 1;
    rep(i,N) gone[i] = 0;
    gone[1] = 1;
    int diff;
    if(K>N) {
        while(1) {
            cur_place = A[cur_place];
            count++;
            if(gone[cur_place] != 0){
                diff = count - gone[cur_place];
                break;
            }
            gone[cur_place] =count;
        }
        gone[cur_place] -= 1;
        // cout << gone[cur_place] << " " << diff <<" "<<cur_place  << endl;
        K = (K - gone[cur_place])  % diff;
        for(int i=0;i<K;i++) {
            cur_place = A[cur_place];
        }
    }else {
        for(int i=0;i<K;i++) {
            cur_place = A[cur_place];
        }
    }
    

    cout << cur_place << endl;


    
    return 0;
}