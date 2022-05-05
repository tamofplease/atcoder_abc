#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    string s; cin >> s;
    cout << "0" + s.substr(0, 3) << endl;
    return 0;
}