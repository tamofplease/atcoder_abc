#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

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


bool checker(string s) {
    int len = s.length();
    for(int i=0;i<len/2;i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;

}

int main(){
    string s;
    cin >> s;
    string bef,af;
    int len = s.length();
    for(int i=0;i<len/2;i++) {
        bef = bef + s[i];
    }

    for(int i=(len+2)/2;i<len;i++) {
        af = af + s[i];
    }

    if(checker(s) && checker(bef) && checker(af)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}