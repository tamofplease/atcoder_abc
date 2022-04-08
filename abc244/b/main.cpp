#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int direction = 0; /// => 0: e, 1: s, 2: w, 3: n;
    map<int, pair<int,int>> route = { {0, {1, 0}}, {1, {0, -1}}, {2, {-1, 0}}, {3, {0, 1}} };
    pair<int, int> cur;
    for(char c: s) {
        if(c == 'R') {
            direction++;
            direction %= 4;   
        } else {
            cur.first += route[direction].first;
            cur.second += route[direction].second;
        }
    }
    cout << cur.first << " " << cur.second << endl;
    return 0;
}