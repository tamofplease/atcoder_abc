#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<bool> isPrime(201, true);
    Rep(i,200) {
        if(i==1) isPrime[i] = false;
        if(isPrime[i]) {
            int j = 2;
            while(j * i < 201) {
                isPrime[j*i] = false;
                j++;
            }
        }
    }
    vector<bool> canMakePrime(b-a+1, false);
    for(int i=a;i<=b;i++) {
        for(int j=c;j<=d;j++) {
            if(isPrime[i+j]) {
                canMakePrime[i-a] = true;
                // break;
            }
        }
    }
    rep(i, b-a+1) {
        if(!canMakePrime[i]) {
            puts("Takahashi");
            return 0;   
        }
    }
    puts("Aoki");
    return 0;
}
