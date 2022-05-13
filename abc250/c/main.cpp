// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64

int main() {
    int n, q;
    cin >> n >> q;
    /// position[i] = k -> ball number i is in position of k;
    /// ball[i] = k -> the ball at the position in i is k;
    vector<int> position(n);
    vector<int> ball(n);
    rep(i, n) {
        position[i] = i;
        ball[i] = i;
    }
    rep(i, q) {
        int fromPosition, toPosition;
        int fromBall, toBall;
        cin >> fromBall;
        fromBall--;
        fromPosition = position[fromBall];
        if (fromPosition == n-1) {
            toPosition = fromPosition - 1;
        } else {
            toPosition = fromPosition + 1;
        }
        toBall = ball[toPosition];
        swap(position[fromBall], position[toBall]);
        swap(ball[toPosition], ball[fromPosition]);
    }
    cout << 1 + ball[0];
    for (int i = 1 ; i < n ; i++) {
        cout << " " << ball[i] + 1;
    }
    cout << endl;

    return 0;
}
