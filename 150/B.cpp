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

int N;
string S;
int main(){
    cin >> N >> S;
    int count = 0;
    for(int i=0;i<N-2;i++){
        if(S[i]=='A' && S[i+1] == 'B'&&S[i+2]=='C'){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}