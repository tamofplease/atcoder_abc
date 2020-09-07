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

const int MAXN = 200001;
int Sur[MAXN];
int main(){
    string S;
    cin >> S;
    int N = S.length();
    int tmp = 0;
    ll cou = 1;
    for(int i=N-1;i>=0;i--){
        tmp += ((S[i]-'0')*cou)%2019;
        cou *= 10;
        cou %= 2019;
        tmp %= 2019;
        Sur[N-i] = tmp;
        Sur[N-i] %= 2019;
    }
    map<int,int> ma;
    int ans = 0;
    Rep(i,N){
        if(ma[Sur[i]]>0){
            ans+=(ma[Sur[i]]);
            ma[Sur[i]]++;
        }else ma[Sur[i]] = 1;
    }
    Rep(i,N){
        if(Sur[i]==0)ans++;
    }
    cout << ans << endl;

    return 0;
}