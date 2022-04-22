#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

#define ll long long

int main() {
    ll n,k,x;
    cin >> n >> k >> x;
    ll sum = 0, cnt = 0;
    priority_queue<int> pq;
    rep(i,n) {
        int a; cin >> a;
        sum += a;
        cnt += a / x;
        pq.push(a % x);
    }
    sum -= x * min(cnt, k);
    if(k <= cnt) {
        cout << sum << endl;
        return 0;
    }

    rep(i, k-cnt) {
        if(pq.empty()) {
            cout << 0 << endl;
            return 0;
        }
        sum -= pq.top();
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}