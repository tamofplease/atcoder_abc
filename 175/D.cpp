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

const ll MAXN=5001;
ll P[MAXN];
ll C[MAXN];
int main(){
    int N;cin >> N;
    ll K; cin >> K;
    Rep(i,N)cin >> P[i];
    Rep(i,N)cin >> C[i];
    ll ans = LLONG_MIN;
    Rep(i,N){
        ll current = i;
        ll counter = 0;
        bool checker[MAXN];
        Rep(j,N)checker[j] = false;
        ll tmp_score = 0;
        ll ma = LLONG_MIN;
        while(!checker[current] && counter<K){
            counter++;
            checker[current] = true;
            current = P[current];
            tmp_score += C[current];
            ma = max(tmp_score,ma);
        }
        ans = max(ma,ans);
        if(checker[current] && tmp_score >= 0){
            
            ll tm = tmp_score * (K/counter);
            ll sur = K - (K/counter) * counter;
            ll tmp_max;
            if(sur==0)tmp_max = 0;
            else tmp_max = LLONG_MIN;
            tmp_score = 0;
            Rep(j,sur){
                current = P[current];
                tmp_score += C[current];
                tmp_max = max(tmp_max,tmp_score);
            }
            ll t = max(tmp_max+tm, tm);
            ans = max(ans,t);
        }
    }
    cout << ans << endl;

    return 0;
}