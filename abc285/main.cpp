#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    string tmp = "";
    string s =
        accumulate(a.begin(), a.end(), tmp, [](string prev, int cur) -> string { return prev + to_string(cur) + "."; });
    cout << s << endl;
    return 0;
}