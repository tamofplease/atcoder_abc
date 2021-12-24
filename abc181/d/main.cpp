#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string s;
int main(){
    cin >> s;
    int have[11];
    memset(have, 0, sizeof(have));
    for(char c : s) {
        int n = c - '0';
        have[n]++;
    }
    if(s.length() == 1) {
        int n = s[0] - '0';
        if(n % 8 == 0) puts("Yes");
        else puts("No");
        return 0;
    }
    if(s.length() == 2) {
        int n1 = s[0] - '0' + (s[1] - '0') * 10;
        int n2 = (s[0] - '0') * 10 + s[1] - '0';
        if(n1 % 8 == 0 || n2 % 8 == 0) puts("Yes");
        else puts("No");
        return 0;
    }
    int tmp = 0;
    while(tmp < 1000) {
        int t = tmp;
        int counter[11];
        memset(counter, 0, sizeof(counter));
        rep(i, 3) {
            counter[t%10]++;
            t /= 10;
        }

        bool flag = true;
        rep(i, 10) {
            if(counter[i] > have[i]) {
                flag = false;
            }
        }
        if(flag) {
            puts("Yes");
            return 0;
        }
        tmp += 8;
    }
    puts("No");

    return 0;
}
