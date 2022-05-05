#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    int a,b,c,d,e,f,x; cin >> a >> b >> c >> d >> e >> f >> x;
    int ta = 0, ao = 0;
    ta = (x / (a+c)) * b * a;
    ao = (x / (d+f)) * e * d;
    ta += b * min(x % (a+c), a);
    ao += e * min(x % (d+f), d);
    if(ta > ao) puts("Takahashi");
    if(ta < ao) puts("Aoki");
    if(ta == ao) puts("Draw");
    return 0;
}