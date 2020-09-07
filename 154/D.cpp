#include <iostream>
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

int N;
int K;
#define MAXN 200000
int p[MAXN];
double go = 0;
int ma  = 0;
int maxi = 0;
int maxi_p = 0;

double get_go(int max_p){
    
    double z = 0;
    for(int i=max_p;i<max_p+K;i++){
        z += (double)(p[i]+1)/2;
        
    }
    
    return z;
}

int main(){
    cin >> N >> K;
    
    rep(i,N){
        cin >> p[i];

    }
    for(int i=0;i<K;i++){
        ma += p[i];
        if(ma > maxi){
            maxi = ma;
            maxi_p = 0;
        }
    }
    for(int i=1;i<=N-K;i++){
        ma -= p[i-1];
        ma += p[i+K-1];
        if(ma > maxi){
            maxi = ma;
            maxi_p = i;
        }
    }
    double ans = get_go(maxi_p);
    printf("%0.8f\n",ans);

    return 0;
}