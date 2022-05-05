#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

string recursive(int n) {
    if(n == 1) return "1";
    string tmp = recursive(n-1);
    return tmp + " " + to_string(n) + " " +tmp;
}
int main() {
    int n; cin >> n;
    cout << recursive(n) << endl;
    return 0;
}