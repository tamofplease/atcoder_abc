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
ll A,B,X;
int getbit(ll N){
    ll count = 0;
    while(N>0){
        N/=10;
        count++;
    }
    return count;
}

bool ok(ll N){
    long double J = (long double)X/(long double)A;
    long double K = (long double)B/(long double)A;
    return J>= N+K*getbit(N);
}

int main(){
    
    cin >> A >> B >> X;
    ll small = 0;
    ll large = 1000000000;
    ll mid ;
    while(abs(large-small)>1){
        mid = (small+large)/2;
        if(!ok(mid)){
            large = mid;
        }else{
            small = mid;
        }
    }
    if(ok(1000000000))cout << 1000000000<<endl;
    else{
        cout << small << endl;
    }
    return 0;
}