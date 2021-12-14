#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
void input() {
   cin >> N; 
}

void solve() {
    if(N >= 42) {
        cout << "AGC0" << N + 1 << endl;
        return;
    }
    if(N < 10) {
        cout << "AGC00" << N << endl;
        return;
    }
    if(N < 42)  {
       cout << "AGC0" << N << endl;
       return;
    }
}

int main(){
    input();
    solve();
    return 0;
}
