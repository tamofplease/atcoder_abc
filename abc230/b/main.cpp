#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string S;
void input() {
   cin >> S; 
}

void solve() {
    string T;
    rep(i, 1000){
       T += "oxx";
    }
    auto found = T.find(S);
    if(found != std::string::npos) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int main(){
    input();
    solve();
    return 0;
}
