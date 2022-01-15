#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int cycle(int n) {
    string s = to_string(n);
    string updated = s.substr(1, s.length() - 1) + s.substr(0, 1);
    return stoi(updated);    
}

int a;

map<int, int> memo;

int search(int cur, int cost) {
    if(memo.find(cur) != memo.end()) {
        if(memo[cur] == -1) return -1;
        return memo[cur] + cost;
    }
    if(cur==1) {
        return cost;
    }
    if(cur < 10) {
        if(cur % a == 0) return search(cur/a, cost+1);
        else return -1;
    }
    if(cur % 10 != 0) {
        int ans = INT32_MAX;
        int cur_cost = cost;
        rep(i, to_string(cur).length()) {
            if(cur % a == 0) {
                int div_val = cur/a;
                int res = search(div_val, cur_cost+1);
                if(memo.find(div_val) != memo.end()) {
                    memo[div_val] = min(memo[div_val], res);
                } else {
                    memo[div_val] = res;
                }
                if(res != -1) {
                    ans = min(ans, res);
                }
            }
            cur = cycle(cur);
            cur_cost++;
        }
        if(ans == INT32_MAX) return -1;
        return ans;
    } 
    if(cur % a != 0) return -1;
    else return search(cur/a, cost+1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> a >> n;
    int ans = search(n, 0);
    cout << ans << endl;    
    return 0;
}
