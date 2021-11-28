#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string a, b;
void input() {
    cin >> a >> b;
}

void solve() {
   if(a == "#." && b == ".#") {
       puts("No");
   }else if(a == ".#" && b == "#.") {
       puts("No");
   }else{
       puts("Yes");
   }
}

int main(){
    input();
    solve();
    return 0;
}
