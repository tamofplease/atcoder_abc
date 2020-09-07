#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

const int MAXN = 300001;
ll N;
ll A[MAXN];



int main(){
    cin >> N ;
    ll maxi = 0;
    rep(i,N){
      cin >> A[i];
      maxi = max(A[i], maxi);
    }
    ll maxbit = 0;
    while(1) {
      maxi = (maxi >> 1);
      maxbit++;
      if(maxi==0)break;
    }
    ll ans = 0;
    ll tmp_bit = 1;
    for(int bit=0;bit<maxbit;bit++) {
      ll zero = 0;
      ll one = 0;
      rep(i,N) {
        if((A[i]>>bit) & 1){
          one++;
        }
        else zero++;
      }
      tmp_bit %= mod;
      ll tmp = (tmp_bit * min(one, zero)) %mod;
      tmp = (tmp * max(zero,one)) % mod;
      ans += tmp;
      ans %= mod;
      tmp_bit *= 2;
      tmp_bit %= mod;
    }
    
    cout << ans << endl;
    return 0;
}