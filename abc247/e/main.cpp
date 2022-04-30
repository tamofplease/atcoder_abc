#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

ll solvePartial(int x, int y, vector<int>& b) {
    int i=0, j=0, countX=0, countY=0;
    ll res = 0;
    while(i != b.size()) {
        while(j!=b.size() && (countX == 0 || countY == 0)) {
            if(b[j] == x) {
                countX++;
            }
            if(b[j] == y) {
                countY++;
            }
            j++;
        }
        if(countX>0 && countY > 0) {
            res += b.size() - j + 1;
        }
        if(b[i] == x) countX--;
        if(b[i] == y) countY--;
        i++;
    }
    return res;
}

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    int i = 0;
    while(i < n) {
        vector<int> b;
        while(i < n && y <= a[i] && a[i] <= x) {
            b.push_back(a[i]);
            i++;
        }
        if(b.size() != 0) {
            ans += solvePartial(x, y, b);
        }
        else {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}