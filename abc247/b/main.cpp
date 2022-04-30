#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n;cin >> n;
    vector<string> s(n), t(n);
    map<string, int> a;
    rep(i,n) {
        cin >> s[i] >> t[i];
        a[s[i]]++;
        a[t[i]]++;
    }
    rep(i,n) {
        if(a[s[i]] != 1 && a[t[i]] != 1) {
            if(s[i] == t[i] && a[s[i]] == 2) continue;
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}