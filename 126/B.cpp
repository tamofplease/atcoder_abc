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

bool is_month(int t){
    if(t<=12 && t>0)return true;
    else return false;
}

int main(){
    string S;cin >> S;
    int first,second;
    first = (S[0]-'0')*10 + (S[1] - '0');
    second = (S[2]-'0')*10 + (S[3]-'0');
    if(is_month(first)){
        if(is_month(second))cout << "AMBIGUOUS";
        else cout << "MMYY";
    }else if(is_month(second))cout << "YYMM";
    else cout << "NA";
    cout << endl;
    return 0;
}