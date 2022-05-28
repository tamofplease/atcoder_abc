// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

ll lcm(ll a, ll b){
  return a*b / gcd(a, b);
}
ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    // a <= b;
    ll sum = ll((n + 1) * n);
    sum -= ll(n / a) * ll(a + a * (n / a));
    if (b % a != 0) {
        sum -= ll(n / b) * ll(b + b * (n / b));
        ll c = lcm(a, b);
        sum += ll(n / c) * ll(c + c * (n / c));
    }
    cout << sum / 2 << endl;
    return 0;
}
