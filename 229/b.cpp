#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll A, B;
void input() {
    cin >> A >> B;
}

void solve() {
    while(A > 0 && B > 0) {
        int a = A % 10;
        int b = B % 10;
        if(a + b > 9) {
            cout << "Hard" << endl;
            return;
        }
        A /= 10;
        B /= 10;
    }
    cout << "Easy" << endl;
}

int main(){
    input();
    solve();
    return 0;
}
