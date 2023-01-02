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
    string s;
    cin >> s;
    stack<char> st;
    set<char> cur;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
            continue;
        }
        if (c == ')') {
            while (st.top() != '(') {
                cur.erase(st.top());
                st.pop();
            }
            st.pop();
            continue;
        }
        if (cur.count(c)) {
            puts("No");
            return 0;
        }
        st.push(c);
        cur.insert(c);
    }
    puts("Yes");
    return 0;
}
