#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    long long a,b,k; cin >> a >> b >> k;
    int ans = 0;
    while(a < b) {
        ans++;
        a *= k;
    }
    cout << ans << endl;
    return 0;
}