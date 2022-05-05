#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    string s; cin >> s;
    int n = s.length();
    bool isUpper = false, isLower = false; 
    set<char> se;
    for(char c : s) {
        int t = int(c);
        if(64 < t && t < 91) {
            isUpper = true;
        } else {
            isLower = true;
        }
        se.insert(c);
    }
    if(isUpper && isLower && se.size() == s.length()) puts("Yes");
    else puts("No");
    return 0;
}