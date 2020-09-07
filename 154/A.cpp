#include <iostream>
#include <string>
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

int A,B;
string S,T;
string U;

int main(){
    int A,B;
    cin >> S >> T >> A >> B;
    cin >> U;
    if(U==S){
        cout << A-1 <<" " <<  B << endl;
    }else{
        cout << A <<" " <<  B-1 << endl;
    }
    return 0;
}