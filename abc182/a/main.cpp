#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int A,B;
void input() {
   cin >> A >> B; 
}

void solve() {
   cout << max(0, 2 * A + 100 - B) << endl; 
}

int main(){
    input();
    solve();
    return 0;
}
