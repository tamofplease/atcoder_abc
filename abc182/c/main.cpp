#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll N;
void input() {
   cin >> N; 
}

void solve() {
    if( N % 3 == 0 ) {
        cout << 0 << endl;
        return;
    }
    
    int zero = 0, one = 0, two = 0;;
    int all = 0;
    ll N2 = N;
    while(N2 > 0) {
        int dig = N2 % 10;
        N2 /= 10;
        all += dig;
        all %= 3;
        if (dig % 3 == 0) zero += 1;
        if (dig % 3 == 1)one += 1;
        if (dig % 3 == 2) two += 1;
    }

    if(all % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    if(all % 3 == 1) {
        if(N >= 10 && one > 0) {
            cout << 1 << endl;
            return;
        }
        if(N >= 100 && two > 1) {
            cout << 2 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }

    if(all % 3 == 2) {
        if(N >= 10 && two > 0) {
            cout << 1 << endl;
            return;
        }
        if(N >= 100 && one > 1) {
            cout << 2 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }


}

int main(){
    input();
    solve();
    return 0;
}
