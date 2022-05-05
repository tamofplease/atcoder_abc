#include <deque>
#include <queue>
#include <iostream>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int q; cin >> q;
    queue<ll> ans;
    deque<pair<int,int>> que;
    rep(i,q) {
        int k; cin >> k;
        if(k == 1){
            int x, c; cin >> x >> c;
            if(x == 0) continue;
            que.push_back({x,c});
        }
        if(k == 2) {
            int c; cin >> c;
            ll sum = 0;
            while(c != 0) {
                pair<int,int> q = que.front(); que.pop_front();    
                ll del = min(q.second, c);
                sum += del * q.first;
                c -= del;
                if(c==0) {
                    que.push_front({q.first, q.second - del});
                }
            }
            ans.push(sum);
        }
    }
    while(!ans.empty()) {
        ll sum = ans.front(); ans.pop();
        cout << sum << endl;
    }
    return 0;
}