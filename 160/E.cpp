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

bool rev(const int &a, const int &b){
    return (a > b);
}

int X,Y,A,B,C;
const int maxabc = 100001;
int p[maxabc],q[maxabc],r[maxabc];

int main(){
    cin >> X >> Y >> A >> B >> C;
    rep(i,A)cin >>p[i];
    rep(i,B)cin >> q[i];
    rep(i,C)cin >> r[i];
    sort(p, p+A, rev);
    sort(q, q+B, rev);
    sort(r, r+C, rev);
    deque<int> d1;
    vector<int> v(0);
    rep(i,X){
        v.push_back(p[i]);
    }
    rep(i,Y){
        v.push_back(q[i]);
    }
    
    sort(v.begin(),v.end());

    rep(i,v.size()) {
        d1.push_back(v[i]);
    }

    rep(i,C) {
        if(d1.front() < r[i]){
            d1.pop_front();
            d1.push_back(r[i]);
        } else {
            break;
        }
    }

    ll ans = 0;
    int len = (int)d1.size();
    rep(i,len) {
        ans += d1.front();
        d1.pop_front();
    }

    cout << ans << endl;

    return 0;
}