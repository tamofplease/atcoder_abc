#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    string s; cin >> s;
    int ans = 45;
    for(char c : s)  ans -= (c - '0');
    cout << ans << endl;
    return 0;
}