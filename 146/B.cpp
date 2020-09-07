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

int main(){
    string S;
    cin >> S;
    if(S=="SUN")cout << 7 << endl;
    if(S=="MON")cout << 6 << endl;
    if(S=="TUE")cout << 5 << endl;
    if(S=="WED")cout << 4 << endl;
    if(S=="THU")cout <<3 << endl;
    if(S=="FRI")cout << 2 << endl;
    if(S=="SAT")cout <<1 << endl;
    
    return 0;
}