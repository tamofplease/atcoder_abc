#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    // Here we will start from sqrt(M) as it is the maximum possible factor of M
    // and go till 1 to find the first number which can be a factor of M and less than equal to N
    ll upper = ceil(sqrt(M));

    ll ans = INT64_MAX;
    for (ll a = upper; a >= 1; a--) {
        ll b = ceil((double)M / a);
        if (a <= N && b <= N) {
            ans = min(ans, a * b);
        }
    }
    if (ans != INT64_MAX) {
        cout << ans << endl;
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
