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

bool exc(const pair<string,int> &p1, const pair<string,int> &p2){
    if(p1.first > p2.first)return false;
    else if(p1.first < p2.first)return true;
    else return p1.second > p2.second;
}


int main(){
    int N;cin >> N;
    pair<string,int> P[101];
    map<pair<string,int> ,int> S;
    rep(i,N){
        cin >> P[i].first >> P[i].second;
        S[P[i]] = i+1;
    }

    sort(P,P+N,exc);

    rep(i,N){
        cout << S[P[i]] << endl;
    }



    return 0;
}