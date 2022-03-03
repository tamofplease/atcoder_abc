#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

vector<vector<ll>> c(61, vector<ll>(61, -1));

string search_ans(ll cur_k, int remain_a, int remain_b) {
    if(cur_k == 1 || remain_a == 0 || remain_b == 0) {
        string as(remain_a, 'a'), bs(remain_b, 'b');
        return as + bs;
    }
    if(c[remain_a+remain_b-1][remain_a-1] >= cur_k) {
        return "a" + search_ans(cur_k, remain_a-1, remain_b);
    } 
    return "b" + search_ans(cur_k - c[remain_a + remain_b - 1][remain_a - 1], remain_a, remain_b-1);
}

int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    Rep(i, 60) {
        c[i][0] = 1, c[i][i] = 1;
    }
    Rep(i, 60) Rep(j, i-1) c[i][j] = c[i-1][j-1] + c[i-1][j];

    cout << search_ans(k, a, b) << endl;
    
    
    return 0;
}
