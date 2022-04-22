#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int x = 0, y=0;
    rep(i, 3) {
        int a, b; cin >> a >> b;
        x ^= a;
        y ^= b;
    }
    cout << x << " " << y << endl;
    return 0;
}