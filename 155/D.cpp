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

int N,K;
#define MAXN 200000
int A[MAXN];
int zero = 0;posi = 0,nega = 0;
int nmax = -1;nmin = -10000000000;
int pmax = 1;pmin = 1000000000;

bool ok(int s){
    if(s>=K)return true;
    else return false;
}

solveNega(){
    ll mid = (nmax + nmin)/2;
    while(1){
        if(ok(mid))nmin = mid;
        else nmax = mid;
    }
}



solvePosi(){
    ll mid = (pmax + pmin)/2;
    while(1){
        if(ok(mid))pmin = mid;
        else pmax = mid;
    }
    return mid;
}

int main(){
    cin >> N >> K;
    rep(i,N){
        cin >> A[i];
        if(A[i]==0)zero ++;
        else if(A[i]>0)opsi++;
        else nega++;
    }
    ll numZero = zero*(posi+nega);
    ll numNega = posi*nega;
    ll numPosi = (posi*(posi-1))/2 + (nega*(nega-1))/2;
    if(K < numNega){
        cout << solveNega() << endl;
    }else{
        K -= numNega;
        if(K < numZero){
            cout << 0 << endl;
        }else{
            K-=numZero;
            cout << solvePosi() << endl;
        }
    }
    return 0;
}