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
const int MAXN = 101;

int main(){
    int N;
    cin >> N;
    int L[MAXN];
    rep(i,N)cin>> L[i];
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(i<j && j<k){
                    if(L[i]==L[j] || L[j]==L[k] || L[i] == L[k])continue;
                    int ma = max(L[i],max(L[j],L[k]));
                    int mi = min(L[i],min(L[j],L[k]));
                    int mid = L[i] + L[j] + L[k] - ma - mi;
                    if(ma < (mi + mid)) count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}