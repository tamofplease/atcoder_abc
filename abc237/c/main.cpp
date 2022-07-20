#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    int sl = s.length();
    int head_a = 0, tail_a = 0;
    for (char c : s) {
        if (c == 'a') head_a++;
        else break;
    }
    for (char c : rev) {
        if (c == 'a') tail_a++;
        else break;
    }
    if (head_a > tail_a) {
        puts("No"); return 0;
    }
    string target = s.substr(head_a, sl - head_a - tail_a);
    // cout << target << endl;
    string rev_target = target;
    reverse(rev_target.begin(), rev_target.end());
    if (rev_target == target) {
        puts("Yes");
        return 0;
    }
    else {
        puts("No");
    }

    return 0;
}
