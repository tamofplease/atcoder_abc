// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    stack<char> st;
    int start = 0;
    for (const char c : s) {
        if (c == '(') start++;

        if (c == ')' && start > 0) {
            while (!st.empty() && st.top() != '(') st.pop();
            start--;
            st.pop();
            continue;
        }
        st.push(c);
    }

    string ans = "";
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
