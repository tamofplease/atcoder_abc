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

bool sor(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

bool desc(const int &a, const int &b) {
    return a > b;
}

int main(){
    int N,M;cin >> N >> M;
    const int MAXN = 100001;
    // memset(Ma,0,sizeof(int)*MAXN);
    int A[MAXN];
    rep(i,N){
        cin >> A[i];
    }
    sort(A,A+N);
    pair<int,int> P[MAXN];

    rep(i,M){
        cin >> P[i].first >> P[i].second;// firstこのseconde
    }

    sort(P,P+M,sor);
    
    int tmp[MAXN+2];
    int count = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<P[i].first;j++){
            tmp[count] = P[i].second;
            count++;
            if(count>N)break;
        }
    }

    sort(tmp,tmp+MAXN,desc);
    ll ans = 0;
    rep(i,N){
        ans += max(tmp[i],A[i]);
    }

    cout << ans << endl;

    return 0;
}