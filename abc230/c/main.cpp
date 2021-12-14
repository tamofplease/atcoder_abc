#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll N, A, B;
ll P, Q, R, S;
void input() {
   cin >> N >> A >> B;
   cin >> P >> Q >> R >> S; 
}

void solve() {
    ll first_x_min = A + max(1-A, 1-B);
    ll first_x_max = A + min(N-A, N-B);
    ll first_y_min = B + max(1-A, 1-B);
    ll first_y_max = B + max(N-A, N-B);
    ll second_x_min = A + max(1-A, B-N);
    ll second_x_max = A + min(N-A, B-1);
    ll second_y_min = B - min(N-A, B-1);
    ll second_y_max = B - max(1-A, B-N);
    for(ll i = P; i<=Q;i++) {
        for(ll j = R; j <= S ; j++) {
            if(i-A == j-B && first_x_min <= i && i <= first_x_max && first_y_min <= j && j <= first_y_max) {
                cout << "#";
            } else if (i-A == -1 * (j-B) && second_x_min <= i && i <= second_x_max && second_y_min <= j && j <= second_y_max) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main(){
    input();
    solve();
    return 0;
}
